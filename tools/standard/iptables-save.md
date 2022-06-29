---
date: 2022-06-29T13:57:35+08:00
author: "Rustle Karl"

title: "iptables-save 备份 iptables 的表配置"
url:  "posts/linux/tools/standard/iptables-save"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

**iptables-save 命令** 用于将 linux 内核中的 iptables 表导出到标准输出设备商，通常，使用 shell 中 I/O 重定向功能将其输出保存到指定文件中。

## 语法

```shell
iptables-save(选项)
```

## 选项

```shell
-c：指定要保存的iptables表时，保存当权的数据包计算器和字节计数器的值；
-t：指定要保存的表的名称。
```

## 实例

```shell
iptables-save -t filter > iptables.bak
```
