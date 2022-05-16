---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "userdel 删除用户"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/userdel"  # 设置网页永久链接
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

> 删除用户

## 格式

```bash
userdel [options] LOGIN
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -f, --force | force removal of files, even if not owned by user |
| -h, --help | display this help message and exit |
| -r, --remove | remove home directory and mail spool |
| -R, --root CHROOT_DIR | directory to chroot into |
| --extrausers | Use the extra users database |
| -Z, --selinux-user | remove any SELinux user mapping for the user |

## 示例

1. 强制删除用户

```bash
userdel cxfans
```

1. 删除用户及其主目录

```bash
userdel -r cxfans
```
