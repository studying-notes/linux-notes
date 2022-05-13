---
date: 2022-05-13T14:07:30+08:00
author: "Rustle Karl"

title: "disown 从作业中移除"
url:  "posts/linux/tools/standard/disown"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 从作业中移除，实现后台运行程序

## 示例

如果命令之前忘记加 nohup，而命令运行一半，通过作业调度和 disown 解决，如下所示：

```shell
ping www.baidu.com > output.txt

# 执行 bg 把该作业放到后台
bg %1

# 查看
jobs 

# 执行 disown 命令，从作业中移除，不能用 jobs 查看
disown -h %1 

ps -ef | grep ping 可以查看
```
