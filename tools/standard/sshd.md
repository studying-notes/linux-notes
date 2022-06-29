---
date: 2022-06-29T14:07:18+08:00
author: "Rustle Karl"

title: "sshd OpenSSH 服务器守护进程"
url:  "posts/linux/tools/standard/sshd"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 语法

```shell
sshd(选项)
```

## 选项

```shell
-4：强制使用IPv4地址；
-6：强制使用IPv6地址；
-D：以后台守护进程方式运行服务器；
-d：调试模式；
-e：将错误发送到标准错误设备，而不是将其发送到系统日志；
-f：指定服务器的配置文件；
-g：指定客户端登录时的过期时间，如果在此期限内，用户没有正确认证，则服务器断开次客户端的连接；
-h：指定读取主机key文件；
-i：ssh以inetd方式运行；
-o：指定ssh的配置选项；
-p：静默模式，没有任何信息写入日志；
-t：测试模式。
```
