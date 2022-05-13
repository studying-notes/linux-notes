---
date: 2022-03-19T18:47:48+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "Linux 学习笔记"  # 文章标题
description: "纸上得来终觉浅，学到过知识点分分钟忘得一干二净，今后无论学什么，都做好笔记吧。"
url:  "posts/linux/README"  # 设置网页永久链接
tags: [ "Linux", "README" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
---

# Linux 学习笔记

> 纸上得来终觉浅，学到过知识点分分钟忘得一干二净，今后无论学什么，都做好笔记吧。

## 目录结构

- `assets/images`: 笔记配图
- `assets/templates`: 笔记模板
- `docs`: 基础语法
- `libraries`: 库
  - `libraries/standard`: 标准库
  - `libraries/tripartite`: 第三方库
- `quickstart`: 基础用法
- `src`: 源码示例
  - `src/docs`: 基础语法源码示例
  - `src/libraries/standard`: 标准库源码示例
  - `src/libraries/tripartite`: 第三方库源码示例
  - `src/quickstart`: 基础用法源码示例

## 基础用法

### 安装配置

- [Ubuntu 系统重装后的基本配置](quickstart/install/ubuntu_desktop.md)
- [Ubuntu 安装 Nvidai 显卡驱动](quickstart/install/ubuntu_desktop_nvidia.md)
- [OpenSSH 教程](quickstart/openssh.md)
- [Fish Shell 安装与主题切换](quickstart/shell/fish.md)
- [Ubuntu WSL 问题笔记](quickstart/install/ubuntu_wsl.md)

## 常用工具

### 系统自带工具

- [top 命令详解](tools/standard/top.md)
- [Cron 表达式详解](libraries/standard/cron.md)

### 常用软件

- [proxychains 与 graftcp 原理对比](quickstart/software/proxychains_graftcp.md)

## Linux网络编程

- [第1章_Linux操作系统概述](docs/Linux网络编程/第1章_Linux操作系统概述.md)
- [第2章_Linux编程环境](docs/Linux网络编程/第2章_Linux编程环境.md)
- [第3章_文件系统简介](docs/Linux网络编程/第3章_文件系统简介.md)
- [第4章_程序、进程和线程](docs/Linux网络编程/第4章_程序、进程和线程.md)
- [第5章_TCP_IP协议族简介](docs/Linux网络编程/第5章_TCP_IP协议族简介.md)
- [第7章_TCP网络编程基础](docs/Linux网络编程/第7章_TCP网络编程基础.md)
- [第8章_服务器和客户端信息的获取](docs/Linux网络编程/第8章_服务器和客户端信息的获取.md)
- [第9章_数据的IO和复用](docs/Linux网络编程/第9章_数据的IO和复用.md)
- [第10章_基于UDP协议的接收和发送](docs/Linux网络编程/第10章_基于UDP协议的接收和发送.md)
- [第11章_高级套接字](docs/Linux网络编程/第11章_高级套接字.md)
- [第15章_IPv6简介](docs/Linux网络编程/第15章_IPv6简介.md)
