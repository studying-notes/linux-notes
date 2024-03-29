---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "cd 改变当前工作目录"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/cd"  # 设置网页永久链接
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

> 改变当前工作目录

## 格式

```bash
cd [-L|[-P [-e]]] [dir]
```

- `dir` 默认为 `HOME`

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -L | Use the logical working directory, without resolving symlinks (default behavior) |
| -P | Use the physical working directory, with symlinks resolved |
| -e | Supply with -P, and the current working directory cannot be successfully determined after a successful directory change, cd will return an unsuccessful status. |

## 示例

```bash
cd /etc/
```
