---
date: 2022-05-02T13:08:48+08:00
author: "Rustle Karl"

title: "Fish Shell 安装与主题切换"
url:  "posts/linux/quickstart/shell/fish"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## Ubuntu

### 添加源安装

```shell
apt-add-repository ppa:fish-shell/release-3 && apt update
```

```shell
apt install -y fish
```

## 简单设置

### 去掉欢迎语句

```shell
# 需进入 Fish 中设置才能生效。
set fish_greeting
```

```shell
fish -c "set -U fish_greeting"
```

### 设置别名，自定义变量

```shell
mkdir -p ~/.config/fish
```

```shell
cat > ~/.config/fish/config.fish <<EOF
alias apti='apt -y install'
alias aptr='apt -y remove'
alias apts='apt search'
alias aa='apt update -y ; apt upgrade -y ; apt autoremove -y'

alias get='git clone'
alias gad='git add'

alias curlip='curl ifconfig.me'
EOF
```

```shell
source ~/.config/fish/config.fish
```

### 修改默认终端

```shell
usermod -s `which fish`  root
```

恢复默认终端：

```shell
usermod -s `which bash`  root
```

## oh-my-fish

> 折腾后发现还是默认最好看。。。

### 代理设置

```shell
git config --global http.https://github.com.proxy ubuntu-amd64:8118
git config --global --unset http.https://github.com.proxy
```

### 安装

```shell
curl -x ubuntu-amd64:8118 https://raw.githubusercontent.com/oh-my-fish/oh-my-fish/master/bin/install | fish
```

### 基本用法

```shell
# 列出已安装的和可安装的主题
omf theme
# 安装 ays 主题
omf install ays
# 更换主题为已安装的 cbjohnson 主题
omf theme cbjohnson
# 检查 omf 是否有错误
omf doctor
# 卸载 omf
omf destroy
```
