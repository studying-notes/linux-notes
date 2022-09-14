---
date: 2020-10-20 09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

title: "find 在指定目录下查找文件"  # 文章标题
url:  "posts/linux/docs/cli/FileAndDirectoryManagement/find"  # 设置网页永久链接
tags: [ "linux", "find" ]  # 标签
categories: [ "Linux 学习笔记" ]  # 分类

toc: true  # 目录
draft: true  # 草稿
---

> 在指定目录下查找文件

**find 命令** 用来在指定目录下查找文件。任何位于参数之前的字符串都将被视为欲查找的目录名。

如果使用该命令时，不设置任何参数，则 find 命令将在当前目录下查找子目录与文件。并且将查找到的子目录和文件全部进行显示。

- [格式](#格式)
  - [选项](#选项)
  - [参数](#参数)
- [示例](#示例)
- [高级用法](#高级用法)
  - [根据文件或者正则表达式进行匹配](#根据文件或者正则表达式进行匹配)
  - [否定参数](#否定参数)
  - [根据文件类型进行搜索](#根据文件类型进行搜索)
  - [基于目录深度搜索](#基于目录深度搜索)
  - [根据文件时间戳进行搜索](#根据文件时间戳进行搜索)
  - [根据文件大小进行匹配](#根据文件大小进行匹配)
  - [删除匹配文件](#删除匹配文件)
  - [根据文件权限/所有权进行匹配](#根据文件权限所有权进行匹配)
  - [借助`-exec`选项与其他命令结合使用](#借助-exec选项与其他命令结合使用)
  - [搜索但跳过指定的目录](#搜索但跳过指定的目录)
  - [列出所有长度为零的文件](#列出所有长度为零的文件)

## 格式

```bash
find [-H] [-L] [-P] [-Olevel] [-D debugopts] [path...] [expression]
```

### 选项

| 参数 | 作用 |
| -------- | -------- |
| -name | 匹配名称 |
| -perm | 匹配权限，`mode` 为完全匹配，`-mode` 为包含即可 |
| -user | 匹配所有者 |
| -group | 匹配所有组 |
| -mtime `-n +n` | 匹配修改内容的时间，`-n` 指 n 天以内，`+n` 指 n 天以前 |
| -atime `-n +n` | 匹配访问文件的时间，`-n` 指 n 天以内，`+n` 指 n 天以前 |
| -ctime `-n +n` | 匹配修改文件权限的时间，`-n` 指 n 天以内，`+n` 指 n 天以前 |
| -nouser | 匹配无所有者的文件 |
| -nogroup | 匹配无所有组的文件 |
| -newer `f1 ! f2` | 匹配比文件 `f1` 新但比 `f2` 旧的文件 |
| --type `b/d/c/p/l/f` | 匹配文件类型，字母参数依次表示块设备、目录、字符设备、管道、链接文件、文本文件 |
| -size | 匹配文件的大小，`+50KB` 为查找超过 50KB 的文件，而 ` -50KB` 为查找小于 50KB 的文件 |
| -prune | 忽略某个目录 |
| -exec | 后面可跟用于进一步处理搜索结果的命令 |

### 参数

- `path` 参数默认为当前目录
- `expression` 参数默认为 `-print`

## 示例

1. 获取目录中所以以 host 开头的文件列表

```bash
find /etc -name "host*" -print
/etc/hosts.deny
/etc/cloud/templates/hosts.debian.tmpl
/etc/cloud/templates/hosts.suse.tmpl
/etc/cloud/templates/hosts.redhat.tmpl
/etc/cloud/templates/hosts.freebsd.tmpl
/etc/host.conf
/etc/hosts.allow
/etc/hosts
/etc/hostname
```

2. 搜索包括 SUID 权限的文件

```bash
find /etc -perm -4000
```

3. 找出所有权是指定用户的文件，然后复制到指定目录

```bash
find /root -user root -exec cp -a {} /tmp/ \;
```

## 高级用法

### 根据文件或者正则表达式进行匹配

列出当前目录及子目录下所有文件和文件夹

```shell
find .
```

在`/home`目录下查找以.txt结尾的文件名

```shell
find /home -name "*.txt"
```

同上，但忽略大小写

```shell
find /home -iname "*.txt"
```

当前目录及子目录下查找所有以.txt和.pdf结尾的文件

```shell
find . \( -name "*.txt" -o -name "*.pdf" \)

或

find . -name "*.txt" -o -name "*.pdf"
```

匹配文件路径或者文件

```shell
find /usr/ -path "*local*"
```

基于正则表达式匹配文件路径

```shell
find . -regex ".*\(\.txt\|\.pdf\)$"
```

同上，但忽略大小写

```shell
find . -iregex ".*\(\.txt\|\.pdf\)$"
```

### 否定参数

找出/home下不是以.txt结尾的文件

```shell
find /home ! -name "*.txt"
```

### 根据文件类型进行搜索

```shell
find . -type 类型参数
```

类型参数列表：

*    **f**  普通文件
*    **l**  符号连接
*    **d**  目录
*    **c**  字符设备
*    **b**  块设备
*    **s**  套接字
*    **p**  Fifo

### 基于目录深度搜索

向下最大深度限制为3

```shell
find . -maxdepth 3 -type f
```

搜索出深度距离当前目录至少2个子目录的所有文件

```shell
find . -mindepth 2 -type f
```

### 根据文件时间戳进行搜索

```shell
find . -type f 时间戳
```

UNIX/Linux文件系统每个文件都有三种时间戳：

*    **访问时间** （-atime/天，-amin/分钟）：用户最近一次访问时间。
*    **修改时间** （-mtime/天，-mmin/分钟）：文件最后一次修改时间。
*    **变化时间** （-ctime/天，-cmin/分钟）：文件数据元（例如权限等）最后一次修改时间。

搜索最近七天内被访问过的所有文件

```shell
find . -type f -atime -7
```

搜索恰好在七天前被访问过的所有文件

```shell
find . -type f -atime 7
```

搜索超过七天内被访问过的所有文件

```shell
find . -type f -atime +7
```

搜索访问时间超过10分钟的所有文件

```shell
find . -type f -amin +10
```

找出比file.log修改时间更长的所有文件

```shell
find . -type f -newer file.log
```

### 根据文件大小进行匹配

```shell
find . -type f -size 文件大小单元
```

文件大小单元：

*    **b**  —— 块（512字节）
*    **c**  —— 字节
*    **w**  —— 字（2字节）
*    **k**  —— 千字节
*    **M**  —— 兆字节
*    **G**  —— 吉字节

搜索大于10KB的文件

```shell
find . -type f -size +10k
```

搜索小于10KB的文件

```shell
find . -type f -size -10k
```

搜索等于10KB的文件

```shell
find . -type f -size 10k
```

### 删除匹配文件

删除当前目录下所有.txt文件

```shell
find . -type f -name "*.txt" -delete
```

### 根据文件权限/所有权进行匹配

当前目录下搜索出权限为777的文件

```shell
find . -type f -perm 777
```

找出当前目录下权限不是644的php文件

```shell
find . -type f -name "*.php" ! -perm 644
```

找出当前目录用户tom拥有的所有文件

```shell
find . -type f -user tom
```

找出当前目录用户组sunk拥有的所有文件

```shell
find . -type f -group sunk
```

### 借助`-exec`选项与其他命令结合使用

找出当前目录下所有root的文件，并把所有权更改为用户tom

```shell
find .-type f -user root -exec chown tom {} \;
```

上例中， **{}**  用于与 **-exec** 选项结合使用来匹配所有文件，然后会被替换为相应的文件名。

找出自己家目录下所有的.txt文件并删除

```shell
find $HOME/. -name "*.txt" -ok rm {} \;
```

上例中， **-ok** 和 **-exec** 行为一样，不过它会给出提示，是否执行相应的操作。

查找当前目录下所有.txt文件并把他们拼接起来写入到all.txt文件中

```shell
find . -type f -name "*.txt" -exec cat {} \;> /all.txt
```

将30天前的.log文件移动到old目录中

```shell
find . -type f -mtime +30 -name "*.log" -exec cp {} old \;
```

找出当前目录下所有.txt文件并以“File:文件名”的形式打印出来

```shell
find . -type f -name "*.txt" -exec printf "File: %s\n" {} \;
```

因为单行命令中-exec参数中无法使用多个命令，以下方法可以实现在-exec之后接受多条命令

```shell
-exec ./text.sh {} \;
```

### 搜索但跳过指定的目录

查找当前目录或者子目录下所有.txt文件，但是跳过子目录sk

```shell
find . -path "./sk" -prune -o -name "*.txt" -print
```

> :warning: ./sk 不能写成 ./sk/ ，否则没有作用。

忽略两个目录

```shell
find . \( -path ./sk -o  -path ./st \) -prune -o -name "*.txt" -print
```

> :warning: 如果写相对路径必须加上`./`

### 列出所有长度为零的文件

```shell
find . -empty
```
