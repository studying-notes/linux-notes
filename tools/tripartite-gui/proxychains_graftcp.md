---
date: 2022-05-09T00:45:32+08:00
author: "Rustle Karl"

title: "proxychains 与 graftcp 原理对比"
url:  "posts/linux/tools/tripartite-gui/proxychains_graftcp"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

https://github.com/haad/proxychains

https://github.com/hmgle/graftcp

## 原理及差异

二者的基本思路大同小异，都是通过截获子进程的 socket 相关的系统调用，偷偷地与代理建立连接，最后在 connect 调用中返回代理的 socket。

但是在具体实现上，二者用了不同的方案。

### proxychains

proxychains 使用了 LD_PRELOAD 环境变量。系统调用都会经过 glibc 的包装，所以在 c 中写个 connect 实际上调用的是 glibc 的库函数。而 LD_PRELOAD 环境变量向用户提供了覆盖库函数的能力，proxychains 正是利用了这一点。

在其源码中可以看到，它一共截获了6个函数：

```cpp
connect_t true_connect;
gethostbyname_t true_gethostbyname;
getaddrinfo_t true_getaddrinfo;
freeaddrinfo_t true_freeaddrinfo;
getnameinfo_t true_getnameinfo;
gethostbyaddr_t true_gethostbyaddr;
```

其中，截获 connect 函数是为了与代理服务器进行连接，也就是执行主要的功能；而其他的几个函数是为了使用 socks5 的远程 DNS 功能，能够解决 DNS 污染的问题。

简单说下之后的过程（不考虑远程 DNS）。在截获 connect 之后，proxychains 会拿到其参数中的目标 ip ；然后与代理服务器建立连接，并请求其代理该 ip 地址；成功之后，便将受到代理的 socket 描述符返回给应用。至此，透明代理建立完成。

### graftcp

graftcp 的思路则是通过 ptrace 调用来截获子进程的 connect 连接，这是二者最大的不同，也直接影响到二者的适用情况。另外有一点不同的是，graftcp 并非自己处理与代理服务器的连接，而是将此任务交给了一个叫做 graftcp-local 的进程去做。

与 proxychains 很大的一点不同在于，graftcp 与被代理的程序并非在同一个进程中运行，而是父子进程的关系，父子进程并不共享文件描述符表，这就导致 graft 不能向 proxychains 一样“自己”去连接代理服务器并将文件描述符直接由 connect 返回了，因为 graft 创建的只能是自己进程内的描述符，不能直接交给子进程使用。（这可以理解为：ptrace 原语相比于 LD_LIBRARY 原语失去了“有效修改 connect 返回的文件描述符”的能力，因此无法直接使用之前的方法。）

针对这个问题，graft 的做法是建立一个单独的服务器 graftcp-local，相当于“代理服务器的代理”，并将子进程发起的 connect 的目的地址改为该服务器的地址，让子进程发起向 graftcp-local 的连接。

但是这又引出了另一个问题：从graftcp-local的角度来看，它接到一个新的连接之后，并不知道这个连接实际上是要连接哪里的，因为connect请求并没有携带原目的地址信息。

这时候又需要 graftcp 进程了，在 graftcp 使用 ptrace 追踪到原 connect 请求之后，他会将原目的地址以及子进程 pid 发送给 graftcp-local，这样 graftcp-local 就有了一个从 pid 到目的地址的映射表，在它得到新连接之后，可以通过查询 /proc/net/tcp 文件取得新连接所在的进程 pid，从而得知它的真实目的地址。至此，graftcp-local 就可以建立完整的代理连接了。

## 优缺点

相比之下，proxychains 最大的优点就是支持远程 DNS 了，但由于 LD_PRELOAD 的一些限制，导致了它：

- 不能以 root 权限用户使用
- 不能给静态编译的程序使用（比如所有的 go 程序）
- 不能在不使用库函数进行 DNS 查询的程序中使用远程 DNS（比如 java）

相反的，graft 并不限制用户和程序，适用性更广泛一点，虽然无法解决 DNS 污染的问题，但是这个问题可以通过更换 DNS 解决。
