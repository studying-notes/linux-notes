---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "ps 显示系统进程状态"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/ps"  # 设置网页永久链接
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

> 显示系统进程状态

**ps命令** 用于报告当前系统的进程状态。可以搭配 kill 指令随时中断、删除不必要的程序。ps 命令是最基本同时也是非常强大的进程查看命令，使用该命令可以确定有哪些进程正在运行和运行的状态、进程是否结束、进程有没有僵死、哪些进程占用了过多的资源等等，总之大部分信息都是可以通过执行该命令得到的。

## 格式

```bash
ps [options]
```

## 选项

选项太多了，常用的也就几个。

### 基础

| 参数 | 作用 |
| -------- | -------- |
| -A, -e | 显示全部进程 |
| -a | 显示所有终端机下执行的程序，除了阶段作业领导者之外 |
| a | 显示现行终端机下的所有程序，包括其他用户的程序 |
| -d | 显示所有程序，但不包括阶段作业领导者的程序 |
| -N, --deselect | 显示所有的程序，除了执行ps指令终端机下的程序之外 |
| r | 只列出现行终端机正在执行中的程序 |
| T | 显示现行终端机下的所有程序 |
| x | 显示所有程序，不以终端机来区分 |

### 筛选

| 参数 | 作用 |
| -------- | -------- |
| -C `<command>` | 指定执行指令的名称，并列出该指令的程序的状况 |
| -G, --Group `<GID>` | 列出属于该群组的程序的状况，也可使用群组名称来指定 |
| -g, --group `<group>` | 此选项的效果和指定"-G"选项相同，当亦能使用阶段作业领导者的名称来指定 |
| -p, p, --pid `<PID>` | 指定程序识别码，并列出该程序的状况 |
| --ppid `<PID>` | 父进程 |
| -q, q, --quick-pid `<PID>` | 指定程序识别码，并列出该程序的状况 (快速模式) |
| -s, --sid `<session>` | 指定阶段作业的程序识别码，并列出隶属该阶段作业的程序的状况 |
| -t, t, --tty `<tty>` | 指定终端机编号，并列出属于该终端机的程序的状况 |
| -u, U, --user `<UID>` | 列出属于该用户的程序的状况 |
| -U, --User `<UID>` | 列出属于该用户的程序的状况，也可使用用户名称来指定 |

### 格式化输出

| 参数 | 作用 |
| -------- | -------- |
| -F | extra full |
| -f | 显示UID,PPIP,C与STIME栏位 |
| f, --forest | 用ASCII字符显示树状结构，表达程序间的相互关系 |
| -H | 显示树状结构，表示程序间的相互关系 |
| -j/j | 采用工作控制的格式显示程序状况 |
| -l/l | 采用详细的格式来显示程序状况 |
| -M, Z | add security data (for SELinux) |
| -O `<format>` | preloaded with default columns |
| O `<format>` | as -O, with BSD personality |
| -o, o, --format `<format>` | user-defined format |
| s | 采用程序信号的格式显示程序状况 |
| u | user-oriented format |
| v | 采用虚拟内存的格式显示程序状况 |
| X | 采用旧式的Linux登陆格式显示程序状况 |
| -y | do not show flags, show rss vs. addr (used with -l) |
| --context | display security context (for SELinux) |
| --headers | repeat header lines, one per page |
| --no-headers | do not print header at all |
| --cols, --columns, --width `<num>` | set screen width |
| --rows, --lines `<num>` | set screen height |

### 显示线程

| 参数 | 作用 |
| ----- | -------- |
| H | as if they were processes |
| -L | 列出栏位的相关信息 |
| -m, m | 显示所有的执行绪 |
| -T | possibly with SPID column |

### 其他杂项

| 参数 | 作用 |
| -------- | -------- |
| -c | 显示CLS和PRI栏位 |
| c | 列出程序时，显示每个程序真正的指令名称，而不包含路径，选项或常驻服务的标示 |
| e | 列出程序时，显示每个程序所使用的环境变量 |
| k, | --sort | specify sort order as: [+ | -]key[,[+ | -]key[,...]] |
| L | show format specifiers |
| n | 以数字来表示USER和WCHAN栏位 |
| S, | --cumulative | 列出程序时，包括已中断的子程序资料 |
| -y | do not show flags, show rss (only with -l) |
| -V, V, --version | 显示版本信息 |
| -w, w | 采用宽阔的格式来显示程序状况 |

### 备注

- 在 Linux 系统中的命令参数有长短格式之分，长格式和长格式之间不能合并，长格式和短格式之间也不能合并，但短格式和短格式之间是可以合并的，合并之后仅保留一个 `-` 即可。
- `ps` 命令可允许参数不加减号 `-`。

## 进程状态

- R（运行）：进程正在运行或在运行队列中等待。
- S（中断）：进程处于休眠中，当某个条件形成后或者接收到信号时，则脱离该
状态。
- D（不可中断）：进程不响应系统异步信号，即便用 `kill` 命令也不能将其中断。
- Z（僵死）：进程已经终止，但进程描述符依然存在, 直到父进程调用 `wait4()` 系统函数后将进程释放。
- T（停止）：进程收到停止信号后停止运行。
- X：死掉的进程。
- <：高优先级。
- N：低优先级。
- L：有些页被锁进内存。
- s：包含子进程。
- +：位于后台的进程组。
- l：多线程，克隆线程。

## 示例

1. 显示全部系统进程信息

```bash
ps -au
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root      2437  0.5  1.9  52180 19856 pts/1    S+   21:02   0:13 wget -r -p http://www.linuxprobe.com
root      2733  0.0  0.3  37364  3416 pts/3    R+   21:44   0:00 ps -au
```

## 实例

```shell
ps axo pid,comm,pcpu # 查看进程的PID、名称以及CPU 占用率
ps aux | sort -rnk 4 # 按内存资源的使用量对进程进行排序
ps aux | sort -nk 3  # 按 CPU 资源的使用量对进程进行排序
ps -A # 显示所有进程信息
ps -u root # 显示指定用户信息
ps -efL # 查看线程数
ps -e -o "%C : %p :%z : %a"|sort -k5 -nr # 查看进程并按内存使用大小排列
ps -ef # 显示所有进程信息，连同命令行
ps -ef | grep ssh # ps 与grep 常用组合用法，查找特定进程
ps -C nginx # 通过名字或命令搜索进程
ps aux --sort=-pcpu,+pmem # CPU或者内存进行排序,-降序，+升序
ps -f --forest -C nginx # 用树的风格显示进程的层次关系
ps -o pid,uname,comm -C nginx # 显示一个父进程的子进程
ps -e -o pid,uname=USERNAME,pcpu=CPU_USAGE,pmem,comm # 重定义标签
ps -e -o pid,comm,etime # 显示进程运行的时间
ps -aux | grep named # 查看named进程详细信息
ps -o command -p 91730 | sed -n 2p # 通过进程id获取服务名称
```
