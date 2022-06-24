---
date: 2022-05-23T14:47:03+08:00
author: "Rustle Karl"

title: "nmap 网络扫描"
url:  "posts/linux/tools/tripartite/nmap"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 更详细深入，见 CTF 学习笔记，这里记一下常用命令

## 实例

### 扫描局域网指定端口范围

```shell
nmap -p”3389,13026-13027“ -v 192.168.4.1/24
```

`3389` 是远程桌面服务。

我一般用来查找失联主机，因为经常网络问题导致 IP 变化，但主机又没有屏幕，只能通过扫描端口找到主机，然后远程桌面连接。
