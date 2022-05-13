---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "whereis 定位文件位置"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/whereis"  # 设置网页永久链接
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

> 定位二进制执行文件、源文件、手册主页文件的位置

## 格式

```bash
whereis [options] [-BMS <dir>... -f] <name>
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -b | search only for binaries |
| -B `<dirs>` | define binaries lookup path |
| -m | search only for manuals and infos |
| -M `<dirs>` | define man and info lookup path |
| -s | search only for sources |
| -S `<dirs>` | define sources lookup path |
| -f | terminate `<dirs>` argument list |
| -u | search for unusual entries |
| -l | output effective lookup paths |
| -h, --help | display this help |
| -V, --version | display version |

## 示例

```bash
whereis rm
```
