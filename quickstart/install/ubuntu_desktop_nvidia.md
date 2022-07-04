---
date: 2022-04-30T15:01:40+08:00
author: "Rustle Karl"

title: "Ubuntu 安装 Nvidai 显卡驱动"
url:  "posts/linux/quickstart/install/ubuntu_desktop_nvidia"  # 永久链接
tags: [ "Linux" ]
categories: [ "Linux 学习笔记" ]

toc: true  # 目录
draft: false  # 草稿
---

## 安装

```shell
ubuntu-drivers devices
```

```shell
ubuntu-drivers autoinstall
```

```shell
reboot
```

## 显示版本

```shell
nvidia-smi
```

## 设置

```shell
nvidia-settings
```

## 无法自动更新提示

```
22 updates could not be installed automatically. For more details,
see /var/log/unattended-upgrades/unattended-upgrades.log
```

删除下面这个文件可以阻止提示：

```shell
rm /var/lib/unattended-upgrades/kept-back
```

但很快还会出现。。。

https://askubuntu.com/questions/601/the-following-packages-have-been-kept-back-why-and-how-do-i-solve-it

```
apt install $(cat /var/lib/unattended-upgrades/kept-back)
```

然后重启。
