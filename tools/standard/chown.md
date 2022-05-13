---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "chown 设置文件或目录的所有者和所属组"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/chown"  # 设置网页永久链接
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

> 设置文件或目录的所有者和所属组

## 格式

```bash
chown [OPTION]... [OWNER][:[GROUP]] FILE...

chown [OPTION]... --reference=RFILE FILE...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -c, --changes | like verbose but report only when a change is made |
| -f, --silent, --quiet | suppress most error messages |
| -v, --verbose | output a diagnostic for every file processed |
| --dereference | affect the referent of each symbolic link (this is the default), rather than the symbolic link itself |
| -h, --no-dereference | affect symbolic links instead of any referenced file (useful only on systems that can change the ownership of a symlink) |
| --from = CURRENT_OWNER:CURRENT_GROUP | change the owner and/or group of each file only if its current owner and/or group match those specified here. Either may be omitted, in which case a match is not required for the omitted attribute |
| --no-preserve-root | do not treat '/' specially (the default) |
| --preserve-root | fail to operate recursively on '/' |
| --reference = RFILE | use RFILE's owner and group rather than specifying OWNER:GROUP values |
| -R, --recursive | operate on files and directories recursively |
| -H | if a command line argument is a symbolic link to a directory, traverse it |
| -L | traverse every symbolic link to a directory encountered |
| -P | do not traverse any symbolic links (default) |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 设置文件或目录的所有者和所属组

```bash
chown root:bin example.sh
```
