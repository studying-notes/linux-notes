---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "lsof 列出当前系统打开的文件"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/lsof"  # 设置网页永久链接
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

> 列出当前系统打开的文件

在 linux 环境下，任何事物都以文件的形式存在，通过文件不仅仅可以访问常规数据，还可以访问网络连接和硬件。所以如传输控制协议 (TCP) 和用户数据报协议 (UDP) 套接字等，系统在后台都为该应用程序分配了一个文件描述符，无论这个文件的本质如何，该文件描述符为应用程序与基础操作系统之间的交互提供了通用接口。

## 格式

```bash
lsof [OPTION]... [FILE]...
```

## 实例

### 查询端口占用情况

```shell
lsof -i:8000
```

```shell
netstat -tunlp | grep 8000
```

### 查找谁在占用文件系统

```shell
lsof /mnt/sda
```
