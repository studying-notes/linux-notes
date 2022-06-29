---
date: 2022-06-29T14:09:41+08:00
author: "Rustle Karl"

title: "ssh-copy-id 把本地的 ssh 公钥文件安装到远程主机对应的账户下"
url:  "posts/linux/tools/standard/ssh-copy-id"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

**ssh-copy-id命令** 可以把本地主机的公钥复制到远程主机的 authorized_keys 文件上，ssh-copy-id 命令也会给远程主机的用户主目录（home）和`~/.ssh`, 和`~/.ssh/authorized_keys`设置合适的权限。

## 语法

```shell
ssh-copy-id [-i [identity_file]] [user@]machine
```

## 选项

```shell
-i：指定公钥文件
```

## 实例

1、把本地的ssh公钥文件安装到远程主机对应的账户下：

```shell
ssh-copy-id user@server
```

```shell
ssh-copy-id -i ~/.ssh/id_rsa.pub user@server
```
