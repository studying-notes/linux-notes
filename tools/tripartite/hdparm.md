---
date: 2022-05-13T16:54:58+08:00
author: "Rustle Karl"

title: "hdparm 硬盘测试"
url:  "posts/linux/tools/tripartite/hdparm"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 安装

可能预装了。

```shell
apt install hdparm

opkg install hdparm
```

## 测试读写

```shell
lsblk
```

```shell
hdparm -Tt /dev/sdd
```
