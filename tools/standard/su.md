---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "su 切换用户"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/su"  # 设置网页永久链接
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

> 切换用户

## 格式

```bash
su [options] [LOGIN]
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -c, --command COMMAND | pass COMMAND to the invoked shell |
| -h, --help | display this help message and exit |
| -, -l, --login | make the shell a login shell |
| -m, -p, --preserve-environment | do not reset environment variables, and keep the same shell |
| -s, --shell SHELL | use SHELL instead of the default in passwd |

- 减号（-），这意味着完全切换到新的用户，即把环境变量信息也变更为新用户的相应信息，而不是保留原始的信息。
- 当从 root 管理员切换到普通用户时是不需要密码验证的，而从普通用户切换成 root 管理员就需要进行密码验证了。

## 示例

1. 从 root 管理员切换至普通用户

```bash
id
uid=0(root) gid=0(root) groups=0(root)

su cxfans
id
uid=1314(cxfans) gid=1314(cxfans) groups=1314(cxfans)
```
