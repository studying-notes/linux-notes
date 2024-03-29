---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "last 显示用户的登录日志"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/last"  # 设置网页永久链接
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

> 显示用户的登录日志

## 格式

```bash
last [options] [<username>...] [<tty>...]
```

- `FILE` 默认为 `/var/run/utmp`

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -`<number>` | how many lines to show |
| -a, --hostlast | display hostnames in the last column |
| -d, --dns | translate the IP number back into a hostname |
| -f, --file `<file>` | use a specific file instead of /var/log/wtmp |
| -F, --fulltimes | print full login and logout times and dates |
| -i, --ip | display IP numbers in numbers-and-dots notation |
| -n, --limit `<number>` | how many lines to show |
| -R, --nohostname | don't display the hostname field |
| -s, --since `<time>` | display the lines since the specified time |
| -t, --until `<time>` | display the lines until the specified time |
| -p, --present `<time>` | display who were present at the specified time |
| -w, --fullnames | display full user and domain names |
| -x, --system | display system shutdown entries and run level changes |
| --time-format `<format>` | show timestamps in the specified `<format>`: notime | short | full | iso |
| -h, --help | display this help |
| -V, --version | display version |

## 示例

1. 显示用户的登录日志

```bash
last
reboot   system boot  4.15.0-70-generi Wed Jan  8 22:29   still running
root     pts/0        118.31.243.133   Mon Jan  6 16:09 - 16:14  (00:04)

wtmp begins Mon Jan  6 16:03:18 2020
```
