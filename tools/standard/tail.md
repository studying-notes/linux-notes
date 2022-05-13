---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "tail 打印文件最后几行"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/tail"  # 设置网页永久链接
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

> 默认打印每个文件的后 10 行到标准输出

## 格式

```bash
tail [OPTION]... [FILE]...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -c, --bytes = [+]NUM | output the last NUM bytes ; or use -c +NUM to output starting with byte NUM of each file |
| -f, --follow[ = {name\ | descriptor}] | output appended data as the file grows ; an absent option argument means 'descriptor' |
| -F | same as --follow = name --retry |
| -n, --lines = [+]NUM | output the last NUM lines, instead of the last 10 ; or use -n +NUM to output starting with line NUM |
| --max-unchanged-stats = N | with --follow = name, reopen a FILE which has not changed size after N (default 5) iterations to see if it has been unlinked or renamed (this is the usual case of rotated log files) ; with inotify, this option is rarely useful |
| --pid = PID | with -f, terminate after process ID, PID dies |
| -q, --quiet, --silent | never output headers giving file names |
| --retry | keep trying to open a file if it is inaccessible |
| -s, --sleep-interval = N | with -f, sleep for approximately N seconds (default 1.0) between iterations ; with inotify and --pid = P, check process P at least once every N seconds |
| -v, --verbose | always output headers giving file names |
| -z, --zero-terminated | line delimiter is NUL, not newline |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 输出文件后 20 行

```bash
tail -n 20 FILE
```

2. 持续刷新一个文件的内容

> 用于浏览实时日志文件比较方便

```bash
tail -f FILE
```

## 实例

### 多个日志文件合并输出

```bash
tail -f file1 file2
```

#### 希望日志的每一行都能出现文件名

```bash
tail -f file1 file2 | awk '/^==> / {a=substr($0, 5, length-8); next} {print a":"$0}'
```

```bash
parallel --tagstring '{}:' --line-buffer tail -f {} ::: file1 file2
```

## 相关命令

- [head](head.md)
