---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "partprobe 通知操作系统分区表的更改"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/partprobe"  # 设置网页永久链接
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

> 通知操作系统分区表的更改

## 格式

```bash
partprobe [OPTION] [DEVICE]...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -d, --dry-run | do not actually inform the operating system |
| -s, --summary | print a summary of contents |
| -h, --help | display this help and exit |
| -v, --version | output version information and exit |

## 示例

1. 不给出 DEVICE 时，默认检测全部分区

```bash
partprobe
```
