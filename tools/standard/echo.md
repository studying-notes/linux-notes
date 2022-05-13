---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "echo 在标准输出回显字符串"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/echo"  # 设置网页永久链接
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

> 显示一行文本，在标准输出回显字符串

## 格式

```bash
echo [SHORT-OPTION]... [STRING]...
echo LONG-OPTION
```

## 参数

| 参数 | 作用 |
| -------- | -------- |
| -n | 不输出结尾的换行符 |
| -e | 启用 `\` 转义 |
| -E | 禁用 `\` 转义（默认）|
| --help | 显示帮助信息 |
| --version | 显示版本信息 |

### 备注

[GNU echo](http://linux.die.net/man/1/echo) 支持以上全部参数，但某些终端内置的 `echo` 命令可能不支持 `--help`、`--version` 参数，默认情况下，必须通过 `/bin/echo` 显式调用才可以显示相关信息：

```bash
/bin/echo --help
```

对于 [`bash`](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html) 终端，可以执行 [`enable`](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html#index-enable) 禁用内置 `echo` 命令：

```bash
enable -n echo
echo --help
```

## 转义

指定 `-e` 启用 `\` 转义时，支持下列字符序列：

| 参数  | 含义                                 |
| ----- | ------------------------------------ |
| \\\   | 一个反斜杠 `\`                       |
| \a    | 响铃（BEL）                          |
| \b    | 退格（BS），将当前位置移到前一列     |
| \c    | 截断输出，不再输出之后的内容         |
| \e    | 转义                                 |
| \f    | 换页（FF），将当前位置移到下页开头   |
| \n    | 换行（LF），将当前位置移到下一行开头 |
| \r    | 回车（CR），将当前位置移到本行开头   |
| \t    | 水平制表（HT）                       |
| \v    | 垂直制表（VT）                       |
| \0NNN | 1 到 3 位八进制数所代表的任意字符    |
| \xHH  | 十六进制所代表的任意字符             |

## 示例

1. 显示普通字符

```bash
echo "a1.3fg@1"
a1.3fg@1
```

2. 显示命令结果

```bash
echo $(ls /root/docker)
builder buildkit containers image network overlay2 plugins runtimes swarm tmp trust volumes
```

```bash
echo `ls /root/docker`
builder buildkit containers image network overlay2 plugins runtimes swarm tmp trust volumes
```

3. 显示变量内容

```bash
echo $PATH
/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

echo '$PATH'
$PATH

echo "$PATH"
/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
```

- `'STRING'` 不执行变量替换
- `"STRING"` 执行变量替换

4. 高级表达

```bash
echo -e "\033[0m   \033[45;32;5m***\033[0m\n    \033[45;32;5m*\033[0m"
```

`\033` 可以引导非常规字符序列，`\033[` 表示终端转义字符开始，`m` 表示设置属性然后结束非常规字符序列，其中的数字字符编码含义如下表所示：

| 编码 | 颜色 / 动作 |
| ---- | -------- |
| 0 | 设置为默认值 |
| 1 | 设置粗体 |
| 2 | 设置一半亮度（模拟彩色显示器的颜色）|
| 4 | 设置下划线（模拟彩色显示器的颜色） |
| 5 | 设置闪烁 |
| 7 | 设置反向图象 |
| 22 | 设置一般密度 |
| 24 | 关闭下划线 |
| 25 | 关闭闪烁 |
| 27 | 关闭反向图象 |
| 30 | 设置黑色前景 |
| 31 | 设置红色前景 |
| 32 | 设置绿色前景 |
| 33 | 设置×××前景 |
| 34 | 设置蓝色前景 |
| 35 | 设置紫色前景 |
| 36 | 设置青色前景 |
| 37 | 设置白色（灰色）背景 |
| 38 | 在默认的前景颜色上设置下划线 |
| 39 | 在默认的前景颜色上关闭下划线 |
| 40 | 设置黑色背景 |
| 41 | 设置红色背景 |
| 42 | 设置绿色背景 |
| 43 | 设置×××背景 |
| 44 | 设置蓝色背景 |
| 45 | 设置紫色背景 |
| 46 | 设置青色背景 |
| 47 | 设置白色（灰色）背景 |
| 49 | 设置默认黑色背景 |

- 第一个 `\033[0m` 后有两个空格；
- 第二个 `\033[45;32;5m***` 显示背景为紫、字体为绿且闪烁的三个 `***`；
- 第三个 `\033[om\n` 之所以加 `\n `是因为最后一个 `*` 要换行，换行后还要接三个空格；
- 第四个 `\033[45;32;5m*` 显示背景为紫、字体为绿且闪烁的一个`*`；
- 第五个 `\033[0m` 字符效果到此结束。
