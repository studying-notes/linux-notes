---
date: 2022-05-19T10:56:17+08:00
author: "Rustle Karl"

title: "apk Alpine Linux 下的包管理工具"
url:  "posts/linux/tools/pkg-manager/apk"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> Alpine Linux 下的包管理工具

## 基本用法

```shell
apk add python3 # 安装包
apk del python3 # 卸载并删除包

apk search python3 # 支持正则
apk info python3 # 查看包的详细信息
apk show # 列出本地安装的包
```

## 升级

upgrade 命令升级系统已安装的所以软件包（一般包括内核），当然也可指定仅升级部分软件包（通过 -u 或– upgrade 选择指定）。

```shell
apk update # 更新最新本地镜像源
apk upgrade # 升级软件
apk add --upgrade busybox # 指定升级部分软件包
```

### 搜索

```shell
apk search # 查找所以可用软件包
apk search -v # 查找所以可用软件包及其描述内容
apk search -v 'python*' # 通过软件包名称查找软件包
apk search -v -d 'python3' # 通过描述文件查找特定的软件包
```

### 查看包信息

info 命令用于显示软件包的信息。

```shell
apk info # 列出所有已安装的软件包
apk info -a zlib # 显示完整的软件包信息
apk info --who-owns /sbin/lbu # 显示指定文件属于的包
```
