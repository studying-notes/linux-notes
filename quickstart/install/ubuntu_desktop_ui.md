---
date: 2022-04-30T19:09:01+08:00
author: "Rustle Karl"

title: "Ubuntu 桌面主题"
url:  "posts/linux/quickstart/install/ubuntu_desktop_ui"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

```shell
alias apt='apt -o Acquire::http::proxy="http://192.168.0.117:8118/"'
```

## 安装依赖

```shell
sudo apt update
sudo apt install -y gnome-tweaks chrome-gnome-shell
sudo apt install -y gtk2-engines-murrine gtk2-engines-pixbuf 
```

```shell
sudo apt install -y sassc optipng inkscape libcanberra-gtk-module libglib2.0-dev libxml2-utils
```

## 安装插件管理器

新版 Firefox 浏览器因为是 Snap 版本的，不支持直接安装插件，所以需要单独安装管理器：

```shell
sudo apt install -y gnome-shell-extension-manager
```

## 安装插件

https://extensions.gnome.org/

- user themes
- dash to dock
