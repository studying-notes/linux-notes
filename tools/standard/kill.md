---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "kill 终止进程"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/kill"  # 设置网页永久链接
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

> 终止某个指定 PID 的服务进程

## 格式

```bash
kill [options] <pid> [...]
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| `<pid>` [...] | send signal to every `<pid>` listed |
| -`<signal>`, -s, --signal `<signal>` | specify the `<signal>` to be sent |
| -l, --list = [`<signal>`] | list all signal names, or convert one to a name |
| -L, --table | list all signal names in a nice table |
| -h, --help | display this help and exit |
| -V, --version | output version information and exit |

## 示例

1. 终止指定 PID 的服务进程

```bash
sleep 10000 &
[1] 4900

pidof -s sleep
4900

kill 4900
```

## 相关命令

- [killall](killall.md)
