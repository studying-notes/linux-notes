---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "Linux 防火墙"  # 文章标题
url:  "posts/linux/abc/firewall"  # 设置网页永久链接
tags: [ "linux" ]  # 标签
series: [ "Linux 学习笔记"]  # 系列
categories: [ "学习笔记"]  # 分类

# 章节
weight: 20 # 排序优先级
chapter: false  # 设置为章节

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
---

## 概述

防火墙策略可以基于流量的源目地址、端口号、协议、应用等信息来定制，然后防火墙使用预先定制的策略规则监控出入的流量，若流量与某一条策略规则相匹配，则执行相应的处理，反之则丢弃。

在 RHEL 7 系统中，firewalld 防火墙取代了 iptables 防火墙。其实，iptables 与 firewalld 都不是真正的防火墙，它们都只是用来定义防火墙策略的防火墙管理工具而已，或者说，它们只是一种服务。iptables 服务会把配置好的防火墙策略交由内核层面的 netfilter 网络过滤器来处理，而 firewalld 服务则是把配置好的防火墙策略交由内核层面的 nftables 包过滤框架来处理。

## iptables

### 策略与规则链

防火墙会从上至下的顺序来读取配置的策略规则，在找到匹配项后就立即结束匹配工作并去执行匹配项中定义的行为（即放行或阻止）。如果在读取完所有的策略规则之后没有匹配项，就去执行默认的策略。一般而言，防火墙策略规则的设置有两种：一种是“通”（即放行），一种是“堵”（即阻止）。当防火墙的默认策略为拒绝时（堵），就要设置允许规则（通），否则谁都进不来；如果防火墙的默认策略为允许时，就要设置拒绝规则，否则谁都能进来，防火墙也就失去了防范的作用。

iptables 服务把用于处理或过滤流量的策略条目称之为规则，多条规则可以组成一个规则链，而规则链则依据数据包处理位置的不同进行分类，具体如下：

- 在进行路由选择前处理数据包（PREROUTING）
- 处理流入的数据包（INPUT）
- 处理流出的数据包（OUTPUT）
- 处理转发的数据包（FORWARD）
- 在进行路由选择后处理数据包（POSTROUTING）

一般来说，从内网向外网发送的流量一般都是可控且良性的，因此我们使用最多的就是INPUT 规则链，该规则链可以增大黑客人员从外网入侵内网的难度。

iptables 服务的术语中有 ACCEPT（允许流量通过）、REJECT（拒绝流量通过，在拒绝流量后再回复一条“您的信息已经收到，但是被扔掉了”信息）、LOG（记录日志信息）、DROP（拒绝流量通过，将流量丢弃而且不响应）。

当把 Linux 系统中的防火墙策略设置为 REJECT 拒绝动作后，流量发送方会看到端口不可达的响应：

```bash
$ ping -c 4 192.168.10.10
PING 192.168.10.10 (192.168.10.10) 56(84) bytes of data.
From 192.168.10.10 icmp_seq=1 Destination Port Unreachable
From 192.168.10.10 icmp_seq=2 Destination Port Unreachable
From 192.168.10.10 icmp_seq=3 Destination Port Unreachable
From 192.168.10.10 icmp_seq=4 Destination Port Unreachable
--- 192.168.10.10 ping statistics ---
4 packets transmitted, 0 received, +4 errors, 100% packet loss, time 3002ms
```

而把 Linux 系统中的防火墙策略修改成 DROP 拒绝动作后，流量发送方会看到响应超时的提醒。但是流量发送方无法判断流量是被拒绝，还是接收方主机当前不在线：

```bash
$ ping -c 4 192.168.10.10
PING 192.168.10.10 (192.168.10.10) 56(84) bytes of data.
--- 192.168.10.10 ping statistics ---
4 packets transmitted, 0 received, 100% packet loss, time 3000ms
```

### 基本的命令参数

iptables 命令可以根据流量的源地址、目的地址、传输协议、服务类型等信息进行匹配，一旦匹配成功，iptables 就会根据策略规则所预设的动作来处理这些流量。

| 参数 | 作用 |
| --------- | --------- |
| -P | 设置默认策略 |
| -F | 清空规则链 |
| -L | 查看规则链 |
| -A | 在规则链的末尾加入新规则 |
| -I num | 在规则链的头部加入新规则 |
| -D num | 删除某一条规则 |
| -s | 匹配来源地址 IP/MASK，加叹号“!”表示除这个 IP 外 -d 匹配目标地址 |
| -i 网卡名称 | 匹配从这块网卡流入的数据 |
| -o 网卡名称 | 匹配从这块网卡流出的数据 |
| -p | 匹配协议，如 TCP、UDP、ICMP |
| --dport num | 匹配目标端口号 |
| --sport num | 匹配来源端口号 |

