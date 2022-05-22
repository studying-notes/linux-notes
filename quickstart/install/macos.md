---
date: 2022-05-22T14:44:07+08:00
author: "Rustle Karl"

title: "MacOS 基本配置"
url:  "posts/linux/quickstart/install/macos"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 打开远程登录

```shell
ssh develop@192.168.0.24

ssh-copy-id -i ~/.ssh/id_rsa.pub develop@192.168.0.24
```

## 从 App Store 安装 Xcode

## 安装 brew

见 [brew](../../tools/pkg-manager/brew.md)

## Fish Shell

```shell
brew install fish
```

设置默认：

```shell
vim /etc/shells
```

```shell
/usr/local/bin/fish
```

加到最后，然后设置：

```shell
chsh -s `which fish`
```

```shell
fish -c "set -U fish_greeting"
```

## Python

```shell
sudo ln -s /usr/bin/python3 /usr/bin/python
```

```shell
sudo ln -s /usr/bin/pip3 /usr/bin/pip
```

## 设置鼠标移动速度

官方的鼠标移动太慢了，难用。

### 显示当前速度

```shell
defaults read -g com.apple.mouse.scaling
```

### 设置速度

```shell
defaults write -g com.apple.mouse.scaling 12
```
