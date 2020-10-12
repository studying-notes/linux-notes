---
date: 2020-09-21T11:01:49+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: " Ubuntu 系统重装后的基本配置"  # 文章标题
description: "每次系统重装、更换新的系统/硬件，开发环境的重新搭建都是一个巨大的工程"
url:  "posts/linux/config/ubuntu"  # 设置网页链接，默认使用文件名
tags: [ "ubuntu", "linux", "config"]  # 自定义标签
series: [ "系统重装基础配置"]  # 文章主题/文章系列
categories: [ "基础配置"]  # 文章分类

# 章节
weight: 20 # 文章在章节中的排序优先级，正序排序
chapter: false  # 将页面设置为章节

index: true  # 文章是否可以被索引
draft: false  # 草稿
---

## 基础配置

### WSL 默认登录 root 用户

```shell
ubuntu config --default-user root
```

```shell
ubuntu2004 config --default-user root
```

### 换镜像源

执行自动换源脚本：

```shell
./sources.sh
```

```shell
# Ubuntu 20.14
./v20.sh
```

更新系统：

```shell
apt update && apt upgrade
```

### VMWare Tools

无法自动安装 VMWare Tools 的虚拟机。

```shell
# GUI
apt-get install open-vm-tools-desktop
```

```shell
# Server
apt-get install open-vm-tools
```

### 非 WSL 启用 SSH 登录 root

1. 安装 SSH 服务

```shell
apt install openssh-server

# 启动服务
systemctl start ssh
```

2. 配置开机自启

```shell
systemctl enable ssh.service
```

3. 设置 root 用户密码

```shell
passwd root
```

4. 添加设置

```shell
echo "PermitRootLogin yes" >> /etc/ssh/sshd_config
sed -i "s/PermitRootLogin prohibit-password/#PermitRootLogin prohibit-password/g" /etc/ssh/sshd_config
```

```shell
# 重启服务
systemctl restart ssh

service ssh restart
```

5. 客户端生成一对公钥密钥

```shell
ssh-keygen -t rsa
```

```shell
# 把公钥放到服务器上
ssh-copy-id -i ~/.ssh/id_rsa.pub root@192.168.134.129
```

```shell
# 然后可以不输密码登录
ssh root@192.168.134.129
```

### 永久修改主机名

```shell
echo ubuntu > /etc/hostname
```

```shell
# 重启
reboot
```

### 不显示登录标语

```shell
touch ~/.hushlogin
```

### 安装 Fish 终端

Setp 1. 添加源安装

```shell
apt-add-repository ppa:fish-shell/release-3 && apt-get update
```

```shell
apt-get install fish
```

Setp 2. 去掉欢迎语句

需进入 Fish 中设置才能生效。

```shell
set fish_greeting
```

Setp 3. 设置别名，自定义变量

```shell
fish alias.sh && source ~/.config/fish/config.fish
```

```shell
source ~/.config/fish/config.fish
```

Setp 4. 修改默认终端

```shell
usermod -s `which fish`  root
```

恢复默认终端：

```shell
usermod -s `which bash`  root
```

## 开发环境

### Git / Curl

```shell
apt install git
git --version
```

```shell
apt install curl
```

### Python3 / Pip3

```shell
apt install python3-pip
```

```shell
source ~/.config/fish/config.fish
```

```shell
pip install toolkit-py # 个人工具包
```

```shell
chs # 换源
```

### GO

{{<card src="posts/go/doc/install">}}
