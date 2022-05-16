---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "history 显示、管理以前执行过的命令"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/history"  # 设置网页永久链接
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

> 显示、管理以前执行过的命令

## 格式

```bash
history [-c] [-d offset] [n]

history -anrw [filename]

history -ps arg [arg...]
```

- `filename` 默认为 `~/.bash_history`

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -c | clear the history list by deleting all of the entries |
| -d offset | delete the history entry at position OFFSET. |
| -a | append history lines from this session to the history file |
| -n | read all history lines not already read from the history file and append them to the history list |
| -r | read the history file and append the contents to the history list |
| -w | write the current history to the history file |
| -p | perform history expansion on each ARG and display the result without storing it in the history list |
| -s | append the ARGs to the history list as a single entry |

## 示例

1. 显示历史命令

```bash
history
```

1. 清空历史命令

```bash
history -c
```
