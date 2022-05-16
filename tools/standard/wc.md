---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "wc 统计指定文本的行数、单词数、字符数、字节数等"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/wc"  # 设置网页永久链接
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

> 统计指定文本的行数、单词数、字符数、字节数等

## 格式

```bash
wc [OPTION]... [FILE]...

wc [OPTION]... --files0-from=F
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -c, --bytes | print the byte counts |
| -m, --chars | print the character counts |
| -l, --lines | print the newline counts |
| --files0-from = F | read input from the files specified by NUL-terminated names in file F ; If F is - then read names from standard input |
| -L, --max-line-length | print the maximum display width |
| -w, --words | print the word counts |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 统计行数

```bash
wc -l /etc/passwd
27 /etc/passwd
```
