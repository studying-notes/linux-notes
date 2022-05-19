---
date: 2022-05-19T13:07:12+08:00
author: "Rustle Karl"

title: "dnf 新一代的 RPM 软件包管理器"
url:  "posts/linux/tools/pkg-manager/dnf"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 新一代的 RPM 软件包管理器

## DNF 是新一代的rpm软件包管理器。首先出现在 Fedora 18 这个发行版中。之后取代了yum，正式成为 Fedora 22 的包管理器。

DNF 包管理器克服了 YUM 包管理器的一些瓶颈，提升了包括用户体验，内存占用，依赖分析，运行速度等多方面的内容。DNF 使用 RPM, libsolv 和 hawkey 库进行包管理操作。

## 安装 DNF 包管理器

DNF 并未默认安装在 RHEL 或 CentOS 7系统中，但是 Fedora 22 已经默认使用 DNF .

1、为了安装 DNF ，您必须先安装并启用 epel-release 依赖。

在系统中执行以下命令：

```shell
yum install epel-release -y
```

2、使用 epel-release 依赖中的 YUM 命令来安装 DNF 包。在系统中执行以下命令：

```shell
yum install dnf -y
```

然后， DNF 包管理器就被成功的安装到你的系统中了。

## 查看 DNF 包管理器版本 

用处：该命令用于查看安装在您系统中的 DNF 包管理器的版本

```shell
dnf --version
```

## 查看系统中可用的 DNF 软件库 

用处：该命令用于显示系统中可用的 DNF 软件库

```shell
dnf repolist
```

## 查看系统中可用和不可用的所有的 DNF 软件库 

用处：该命令用于显示系统中可用和不可用的所有的 DNF 软件库

```shell
dnf repolist all
```

## 列出所有 RPM 包 

用处：该命令用于列出用户系统上的所有来自软件库的可用软件包和所有已经安装在系统上的软件包

```shell
dnf list
```

## 列出所有安装了的 RPM 包 

用处：该命令用于列出所有安装了的 RPM 包

```shell
dnf list installed
```

## 列出所有可供安装的 RPM 包 

用处：该命令用于列出来自所有可用软件库的可供安装的软件包

```shell
dnf list available
```

## 搜索软件库中的 RPM 包 

用处：当你不知道你想要安装的软件的准确名称时，你可以用该命令来搜索软件包。你需要在”search”参数后面键入软件的部分名称来搜索。（在本例中我们使用”nano”）

```shell
dnf search nano
```

## 查找某一文件的提供者 

用处：当你想要查看是哪个软件包提供了系统中的某一文件时，你可以使用这条命令。（在本例中，我们将查找”/bin/bash”这个文件的提供者）

```shell
dnf provides /bin/bash
```

## 查看软件包详情 

用处：当你想在安装某一个软件包之前查看它的详细信息时，这条命令可以帮到你。（在本例中，我们将查看”nano”这一软件包的详细信息）

```shell
dnf info nano
```

## 安装软件包 

用处：使用该命令，系统将会自动安装对应的软件及其所需的所有依赖（在本例中，我们将用该命令安装nano软件）

```shell
dnf install nano
```

## 升级软件包 

用处：该命令用于升级制定软件包（在本例中，我们将用命令升级”systemd”这一软件包）

```shell
dnf update systemd
```

## 检查系统软件包的更新 

用处：该命令用于检查系统中所有软件包的更新

```shell
dnf check-update
```

## 升级所有系统软件包 

用处：该命令用于升级系统中所有有可用升级的软件包

```shell
dnf update 或 dnf upgrade
```

## 删除软件包 

用处：删除系统中指定的软件包（在本例中我们将使用命令删除”nano”这一软件包）

```shell
dnf remove nano 或 dnf erase nano
```

## 删除无用孤立的软件包 

用处：当没有软件再依赖它们时，某一些用于解决特定软件依赖的软件包将会变得没有存在的意义，该命令就是用来自动移除这些没用的孤立软件包。

```shell
dnf autoremove
```

## 删除缓存的无用软件包 

用处：在使用 DNF 的过程中，会因为各种原因在系统中残留各种过时的文件和未完成的编译工程。我们可以使用该命令来删除这些没用的垃圾文件。

```shell
dnf clean all
```

## 获取有关某条命令的使用帮助 

用处：该命令用于获取有关某条命令的使用帮助（包括可用于该命令的参数和该命令的用途说明）（本例中我们将使用命令获取有关命令”clean”的使用帮助）

```shell
dnf help clean
```

## 查看所有的 DNF 命令及其用途 

用处：该命令用于列出所有的 DNF 命令及其用途

```shell
dnf help
```

## 查看 DNF 命令的执行历史 

用处：您可以使用该命令来查看您系统上 DNF 命令的执行历史。通过这个手段您可以知道在自您使用 DNF 开始有什么软件被安装和卸载。

```shell
dnf history
```

## 查看所有的软件包组 

用处：该命令用于列出所有的软件包组

```shell
dnf grouplist
```

## 安装一个软件包组 

用处：该命令用于安装一个软件包组（本例中，我们将用命令安装”Educational Software”这个软件包组）

```shell
dnf groupinstall ‘Educational Software’
```

## 升级一个软件包组中的软件包 

用处：该命令用于升级一个软件包组中的软件包（本例中，我们将用命令升级”Educational Software”这个软件包组中的软件）

```shell
dnf groupupdate ‘Educational Software’
```

## 删除一个软件包组 

用处：该命令用于删除一个软件包组（本例中，我们将用命令删除”Educational Software”这个软件包组）

```shell
dnf groupremove ‘Educational Software’
```

## 从特定的软件包库安装特定的软件 

用处：该命令用于从特定的软件包库安装特定的软件（本例中我们将使用命令从软件包库 epel 中安装 phpmyadmin 软件包）

```shell
dnf –enablerepo=epel install phpmyadmin
```

## 更新软件包到最新的稳定发行版 

用处：该命令可以通过所有可用的软件源将已经安装的所有软件包更新到最新的稳定发行版

```shell
dnf distro-sync
```

## 重新安装特定软件包 

用处：该命令用于重新安装特定软件包（本例中，我们将使用命令重新安装”nano”这个软件包）

```shell
dnf reinstall nano
```

## 回滚某个特定软件的版本 

```shell
dnf downgrade acpid
```
