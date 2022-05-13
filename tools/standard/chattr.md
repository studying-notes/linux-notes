---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "chattr 设置文件的隐藏权限"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/chattr"  # 设置网页永久链接
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

> 设置文件的隐藏权限

## 格式

```bash
chattr [-pRVf] [-+=aAcCdDeijPsStTu] [-v version] files...
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| i | 无法对文件进行修改；若对目录设置了该参数，则仅能修改其中的子文件内容 |
| 而不能新建或删除文件 |
| a | 仅允许补充（追加）内容，无法覆盖 / 删除内容（Append Only） |
| S | 文件内容在变更后立即同步到硬盘（sync） |
| s | 彻底从硬盘中删除，不可恢复（用 0 填充原文件所在硬盘区域） |
| A | 不再修改这个文件或目录的最后访问时间（atime） |
| b | 不再修改文件或目录的存取时间 |
| D | 检查压缩文件中的错误 |
| d | 使用 dump 命令备份时忽略本文件 / 目录 |
| c | 默认将文件或目录进行压缩 |
| u | 当删除该文件后依然保留其在硬盘中的数据，方便日后恢复 |
| t | 让文件系统支持尾部合并（tail-merging） |
| X | 可以直接访问压缩文件中的内容 |

## 示例

1. 设置不允许删除与覆盖权限

```bash
echo 'cxfans' > demo

chattr +a demo

rm demo
rm: cannot remove 'demo': Operation not permitted
```
