---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "unalias 取消别名"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/unalias"  # 设置网页永久链接
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

> 取消别名

## 格式

```bash
unalias [-a] name [name ...]
```

## 参数

| 参数 | 作用                         |
| ---- | ---------------------------- |
| -a   | remove all alias definitions |

## 示例

1. 取消别名

```bash
alias c='clear'
unalias c
```

## 相关命令

- [alias](alias.md) - 设置别名
