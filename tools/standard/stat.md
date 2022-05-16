---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "stat 查询文件、文件系统状态信息"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/stat"  # 设置网页永久链接
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

> 查询文件、文件系统状态信息

## 格式

```bash
stat [OPTION]... FILE...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -L, --dereference | follow links |
| -f, --file-system | display file system status instead of file status |
| -c --format = FORMAT | use the specified FORMAT instead of the default ; output a newline after each use of FORMAT |
| --printf = FORMAT | like --format, but interpret backslash escapes, and do not output a mandatory trailing newline ; if you want a newline, include \n in FORMAT |
| -t, --terse | print the information in terse form |
| --help | display this help and exit |
| --version | output version information and exit |

## 格式化输出

### 文件

| 占位符 | 含义 |
| ------ | -------- |
| %a | access rights in octal (note '#' and '0' printf flags) |
| %A | access rights in human readable form |
| %b | number of blocks allocated (see %B) |
| %B | the size in bytes of each block reported by %b |
| %C | SELinux security context string |
| %d | device number in decimal |
| %D | device number in hex |
| %f | raw mode in hex |
| %F | file type |
| %g | group ID of owner |
| %G | group name of owner |
| %h | number of hard links |
| %i | inode number |
| %m | mount point |
| %n | file name |
| %N | quoted file name with dereference if symbolic link |
| %o | optimal I/O transfer size hint |
| %s | total size, in bytes |
| %t | major device type in hex, for character/block device special files |
| %T | minor device type in hex, for character/block device special files |
| %u | user ID of owner |
| %U | user name of owner |
| %w | time of file birth, human-readable ; - if unknown |
| %W | time of file birth, seconds since Epoch ; 0 if unknown |
| %x | time of last access, human-readable |
| %X | time of last access, seconds since Epoch |
| %y | time of last data modification, human-readable |
| %Y | time of last data modification, seconds since Epoch |
| %z | time of last status change, human-readable |
| %Z | time of last status change, seconds since Epoch |

### 文件系统

| 占位符 | 含义 |
| ------ | -------- |
| %a | free blocks available to non-superuser |
| %b | total data blocks in file system |
| %c | total file nodes in file system |
| %d | free file nodes in file system |
| %f | free blocks in file system |
| %i | file system ID in hex |
| %l | maximum length of filenames |
| %n | file name |
| %s | block size (for faster transfers) |
| %S | fundamental block size (for block counts) |
| %t | file system type in hex |
| %T | file system type in human readable form |


## 示例

1. 查询文件的存储和修改时间等信息

```bash
stat /etc/passwd
```

```
  File: /etc/passwd
  Size: 1413            Blocks: 8          IO Block: 4096   regular file
Device: fc01h/64513d    Inode: 1049326     Links: 1
Access: (0644/-rw-r--r--)  Uid: (    0/    root)   Gid: (    0/    root)
Access: 2020-01-09 21:28:13.151836545 +0800
Modify: 2019-06-24 18:10:17.075827119 +0800
Change: 2019-06-24 18:10:17.075827119 +0800
 Birth: -
```
