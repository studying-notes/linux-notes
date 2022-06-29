---
date: 2022-06-29T14:10:31+08:00
author: "Rustle Karl"

title: "ssh-agent SSH 密钥管理器"
url:  "posts/linux/tools/standard/ssh-agent"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

**ssh-agent 命令** 是一种控制用来保存公钥身份验证所使用的私钥的程序。ssh-agent 在 X 会话或登录会话之初启动，所有其他窗口或程序则以客户端程序的身份启动并加入到 ssh-agent 程序中。通过使用环境变量，可定位代理并在登录到其他使用 ssh 机器上时使用代理自动进行身份验证。

其实 ssh-agent 就是一个密钥管理器，运行 ssh-agent 以后，使用 ssh-add 将私钥交给 ssh-agent 保管，其他程序需要身份验证的时候可以将验证申请交给 ssh-agent 来完成整个认证过程。

## 语法

```shell
ssh-agent [-c | -s] [-d] [-a bind_address] [-t life] [command [arg ...]]
ssh-agent [-c | -s] -k
```

## 选项

```shell
-a bind_address：bind the agent to the UNIX-domain socket bind_address.
-c：生成C-shell风格的命令输出。
-d：调试模式。
-k：把ssh-agent进程杀掉。
-s：生成Bourne shell 风格的命令输出。
-t life：设置默认值添加到代理人的身份最大寿命。
```

## 实例

运行ssh-agent：

```shell
ssh-agent
```

运行ssh-agent，它会打印出来它使用的环境和变量。