**在 iptables 命令后添加 `-L` 参数查看已有的防火墙规则链：**

```bash
$ iptables -L
Chain INPUT (policy ACCEPT)
target     prot opt source               destination
ACCEPT     all  --  anywhere             anywhere             ctstate RELATED,ESTABLISHED
ACCEPT     all  --  anywhere             anywhere
INPUT_direct  all  --  anywhere             anywhere
INPUT_ZONES_SOURCE  all  --  anywhere             anywhere
INPUT_ZONES  all  --  anywhere             anywhere
ACCEPT     icmp --  anywhere             anywhere
REJECT     all  --  anywhere             anywhere             reject-with icmp-host-prohibited
……
```

**在 iptables 命令后添加 `-F` 参数清空已有的防火墙规则链：**

```bash
$ iptables -F
```

**把 INPUT 规则链的默认策略设置为拒绝：**

```bash
$ iptables -P INPUT DROP

$ iptables -L
Chain INPUT (policy DROP)
……
```

前文提到，防火墙策略规则的设置有两种：通和堵。当把 INPUT 链设置为默认拒绝后，就要在防火墙策略中写入允许策略了，否则所有到来的流量都会被拒绝掉。另外，需要注意的是，规则链的默认拒绝动作只能是 DROP，而不能是 REJECT。


```powershell
PS > ping 192.168.244.137

正在 Ping 192.168.244.137 具有 32 字节的数据:
请求超时。
请求超时。
请求超时。
请求超时。

192.168.244.137 的 Ping 统计信息:
    数据包: 已发送 = 4，已接收 = 0，丢失 = 4 (100% 丢失)，
```

**向 INPUT 链中添加允许 ICMP 流量进入的策略规则：**


```bash
$ iptables -I INPUT -p icmp -j ACCEPT
```

```powershell
PS > ping 192.168.244.137

正在 Ping 192.168.244.137 具有 32 字节的数据:
来自 192.168.244.137 的回复: 字节=32 时间<1ms TTL=64
来自 192.168.244.137 的回复: 字节=32 时间<1ms TTL=64
来自 192.168.244.137 的回复: 字节=32 时间<1ms TTL=64
来自 192.168.244.137 的回复: 字节=32 时间<1ms TTL=64

192.168.244.137 的 Ping 统计信息:
    数据包: 已发送 = 4，已接收 = 4，丢失 = 0 (0% 丢失)，
往返行程的估计时间(以毫秒为单位):
    最短 = 0ms，最长 = 0ms，平均 = 0ms
```

**删除 INPUT 规则链中刚刚加入的那条策略（允许CMP流量），并把默认策略设置为允许**

```bash
$ iptables -D INPUT 1
$ iptables -P INPUT ACCEPT
```

**将 INPUT 规则链设置为只允许指定网段的主机访问本机的 22 端口，拒绝来自其他所有主机的流量：**

```bash
$ iptables -I INPUT -s 192.168.244.0/24 -p tcp --dport 22 -j ACCEPT
$ iptables -A INPUT -p tcp --dport 22 -j REJECT
```

防火墙策略规则是按照从上到下的顺序匹配的，因此一定要把允许动作放到拒绝动作前面，否则所有的流量就将被拒绝掉，从而导致任何主机都无法访问我们的服务。

```bash
$ ssh root@192.168.244.137
```

**向 INPUT 规则链中添加拒绝所有人访问本机12345端口的策略规则：**

```bash
$ iptables -I INPUT -p tcp --dport 12345 -j REJECT
$ iptables -I INPUT -p udp --dport 12345 -j REJECT
```

**向 INPUT 规则链中添加拒绝 192.168.10.5 主机访问本机 80 端口的策略规则：**

```bash
$ iptables -I INPUT -p tcp -s 192.168.10.5 --dport 80 -j REJECT
```

**向 INPUT 规则链中添加拒绝所有主机访问本机 1000~1024 端口的策略规则：**

```bash
$ iptables -A INPUT -p tcp --dport 1000:1024 -j REJECT
$ iptables -A INPUT -p udp --dport 1000:1024 -j REJECT
```

使用 iptables 命令配置的防火墙规则默认会在系统下一次重启时失效，如果想让配置的防火墙策略永久生效，还要执行保存命令：

```bash
$ service iptables save
```

## firewalld

相较于传统的防火墙管理配置工具，firewalld 支持动态更新技术并加入了区域（zone）的概念。简单来说，区域就是 firewalld 预先准备了几套防火墙策略集合（策略模板），用户可以根据生产场景的不同而选择合适的策略集合，从而实现防火墙策略之间的快速切换。

