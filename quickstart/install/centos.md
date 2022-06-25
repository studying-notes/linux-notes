---
date: 2020-11-27T12:58:26+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "CentOS 系统重装后的基本配置"  # 文章标题
description: "每次系统重装、更换新的系统/硬件，开发环境的重新搭建都是一个巨大的工程"
url:  "posts/linux/quickstart/install/centos"  # 设置网页链接，默认使用文件名
tags: [ "centos", "linux", "config"]
categories: [ "Linux 学习笔记" ]

# 章节
weight: 20 # 排序优先级
chapter: false  # 设置为章节

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
---

## 联网

wget -e http_proxy=192.168.10.138:8118 -e https_proxy=192.168.10.138:8118 https://dl.google.com/linux/direct/google-chrome-stable_current_x86_64.rpm

```shell
curl -x 192.168.10.138:8118 https://www.google.com
```

```shell
sed -i 's/ONBOOT=no/ONBOOT=yes/g' /etc/sysconfig/network-scripts/ifcfg-ens33
```

```shell
service network restart
```

## 虚拟机与主机互通网络

https://blog.csdn.net/ww1473345713/article/details/51490525

修改 VMware Network Adapter VMnet8 网络适配器 IP 设置，设置成与虚拟机同一网段。

编辑-->虚拟网络编辑器-->勾选将主机虚拟连接到此网络-->应用-->取消勾选--应用-->勾选-->应用

## 开启 SSH

```shell
yum install -y openssh-server
```

### 编译配置文件

```shell
vi /etc/ssh/sshd_config
```

启动服务

```shell
systemctl start sshd
```

```shell
systemctl restart sshd
```

```shell
ssh root@192.168.10.109
```

```shell
cat >> /etc/hosts << EOF
192.168.10.109 master
192.168.10.216 node1
EOF
```

配置开机自启

```shell
systemctl enable sshd
```

```shell
ssh-keygen -t rsa
```

```shell
ssh-copy-id -i ~/.ssh/id_rsa.pub  root@192.168.10.109
```

### 永久修改主机名

重启生效

```shell
echo master > /etc/hostname
```

```shell
echo node9 > /etc/hostname && reboot now
```

```shell
reboot now
```

### 不显示登录标语

```shell
touch ~/.hushlogin
```

## 系统版本

```shell
cat /etc/redhat-release
```

```shell
cat /etc/centos-release
```

以上两个命令等价。

```shell
cat /proc/version
```

## 基础配置

### 常用工具

```shell
yum install -y wget curl psmisc
```


### 安装 Fish 终端

Setp 1. 添加源安装

https://software.opensuse.org/download.html?project=shells%3Afish&package=fish

```shell
cd /etc/yum.repos.d/ && wget https://download.opensuse.org/repositories/shells:fish/CentOS_7/shells:fish.repo
```

```shell
yum install -y fish
```

Setp 2. 去掉欢迎语句

需进入 Fish 中设置才能生效。

```shell
set fish_greeting
```

Setp 3. 设置别名，自定义变量

```shell
./alias.sh && source ~/.config/fish/config.fish
```

```shell
source ~/.config/fish/config.fish
```

Setp 4. 修改默认终端

> 在原生 shell 中

```shell
usermod -s `which fish`  root
```

恢复默认终端：

```shell
usermod -s `which bash`  root
```

### Python3 / Pip3

```shell
yum install python3 -y
```

```shell
pip3 install toolkit-py -i https://pypi.douban.com/simple  # 个人工具包
```
