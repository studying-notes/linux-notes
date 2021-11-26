---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "Linux 的启动过程"  # 文章标题
url:  "posts/linux/abc/boot"  # 设置网页永久链接
tags: [ "linux" ]  # 标签
series: [ "Linux 学习笔记"]  # 系列
categories: [ "学习笔记"]  # 分类

# 章节
weight: 20 # 排序优先级
chapter: false  # 设置为章节

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
---

## 启动介质引导

1. 计算机通电后，CPU 开始从一个固定的地址加载代码开始执行，这个地址就是 BIOS 的驱动程序所在的位置，于是 BIOS 的驱动开始执行。

2. BIOS 驱动首先进行一些自检工作，然后根据配置的启动顺序，依次尝试加载启动程序。比如配置的启动顺序是 CD -> 网卡 -> USB -> 硬盘。 BIOS 将先检查是否能从 CD 启动，如果不行，接着尝试从网卡启动，再试 USB 盘，最后再试硬盘。

3. CD，U盘和硬盘的启动都是一样的，对 BIOS 来说，它们都是块设备，BIOS 通过硬件访问接口直接访问这些块设备，加载固定位置的内容到内存，然后跳转到那个内存的位置开始执行，这里固定位置所存放的就是 Bootloader 的代码，从这个时间点开始，启动的工作就由 BIOS 交接到了 Bootloader 手中了。对大多数发行版来说，CD 和 U盘里面放的都是安装程序，里面用的 Bootloader 一般都是 [ISOLINUX](https://wiki.syslinux.org/wiki/index.php?title=ISOLINUX)，而硬盘里面存放的是安装好的系统，常用的 Bootloader 是 [GRUB2](https://www.gnu.org/software/grub/)，当然开源的 Bootloader 有很多种，各有各的特点。

4. 从网卡启动稍微有所不同，前提条件是网卡支持 PXE 启动，大概的步骤如下：

    1. 从网卡中加载 PXE Firmware 到内存中执行，里面包含一个很小的网络驱动和 TFTP Client 的实现；
    2. 发送 UDP 广播到当前局域网，向 DHCP 服务器请求 IP 和 NBP(Network Boot Program) 的地址；
    3. DHCP 服务器收到广播后，会发送应答，里面包含分配给请求机器的 IP 以及 NBP 的所在位置；
    4. 将分配的 IP 应用到网卡上，然后根据收到的 NBP 的地址，用 TFTP 协议到相应的服务器上取相应的 NBP 文件（取文件的过程不再是广播，而是点对点的文件传输过程，所以当前网卡必须要有 IP）；
    5. 开始执行取到的 NBP（Linux 一般使用 [PXELINUX](https://wiki.syslinux.org/wiki/index.php?title=PXELINUX) 作为 NBP）。

## 系统启动过程

以硬盘启动及 [GRUB2](https://en.wikipedia.org/wiki/GNU_GRUB) 为例：

1. BIOS 加载硬盘 MBR 中的 GRUB ，将启动工作交由 GRUB2 负责；
2. 由于 MBR 里面空间很小，GRUB2 只能放部分代码到里面，所以采用多级结构来加载数据，其中最重要的一点是 GRUB2 会加载 `/boot/grub/` 下的驱动到内存中；
3. GRUB2 加载内核和 Initrd Image，启动内核，然后由内核接管整个系统；
4. 内核进行初始化，最后启动初始化进程；
5. 初始化进程完成 Linux 系统中相关的初始化工作，比如挂载文件系统和交换分区、启动各类进程服务等，为用户提供合适的工作环境。

> 目前大部分 Linux 发行版本都采用了**并发启动机制**的 systemd 作为初始化进程。
