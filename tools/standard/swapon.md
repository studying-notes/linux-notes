---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "swapon 挂载 swap 分区"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/swapon"  # 设置网页永久链接
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

> 挂载 swap 分区

## 格式

```bash
swapon [options] [<spec>]
```

## 参数

### options

| 参数 | 作用 |
| -------- | -------- |
| -a, --all | enable all swaps from /etc/fstab |
| -d, --discard | discard freed pages before they are reused |
| -e, --ifexists | silently skip devices that do not exist |
| -f, --fixpgsz | reinitialize the swap space if necessary |
| -p, --priority `<prio>` | specify the priority of the swap device |
| -s, --summary | display summary about used swap devices |
| --show[ = `<columns>`] display summary in definable table |
| --noheadings | don't print headings, use with --show |
| --raw | use the raw output format, use with --show |
| --bytes | display swap size in bytes in --show output |
| -v, --verbose | verbose mode |
| -h, --help | display this help and exit |
| -V, --version | output version information and exit |

### spec

| 参数 | 作用 |
| -------- | -------- |
| -L `<label>` | synonym for LABEL = `<label>` |
| -U `<uuid>` | synonym for UUID = `<uuid>` |
| LABEL = `<label>` | specifies device by swap area label |
| UUID = `<uuid>` | specifies device by swap area UUID |
| PARTLABEL = `<label>` | specifies device by partition label |
| PARTUUID = `<uuid>` | specifies device by partition UUID |
| `<device>` | name of device to be used |
| `<file>` | name of file to be used |

## columns

| 参数 | 作用 |
| ---- | -------- |
| NAME | device file or partition path |
| TYPE | type of the device |
| SIZE | size of the swap area |
| USED | bytes in use |
| PRIO | swap priority |

## 示例

```bash
free -h
```

```
             total       used       free     shared    buffers     cached
Mem:          1.9G       1.1G       833M       9.6M       1.7M       304M
-/+ buffers/cache:       848M       1.1G
Swap:         2.0G         0B       2.0G

```bash
swapon /dev/sdb2
```

```bash
free -h
```

```
             total       used       free     shared    buffers     cached
Mem:          1.9G       1.1G       824M       9.6M       1.7M       304M
-/+ buffers/cache:       857M       1.1G
Swap:         7.0G         0B       7.0G
```

## 关闭 swap

```shell
swapoff -a
```

```shell
vi /etc/fstab
# 注释掉 swap 挂载命令
```
