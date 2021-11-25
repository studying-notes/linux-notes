---
date: 2020-12-27T16:07:32+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: " Ubuntu 桌面版重装后的基本配置"  # 文章标题
description: "每次系统重装、更换新的系统/硬件，开发环境的重新搭建都是一个巨大的工程"
url:  "posts/linux/config/ubuntu-gui"  # 设置网页链接，默认使用文件名
tags: [ "ubuntu", "linux", "config"]  # 自定义标签
series: [ "系统重装基础配置", "Linux 学习笔记" ]  # 文章主题/文章系列
categories: [ "基础配置"]  # 文章分类

# 章节
weight: 20 # 排序优先级
chapter: false  # 设置为章节

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
---

{{<link src="posts/linux/config/ubuntu">}}

## 允许 root 登录

1. 设置 root 密码

```shell
sudo passwd root
```

2. 修改文件

`50-ubuntu.conf`

```shell
sudo gedit /usr/share/lightdm/lightdm.conf.d/50-ubuntu.conf
```

在文件末尾增加如下两行：

```ini
greeter-show-manual-login=true
all-guest=false  
```

`gdm-autologin`

```shell
sudo gedit /etc/pam.d/gdm-autologin
```

注释内容

```ini
auth required pam_succeed_if.so user != root quiet_success
```

`gdm-password`

```shell
sudo gedit /etc/pam.d/gdm-password
```

注释内容

```shell
auth required pam_succeed_if.so user != root quiet_success
```

`/root/.profile`

```shell
sudo gedit /root/.profile
```

将文件末尾的

```ini
mesg n 2> /dev/null || true
```

这一行修改成

```ini
tty -s && mesg n || true
```

## 找不到共享文件夹

```shell
vmhgfs-fuse /mnt/hgfs/
```
