---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "umount 卸载文件系统"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/umount"  # 设置网页永久链接
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

> 卸载文件系统

## 格式

```bash
umount [-hV]
umount -a [options]
umount [options] <source> | <directory>
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -a, --all | unmount all filesystems |
| -A, --all-targets | unmount all mountpoints for the given device in the current namespace |
| -c, --no-canonicalize | don't canonicalize paths |
| -d, --detach-loop | if mounted loop device, also free this loop device |
| --fake | dry run ; skip the umount(2) syscall |
| -f, --force | force unmount (in case of an unreachable NFS system) |
| -i, --internal-only | don't call the umount.`<type>` helpers |
| -n, --no-mtab | don't write to /etc/mtab |
| -l, --lazy | detach the filesystem now, clean up things later |
| -O, --test-opts `<list>` | limit the set of filesystems (use with -a) |
| -R, --recursive | recursively unmount a target with all its children |
| -r, --read-only | in case unmounting fails, try to remount read-only |
| -t, --types `<list>` | limit the set of filesystem types |
| -v, --verbose | say what is being done |
| -h, --help | display this help |
| -V, --version | display version |

## 示例

1. 卸载硬盘设备

```bash
umount /dev/sdb2
```