### 常用的区域名称及策略规则

| 区域 | 默认策略规则 |
| --------- | --------- |
| trusted | 允许所有的数据包 |
| home | 拒绝流入的流量，除非与流出的流量相关；而如果流量与 ssh、mdns、ipp-client、amba-client 与 dhcpv6-client 服务相关，则允许流量 |
| internal | 等同于 home 区域 |
| work | 拒绝流入的流量，除非与流出的流量数相关；而如果流量与 ssh、ipp-client 与 |
| dhcpv6-client | 服务相关，则允许流量 |
| public | 拒绝流入的流量，除非与流出的流量相关；而如果流量与 ssh、dhcpv6-client 服务 相关，则允许流量 |
| external | 拒绝流入的流量，除非与流出的流量相关；而如果流量与 ssh 服务相关，则允许流量 |
| dmz | 拒绝流入的流量，除非与流出的流量相关；而如果流量与 ssh 服务相关，则允许流量 |
| block | 拒绝流入的流量，除非与流出的流量相关 |
| drop | 拒绝流入的流量，除非与流出的流量相关 |

### 终端管理工具

| 参数 | 作用 |
| --------- | --------- |
| --get-default-zone | 查询默认的区域名称 |
| --set-default-zone=<区域名称> | 设置默认的区域，使其永久生效 |
| --get-zones | 显示可用的区域 |
| --get-services | 显示预先定义的服务 |
| --get-active-zones | 显示当前正在使用的区域与网卡名称 |
| --add-source= | 将源自此 IP 或子网的流量导向指定的区域 |
| --remove-source= | 不再将源自此 IP 或子网的流量导向某个指定区域 |
| --add-interface=<网卡名称> | 将源自该网卡的所有流量都导向某个指定区域 |
| --change-interface=<网卡名称> | 将某个网卡与区域进行关联 |
| --list-all | 显示当前区域的网卡配置参数、资源、端口以及服务等信息 |
| --list-all-zones | 显示所有区域的网卡配置参数、资源、端口以及服务等信息 |
| --add-service=<服务名> | 设置默认区域允许该服务的流量 |
| --add-port=<端口号/协议> | 设置默认区域允许该端口的流量 |
| --remove-service=<服务名> | 设置默认区域不再允许该服务的流量 |
| --remove-port=<端口号/协议> | 设置默认区域不再允许该端口的流量 |
| --reload | 让“永久生效”的配置规则立即生效，并覆盖当前的配置规则 |
| --panic-on | 开启应急状况模式 |
| --panic-off | 关闭应急状况模式 |

与 Linux 系统中其他的防火墙策略配置工具一样，使用 firewalld 配置的防火墙策略默认为运行时（Runtime）模式，又称为当前生效模式，而且随着系统的重启会失效。如果想让配置策略一直存在，就需要使用永久（Permanent）模式了，方法就是在用 firewall-cmd 命令正常设置防火墙策略时添加 `--permanent` 参数，这样配置的防火墙策略就可以永久生效了。但是，永久生效模式设置的策略只有在系统重启之后才能自动生效。如果想让配置的策略立即生效，需要手动执行 `firewall-cmd --reload` 命令。

查看 firewalld 服务当前所使用的区域：

```bash
$ firewall-cmd --get-default-zone
public
```

查询 eno16777728 网卡（虚拟机网卡）在 firewalld 服务中的区域：

```bash
$ firewall-cmd --get-zone-of-interface=eno16777728
public
```

把 firewalld 服务中 eno16777728 网卡的默认区域修改为 external，并在系统重启后生效。分别查看当前与永久模式下的区域名称：

```bash
$ firewall-cmd --permanent --zone=external --change-interface=eno16777728
success

$ firewall-cmd --get-zone-of-interface=eno16777728
public

$ firewall-cmd --permanent --get-zone-of-interface=eno16777728
external
```

把 firewalld 服务的当前默认区域设置为 public：

```bash
$ firewall-cmd --set-default-zone=public
success

$ firewall-cmd --get-default-zone
public
```

启动/关闭 firewalld 防火墙服务的应急状况模式，阻断一切网络连接（当远程控制服务器时请慎用）：

```bash
$ firewall-cmd --panic-on
success

$ firewall-cmd --panic-off
success
```

查询 public 区域是否允许请求 SSH 和 HTTPS 协议的流量：

```bash
$ firewall-cmd --zone=public --query-service=ssh
yes

$ firewall-cmd --zone=public --query-service=https
no
```

