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

- [更新系统](#更新系统)
- [启用 SSH 登录 root](#启用-ssh-登录-root)
- [换镜像源](#换镜像源)
  - [Python3 / Pip3](#python3--pip3)
- [时间同步](#时间同步)
  - [永久修改主机名](#永久修改主机名)
  - [不显示登录标语](#不显示登录标语)
  - [安装 Fish 终端](#安装-fish-终端)
    - [切换主题](#切换主题)
- [WSL 默认 root](#wsl-默认-root)
- [VMWare Tools](#vmware-tools)
- [Xvfb 虚拟 X Server](#xvfb-虚拟-x-server)
  - [启动](#启动)
- [System Program Problem Detected 弹窗](#system-program-problem-detected-弹窗)
- [桌面允许 root 登录](#桌面允许-root-登录)
- [远程桌面](#远程桌面)
- [安装 Docker](#安装-docker)
- [安装 OneDrive](#安装-onedrive)

## 更新系统

```shell
apt update
```

官方源速度现在也不慢了。

```shell
apt upgrade -y
```

一行命令：

```shell
apt update && apt upgrade -y
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
ssh-copy-id -i ~/.ssh/id_rsa.pub root@ubuntu-amd64
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
echo ubuntu-amd64 > /etc/hostname
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

```shell
fish -c "set -U fish_greeting"
```

需进入 Fish 中设置才能生效。

```shell
set -U fish_greeting
```

Setp 3. 设置别名，自定义变量

```shell
vi ~/.config/fish/config.fish
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

#### 切换主题

```shell
git config --global http.https://github.com.proxy ubuntu-amd64:8118

curl -x 192.168.0.107:8118 https://raw.githubusercontent.com/oh-my-fish/oh-my-fish/master/bin/install | fish

omf install eclm
omf theme eclm

omf install batman
omf theme batman

omf install harleen
omf theme harleen

git config --global --unset http.https://github.com.proxy
```

## WSL 默认 root

```shell
ubuntu config --default-user root
kali config --default-user root
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

## Xvfb 虚拟 X Server

Xvfb 是一个 X server，主要用于在没有显示设备的主机上，进行拥有图形界面程序的运行。比如自动化测试。

```shell
sudo apt install xvfb
```

### 启动

- 3: 虚拟屏幕 ID
- 1336x768x24: 屏幕分辨率

```shell
Xvfb -ac :3 -screen 0 1336x768x24 > /dev/null 2>&1

export DISPLAY=:3
```

## System Program Problem Detected 弹窗

```shell
sudo rm /var/crash/*
```

```shell
sed -i /etc/default/apport
```

```shell
sed -i 's/enabled=1/enabled=0/g' /etc/default/apport
```

## 桌面允许 root 登录

vim /usr/share/lightdm/lightdm.conf.d/50-ubuntu.conf

```
[Seat:*]
user-session=ubuntu
greeter-show-manual-login= true
```

以下两个文件注释掉不许 root 登录的判断

```
vim /etc/pam.d/gdm-autologin
vim /etc/pam.d/gdm-password
```

然后重启。

## 远程桌面

```shell
apt install -y tightvncserver xrdp
```

完成安装后，进入 Windows 的操作系统，打开 Windows 的远程桌面工具，输入 Ubuntu 系统的 IP 地址，就可以进行远程桌面的链接。

链接成功后，选择 xorg，输入链接 Ubuntu 桌面的账号和密码，进入桌面后就可以开始远程管理控制远程的 Ubuntu 系统了。

需要注意的是，远程桌面链接的账号默认需要 root 用户方可登陆，开启 root 的账号的方法，需要在 Ubuntu 的终端命令窗口下输入下面的指令。

```shell
passwd root
```

## 安装 Docker

见树莓派笔记。

## 安装 OneDrive

见树莓派笔记。
