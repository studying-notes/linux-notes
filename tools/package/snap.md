---
date: 2022-06-30T09:03:37+08:00
author: "Rustle Karl"

title: "snap 包管理器"
url:  "posts/linux/tools/package/snap"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 安装

```shell
apt install -y snapd
```

```shell
snap install snap-store
```

## 更新

```shell
snap refresh package
```

## 设置代理

```shell
snap set system proxy.http="http://192.168.199.140:7890"
snap set system proxy.https="http://192.168.199.140:7890"
```

```shell
snap set system proxy.http="socks5://localhost:10808"
snap set system proxy.https="socks5://localhost:10808"
```

```shell
snap unset system proxy.http
snap unset system proxy.https
```
