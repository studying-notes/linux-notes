---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "groupadd 创建新的用户组"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/groupadd"  # 设置网页永久链接
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

> 创建新的用户组

## 格式

```bash
groupadd [options] GROUP
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -f, --force | exit successfully if the group already exists, and cancel -g if the GID is already used |
| -g, --gid GID | use GID for the new group |
| -h, --help | display this help message and exit |
| -K, --key KEY = VALUE | override /etc/login.defs defaults |
| -o, --non-unique | allow to create groups with duplicate (non-unique) GID |
| -p, --password PASSWORD | use this encrypted password for the new group |
| -r, --system | create a system account |
| -R, --root CHROOT_DIR | directory to chroot into |
| --extrausers | Use the extra users database |

## 示例

1. 创建一个用户组

```bash
groupadd workers
```

## 相关命令

- [id](id.md)
- [useradd](useradd.md)
- [reboot](reboot.md)
- [ctrlaltdel](ctrlaltdel.md)
