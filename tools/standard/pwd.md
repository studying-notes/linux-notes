---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "pwd 输出当前工作目录"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/pwd"  # 设置网页永久链接
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

> 输出当前工作目录

## 格式

```bash
pwd
```

## 参数

| 参数 | 作用 |
| ---- | -------- |
| -L | Output the logical working directory, without resolving symlinks (default behavior) |
| -P | Output the physical working directory, with symlinks resolved |

## 示例

```bash
pwd
```
