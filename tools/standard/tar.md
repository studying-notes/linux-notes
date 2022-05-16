---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "tar 对文件进行打包压缩或解压"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/tar"  # 设置网页永久链接
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

> 对文件进行打包压缩或解压

## 格式

```bash
tar [OPTION...] [FILE]...
```

## 参数

参数过多，遇到再说，这里就列几个常用的：

| 参数 | 作用 |
| --------- | --------- |
| -c | 创建压缩文件 |
| -x | 解开压缩文件 |
| -t | 查看压缩包内有哪些文件 |
| -z | 用 gzip 压缩或解压 |
| -j | 用 bzip2 压缩或解压 |
| -v | 显示压缩或解压的过程 |
| -f | 目标文件名 |
| -p | 保留原始的权限与属性 |
| -P | 使用绝对路径来压缩 |
| -C | 指定解压到的目录 |

## 示例

```bash
# Create archive.tar from files foo and bar.
tar -cf archive.tar foo bar

# List all files in archive.tar verbosely.
tar -tvf archive.tar

# Extract all files from archive.tar.
tar -xf archive.tar
```

解压到指定目录

```bash
tar -xf archive.tar -C ~/archive
```
