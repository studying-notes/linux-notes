---
date: 2022-05-19T11:17:18+08:00
author: "Rustle Karl"

title: "apt-key 管理 Debian Linux 系统中的软件包密钥"
url:  "posts/linux/tools/pkg-manager/apt-key"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 管理 Debian Linux 系统中的软件包密钥

**apt-key 命令** 用于管理 Debian Linux 系统中的软件包密钥。每个发布的 deb 包，都是通过密钥认证的，apt-key 用来管理密钥。

## 语法

```shell
apt-key(参数)
```

## 参数

操作指令：APT 密钥操作指令。

## 实例

```shell
apt-key list          # 列出已保存在系统中key。
apt-key add keyname   # 把下载的key添加到本地trusted数据库中。
apt-key del keyname   # 从本地trusted数据库删除key。
apt-key update        # 更新本地trusted数据库，删除过期没用的key。
```
