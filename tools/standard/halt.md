---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "halt 中断系统"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/halt"  # 设置网页永久链接
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

> 中断系统

## 格式

```bash
halt [OPTIONS...] [TIME] [WALL...]
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

### 备注

`halt` 命令用来关闭正在运行的 Linux 操作系统。`halt` 命令会先检测系统的 `runlevel`，若 `runlevel` 为 `0/6`，则关闭系统，否则调用 `shutdown` 来关闭系统。

## 示例

1. 关闭系统后关闭电源

```bash
halt -p
```

2. 关闭系统，但不留下记录

```bash
halt -d
```

## 相关命令

- [poweroff](poweroff.md)
- [poweroff](poweroff.md)
- [reboot](reboot.md)
- [ctrlaltdel](ctrlaltdel.md)
