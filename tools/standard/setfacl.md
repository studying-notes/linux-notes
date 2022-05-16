---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "setfacl 管理文件的 ACL 规则"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/setfacl"  # 设置网页永久链接
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

> 管理文件的 ACL 规则

## 格式

```bash
setfacl [-bkndRLP] { -m|-M|-x|-X ... } file ...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -m, --modify = acl | modify the current ACL(s) of file(s) |
| -M, --modify-file = file | read ACL entries to modify from file |
| -x, --remove = acl | remove entries from the ACL(s) of file(s) |
| -X, --remove-file = file | read ACL entries to remove from file |
| -b, --remove-all | remove all extended ACL entries |
| -k, --remove-default | remove the default ACL |
| --set = acl | set the ACL of file(s), replacing the current ACL |
| --set-file = file | read ACL entries to set from file |
| --mask | do recalculate the effective rights mask |
| -n, --no-mask | don't recalculate the effective rights mask |
| -d, --default | operations apply to the default ACL |
| -R, --recursive | recurse into subdirectories |
| -L, --logical | logical walk, follow symbolic links |
| -P, --physical | physical walk, do not follow symbolic links |
| --restore = file | restore ACLs (inverse of `getfacl -R') |
| --test | test mode (ACLs are not modified) |
| -v, --version | print version and exit |
| -h, --help | this help text |

## 示例

1. 设置用户在 `/root` 目录上的权限

```bash
setfacl -Rm u:cxfans:rwx /root

su - cxfans
# 该用户可以对 /root 目录进行读写
```
