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
- `tools`: 常用工具
  - `tools/standard`: 标准常用工具
  - `tools/tripartite`: 第三方常用工具
- `quickstart`: 基础用法
- `src`: 源码示例
  - `src/docs`: 基础语法源码示例

## 基础用法

### 安装配置

```
cinst rufus
```

- [Ubuntu 系统重装后的基本配置](quickstart/install/ubuntu_desktop.md)
- [Ubuntu 安装 Nvidai 显卡驱动](quickstart/install/ubuntu_desktop_nvidia.md)
- [OpenSSH 教程](quickstart/openssh.md)
- [Fish Shell 安装与主题切换](quickstart/shell/fish.md)
- [Ubuntu WSL 问题笔记](quickstart/install/ubuntu_wsl.md)
- [Kali Linux WSL 问题笔记](quickstart/install/kali_wsl.md)

## 常用工具

### 系统自带工具

- [alias 设置别名](tools/standard/alias.md)
- [at 设置一次性定时执行任务](tools/standard/at.md)
- [awk 文本处理](tools/standard/awk.md)
- [chattr 设置文件的隐藏权限](tools/standard/chattr.md)
- [unalias 取消别名](tools/standard/unalias.md)
- [cat 打印到标准输出](tools/standard/cat.md)
- [cd 改变当前工作目录](tools/standard/cd.md)
- [chmod 设置文件或目录的权限](tools/standard/chmod.md)
- [chown 设置文件或目录的所有者和所属组](tools/standard/chown.md)
- [chsh 更改登录 Shell](tools/standard/chsh.md)
- [cp 复制](tools/standard/cp.md)
- [crontab 设置长期性计划任务](tools/standard/crontab.md)
- [ctrlaltdel 设置组合键 `Ctrl+Alt+Del` 的功能](tools/standard/ctrlaltdel.md)
- [cut 按列提取文本字符](tools/standard/cut.md)
- [date 打印或者设置系统日期和时间](tools/standard/date.md)
- [dd 复制文件或转换文件](tools/standard/dd.md)
- [df 显示文件系统的信息](tools/standard/df.md)
- [diff 按行比较多个文本文件的内容差异](tools/standard/diff.md)
- [disown 从作业中移除](tools/standard/disown.md)
- [du 查看磁盘使用情况](tools/standard/du.md)
- [e2fsck 检查文件系统的完整性](tools/standard/e2fsck.md)
- [echo 在标准输出回显字符串](tools/standard/echo.md)
- [edquota 编辑用户的 quota 配额限制](tools/standard/edquota.md)
- [export 在当前会话修改环境变量](tools/standard/export.md)
- [fdisk 管理硬盘设备](tools/standard/fdisk.md)
- [file 确定文件类型](tools/standard/file.md)
- [find 按照指定条件查找文件](tools/standard/find.md)
- [getfacl 显示文件上设置的 ACL 信息](tools/standard/getfacl.md)
- [groupadd 创建新的用户组](tools/standard/groupadd.md)
- [halt 中断系统](tools/standard/halt.md)
- [head 打印文件前几行](tools/standard/head.md)
- [history 显示、管理以前执行过的命令](tools/standard/history.md)
- [free 查询内存资源信息](tools/standard/free.md)
- [grep 搜索匹配关键词](tools/standard/grep.md)
- [ifconfig 获取网卡配置与网络状态等信息](tools/standard/ifconfig.md)
- [id 显示指定用户的相关信息](tools/standard/id.md)
- [kill 终止进程](tools/standard/kill.md)
- [killall 终止指定名称的全部进程](tools/standard/killall.md)
- [ln 创建链接文件](tools/standard/ln.md)
- [last 显示用户的登录日志](tools/standard/last.md)
- [lsattr 显示文件的隐藏权限](tools/standard/lsattr.md)
- [ls 列出目录下文件的权限和属性信息](tools/standard/ls.md)
- [lsof 列出当前系统打开的文件](tools/standard/lsof.md)
- [mkdir 创建目录](tools/standard/mkdir.md)
- [mkfs 格式化硬盘，创建文件系统](tools/standard/mkfs.md)
- [mv 移动，重命名](tools/standard/mv.md)
- [nohup 以忽略挂起信号的方式运行程序](tools/standard/nohup.md)
- [passwd 修改用户名密码](tools/standard/passwd.md)
- [pidof 打印指定进程名称的全部 PID 值](tools/standard/pidof.md)
- [poweroff 关闭操作系统，切断系统电源](tools/standard/poweroff.md)
- [ps 显示系统进程状态](tools/standard/ps.md)
- [pwd 输出当前工作目录](tools/standard/pwd.md)
- [reboot 重启系统](tools/standard/reboot.md)
- [rm 移除项目](tools/standard/rm.md)
- [scp 在网络之间进行安全传输数据](tools/standard/scp.md)
- [screen 命令行终端切换](tools/standard/screen.md)
- [setsid 让进程在新的会话中运行](tools/standard/setsid.md)
- [shutdown 关闭操作系统](tools/standard/shutdown.md)
- [source 在当前终端执行来自一个文件的命令](tools/standard/source.md)
- [sudo 给普通用户提供额外的权限](tools/standard/sudo.md)
- [tail 打印文件最后几行](tools/standard/tail.md)
- [tmux 运行多个终端会话](tools/standard/tmux.md)
- [top 进程活动监视](tools/standard/top.md)
- [touch 创建空白文件](tools/standard/touch.md)
- [umount 卸载文件系统](tools/standard/umount.md)
- [userdel 删除用户](tools/standard/userdel.md)
- [su 切换用户](tools/standard/su.md)
- [stat 查询文件、文件系统状态信息](tools/standard/stat.md)
- [swapon 挂载 swap 分区](tools/standard/swapon.md)
- [tr 字符替换](tools/standard/tr.md)
- [tar 对文件进行打包压缩或解压](tools/standard/tar.md)
- [useradd 创建新的用户](tools/standard/useradd.md)
- [uptime 查询系统负载信息](tools/standard/uptime.md)
- [uname 获取当前系统信息](tools/standard/uname.md)
- [usermod 修改用户的属性](tools/standard/usermod.md)
- [wget 非交互式网络下载器](tools/standard/wget.md)
- [wc 统计指定文本的行数、单词数、字符数、字节数等](tools/standard/wc.md)
- [whereis 定位文件位置](tools/standard/whereis.md)
- [which 定位可执行命令的位置](tools/standard/which.md)
- [who 显示当前用户名及其启动的终端信息](tools/standard/who.md)

### 第三方工具

- [hdparm 硬盘测试](tools/tripartite/hdparm.md)
- [rsync 同步文件](tools/tripartite/rsync.md)

### 常用软件

- [proxychains 与 graftcp 原理对比](quickstart/software/proxychains_graftcp.md)
- [root 用户启动 google chrome](quickstart/software/google-chrome.md)

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
