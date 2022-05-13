---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "ctrlaltdel 设置组合键 `Ctrl+Alt+Del` 的功能"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/ctrlaltdel"  # 设置网页永久链接
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

> 设置组合键 `Ctrl+Alt+Del` 的功能

## 格式

```bash
ctrlaltdel hard|soft
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -h, --help | display this help |
| -V, --version | display version |

### 备注

- Hard：当按下组合键 `Ctrl+Alt+Del` 时，立即执行重新启动操作系统的操作，而不是先执行 [`sync`](http://man.linuxde.net/sync) 系统调用和其他的标准关机操作。
- Soft：当按下组合键 `Ctrl+Alt+Del` 时，首先向 [`init`](http://man.linuxde.net/init) 进程发送 `SIGINT` 信号，然后由 `init` 进程处理关机操作。

## 相关命令

- [poweroff](poweroff.md)
- [poweroff](poweroff.md)
- [reboot](reboot.md)
- [halt](halt.md)