把 firewalld 服务中请求 HTTPS 协议的流量设置为永久允许，并立即生效：

```bash
$ firewall-cmd --zone=public --add-service=https
success

$ firewall-cmd --permanent --zone=public --add-service=https
success

$ firewall-cmd --reload
success

$ firewall-cmd --zone=public --query-service=https
yes
```

把 firewalld 服务中请求 HTTP 协议的流量设置为永久拒绝，并立即生效：

```bash
$ firewall-cmd --permanent --zone=public --remove-service=http
success

$ firewall-cmd --reload
success
```

把在 firewalld 服务中访问 8080 和 8081 端口的流量策略设置为允许，但仅限当前生效：

```bash
$ firewall-cmd --zone=public --add-port=8080-8081/tcp
success

$ firewall-cmd --zone=public --list-ports
8080-8081/tcp
```

把原本访问本机 888 端口的流量转发到 22 端口，要且求当前和长期均有效：

```bash
$ firewall-cmd --permanent --zone=public --add-forward-port=port=888:proto=tcp:toport=22:toaddr=192.168.244.137
success

$ firewall-cmd --reload
success
```

在客户端使用 ssh 命令尝试访问 192.168.10.10 主机的 888 端口：

```bash
$ ssh -p 888 root@192.168.244.137
```

firewalld 中的富规则表示更细致、更详细的防火墙策略配置，它可以针对系统服务、端口号、源地址和目标地址等诸多信息进行更有针对性的策略配置。它的优先级在所有的防火墙策略中也是最高的。比如，我们可以在 firewalld 服务中配置一条富规则，使其拒绝 192.168.10.0/24 网段的所有用户访问本机的 ssh 服务（22 端口）：

```bash
$ firewall-cmd --permanent --zone=public --add-rich-rule="rule family="ipv4" source address="192.168.244.0/24" service name="ssh" reject"
success

$ firewall-cmd --reload
success
```

## 服务的访问控制列表

TCP Wrappers 是 RHEL 7 系统中默认启用的一款流量监控程序，它能够根据来访主机的地址与本机的目标服务程序作出允许或拒绝的操作。换句话说，Linux 系统中其实有两个层面的防火墙，第一种是前面讲到的基于 TCP/IP 协议的流量过滤工具，而 TCP Wrappers 服务则是能允许或禁止 Linux 系统提供服务的防火墙，从而在更高层面保护了 Linux 系统的安全运行。

TCP Wrappers 服务的防火墙策略由两个控制列表文件所控制，用户可以编辑允许控制列表文件来放行对服务的请求流量，也可以编辑拒绝控制列表文件来阻止对服务的请求流量。控制列表文件修改后会立即生效，系统将会先检查允许控制列表文件 `etc/hosts.allow`，如果匹配到相应的允许策略则放行流量；如果没有匹配，则去进一步匹配拒绝控制列表文件 `/etc/hosts.deny`，若找到匹配项则拒绝该流量。如果这两个文件全都没有匹配到，则默认放行流量。

### 控制列表文件中常用的参数

| 客户端类型 | 示例 | 满足示例的客户端列表 |
| --------- | --------- | --------- |
| 单一主机 | 192.168.10.10 | IP 地址为 192.168.10.10 的主机 |
| 指定网段 | 192.168.10. | IP 段为 192.168.10.0/24 的主机 |
| 指定网段 | 192.168.10.0/255.255.255.0 | IP 段为 192.168.10.0/24 的主机 |
| 指定 DNS 后缀 | .cxfans.com | 所有 DNS后缀为.cxfans.com的主机 |
| 指定主机名称 | www.cxfans.com | 主机名称为 www.cxfans.com 的主机 |
| 指定所有客户端 | ALL | 所有主机全部包括在内 |

在配置 TCP Wrappers 服务时需要遵循两个原则：

- 编写拒绝策略规则时，填写的是服务名称，而非协议名称；
- 建议先编写拒绝策略规则，再编写允许策略规则，以便直观地看到相应的效果。

编写拒绝策略规则文件，禁止访问本机 sshd 服务的所有流量，无须 `/etc/hosts.deny` 文件中修改原有的注释信息：

```bash
$ vim /etc/hosts.deny
## hosts.deny This file contains access rules which are used to
# deny connections to network services that either use
# the tcp_wrappers library or that have been
# started through a tcp_wrappers-enabled xinetd.
## The rules in this file can also be set up in
# /etc/hosts.allow with a 'deny' option instead.
## See 'man 5 hosts_options' and 'man 5 hosts_access'
# for information on rule syntax.
# See 'man tcpd' for information on tcp_wrappers
sshd:*
```
