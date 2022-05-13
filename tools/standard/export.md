---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "export 在当前会话修改环境变量"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/export"  # 设置网页永久链接
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

> 在当前会话新增、修改或删除环境变量

## 格式

```bash
export [-fn] [NAME[=VALUE] ...]
export -p
```

## 参数

| 参数 | 作用 |
| ---- | -------- |
| -f | 代表 [NAME] 中为函数名称 |
| -n | 删除指定的变量，仅当前会话有效 |
| -p | 列出全部导出的变量和函数 |

## 示例

1. 新增临时环境变量

```bash
export WORKDIR=/root/workdir
```
