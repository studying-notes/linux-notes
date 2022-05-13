---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "grep 搜索匹配关键词"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/grep"  # 设置网页永久链接
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

> 在文本中搜索匹配的关键词，显示结果

## 格式

```bash
grep [OPTION]... PATTERN [FILE]...
```

## 参数

### Pattern selection and interpretation

| 参数 | 作用 |
| -------- | -------- |
| -E, --extended-regexp | PATTERN is an extended regular expression |
| -F, --fixed-strings | PATTERN is a set of newline-separated strings |
| -G, --basic-regexp | PATTERN is a basic regular expression (default) |
| -P, --perl-regexp | PATTERN is a Perl regular expression |
| -e, --regexp = PATTERN | use PATTERN for matching |
| -f, --file = FILE | obtain PATTERN from FILE |
| -i, --ignore-case | ignore case distinctions |
| -w, --word-regexp | force PATTERN to match only whole words |
| -x, --line-regexp | force PATTERN to match only whole lines |
| -z, --null-data | a data line ends in 0 byte, not newline |

### Miscellaneous

| 参数 | 作用 |
| -------- | -------- |
| -s, --no-messages | suppress error messages |
| -v, --invert-match | select non-matching lines |
| -V, --version | display version information and exit |
| --help | display this help text and exit |

### Output control

| 参数 | 作用 |
| -------- | -------- |
| -m, --max-count = NUM | stop after NUM selected lines |
| -b, --byte-offset | print the byte offset with output lines |
| -n, --line-number | print line number with output lines |
| --line-buffered | flush output on every line |
| -H, --with-filename | print file name with output lines |
| -h, --no-filename | suppress the file name prefix on output |
| --label = LABEL | use LABEL as the standard input file name prefix |
| -o, --only-matching | show only the part of a line matching PATTERN |
| -q, --quiet, --silent | suppress all normal output |
| --binary-files = TYPE | assume that binary files are TYPE ; TYPE is 'binary', 'text', or 'without-match' |
| -a, --text | equivalent to --binary-files = text |
| -I | equivalent to --binary-files = without-match |
| -d, --directories = ACTION | how to handle directories ; ACTION is 'read', 'recurse', or 'skip' |
| -D, --devices = ACTION | how to handle devices, FIFOs and sockets ; ACTION is 'read' or 'skip' |
| -r, --recursive | like --directories = recurse |
| -R, --dereference-recursive | likewise, but follow all symlinks |
| --include = FILE_PATTERN | search only files that match FILE_PATTERN |
| --exclude = FILE_PATTERN | skip files and directories matching FILE_PATTERN |
| --exclude-from = FILE | skip files matching any file pattern from FILE |
| --exclude-dir = PATTERN | directories that match PATTERN will be skipped. |
| -L, --files-without-match | print only names of FILEs with no selected lines |
| -l, --files-with-matches | print only names of FILEs with selected lines |
| -c, --count | print only a count of selected lines per FILE |
| -T, --initial-tab | make tabs line up (if needed) |
| -Z, --null | print 0 byte after FILE name |

### Context control

| 参数 | 作用 |
| -------- | -------- |
| -B, --before-context = NUM | print NUM lines of leading context |
| -A, --after-context = NUM | print NUM lines of trailing context |
| -C, --context = NUM | print NUM lines of output context |
| -NUM | same as --context = NUM |
| --color[ = WHEN], --colour[ = WHEN] | use markers to highlight the matching strings ; WHEN is 'always', 'never', or 'auto' |
| -U, --binary | do not strip CR characters at EOL (MSDOS/Windows) |

## 示例

1. 显示匹配结果的行号

```bash
echo -e "abc\ndef\nghi\njkl" > demo
cat demo
abc
def
ghi
jkl

grep -n ghi demo
3:ghi
```

2. 反选匹配结果

```bash
grep -nv ghi demo
1:abc
2:def
4:jkl
```

3. 在 Linux 系统中，`/etc/passwd` 文件保存着所有用户的信息，而一旦用户的登录终端被设置成 `/sbin/nologin`，则表示不允许登录系统，因此可以使用 `grep` 命令来查找出当前系统中不允许登录系统的所有用户信息：

```bash
grep /sbin/nologin /etc/passwd
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sshd:x:107:65534::/run/sshd:/usr/sbin/nologin
```
