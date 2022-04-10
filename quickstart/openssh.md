---
date: 2022-04-10T13:36:06+08:00
author: "Rustle Karl"

title: "OpenSSH 教程"
url:  "posts/linux/quickstart/openssh"  # 永久链接
tags: [ "Linux", "README" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 配置公钥仍询问密码的问题

首先查看日志，看看能否发现问题原因：

```shell
journalctl --unit=sshd
```

```
Authentication refused: bad ownership or modes for file /home/admin/.ssh/authorized_
```

文件权限设置异常，ssh 出于安全性考虑，对 .ssh 目录下的文件权限内容有着严格的权限要求，如下：

```shell
drwx------  2 root root 4096 Apr 10 12:41 ./
drwx------ 22 root root 4096 Apr 10 12:33 ../
-rw-------  1 root root 2178 Apr 10 13:29 authorized_keys
```

文件 authorized_keys 除了属主拥有读写 (-rw) 权限以外属组和其他用户是没有任何权限的。

由于 authorized_keys 这个文件是从其他地方复制过来的，导致权限不符合。因此 ssh 在比对秘钥的时候无法打开 authorized_keys 从而导致秘钥配对失败。而 ssh 此时没有放弃连接，尝试询问用户密码。最终产生了用户配置了公钥却仍然需要输入密码的问题。

知道问题原因后处理起来也比较简单了，只需修改相对应的目录权限即可：

```shell
cd ~/.ssh
chmod 700 ../
chmod 700 .
chmod 600 authorized_keys
```

```shell

```
