---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "alias 设置别名"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/alias"  # 设置网页永久链接
tags: [ "linux", "cmd" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

# 章节
weight: 20 # 排序优先级
chapter: false  # 设置为章节

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
----

> 设置别名

定义或显示别名。

## 用途

- 简化较长的命令。
- 定义一个或多个别名。
- 修改一个或多个已定义别名的值。
- 显示一个或多个已定义别名。
- 显示全部已定义的别名。

## 格式

```bash
alias [-p] [name[=value] ... ]
```

## 参数

| 参数 | 作用 |
| ---- | -------- |
| -p | 显示全部已定义的别名 |

## 选项

```shell
name（可选）：指定要（定义、修改、显示）的别名。
value（可选）：别名的值。
```

## 示例

1. 显示全部已设置的别名

```bash
alias
# or
alias -p
```

```
alias cls='clear'
alias egrep='egrep --color=auto'
alias fgrep='fgrep --color=auto'
alias grep='grep --color=auto'
alias l='ls -CF'
alias la='ls -A'
alias ll='ls -alF'
alias ls='ls --color=auto'
```

2. 设置别名

```bash
alias c='clear'

echo "alias c='clear'" >> ~/.profile
```

## 知识点

直接在shell里设定的命令别名，在终端关闭或者系统重新启动后都会失效，如何才能永久有效呢？

使用编辑器打开`~/.bashrc`，在文件中加入别名设置，如：`alias rm='rm -i'`，保存后执行`source ~/.bashrc`，这样就可以永久保存命令的别名了。

因为修改的是当前用户目录下的 `~ /.bashrc` 文件，所以这样的方式只对当前用户有用。如果要对所有用户都有效，修改 `/etc/bashrc` 文件就可以了。

> 请注意，以下内容可能与您实际使用的系统有出入:
>
> 在CentOS7下，这个文件是`/etc/bash.bashrc`。此外在CentOS7下，细看`~/.bashrc`文件，会发现有这样一段代码：
>
> ```shell
> if [ -f ~/.bash_aliases ]; then
>   . ~/.bash_aliases
> fi
> ```
>
> 这个代码的意思就是如果存在那么就加载 `.bash_aliases` 文件，所以也可以在用户根目录下新建该文件用于单独存放命令别名设置。

## 错误用法

- 要显示的别名未定义。
- 当您定义（修改）别名的值的时候，由于值的字符串有空格但您没有用**单引号扩起**，那么会导致严重的问题：

为方便演示，删除全部别名：

```shell
unalias -a
```

没有用单引号：

```shell
alias rm=rm -rf
```

执行命令后报错 `bash: alias: -rf: not found`，这时使用 alias 查看 rm 的别名时返回：

```shell
alias rm='rm'
```

仍然没有用单引号括起：

```shell
alias ls=ls --color=never
```

执行命令后看起来没有报错，使用 alias 查看全部别名会发现运行结果如下：

```shell
alias --color=never
alias ls='ls'
```

alias 处理时将它们看成了两组

## 注意

1. 执行脚本时请注意：
    - 使用 `source` 命令执行的 bash 脚本如果执行了 `alias` 或 `unalias` 命令，那么有可能会对终端环境的别名设置产生影响；终端环境的别名设置也可能改变运行结果；
    - 通过 `sh` 方式调用的 bash 脚本或直接运行当前用户有执行权限的脚本不受终端环境的别名影响。
2. 删除别名，请查看`unalias`命令。
3. 建议您不要对 `mv cp rm` 等命令的别名设置危险的 `-f` 选项，比如 `alias rm='rm -f'`。
4. 需要注意别名是否和其他命令有冲突的情况。
5. 该命令是 bash 内建命令，相关的帮助信息请查看 `help` 命令。

## 相关命令

- [unalias](unalias.md) - 取消别名
