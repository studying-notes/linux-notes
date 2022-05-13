---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "shutdown 关闭操作系统"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/shutdown"  # 设置网页永久链接
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

> 关闭操作系统

## 格式

```bash
shutdown [OPTIONS...] [TIME] [WALL...]
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| --help | Show this help |
| -H --halt | Halt the machine |
| -P --poweroff | Power-off the machine |
| -r --reboot | Reboot the machine |
| -h | Equivalent to --poweroff, overridden by --halt |
| -k | Don't halt/power-off/reboot, just send warnings |
| --no-wall | Don't send wall message before halt/power-off/reboot |
| -c | Cancel a pending shutdown |

### 备注

关闭所有程序，然后默认关机。

## 示例

1. 立即关机

```bash
shutdown -h now
```

2. 5分钟后关机

```bash
shutdown +5 "System will shutdown after 5 minutes."
Shutdown scheduled for Wed 2020-01-08 14:42:40 CST, use 'shutdown -c' to cancel.

# 取消定时关机
shutdown -c
```

## 相关命令

- [poweroff](poweroff.md)
- [halt](halt.md)
- [reboot](reboot.md)
- [ctrlaltdel](ctrlaltdel.md)
