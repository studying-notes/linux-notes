---
date: 2022-05-13T14:14:29+08:00
author: "Rustle Karl"

title: "screen 命令行终端切换"
url:  "posts/linux/tools/standard/screen"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 用户可以通过该软件同时连接多个本地或远程的命令行会话，并在其间自由切换。

## 格式

```shell
screen [-AmRvx -ls -wipe][-d <作业名称>][-h <行数>][-r <作业名称>][-s ][-S <作业名称>]
```

## 选项

-A 将所有的视窗都调整为目前终端机的大小
-d `< 作业名称 >` 将指定的 screen 作业离线
-h `< 行数 >` 指定视窗的缓冲区行数
-m 即使目前已在作业中的 screen 作业，仍强制建立新的 screen 作业
-r `< 作业名称 >` 恢复离线的 screen 作业
-R 先试图恢复离线的作业。若找不到离线的作业，即建立新的 screen 作业
-s 指定建立新视窗时，所要执行的 shell
-S `< 作业名称 >` 指定 screen 作业的名称
-v 显示版本信息
-x 恢复之前离线的 screen 作业
-ls 或 --list 显示目前所有的 screen 作业
-wipe 检查目前所有的 screen 作业，并删除已经无法使用的 screen 作业。

## 示例

### 新建一个叫 yourname 的 session

```shell
screen -S yourname
```

### 列出当前所有的 session

```
screen -ls
```

### 回到 yourname 这个 session

```
screen -r yourname
```

### 远程 detach 某个 session

```
screen -d yourname
```

### 结束当前 session 并回到 yourname 这个 session

```
screen -d -r yourname
```
