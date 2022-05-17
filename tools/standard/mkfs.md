---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "mkfs 格式化硬盘，创建文件系统"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/mkfs"  # 设置网页永久链接
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

> 格式化硬盘，创建文件系统

**mkfs命令** 用于在设备上（通常为硬盘）创建 Linux 文件系统。mkfs 本身并不执行建立文件系统的工作，而是去调用相关的程序来执行。

## 格式

```bash
mkfs [options] [-t <type>] [fs-options] <device> [<size>]
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -t, --type = `<type>` | 指定要建立何种文件系统，默认 ext2 |
| fs-options | 指定建立文件系统时的参数 |
| `<device>` | 指定要创建的文件系统对应的设备文件名 |
| `<size>` | 指定文件系统的磁盘块数 |
| -v, --verbose | explain what is being done ; specifying -V more than once will cause a dry-run |
| -h, --help | display this help |
| -V, --version | display version |

## 示例

1. 显示可创建的文件系统

```bash
mkfs  # 2次 Tab 键
mkfs         mkfs.cramfs  mkfs.ext4    mkfs.msdos
mkfs.bfs     mkfs.ext2    mkfs.fat     mkfs.ntfs
mkfs.btrfs   mkfs.ext3    mkfs.minix   mkfs.vfat
```

2. 创建文件系统

```bash
mkfs.xfs /dev/sdb1
```

不指定相关参数会以交互方式进行。
