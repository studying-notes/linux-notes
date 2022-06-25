---
date: 2022-05-02T12:19:52+08:00
author: "Rustle Karl"

title: "Ubuntu WSL 问题笔记"
url:  "posts/linux/quickstart/install/ubuntu_wsl"  # 永久链接
tags: [ "Linux" ]
categories: [ "Linux 学习笔记" ]

toc: true  # 目录
draft: false  # 草稿
---

## 系统更新

```shell
sudo sed -i 's/archive.ubuntu.com/mirrors.ustc.edu.cn/g' /etc/apt/sources.list

sudo sed -i 's/mirrors.ustc.edu.cn/archive.ubuntu.com/g' /etc/apt/sources.list

apt update && apt upgrade -y
```

## WSL 默认 root

```shell
ubuntu config --default-user root

kali config --default-user root
```

```shell
ubuntu2004 config --default-user root
```

## WSL1 转换为 WSL2

```shell
wsl.exe -l -v
```

```shell
wsl.exe --set-default-version 2
```

```shell
wsl.exe --set-version ubuntu 2
```

## 修改 hostname

> https://www.srccodes.com/change-hostname-ubuntu-microsoft-windows-subsystem-for-linux-wsl-wsl2-wsl-conf-unable-resolve-hosts-name-service-not-known-list-running-shutdown-vm-srccodes/

默认情况跟宿主机是一样的，看着很难受。

```shell
vim /etc/wsl.conf

vi /etc/wsl.conf
```

```shell
[network]
hostname = ubuntu-wsl
generateHosts = false
```

```shell
[network]
hostname = kali-wsl
generateHosts = false
```

```shell
wsl --shutdown
```

## 升级大版本

```shell
apt update && apt upgrade -y
```

do-release-upgrade 指令可以帮助我们升级 Ubuntu 版本，但是如果直接运行，会提醒没有更新的版本，这时我们就需要

```shell
do-release-upgrade -d
```

```shell
lsb_release -a
```

## WSL2 GUI 测试

```
apt install gedit -y

gedit ~/.bashrc
```

分辨率不匹配，基本用不了。

## 卸载重启检测

```shell
apt purge needrestart
```
