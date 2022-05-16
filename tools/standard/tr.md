---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "tr 字符替换"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/tr"  # 设置网页永久链接
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

> 字符替换

## 格式

```bash
tr [OPTION]... SET1 [SET2]
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -c, -C, --complement | use the complement of SET1 |
| -d, --delete | delete characters in SET1, do not translate |
| -s, --squeeze-repeats | replace each sequence of a repeated character that is listed in the last specified SET, with a single occurrence of that character |
| -t, --truncate-set1 | first truncate SET1 to length of SET2 |
| --help | display this help and exit |
| --version | output version information and exit |

## 正则表达式

| 表达式 | 含义 |
| -------- | -------- |
| \NNN | character with octal value NNN (1 to 3 octal digits) |
| \\ | backslash |
| \a | audible BEL |
| \b | backspace |
| \f | form feed |
| \n | new line |
| \r | return |
| \t | horizontal tab |
| \v | vertical tab |
| CHAR1-CHAR2 | all characters from CHAR1 to CHAR2 in ascending order |
| [CHAR * ] | in SET2, copies of CHAR until length of SET1 |
| [CHAR * REPEAT] | REPEAT copies of CHAR, REPEAT octal if starting with 0 |
| [:alnum:] | all letters and digits |
| [:alpha:] | all letters |
| [:blank:] | all horizontal whitespace |
| [:cntrl:] | all control characters |
| [:digit:] | all digits |
| [:graph:] | all printable characters, not including space |
| [:lower:] | all lower case letters |
| [:print:] | all printable characters, including space |
| [:punct:] | all punctuation characters |
| [:space:] | all horizontal or vertical whitespace |
| [:upper:] | all upper case letters |
| [:xdigit:] | all hexadecimal digits |
| [ = CHAR = ] | all characters which are equivalent to CHAR |

## 示例

1. 将英文字符全部替换成大写

```bash
echo abcdefghijk > demo
cat demo
abcdefghijk

cat demo | tr [a-z] [A-Z]
ABCDEFGHIJK
```
