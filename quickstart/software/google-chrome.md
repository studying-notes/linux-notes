---
date: 2022-05-08T10:01:38+08:00
author: "Rustle Karl"

title: "root 用户启动 google chrome"
url:  "posts/linux/quickstart/software/google-chrome"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 编辑启动项

```shell
vim /usr/share/applications/google-chrome.desktop
```

```shell
Exec=/usr/bin/google-chrome-stable --no-sandbox
```

## 设置代理

```shell
/usr/bin/google-chrome-stable --no-sandbox --proxy-server="socks5://127.0.0.1:8118"
```
