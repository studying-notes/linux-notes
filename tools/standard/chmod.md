---
date: 2020-11-23T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "chmod 设置文件或目录的权限"  # 文章标题
url:  "posts/linux/tools/standard/chmod"  # 设置网页永久链接
tags: [ "linux", "cmd" ]  # 标签
series: [ "Linux 学习笔记"]  # 系列
categories: [ "学习笔记"]  # 分类

# 章节
weight: 20 # 排序优先级
chapter: false  # 设置为章节

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
---

> 设置文件或目录的权限

## 格式

```bash
chmod [OPTION]... MODE[,MODE]... FILE...

chmod [OPTION]... OCTAL-MODE FILE...

chmod [OPTION]... --reference=RFILE FILE...
```

- MODE - [ugoa]*([-+=]([rwxXst]*|[ugo]))+|[-+=][0-7]+

## 参数

| 参数 | 作用 |
| --------------------- | -------------------------------------------------- |
| -c, --changes | like verbose but report only when a change is made |
| -f, --silent, --quiet | suppress most error messages |
| -v, --verbose | output a diagnostic for every file processed |
| --no-preserve-root | do not treat '/' specially (the default) |
| --preserve-root | fail to operate recursively on '/' |
| --reference = RFILE | use RFILE's mode instead of MODE values |
| -R, --recursive | change files and directories recursively |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 赋予可执行权限

```bash
chmod +x example.sh
```

2. 递归赋予权限，忽略大部分错误信息

```bash
chmod -Rf 777 dir
```

3. 设置 SGID 特殊权限位

```bash
chmod -Rf g+s sharedir
ls -ld sharedir
drwxrwsrwx 2 root root 4096 Jan 15 18:28 sharedir
```

4. 设置 SBIT 特殊权限位

```bash
chmod -R o+t sharedir
ls -ld sharedir
drwxrwsrwt 2 root root 4096 Jan 15 18:28 sharedir
```

5. 全部赋予权限

```bash
chmod 777 *
```
