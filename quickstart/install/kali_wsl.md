---
date: 2022-05-11T12:41:48+08:00
author: "Rustle Karl"

title: "Kali Linux WSL 问题笔记"
url:  "posts/linux/quickstart/install/kali_wsl"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

WSL 2 、修改主机名等通用问题参考 Ubuntu。

## 基本工具集

```shell
apt update && apt upgrade -y

apt install -y kali-linux-default
```

## 官方桌面

> 用处不大

```shell
apt install kali-win-kex
```

https://www.kali.org/docs/wsl/win-kex/
