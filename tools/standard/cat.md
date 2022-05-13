---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "cat 打印到标准输出"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/cat"  # 设置网页永久链接
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

> 将一个或多个文件的内容打印到标准输出

## 格式

```bash
cat [OPTION]... [FILE]...
```

- 若是未提供 `FILE` 参数，则从标准输入读取。
- `FILE` 为 `-` 时，表示从标准输入读取。

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -A, --show-all | equivalent to -vET |
| -b, --number-nonblank | number nonempty output lines, overrides -n |
| -e | equivalent to -vE |
| -E, --show-ends | display $ at end of each line |
| -n, --number | number all output lines |
| -s, --squeeze-blank | suppress repeated empty output lines |
| -t | equivalent to -vT |
| -T, --show-tabs | display TAB characters as ^I |
| -u | (ignored) |
| -v, --show-nonprinting | use ^ and M- notation, except for LFD and TAB |
| --help | display this help and exit |
| --version | output version information and exit |


## 示例

1. 输出文件内容和行号

```bash
cat -n
```
