---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "scp 在网络之间进行安全传输数据"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/scp"  # 设置网页永久链接
tags: [ "linux", "cmd" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

# 章节
weight: 20 # 排序优先级
chapter: false  # 设置为章节

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
----

> 加密的方式在本地主机和远程主机之间复制文件

## scp 命令 用于在 Linux 下进行远程拷贝文件的命令，和它类似的命令有 cp，不过 cp 只是在本机进行拷贝不能跨服务器，而且 scp 传输是加密的。可能会稍微影响一下速度。当你服务器硬盘变为只读 read only system 时，用 scp 可以帮你把文件移出来。另外，scp 还非常不占资源，不会提高多少系统负荷，在这一点上，rsync 就远远不及它了。虽然 rsync 比 scp 会快一点，但当小文件众多的情况下，rsync 会导致硬盘 I/O 非常高，而 scp 基本不影响系统正常使用。

## 格式

```bash
scp [-12346BCpqrv] [-c cipher] [-F ssh_config] [-i identity_file] [-l limit] [-o ssh_option] [-P port] [-S program] [[user@]host1:]file1 ... [[user@]host2:]file2
```

## 选项

```shell
-1：使用ssh协议版本1；
-2：使用ssh协议版本2；
-4：使用ipv4；
-6：使用ipv6；
-B：以批处理模式运行；
-C：使用压缩；
-F：指定ssh配置文件；
-i：identity_file 从指定文件中读取传输时使用的密钥文件（例如亚马逊云pem），此参数直接传递给ssh；
-l：指定宽带限制；
-o：指定使用的ssh选项；
-P：指定远程主机的端口号；
-p：保留文件的最后修改时间，最后访问时间和权限模式；
-q：不显示复制进度；
-r：以递归方式复制。
```

* 源文件：指定要复制的源文件。
* 目标文件：目标文件。格式为`user@host:filename`（文件名为目标文件的名称）。

## 参数

| 参数 | 作用 |
| ---- | -------- |
| -v | 显示详细的连接进度 |
| -P | 指定远程主机的 sshd 端口号 |
| -r | 用于传送文件夹 |
| -6 | 使用 IPv6 协议 |

## 示例

1. 从客户端上传到远程服务器

```bash
scp LICENSE root@120.77.220.48:/root
LICENSE                             100% 1080    32.2KB/s   00:00
```

1. 从远程服务器下载到本地

```bash
scp root@120.77.220.48:/etc/hosts .
hosts                               100%  178     6.6KB/s   00:00
```

## 实例

从远程复制到本地的 scp 命令与上面的命令雷同，只要将从本地复制到远程的命令后面 2 个参数互换顺序就行了。

### 从远程机器复制文件到本地目录 

```shell
scp root@10.10.10.10:/opt/soft/nginx-0.5.38.tar.gz /opt/soft/
```

从10.10.10.10机器上的`/opt/soft/`的目录中下载nginx-0.5.38.tar.gz 文件到本地`/opt/soft/`目录中。

### 从亚马逊云复制OpenVPN到本地目录 

```shell
scp -i amazon.pem ubuntu@10.10.10.10:/usr/local/openvpn_as/etc/exe/openvpn-connect-2.1.3.110.dmg openvpn-connect-2.1.3.110.dmg
```

从10.10.10.10机器上下载openvpn安装文件到本地当前目录来。

### 从远程机器复制到本地 

```shell
scp -r root@10.10.10.10:/opt/soft/mongodb /opt/soft/
```

从10.10.10.10机器上的`/opt/soft/`中下载mongodb目录到本地的`/opt/soft/`目录来。

### 上传本地文件到远程机器指定目录 

```shell
scp /opt/soft/nginx-0.5.38.tar.gz root@10.10.10.10:/opt/soft/scptest
# 指定端口 2222
scp -rp -P 2222 /opt/soft/nginx-0.5.38.tar.gz root@10.10.10.10:/opt/soft/scptest
```

复制本地`/opt/soft/`目录下的文件nginx-0.5.38.tar.gz到远程机器10.10.10.10的`opt/soft/scptest`目录。

### 上传本地目录到远程机器指定目录 

```shell
scp -r /opt/soft/mongodb root@10.10.10.10:/opt/soft/scptest
```

上传本地目录`/opt/soft/mongodb`到远程机器10.10.10.10上`/opt/soft/scptest`的目录中去。
