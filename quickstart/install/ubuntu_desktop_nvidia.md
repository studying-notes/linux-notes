---
date: 2022-04-30T15:01:40+08:00
author: "Rustle Karl"

title: "Ubuntu 安装 Nvidai 显卡驱动"
url:  "posts/linux/quickstart/install/ubuntu_desktop_nvidia"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

```shell
sudo apt update && sudo apt upgrade -y
```

```shell
ubuntu-drivers devices
```

```shell
sudo ubuntu-drivers autoinstall
```

```shell
reboot
```

```shell
nvidia-smi
```

```shell
nvidia-settings
```

```shell

```
