---
date: 2020-11-23T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "chmod 设置文件或目录的权限"  # 文章标题
url:  "posts/linux/tools/standard/chmod"  # 设置网页永久链接
tags: [ "linux", "cmd" ]  # 标签
series: [ "Linux 学习笔记"]  # 系列
categories: [ "学习笔记"]  # 分类

# 章节
weight: 20 # 排序优先级
chapter: false  # 设置为章节

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
---

> 设置文件或目录的权限

## 格式

```bash
chmod [OPTION]... MODE[,MODE]... FILE...

chmod [OPTION]... OCTAL-MODE FILE...

chmod [OPTION]... --reference=RFILE FILE...
```

- MODE - [ugoa]*([-+=]([rwxXst]*|[ugo]))+|[-+=][0-7]+

## 主要用途

- 通过符号组合的方式更改目标文件或目录的权限。
- 通过八进制数的方式更改目标文件或目录的权限。
- 通过参考文件的权限来更改目标文件或目录的权限。

## 参数

- mode：八进制数或符号组合。
- file：指定要更改权限的一到多个文件。

## 选项 

```shell
-c, --changes：当文件的权限更改时输出操作信息。
--no-preserve-root：不将'/'特殊化处理，默认选项。
--preserve-root：不能在根目录下递归操作。
-f, --silent, --quiet：抑制多数错误消息的输出。
-v, --verbose：无论文件是否更改了权限，一律输出操作信息。
--reference=RFILE：使用参考文件或参考目录RFILE的权限来设置目标文件或目录的权限。
-R, --recursive：对目录以及目录下的文件递归执行更改权限操作。
--help：显示帮助信息并退出。
--version：显示版本信息并退出。
```

## 用户与权限

> - `u`符号代表当前用户。
> - `g`符号代表和当前用户在同一个组的用户，以下简称组用户。
> - `o`符号代表其他用户。
> - `a`符号代表所有用户。
> - `r`符号代表读权限以及八进制数`4`。
> - `w`符号代表写权限以及八进制数`2`。
> - `x`符号代表执行权限以及八进制数`1`。
> - `X`符号代表如果目标文件是可执行文件或目录，可给其设置可执行权限。
> - `s`符号代表设置权限suid和sgid，使用权限组合`u+s`设定文件的用户的ID位，`g+s`设置组用户ID位。
> - `t`符号代表只有目录或文件的所有者才可以删除目录下的文件。
> - `+`符号代表添加目标用户相应的权限。
> - `-`符号代表删除目标用户相应的权限。
> - `=`符号代表添加目标用户相应的权限，删除未提到的权限。

## 用户权限说明 

```shell
ls -la
```

```
-rw-r--r--   1 user  staff   651 Oct 12 12:53 .gitmodules
```

- 第 1 位如果是 d 则代表目录，是 - 则代表普通文件。
- 第 2 到 4 位代表当前用户的权限。
- 第 5 到 7 位代表组用户的权限。
- 第 8 到 10 位代表其他用户的权限。

## 示例

1. 赋予可执行权限

```bash
chmod +x example.sh
```

2. 递归赋予权限，忽略大部分错误信息

```bash
chmod -Rf 777 dir
```

3. 设置 SGID 特殊权限位

```bash
chmod -Rf g+s sharedir
ls -ld sharedir
drwxrwsrwx 2 root root 4096 Jan 15 18:28 sharedir
```

4. 设置 SBIT 特殊权限位

```bash
chmod -R o+t sharedir
ls -ld sharedir
drwxrwsrwt 2 root root 4096 Jan 15 18:28 sharedir
```

5. 全部赋予权限

```bash
chmod 777 *
```

### 添加组用户的写权限

```shell
chmod -R g+w config
```

### 添加其他用户的写权限

```shell
chmod -R o+w config
```

### 删除其他用户的所有权限

```shell
chmod o= ./test.log
# 使得所有用户都没有写权限。
chmod a-w ./test.log
# 当前用户具有所有权限，组用户有读写权限，其他用户只有读权限。
chmod u=rwx, g=rw, o=r ./test.log
# 等价的八进制数表示：
chmod 764 ./test.log
# 将目录以及目录下的文件都设置为所有用户拥有读写权限。
# 注意，使用'-R'选项一定要保留当前用户的执行和读取权限，否则会报错！
chmod -R a=rw ./testdir/
# 根据其他文件的权限设置文件权限。
chmod --reference=./1.log  ./test.log
```

## 注意

1. 该命令是`GNU coreutils`包中的命令，相关的帮助信息请查看`man chmod`或`info coreutils 'chmod invocation'`。

2. 符号连接的权限无法变更，如果用户对符号连接修改权限，其改变会作用在被连接的原始文件。

3. 使用`-R`选项一定要保留当前用户的执行和读取权限，否则会报错！
