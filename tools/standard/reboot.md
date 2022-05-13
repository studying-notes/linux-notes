---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "reboot 重启系统"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/reboot"  # 设置网页永久链接
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

> 重启系统

## 格式

```bash
reboot [OPTIONS...] [ARG]
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| --help | Show this help |
| --halt | Halt the machine |
| -p --poweroff | Switch off the machine |
| --reboot | Reboot the machine |
| -f --force | Force immediate halt/power-off/reboot |
| -w --wtmp-only | Don't halt/power-off/reboot, just write wtmp record |
| -d --no-wtmp | Don't write wtmp record |
| --no-wall | Don't send wall message before halt/power-off/reboot |

## 示例

1. 重启系统

```bash
reboot
```

2. 不重启，只是写入重启记录

```bash
reboot -w
```

## 相关命令

- [shutdown](shutdown.md)
- [halt](halt.md)
- [poweroff](poweroff.md)
- [ctrlaltdel](ctrlaltdel.md)
