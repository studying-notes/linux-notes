---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "free 查询内存资源信息"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/free"  # 设置网页永久链接
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

> 查询内存资源信息

## 格式

```bash
free [options]
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -b, --bytes | show output in bytes |
| --kilo | show output in kilobytes |
| --mega | show output in megabytes |
| --giga | show output in gigabytes |
| --tera | show output in terabytes |
| --peta | show output in petabytes |
| -k, --kibi | show output in kibibytes |
| -m, --mebi | show output in mebibytes |
| -g, --gibi | show output in gibibytes |
| --tebi | show output in tebibytes |
| --pebi | show output in pebibytes |
| -h, --human | show human-readable output |
| --si | use powers of 1000 not 1024 |
| -l, --lohi | show detailed low and high memory statistics |
| -t, --total | show total for RAM + swap |
| -s N, --seconds N | repeat printing every N seconds |
| -c N, --count N | repeat printing N times, then exit |
| -w, --wide | wide output |
| --help | display this help and exit |
| -V, --version | output version information and exit |

## 示例

1. 可读格式输出信息

```bash
free -h
              total        used        free      shared  buff/cache   available
Mem:           985M        252M         92M        4.2M        640M        574M
Swap:          947M         11M        935M
```
