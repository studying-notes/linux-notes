---
date: 2022-05-13T14:14:29+08:00
author: "Rustle Karl"

title: "screen 命令行终端切换"
url:  "posts/linux/tools/standard/screen"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 用户可以通过该软件同时连接多个本地或远程的命令行会话，并在其间自由切换。

**Screen** 是一款由 GNU 计划开发的用于命令行终端切换的自由软件。用户可以通过该软件同时连接多个本地或远程的命令行会话，并在其间自由切换。GNU Screen 可以看作是窗口管理器的命令行界面版本。它提供了统一的管理多个会话的界面和相应的功能。

只要 Screen 本身没有终止，在其内部运行的会话都可以恢复。这一点对于远程登录的用户特别有用——即使网络连接中断，用户也不会失去对已经打开的命令行会话的控制。只要再次登录到主机上执行 `screen -r` 就可以恢复会话的运行。同样在暂时离开的时候，也可以执行分离命令 detach，在保证里面的程序正常运行的情况下让 Screen 挂起（切换到后台）。这一点和图形界面下的 VNC 很相似。

在 Screen 环境下，所有的会话都独立的运行，并拥有各自的编号、输入、输出和窗口缓存。用户可以通过快捷键在不同的窗口下切换，并可以自由的重定向各个窗口的输入和输出。Screen 实现了基本的文本操作，如复制粘贴等；还提供了类似滚动条的功能，可以查看窗口状况的历史记录。窗口还可以被分区和命名，还可以监视后台窗口的活动。 会话共享 Screen 可以让一个或多个用户从不同终端多次登录一个会话，并共享会话的所有特性（比如可以看到完全相同的输出）。它同时提供了窗口访问权限的机制，可以对窗口进行密码保护。

- [安装](#安装)
- [格式](#格式)
- [选项](#选项)
- [示例](#示例)
  - [新建一个叫 prefect 的 session](#新建一个叫-prefect-的-session)
  - [查看窗口和窗口名称](#查看窗口和窗口名称)
  - [列出当前所有的 session](#列出当前所有的-session)
  - [回到 prefect 这个 session](#回到-prefect-这个-session)
  - [远程 detach 某个 session](#远程-detach-某个-session)
  - [结束当前 session 并回到 prefect 这个 session](#结束当前-session-并回到-prefect-这个-session)
  - [屏幕分割](#屏幕分割)

## 安装

```shell
apt install screen -y

yum install screen -y
```

## 格式

```shell
screen [-AmRvx -ls -wipe][-d <作业名称>][-h <行数>][-r <作业名称>][-s ][-S <作业名称>]
```

## 选项

-A 将所有的视窗都调整为目前终端机的大小
-d `< 作业名称 >` 将指定的 screen 作业离线
-h `< 行数 >` 指定视窗的缓冲区行数
-m 即使目前已在作业中的 screen 作业，仍强制建立新的 screen 作业
-r `< 作业名称 >` 恢复离线的 screen 作业
-R 先试图恢复离线的作业。若找不到离线的作业，即建立新的 screen 作业
-s 指定建立新视窗时，所要执行的 shell
-S `< 作业名称 >` 指定 screen 作业的名称
-v 显示版本信息
-x 恢复之前离线的 screen 作业
-ls 或 --list 显示目前所有的 screen 作业
-wipe 检查目前所有的 screen 作业，并删除已经无法使用的 screen 作业。

## 示例

### 新建一个叫 prefect 的 session

```shell
screen -S prefect
```

screen 启动后，会创建第一个窗口，也就是窗口 No. 0，并在其中打开一个系统默认的 shell，一般都会是 bash。所以你敲入命令 screen 之后，会立刻又返回到命令提示符，仿佛什么也没有发生似的。Screen 默认会为窗口命名为编号和窗口中运行程序名的组合。

可以使用快捷键 C-a A 来为当前窗口重命名，按下快捷键后，Screen 会允许你为当前窗口输入新的名字，回车确认。

### 查看窗口和窗口名称

打开多个窗口后，可以使用快捷键 C-a w 列出当前所有窗口。

### 列出当前所有的 session

```
screen -ls
```

### 回到 prefect 这个 session

```
screen -r prefect
```

### 远程 detach 某个 session

```
screen -d prefect
```

### 结束当前 session 并回到 prefect 这个 session

```
screen -d -r prefect
```

### 屏幕分割

- `ctrl+a shift+s` 将显示器水平分割
- `ctrl+a shift+|` 垂直分屏

可以使用 `ctrl+a tab` 在屏幕各个区块间切换，每一区块上都可以创建窗口 `ctrl+a c` 并在其中运行进程。

- `ctrl+a x` 关闭终端

