---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "passwd 修改用户名密码"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/passwd"  # 设置网页永久链接
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

> 修改用户名密码

## 格式

```bash
passwd [options] [LOGIN]
```

## 参数

### Ubuntu 18.04 LTS

| 参数 | 作用 |
| -------- | -------- |
| -a, --all | report password status on all accounts |
| -d, --delete | delete the password for the named account |
| -e, --expire | force expire the password for the named account |
| -h, --help | display this help message and exit |
| -k, --keep-tokens | change password only if expired |
| -i, --inactive INACTIVE | set password inactive after expiration to INACTIVE |
| -l, --lock | lock the password of the named account |
| -n, --mindays MIN_DAYS | set minimum number of days before password change to MIN_DAYS |
| -q, --quiet | quiet mode |
| -r, --repository REPOSITORY | change password in REPOSITORY repository |
| -R, --root CHROOT_DIR | directory to chroot into |
| -S, --status | report password status on the named account |
| -u, --unlock | unlock the password of the named account |
| -w, --warndays WARN_DAYS | set expiration warning days to WARN_DAYS |
| -x, --maxdays MAX_DAYS | set maximum number of days before password change to MAX_DAYS |

### RHEL 7

| 参数 | 作用 |
| -------- | -------- |
| -k, --keep-tokens | keep non-expired authentication tokens |
| -d, --delete | delete the password for the named account (root only) |
| -l, --lock | lock the password for the named account (root only) |
| -u, --unlock | unlock the password for the named account (root only) |
| -e, --expire | expire the password for the named account (root only) |
| -f, --force | force operation |
| -x, --maximum = DAYS | maximum password lifetime (root only) |
| -n, --minimum = DAYS | minimum password lifetime (root only) |
| -w, --warning = DAYS | number of days warning users receives before password expiration (root only) |
| -i, --inactive = DAYS | number of days after password expiration when an account becomes disabled (root only) |
| -S, --status | report password status on the named account (root only) |
| --stdin | read new tokens from stdin (root only) |
| - ?, --help | Show this help message |
| --usage | Display brief usage message |

## 示例

1. 修改 RHEL 用户密码

```bash
echo "root" | passwd --stdin admin
Changing password for user admin.
passwd: all authentication tokens updated successfully.
```

2. 修改 Ubuntu 用户密码

```bash
echo -e "admin\nadmin" | passwd admin
Enter new UNIX password: Retype new UNIX password: passwd: password updated successfully
```

3. 禁止某用户登录

```bash
passwd -l cxfans
passwd: password expiry information changed.

passwd -S cxfans
cxfans L 01/14/2020 0 99999 7 -1

passwd -u cxfans
passwd: unlocking the password would result in a passwordless account.
You should set a password with usermod -p to unlock the password of this account.
```
