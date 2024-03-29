---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "file 确定文件类型"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/file"  # 设置网页永久链接
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

> 确定文件类型

## 格式

```bash
file [OPTION...] [FILE...]
```

- 在 Linux 系统中，由于文本、目录、设备等所有这些一切都统称为文件，而我们又不能单凭后缀就知道具体的文件类型，这时就需要使用 `file` 命令来查看文件类型了。

## 参数

| 参数 | 作用 |
| -------- | -------- |
| --help | display this help and exit |
| -v, --version | output version information and exit |
| -m, --magic-file LIST | use LIST as a colon-separated list of magic number files |
| -z, --uncompress | try to look inside compressed files |
| -Z, --uncompress-noreport | only print the contents of compressed files |
| -b, --brief | do not prepend filenames to output lines |
| -c, --checking-printout | print the parsed form of the magic file, use in conjunction with -m to debug a new magic file before installing it |
| -e, --exclude TEST | exclude TEST from the list of test to be performed for file. Valid tests are: apptype, ascii, cdf, compress, elf, encoding, soft, tar, text, tokens |
| -f, --files-from FILE | read the filenames to be examined from FILE |
| -F, --separator STRING | use string as separator instead of `:' |
| -i, --mime | output MIME type strings (--mime-type and --mime-encoding) |
| --apple | output the Apple CREATOR/TYPE |
| --extension | output a slash-separated list of extensions |
| --mime-type | output the MIME type |
| --mime-encoding | output the MIME encoding |
| -k, --keep-going | don't stop at the first match |
| -l, --list | list magic strength |
| -L, --dereference | follow symlinks (default if POSIXLY_CORRECT is set) |
| -h, --no-dereference | don't follow symlinks (default if POSIXLY_CORRECT is not set) (default) |
| -n, --no-buffer | do not buffer output |
| -N, --no-pad | do not pad output |
| -0, --print0 | terminate filenames with ASCII NUL |
| -p, --preserve-date | preserve access times on files |
| -P, --parameter | set file engine parameter limits: indir -15 recursion limit for indirection ; name -30 use limit for name/use magic ; elf_notes -256 max ELF notes processed ; elf_phnum -128 max ELF prog sections processed ; elf_shnum -32768 max ELF sections processed |
| -r, --raw | don't translate unprintable chars to \ooo |
| -s, --special-files | treat special (block/char devices) files as ordinary ones |
| -C, --compile | compile file specified by -m |
| -d, --debug | print debugging messages |

## 示例

1. 确定文件类型

```bash
file /dev/zero
/dev/zero: character special (1/5)

file /dev
/dev: directory
```
