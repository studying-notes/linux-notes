---
date: 2022-06-29T13:57:25+08:00
author: "Rustle Karl"

title: "iptables-restore 还原 iptables 表的配置"
url:  "posts/linux/tools/standard/iptables-restore"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

**iptables-restore 命令** 用来还原 iptables-save 命令所备份的 iptables 配置。

## 语法

```shell
iptables-restore(选项)
```

## 选项

```shell
-c：指定在还原iptables表时候，还原当前的数据包计数器和字节计数器的值；
-t：指定要还原表的名称。
```

## 实例

```shell
iptables-restore < iptables.bak
```

iptables.bak 是 iptables-save 命令所备份的文件。
