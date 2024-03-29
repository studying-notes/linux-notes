---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "mv 移动，重命名"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/mv"  # 设置网页永久链接
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

> 移动，重命名

## 格式

```bash
mv [OPTION]... [-T] SOURCE DEST

mv [OPTION]... SOURCE... DIRECTORY

mv [OPTION]... -t DIRECTORY SOURCE...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| --backup[ = CONTROL] | make a backup of each existing destination file |
| -b | like --backup but does not accept an argument |
| -f, --force | do not prompt before overwriting |
| -i, --interactive | prompt before overwrite |
| -n, --no-clobber | do not overwrite an existing file If you specify more than one of -i, -f, -n, only the final one takes effect. |
| --strip-trailing-slashes | remove any trailing slashes from each SOURCE argument |
| -S, --suffix = SUFFIX | override the usual backup suffix |
| -t, --target-directory = DIRECTORY | move all SOURCE arguments into DIRECTORY |
| -T, --no-target-directory | treat DEST as a normal file |
| -u, --update | move only when the SOURCE file is newer than the destination file or when the destination file is missing |
| -v, --verbose | explain what is being done |
| -Z, --context | set SELinux security context of destination file to default type |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 移动文件夹

```bash
mv -t demo backup
```
