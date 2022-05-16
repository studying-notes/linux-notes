---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "head 打印文件前几行"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/head"  # 设置网页永久链接
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

> 默认打印每个文件的前 10 行到标准输出

## 格式

```bash
head [OPTION]... [FILE]...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -c, --bytes = [-]NUM | print the first NUM bytes of each file ; with the leading '-', print all but the last NUM bytes of each file |
| -n, --lines = [-]NUM | print the first NUM lines instead of the first 10 ; with the leading '-', print all but the last NUM lines of each file |
| -q, --quiet, --silent | never print headers giving file names |
| -v, --verbose | always print headers giving file names |
| -z, --zero-terminated | line delimiter is NUL, not newline |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 输出文件前 20 行

```bash
head -n 20 FILE
```

## 相关命令

- [tail](tail.md)
