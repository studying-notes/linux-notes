---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "lsattr 显示文件的隐藏权限"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/lsattr"  # 设置网页永久链接
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

> 显示文件的隐藏权限

## 格式

```bash
lsattr [-RVadlpv] [files...]
```

## 参数

| 参数 | 作用                                                                          |
| ---- | ----------------------------------------------------------------------------- |
| -R   | Recursively list attributes of directories and their contents.                |
| -V   | Display the program version.                                                  |
| -a   | List all files in directories, including files that start with `.'.           |
| -d   | List directories like other files, rather than listing their contents.        |
| -l   | Print the options using long names instead of single character abbreviations. |
| -p   | List the file's project number.                                               |
| -v   | List the file's version/generation number.                                    |

## 示例

```bash
echo 'cxfans' > demo

chattr +a demo

rm demo
rm: cannot remove 'demo': Operation not permitted

lsattr demo
-----a------------ demo

chattr -a demo
lsattr demo
------------------ demo
```
