---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "uptime 查询系统负载信息"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/uptime"  # 设置网页永久链接
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

> 查询系统负载信息

## 格式

```bash
uptime [options]
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -p, --pretty | show uptime in pretty format |
| -s, --since | system up since |
| -h, --help | display this help and exit |
| -V, --version | output version information and exit |

## 示例

1. 显示系统负载信息

```bash
uptime
16:56:10 up 1 day,  2:26,  0 users,  load average: 0.12, 0.07, 0.02
```

- 依次是当前系统时间、系统已运行时间、启用终端数量以及平均负载值等信息。
- 平均负载值指的是系统在最近 1分钟、 5分钟、 15 分钟内的压力情况；负载值越低越好，如果是单核 CPU，尽量不要长期超过 1，在生产环境中不要超过 5，多核不超过 CPU 核心数量。
