---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "find 按照指定条件查找文件"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/find"  # 设置网页永久链接
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

> 按照指定条件查找文件

## 格式

```bash
find [-H] [-L] [-P] [-Olevel] [-D debugopts] [path...] [expression]
```

## 参数

- `path` 参数默认为当前目录
- `expression` 参数默认为 `-print`

| 参数 | 作用 |
| -------- | -------- |
| -name | 匹配名称 |
| -perm | 匹配权限，`mode` 为完全匹配，`-mode` 为包含即可 |
| -user | 匹配所有者 |
| -group | 匹配所有组 |
| -mtime `-n +n` | 匹配修改内容的时间，`-n` 指 n 天以内，`+n` 指 n 天以前 |
| -atime `-n +n` | 匹配访问文件的时间，`-n` 指 n 天以内，`+n` 指 n 天以前 |
| -ctime `-n +n` | 匹配修改文件权限的时间，`-n` 指 n 天以内，`+n` 指 n 天以前 |
| -nouser | 匹配无所有者的文件 |
| -nogroup | 匹配无所有组的文件 |
| -newer `f1 ! f2` | 匹配比文件 `f1` 新但比 `f2` 旧的文件 |
| --type `b/d/c/p/l/f` | 匹配文件类型，字母参数依次表示块设备、目录、字符设备、管道、链接文件、文本文件 |
| -size | 匹配文件的大小，`+50KB` 为查找超过 50KB 的文件，而 ` -50KB` 为查找小于 50KB 的文件 |
| -prune | 忽略某个目录 |
| -exec | 后面可跟用于进一步处理搜索结果的命令 |

## 示例

1. 获取目录中所以以 host 开头的文件列表

```bash
find /etc -name "host*" -print
/etc/hosts.deny
/etc/cloud/templates/hosts.debian.tmpl
/etc/cloud/templates/hosts.suse.tmpl
/etc/cloud/templates/hosts.redhat.tmpl
/etc/cloud/templates/hosts.freebsd.tmpl
/etc/host.conf
/etc/hosts.allow
/etc/hosts
/etc/hostname
```

2. 搜索包括 SUID 权限的文件

```bash
find /etc -perm -4000
```

3. 找出所有权是指定用户的文件，然后复制到指定目录

```bash
find /root -user root -exec cp -a {} /tmp/ \;
```
