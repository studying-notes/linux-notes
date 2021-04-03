---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "top 命令详解"  # 文章标题
# description: "文章描述"
url:  "posts/linux/cmd/top"  # 设置网页永久链接
tags: [ "linux", "cmd"]  # 标签
series: [ "Linux 学习笔记"]  # 系列
categories: [ "学习笔记"]  # 分类

# 章节
weight: 20 # 排序优先级
chapter: false  # 设置为章节

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
----

> 动态地监视进程活动与系统负载等信息

## 格式

```bash
top -hv | -bcHiOSs -d secs -n max -u|U user -p pID(s) -o field -w [cols]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -h | 帮助信息 |
| -v | 版本信息 |
| -b | 以批处理模式操作 |
| -c | 命令行/程序名切换 |
| -H | 显示线程运行情况 |
| -i | 空闲进程切换 |
| -S | 累积模式 |
| -s | 保密模式 |
| -I | 忽略失效过程 |
| -d | 显示信息刷新间隔时间 |
| -n<次数> | 循环显示的次数 |
| -u|U<用户名> | 仅显示指定用户名所属进程的信息 |
| -p<进程号> | 仅显示指定进程的信息 |

## 详解

```bash
$ top
top - 09:12:12 up 18:42,  0 users,  load average: 0.03, 0.05, 0.01
Tasks:  83 total,   1 running,  52 sleeping,   0 stopped,   0 zombie
%Cpu(s):  1.1 us,  1.3 sy,  0.0 ni, 97.2 ID,  0.3 wa,  0.0 hi,  0.0 si,  0.0 st
KiB Mem :  1009060 total,    68760 free,   328936 used,   611364 buff/cache
KiB Swap:   969964 total,   962272 free,     7692 used.   503076 avail Mem 

  PID USER      PR  NI    VIRT    RES    SHR S %CPU %MEM     TIME+ COMMAND                      
    1 root      20   0   77528   6144   4156 S  0.0  0.6   0:01.88 systemd                 
    2 root      20   0       0      0      0 S  0.0  0.0   0:00.00 kthreadd                
    4 root       0 -20       0      0      0 I  0.0  0.0   0:00.00 kworker/0:0H                               
   11 root      rt   0       0      0      0 S  0.0  0.0   0:00.15 watchdog/0               
   14 root       0 -20       0      0      0 I  0.0  0.0   0:00.00 netns                             
   23 root       0 -20       0      0      0 I  0.0  0.0   0:00.00 crypto                      
```

前 5 行是系统统计信息，其所代表的含义如下：

- 第 1 行：任务队列信息，同 [`uptime`](uptime.md) 命令执行结果。依次是系统时间、运行时间、登录终端数、系统负载（即任务队列的平均长度。三个数值分别为 1 分钟、5 分钟、15 分钟内的平均值，数值越小意味着负载越低）。一个 CPU 在一个时间片里面只能运行一个进程，CPU 核数的多少直接影响到这台机器在同时间能运行的进程数。所以一般来说 Load Average 的数值别超过这台机器的总核数，就基本没啥问题。
- 第 2 行：进程信息。依次是进程总数、运行中的进程数、睡眠中的进程数、停止的进程数、僵死的进程数。
- 第 3 行：CPU 相关的百分比信息。依次是用户占用资源百分比、系统内核占用资源百分比、改变过优先级的进程资源百分比、空闲的资源百分比、等待输入输出的百分比等。
- 第 4 行：物理内存总量、物理内存使用量、内存空闲量、作为内核缓存的内存量。
- 第 5 行：交换空间总量、交换空间使用量、交换空间空闲量、已被提前加载的内存量。

统计信息下方显示了各个进程的详细信息，各列的含义如下：

| 代码 | 列名 | 含义 |
| --------- | --------- | --------- |
| a | PID | 进程 ID |
| b | PPID | 父进程 ID |
| c | RUSER | Real User Name |
| d | UID | 进程所有者的用户 ID |
| e | USER | 进程所有者的用户名 |
| f | GROUP | 进程所有者的组名 |
| g | TTY | 启动进程的终端名，不是从终端启动的进程则显示为 `?` |
| h | PR | 优先级 |
| i | NI | `Nice` 值。负值表示高优先级，正值表示低优先级 |
| j | P | 最后使用的 CPU，仅在多 CPU 环境下有意义 |
| k | %CPU | 上次更新到现在的 CPU 时间占用百分比 |
| l | TIME | 进程使用的 CPU 时间总计，单位秒 |
| m | TIME+ | 进程使用的 CPU 时间总计，单位 1/100 秒 |
| n | %MEM | 进程使用的物理内存百分比 |
| o | VIRT | 进程使用的虚拟内存总量，单位 kb。VIRT=SWAP+RES |
| p | SWAP | 进程使用的虚拟内存中，被换出的大小，单位 `kb` |
| q | RES | 进程使用的、未被换出的物理内存大小，单位 `kb`。RES=CODE+DATA |
| r | CODE | 可执行代码占用的物理内存大小，单位 `kb` |
| s | DATA | 可执行代码以外的部分(数据段+栈)占用的物理内存大小，单位 `kb` |
| t | SHR | 共享内存大小，单位 `kb` |
| u | nFLT | 页面错误次数 |
| v | nDRT | 最后一次写入到现在，被修改过的页面数 |
| w | S | 进程状态 |
| x | COMMAND | 命令名/命令行 |
| y | WCHAN | 若该进程在睡眠，则显示睡眠中的系统函数名 |
| z | Flags | 任务标志 [linux/sched.h](https://linux.die.net/include/linux/sched.h) |

## 示例

1. 更新 2 次后终止更新显示

```bash
$ top -n 2
```

2. 设置信息更新周期为 3 秒

```bash
$ top -d 3
```

3. 仅显示 PID 为 1138 的进程信息

```bash
$ top -p 1138
```

## 参考

- [Man Page](https://linux.die.net/man/1/top)
- [12 TOP Command Examples in Linux](https://www.tecmint.com/12-top-command-examples-in-linux/)
