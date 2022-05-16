---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "id 显示指定用户的相关信息"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/id"  # 设置网页永久链接
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

> 显示指定用户的相关信息

## 格式

```bash
id [OPTION]... [USER]
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -a | ignore, for compatibility with other versions |
| -Z, --context | print only the security context of the process |
| -g, --group | print only the effective group ID |
| -G, --groups | print all group IDs |
| -n, --name | print a name instead of a number, for -ugG |
| -r, --real | print the real ID instead of the effective ID, with -ugG |
| -u, --user | print only the effective user ID |
| -z, --zero | delimit entries with NUL characters, not whitespace ; not permitted in default format |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

```bash
id
uid=0(root) gid=0(root) groups=0(root)
```

## 相关命令

- [useradd](useradd.md)
- [halt](halt.md)
- [reboot](reboot.md)
- [ctrlaltdel](ctrlaltdel.md)
