---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "alias 设置别名"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/alias"  # 设置网页永久链接
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

> 设置别名

## 格式

```bash
alias [-p] [name[=value] ... ]
```

## 参数

| 参数 | 作用                                           |
| ---- | ---------------------------------------------- |
| -p   | print all defined aliases in a reusable format |

## 示例

1. 显示全部已设置的别名

```bash
alias
alias cls='clear'
alias egrep='egrep --color=auto'
alias fgrep='fgrep --color=auto'
alias grep='grep --color=auto'
alias l='ls -CF'
alias la='ls -A'
alias ll='ls -alF'
alias ls='ls --color=auto'
```

2. 设置别名

```bash
alias c='clear'

echo "alias c='clear'" >> ~/.profile
```

## 相关命令

- [unalias](unalias.md) - 取消别名
