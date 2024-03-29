---
date: 2022-06-29T14:08:52+08:00
author: "Rustle Karl"

title: "ssh-keygen 为 ssh 生成、管理和转换认证密钥"
url:  "posts/linux/tools/standard/ssh-keygen"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

**ssh-keygen 命令** 用于为“ssh”生成、管理和转换认证密钥，它支持 RSA 和 DSA 两种认证密钥。

## 语法

```shell
ssh-keygen(选项)
```

## 选项

```shell
-b：指定密钥长度；
-e：读取openssh的私钥或者公钥文件；
-C：添加注释；
-f：指定用来保存密钥的文件名；
-i：读取未加密的ssh-v2兼容的私钥/公钥文件，然后在标准输出设备上显示openssh兼容的私钥/公钥；
-l：显示公钥文件的指纹数据；
-N：提供一个新密语；
-P：提供（旧）密语；
-q：静默模式；
-t：指定要创建的密钥类型。
```
