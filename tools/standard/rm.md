---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "rm 移除项目"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/rm"  # 设置网页永久链接
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

> 移除项目

## 格式

```bash
rm [OPTION]... [FILE]...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -f, --force | ignore nonexistent files and arguments, never prompt |
| -i | prompt before every removal |
| -I | prompt once before removing more than three files, or when removing recursively ; less intrusive than -i, while still giving protection against most mistakes |
| --interactive[ = WHEN] | prompt according to WHEN: never, once (-I), or always (-i) ; without WHEN, prompt always |
| --one-file-system | when removing a hierarchy recursively, skip any directory that is on a file system different from that of the corresponding command line argument |
| --no-preserve-root | do not treat '/' specially |
| --preserve-root | do not remove '/' (default) |
| -r, -R, --recursive | remove directories and their contents recursively |
| -d, --dir | remove empty directories |
| -v, --verbose | explain what is being done |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 强制删除目录

```bash
rm -rf demo
```

2. 确认每次删除操作

```bash
rm -ri demo
```

```bash
mkdir /tmp/test

rsync --delete-before -avH --force --progress --stats /tmp/test /mnt/storage/vsftp/Dropin/*
```
