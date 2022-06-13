---
date: 2022-05-21T08:56:43+08:00
author: "Rustle Karl"

title: "dpkg Debian Linux 系统上安装、创建和管理软件包"
url:  "posts/linux/tools/pkg-manager/dpkg"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> Debian Linux 系统上安装、创建和管理软件包

缺点大概是不能自动解决依赖，可以用 apt 替代：

```
apt install -fy ./xxx.deb
```

## 语法

```shell
dpkg(选项)(参数)
```

## 选项

```shell
-i：安装软件包；
-r：删除软件包；
-P：删除软件包的同时删除其配置文件；
-L：显示于软件包关联的文件；
-l：显示已安装软件包列表；
--unpack：解开软件包；
-c：显示软件包内文件列表；
--confiugre：配置软件包。
```

## 参数

Deb 软件包：指定要操作的.deb 软件包。

## 实例

```shell
dpkg -i package.deb     # 安装包
dpkg -r package         # 删除包
dpkg -P package         # 删除包（包括配置文件）
dpkg -L package         # 列出与该包关联的文件
dpkg -l package         # 显示该包的版本
dpkg --unpack package.deb  # 解开deb包的内容
dpkg -S keyword            # 搜索所属的包内容
dpkg -l                    # 列出当前已安装的包
dpkg -c package.deb        # 列出deb包的内容
dpkg --configure package   # 配置包
```

## 常用软件

### Git & SSH

```shell
opkg install git-http openssh-keygen openssh-client openssh-sftp-server
```

缺一个 Git 都不能正常。

### Docker

```shell
opkg install --force-overwrite docker docker-compose dockerd luci-app-docker
opkg install --force-overwrite luci-app-dockerman luci-i18n-dockerman-zh-cn luci-lib-docker
opkg install --force-overwrite luci-i18n-docker-zh-cn
```

```shell
opkg install fuse-overlayfs
```

### Python

```shell
opkg install python3 python3-pip
```

### Golang

```shell
opkg install golang
```
