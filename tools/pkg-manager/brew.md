---
date: 2022-05-22T14:37:54+08:00
author: "Rustle Karl"

title: "brew MacOS 包管理器"
url:  "posts/linux/tools/pkg-manager/brew"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 安装

```shell
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

可能会遇到 Failed to install Homebrew Portable Ruby，删除下面的文件即可：

```shell
rm /Users/yn/Library/Caches/Homebrew/portable-ruby-2.6.3_2.yosemite.bottle.tar.gz
```

## 基本功能

```shell
# 查询
brew search 软件名

# 安装
brew install 软件名

# 卸载
brew uninstall 软件名

# 更新 Homebrew
brew update 

# 查看 Homebrew 配置信息
brew config 
```

## 常用

```shell
brew install visual-studio-code 
brew install golang
brew install microsoft-remote-desktop
brew install --cask jetbrains-toolbox
brew install google-chrome 
```

## 代理下载

与 Linux 系统是一样的，自动检测代理相关的环境变量：

```shell
ALL_PROXY= http://127.0.0.1:8118 brew
```
