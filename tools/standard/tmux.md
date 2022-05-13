---
date: 2022-05-13T15:03:58+08:00
author: "Rustle Karl"

title: "tmux 运行多个终端会话"
url:  "posts/linux/tools/standard/tmux"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 在一个终端窗口中运行多个终端会话

## 示例

### 创建一个新的窗口

```shell
tmux new -s new_window
```

### 查看 tmux 状态

```shell
tmux ls
```
