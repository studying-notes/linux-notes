---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "cut 按列提取文本字符"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/cut"  # 设置网页永久链接
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

> 按列提取文本字符

## 格式

```bash
cut OPTION... [FILE]...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -b, --bytes = LIST | select only these bytes |
| -c, --characters = LIST | select only these characters |
| -d, --delimiter = DELIM | use DELIM instead of TAB for field delimiter |
| -f, --fields = LIST | select only these fields ; also print any line that contains no delimiter character, unless the -s option is specified |
| -n | (ignored) |
| --complement | complement the set of selected bytes, characters or fields |
| -s, --only-delimited | do not print lines not containing delimiters |
| --output-delimiter = STRING | use STRING as the output delimiter the default is to use the input delimiter |
| -z, --zero-terminated | line delimiter is NUL, not newline |
| --help | display this help and exit |
| --version | output version information and exit |

- N     N'th byte, character or field, counted from 1
- N-    from N'th byte, character or field, to end of line
- N-M   from N'th to M'th (included) byte, character or field
- -M    from first to M'th (included) byte, character or field

## 示例

1. 提取以 `:` 为间隔符号的第一列内容

```bash
head -n2 /etc/passwd
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin

cut -d: -f1 /etc/passwd
root
daemon
……
```
