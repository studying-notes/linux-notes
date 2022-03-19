---
date: 2022-03-19T18:49:09+08:00
author: "Rustle Karl"

title: "Ubuntu 系统重装后的基本配置"
url:  "posts/linux/quickstart/install/ubuntu_desktop"  # 永久链接
tags: [ "Linux", "README" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 更新系统

```shell
apt update
```

官方源速度现在也不慢了。

```shell
apt upgrade -y
```

## 启用 SSH 登录 root

1. 安装 SSH 服务

```shell
apt install -y openssh-server
```

```shell
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
```

```shell
sed -i "s/PermitRootLogin prohibit-password/#PermitRootLogin prohibit-password/g" /etc/ssh/sshd_config
```

```shell
# 重启服务
systemctl restart ssh
```

5. 客户端生成一对公钥密钥

可能已经有该文件了，就不必再生成。

```shell
ssh-keygen -t rsa
```

6. 把公钥放到服务器上

```shell
ssh-copy-id -i ~/.ssh/id_rsa.pub root@192.168.0.111 -p20000
ssh-copy-id -i ~/.ssh/id_rsa.pub root@192.168.0.111
ssh-copy-id -i ~/.ssh/id_rsa.pub root@master
```

然后可以不输密码登录

```shell
ssh root@master
```

```shell
ssh root@master -p20000
```

## 换镜像源

### Python3 / Pip3

```shell
ln -s /usr/bin/python3 /usr/bin/python
```

```shell
apt install -y python3-pip
```

```shell
ln -s /usr/bin/pip3 /usr/bin/pip
```

```shell
pip3 install toolkit-py -i https://pypi.douban.com/simple  # 个人工具包
```

```shell
cfm py
```

## 时间同步

```shell
apt install ntpdate -y
```

```shell
ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime && echo 'Asia/Shanghai' > /etc/timezone && ntpdate time2.aliyun.com
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
apt-add-repository ppa:fish-shell/release-3 && apt update
```

```shell
apt install -y fish
```

Setp 2. 去掉欢迎语句

需进入 Fish 中设置才能生效。

```shell
set fish_greeting
```

Setp 3. 设置别名，自定义变量

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

## WSL 默认 root

```shell
ubuntu config --default-user root
```

```shell
ubuntu2004 config --default-user root
```

## VMWare Tools

无法自动安装 VMWare Tools 的虚拟机。

```shell
# GUI
apt install -y open-vm-tools-desktop
```

```shell
# Server
apt install -y open-vm-tools
```
