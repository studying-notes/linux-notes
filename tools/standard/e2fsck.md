---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "e2fsck 检查文件系统的完整性"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/e2fsck"  # 设置网页永久链接
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

> 检查文件系统的完整性

## 格式

```bash
e2fsck [-panyrcdfvtDFV] [-b superblock] [-B blocksize]
		[-I inode_buffer_blocks] [-P process_inode_size]
		[-l|-L bad_blocks_file] [-C fd] [-j external_journal]
		[-E extended-options] device
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -p | Automatic repair (no questions) |
| -n | Make no changes to the filesystem |
| -y | Assume "yes" to all questions |
| -c | Check for bad blocks and add them to the badblock list |
| -f | Force checking even if filesystem is marked clean |
| -v | Be verbose |
| -b superblock | Use alternative superblock |
| -B blocksize | Force blocksize when looking for superblock |
| -j external_journal Set location of the external journal |
| -l bad_blocks_file | Add to badblocks list |
| -L bad_blocks_file | Set badblocks list |

## 示例

1. 检查文件系统的完整性

```bash
e2fsck -f /dev/storage/vo
e2fsck 1.42.9 (28-Dec-2013)
Pass 1: Checking inodes, blocks, and sizes
Pass 2: Checking directory structure
Pass 3: Checking directory connectivity
Pass 4: Checking reference counts
Pass 5: Checking group summary information
/dev/storage/vo: 11/74000 files (0.0% non-contiguous), 15507/299008 blocks
```
