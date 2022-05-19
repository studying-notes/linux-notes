---
date: 2022-05-19T11:19:48+08:00
author: "Rustle Karl"

title: "opkg OpenWrt 包管理器"
url:  "posts/linux/tools/pkg-manager/opkg"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> https://openwrt.org/zh/docs/techref/opkg

## 用法

```shell
opkg [选项…] 子命令 [参数]
```

```shell
opkg update # 更新可用软件包列表
opkg upgrade # 升级软件包
opkg install # 安装一个或多个软件包
opkg remove # 移除一个或多个软件包
```

```shell
opkg list # 列出可用软件包
opkg list | grep python # 搜索软件包

opkg list-upgradable # 列出可用软件包
```

## 技巧

### 升级全部可更新包

```
opkg list-upgradable | cut -f 1 -d ' ' | xargs -r opkg upgrade
```
