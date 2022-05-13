---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "ln 创建链接文件"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/ln"  # 设置网页永久链接
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

> 创建链接文件

## 格式

```bash
ln [OPTION]... [-T] TARGET LINK_NAME   (1st form)
ln [OPTION]... TARGET                  (2nd form)
ln [OPTION]... TARGET... DIRECTORY     (3rd form)
ln [OPTION]... -t DIRECTORY TARGET...  (4th form)
```

- In the 1st form, create a link to TARGET with the name LINK_NAME.
- In the 2nd form, create a link to TARGET in the current directory.
- In the 3rd and 4th forms, create links to each TARGET in DIRECTORY.
- Create hard links by default, symbolic links with `--symbolic`.
- By default, each destination (name of new link) should not already exist.
- When creating hard links, each TARGET must exist.  Symbolic links can hold arbitrary text; if later resolved, a relative link is interpreted in relation to its parent directory.

## 参数

| 参数 | 作用 |
| -------- | -------- |
| --backup[ = CONTROL] | make a backup of each existing destination file |
| -b | like --backup but does not accept an argument |
| -d, -F, --directory | allow the superuser to attempt to hard link directories (note: will probably fail due to system restrictions, even for the superuser) |
| -f, --force | remove existing destination files |
| -i, --interactive | prompt whether to remove destinations |
| -L, --logical | dereference TARGETs that are symbolic links |
| -n, --no-dereference | treat LINK_NAME as a normal file if it is a symbolic link to a directory |
| -P, --physical | make hard links directly to symbolic links |
| -r, --relative | create symbolic links relative to link location |
| -s, --symbolic | make symbolic links instead of hard links |
| -S, --suffix = SUFFIX | override the usual backup suffix |
| -t, --target-directory = DIRECTORY | specify the DIRECTORY in which to create the links |
| -T, --no-target-directory | treat LINK_NAME as a normal file always |
| -v, --verbose | print name of each linked file |
| --help | display this help and exit |
| --version | output version information and exit |

- The backup suffix is '~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.
- The version control method may be selected via the --backup option or through the VERSION_CONTROL environment variable.  Here are the values:

  - none, off       never make backups (even if --backup is given)
  - numbered, t     make numbered backups
  - existing, nil   numbered if numbered backups exist, simple otherwise
  - simple, never   always make simple backups

- Using -s ignores -L and -P.  Otherwise, the last option specified controls behavior when a TARGET is a symbolic link, defaulting to -P.

## 示例

1. 创建一个类似于 Windows 系统中快捷方式的软链接，当原始文件被删除后，就无法读取新建的链接文件了

```bash
echo "I love you!" > love
ln -s love loveln

cat love
I love you!

cat loveln
I love you!

rm -f love
cat loveln
cat: loveln: No such file or directory
```

2. 创建一个硬链接，即相当于针对原始文件的硬盘存储位置创建了一个指针，这样一来，新创建的这个硬链接就不再依赖于原始文件的名称等信息，也不会因为原始文件的删除而导致无法读取。同时可以看到创建硬链接后，原始文件的硬盘链接数量增加到了 2

```bash
echo "I love you!" > love
ln love loveln

cat love
I love you!

cat loveln
I love you!

ls -l love
-rw-r--r-- 2 root root 12 Jan 19 13:56 love

rm -f love
cat loveln
I love you!
```
