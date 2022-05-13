---
date: 2022-05-13T14:00:16+08:00
author: "Rustle Karl"

title: "nohup 以忽略挂起信号的方式运行程序"
url:  "posts/linux/tools/standard/nohup"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 可以将程序以忽略挂起信号的方式运行起来，被运行的程序的输出信息将不会显示到终端

## 格式

```shell
nohup OPTION
```

## 示例

```shell
nohup ping www.baidu.com &
```

```shell
nohup ping www.baidu.com >ping_baidu.txt &
```

```shell
nohup ping www.baidu.omc >ping_baidu.txt 1>&2 &
```

```shell
nohup ping www.baidu.com >/dev/null 1>&2 &
```
