---
date: 2022-05-13T14:12:06+08:00
author: "Rustle Karl"

title: "setsid 让进程在新的会话中运行"
url:  "posts/linux/tools/standard/setsid"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 让进程在一个新的会话中运行，从而避开当前会话的 SIGHUP 信号

## 示例

```shell
setsid ping www.ibm.com 

ps -ef | grep www.ibm.com
```
