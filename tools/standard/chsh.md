---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "chsh 更改登录 Shell"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/chsh"  # 设置网页永久链接
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

> 更改登录 Shell

## 格式

```bash
chsh [options] [LOGIN]
```

## 示例

```bash
chsh -s `which fish`
```
