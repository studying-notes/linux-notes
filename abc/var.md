# 系统变量

- [系统变量](#系统变量)
  - [概述](#概述)
  - [命令执行过程](#命令执行过程)
  - [最常见的几个环境变量](#最常见的几个环境变量)
  - [重置 PATH](#重置-path)

## 概述

**变量是计算机系统用于保存可变值的数据类型**。在 Linux 系统中，**变量名称一般都是大写的**，这是一种约定俗成的规范。我们可以直接通过变量名称来提取到对应的变量值。

Linux 系统中的环境变量是用来**定义系统运行环境的一些参数**，比如每个用户不同的主目录、邮件存放位置等。为了通过环境变量帮助 Linux 系统构建起能够为用户提供服务的工作运行环境，需要数百个变量协同工作才能完成。

**在 Linux 系统中一切都是文件，Linux 命令也不例外。**

## 命令执行过程

那么，在用户执行了一条命令之后，Linux 系统中到底发生了什么事情呢？命令在 Linux 中的执行分为 4 个步骤：

1. 判断用户是否以绝对路径或相对路径的方式输入命令，如果是的话则直接执行。

2. Linux 系统检查用户输入的命令是否为“别名命令”，即用一个自定义的命令名称来替换原本的命令名称。可以用 `alias` 命令来创建一个属于自己的命令别名，格式为 `alias 别名=命令`。若要取消一个命令别名，则是用 `unalias` 命令，格式为 `unalias 别名`。

3. 终端解释器判断用户输入的是内部命令还是外部命令。内部命令是解释器内部的指令，会被直接执行；而用户在绝大部分时间输入的是外部命令，这些命令交由步骤 4 继续处理。可以使用 `type 命令名称` 来判断用户输入的命令是内部命令还是外部命令。

```bash
$ type echo
echo is a shell builtin
```

```bash
$ type ps
ps is /bin/ps
```

```bash
$ type docker
docker is /usr/bin/docker
```

4. 系统在多个路径中查找用户输入的命令文件，而定义这些路径的变量叫作 PATH，作用是告诉终端解释器待执行的命令可能存放的位置，然后终端解释器就会在这些位置中逐个查找。PATH 是由多个路径值组成的变量，每个路径值之间用冒号间隔，对这些路径的增加和删除操作将影响到终端解释器对 Linux 命令的查找。

```bash
$ echo $PATH
/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin
```

```bash
$ PATH=$PATH:/root/bin
$ echo $PATH
/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin:/root/bin

$ echo "export PATH=$PATH:/usr/local/go/bin" >> ~/.profile && source ~/.profile
```

## 最常见的几个环境变量

| 名称 | 作用 |
| --------- | --------- |
| HOME | 用户的主目录 |
| SHELL | 用户终端解释器名称 |
| HISTSIZE | 输出的历史命令记录条数 |
| HISTFILESIZE | 保存的历史命令记录条数 |
| MAIL | 邮件保存路径 |
| LANG | 系统语言名称 |
| RANDOM | 生成一个随机数字 |
| PS1 |终端|
| PATH | 定义解释器搜索用户执行命令的路径 |
| EDITOR | 用户默认的文本编辑器 |

Linux 作为一个多用户多任务的操作系统，能够为每个用户提供独立的、合适的工作运行环境，一个相同的变量可能会因为用户身份的不同而具有不同的值。

## 重置 PATH

```
PATH=$(getconf PATH)
```

```
export PATH=/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin:/root/bin
```
