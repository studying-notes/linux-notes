---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "useradd 创建新的用户"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/useradd"  # 设置网页永久链接
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

> 创建新的用户

## 格式

```bash
useradd [options] LOGIN
useradd -D
useradd -D [options]
```

- 默认的用户主目录会被存放在 `/home` 目录中，默认的 Shell 解释器为 `/bin/bash`，而且默认会创建一个与该用户同名的基本用户组。

## 参数

| 参数                         | 作用                                                     |
| ---------------------------- | -------------------------------------------------------- |
| -b, --base-dir BASE_DIR      | base directory for the home directory of the new account |
| -c, --comment COMMENT        | GECOS field of the new account                           |
| -d, --home-dir HOME_DIR      | home directory of the new account                        |
| -D, --defaults               | print or change default useradd configuration            |
| -e, --expiredate EXPIRE_DATE | expiration date of the new account                       |
| -f, --inactive INACTIVE      | password inactivity period of the new account            |
| -g, --gid GROUP              | name or ID of the primary group of the new account       |
| -G, --groups GROUPS          | list of supplementary groups of the new account          |
| -h, --help                   | display this help message and exit                       |
| -k, --skel SKEL_DIR          | use this alternative skeleton directory                  |
| -K, --key KEY=VALUE          | override /etc/login.defs defaults                        |
| -l, --no-log-init            | do not add the user to the lastlog and faillog databases |
| -m, --create-home            | create the user's home directory                         |
| -M, --no-create-home         | do not create the user's home directory                  |
| -N, --no-user-group          | do not create a group with the same name as the user     |
| -o, --non-unique             | allow to create users with duplicate (non-unique) UID    |
| -p, --password PASSWORD      | encrypted password of the new account                    |
| -r, --system                 | create a system account                                  |
| -R, --root CHROOT_DIR        | directory to chroot into                                 |
| -s, --shell SHELL            | login shell of the new account                           |
| -u, --uid UID                | user ID of the new account                               |
| -U, --user-group             | create a group with the same name as the user            |
| -Z, --selinux-user SEUSER    | use a specific SEUSER for the SELinux user mapping       |
| --extrausers                 | Use the extra users database                             |

## 示例

1. 创建一个普通用户

```bash
useradd -d /home/cxfans -u 1314 -s /usr/bin/fish cxfans
id cxfans
uid=1314(cxfans) gid=1314(cxfans) groups=1314(cxfans)
```
