---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "mkdir 创建目录"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/mkdir"  # 设置网页永久链接
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

> 创建目录

## 格式

```bash
mkdir [OPTION]... DIRECTORY...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -m, --mode = MODE | set file mode (as in chmod), not a = rwx - umask |
| -p, --parents | no error if existing, make parent directories as needed |
| -v, --verbose | print a message for each created directory |
| -Z | set SELinux security context of each created directory to the default type |
| --context[ = CTX] | like -Z, or if CTX is specified then set the SELinux or SMACK security context to CTX |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 创建目录

```bash
mkdir demo
```

2. 创建多层目录

```bash
mkdir -p demo/a/b/c/d/e/f/g/h/i/j/k/l/m/n
```
