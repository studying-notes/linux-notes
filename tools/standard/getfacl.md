---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "getfacl 显示文件上设置的 ACL 信息"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/getfacl"  # 设置网页永久链接
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

> 显示文件上设置的 ACL 信息

## 格式

```bash
getfacl [-aceEsRLPtpndvh] file ...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -a, --access | display the file access control list only |
| -d, --default | display the default access control list only |
| -c, --omit-header | do not display the comment header |
| -e, --all-effective | print all effective rights |
| -E, --no-effective | print no effective rights |
| -s, --skip-base | skip files that only have the base entries |
| -R, --recursive | recurse into subdirectories |
| -L, --logical | logical walk, follow symbolic links |
| -P, --physical | physical walk, do not follow symbolic links |
| -t, --tabular | use tabular output format |
| -n, --numeric | print numeric user/group identifiers |
| -p, --absolute-names | don't strip leading '/' in pathnames |
| -v, --version | print version and exit |
| -h, --help | this help text |

## 示例

1. 显示文件上设置的 ACL 信息

```bash
setfacl -Rm u:cxfans:rwx /root

getfacl /root
getfacl: Removing leading '/' from absolute path names
# file: root
# owner: root
# group: root
user::rwx
user:cxfans:rwx
group::---
mask::rwx
other::---
```
