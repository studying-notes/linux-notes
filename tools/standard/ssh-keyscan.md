---
date: 2022-06-29T14:08:03+08:00
author: "Rustle Karl"

title: "ssh-keyscan 收集主机公钥的使用工具"
url:  "posts/linux/tools/standard/ssh-keyscan"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 补充说明

**ssh-keyscan 命令** 是一个收集大量主机公钥的使用工具。

## 语法

```shell
ssh-keyscan(选项)(参数)
```

### 选项

```shell
-4：强制使用IPv4地址；
-6：强制使用IPv6地址；
-f：从指定文件中读取“地址列表/名字列表”；
-p：指定连接远程主机的端口；
-T：指定连接尝试的超时时间；
-t：指定要创建的密钥类型；
-v：信息模式，打印调试信息。
```

## 参数

主机列表：指定要收集公钥的主机列表。
