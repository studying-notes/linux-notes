---
date: 2022-05-19T11:07:44+08:00
author: "Rustle Karl"

title: "apt-get Debian Linux 发行版中的 APT 软件包管理工具"
url:  "posts/linux/tools/pkg-manager/apt-get"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> Debian Linux 发行版中的 APT 软件包管理工具

**apt-get 命令** 是 Debian Linux 发行版中的 APT 软件包管理工具。所有基于 Debian 的发行都使用这个包管理系统。deb 包可以把一个应用的文件包在一起，大体就如同 Windows 上的安装文件。

apt 是其继任者，相比更加强大，现在推荐的做法是脚本中用 apt-get，交互执行的用 apt。

## 语法

```shell 
apt-get [OPTION] PACKAGE
```

## 选项

```shell
apt-get install  # 安装新包
apt-get remove   # 卸载已安装的包（保留配置文件）
apt-get purge    # 卸载已安装的包（删除配置文件）
apt-get update   # 更新软件包列表
apt-get upgrade  # 更新所有已安装的包
apt-get autoremove   # 卸载已不需要的包依赖
apt-get dist-upgrade # 自动处理依赖包升级
apt-get autoclean    # 将已经删除了的软件包的.deb安装文件从硬盘中删除掉
apt-get clean        # 删除软件包的安装包

-c：指定配置文件。
```

## 参数

* 管理指令：对 APT 软件包的管理操作；
* 软件包：指定要操纵的软件包。

## 实例

使用 apt-get 命令的第一步就是引入必需的软件库，Debian 的软件库也就是所有 Debian 软件包的集合，它们存在互联网上的一些公共站点上。把它们的地址加入，apt-get 就能搜索到我们想要的软件。`/etc/apt/sources.list` 是存放这些地址列表的配置文件，其格式如下：

```shell
deb web或[ftp地址] [发行版名字] main/contrib/non-[free]
```

我们常用的 Ubuntu 就是一个基于 Debian 的发行，我们使用 apt-get 命令获取这个列表，以下是我整理的常用命令：

在修改 `/etc/apt/sources.list` 或者 `/etc/apt/preferences` 之后运行该命令。此外您需要定期运行这一命令以确保您的软件包列表是最新的：

```shell
apt-get update
```

安装一个新软件包：

```shell
apt-get install python3
```

卸载一个已安装的软件包（保留配置文件）：

```shell
apt-get remove python3
```

卸载一个已安装的软件包（删除配置文件）：

```shell
apt-get –purge remove python3
```

会把已装或已卸的软件都备份在硬盘上，所以如果需要空间的话，可以让这个命令来删除你已经删掉的软件：

```shell
apt-get autoclean python3
```

这个命令会把安装的软件的备份也删除，不过这样不会影响软件的使用的：

```shell
apt-get clean python3
```

更新所有已安装的软件包：

```shell
apt-get upgrade
```

将系统升级到新版本：

```shell
apt-get dist-upgrade
```

定期运行这个命令来清除那些已经卸载的软件包的.deb 文件。通过这种方式，您可以释放大量的磁盘空间。如果您的需求十分迫切，可以使用 `apt-get clean` 以释放更多空间。这个命令会将已安装软件包裹的.deb 文件一并删除。大多数情况下您不会再用到这些.debs 文件，因此如果您为磁盘空间不足 而感到焦头烂额，这个办法也许值得一试：

```shell
apt-get autoclean
```
