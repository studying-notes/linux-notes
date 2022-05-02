---
date: 2022-05-02T12:19:52+08:00
author: "Rustle Karl"

title: "Ubuntu WSL 问题笔记"
url:  "posts/linux/quickstart/install/ubuntu_wsl_upgrade"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 修改 hostname

> https://www.srccodes.com/change-hostname-ubuntu-microsoft-windows-subsystem-for-linux-wsl-wsl2-wsl-conf-unable-resolve-hosts-name-service-not-known-list-running-shutdown-vm-srccodes/

默认情况跟宿主机是一样的，看着很难受。

```shell
vim /etc/wsl.conf
```

```shell
[network]
hostname = ubuntu-wsl
generateHosts = false
```

```shell
wsl --shutdown
```

## 升级大版本

```shell
apt update && apt upgrade -y && apt --purge autoremove
```

do-release-upgrade 指令可以帮助我们升级 Ubuntu 版本，但是如果直接运行，会提醒没有更新的版本，这时我们就需要

```shell
do-release-upgrade -d
```

```shell
lsb_release -a
```
