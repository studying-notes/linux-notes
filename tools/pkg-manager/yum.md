---
date: 2022-05-19T11:36:46+08:00
author: "Rustle Karl"

title: "yum 基于 RPM 的软件包管理器"
url:  "posts/linux/tools/pkg-manager/yum"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 基于 RPM 的软件包管理器

**yum 命令** 是在 Fedora 和 RedHat 以及 SUSE 中基于 rpm 的软件包管理器，它可以使系统管理人员交互和自动化地更新与管理 RPM 软件包，能够从指定的服务器自动下载 RPM 包并且安装，可以自动处理依赖性关系，并且一次安装所有依赖的软体包，无须繁琐地一次次下载、安装。

## 语法

```shell
yum(选项)(参数)
```

## 选项

```shell
-h：显示帮助信息；
-y：对所有的提问都回答“yes”；
-c：指定配置文件；
-q：安静模式；
-v：详细模式；
-d：设置调试等级（0-10）；
-e：设置错误等级（0-10）；
-R：设置 yum 处理一个命令的最大等待时间；
-C：完全从缓存中运行，而不去下载或者更新任何头文件。
```

## 参数

```shell
install：安装 rpm 软件包；
update：更新 rpm 软件包；
check-update：检查是否有可用的更新 rpm 软件包；
remove：删除指定的 rpm 软件包；
list：显示软件包的信息；
search：检查软件包的信息；
info：显示指定的 rpm 软件包的描述信息和概要信息；
clean：清理 yum 过期的缓存；
shell：进入 yum 的 shell 提示符；
resolvedep：显示 rpm 软件包的依赖关系；
localinstall：安装本地的 rpm 软件包；
localupdate：显示本地 rpm 软件包进行更新；
deplist：显示 rpm 软件包的所有依赖关系。
```

## 常用命令

### 自动搜索最快镜像插件

```shell
yum install -y yum-fastestmirror
```

## 实例

### 安装

```shell
yum install              #全部安装
yum install package1     #安装指定的安装包package1
yum groupinsall group1   #安装程序组group1
```

### 更新和升级

```shell
yum update               #全部更新
yum update package1      #更新指定程序包package1
yum check-update         #检查可更新的程序
yum upgrade package1     #升级指定程序包package1
yum groupupdate group1   #升级程序组group1
```

### 查找和显示

```shell
# 检查 MySQL 是否已安装
yum list installed | grep mysql
yum list installed mysql*

yum info package1      #显示安装包信息package1
yum list               #显示所有已经安装和可以安装的程序包
yum list package1      #显示指定程序包安装情况package1
yum groupinfo group1   #显示程序组group1信息yum search string 根据关键字string查找安装包
```

### 删除程序

```shell
yum remove &#124; erase package1   #删除程序包package1
yum groupremove group1             #删除程序组group1
yum deplist package1               #查看程序package1依赖情况
```

### 清除缓存

```shell
yum clean packages       # 清除缓存目录下的软件包
yum clean headers        # 清除缓存目录下的 headers
yum clean oldheaders     # 清除缓存目录下旧的 headers
```
