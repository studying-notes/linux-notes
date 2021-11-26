---
date: 2020-09-19 21:32:43  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "Linux 存储结构与磁盘划分"  # 文章标题
url:  "posts/linux/abc/storage"  # 设置网页永久链接
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

文件系统层次化标准（FHS，Filesystem Hierarchy Standard）、udev 硬件命名规则以及硬盘分区的规划方法。

## 一切从“/”开始

Linux 系统中的一切文件都是从“根（/）”目录开始的，并按照文件系统层次化标准（FHS）采用树形结构来存放文件，以及定义了常见目录的用途。另外，Linux 系统中的文件和目录名称是严格区分大小写的。例如，root、rOOt、Root、rooT 均代表不同的目录，并且文件名称中不得包含斜杠（/）。

### 常见的目录名称以及相应内容

| 目录 | 描述 |
| --------- | --------- |
| /boot | 开机所需文件—内核、开机菜单以及所需配置文件等 |
| /dev | 以文件形式存放任何设备与接口 |
| /etc | 配置文件 |
| /home | 用户主目录 |
| /bin | 存放单用户模式下还可以操作的命令 |
| /lib | 开机时用到的函数库，以及 `/bin` 与 `/sbin` 下面的命令要调用的函数 |
| /sbin | 开机过程中需要的命令 |
| /media | 用于挂载设备文件的目录 |
| /opt | 放置第三方的软件 |
| /root | 系统管理员的主目录 |
| /srv | 一些网络服务的数据文件目录 |
| /tmp | 任何人均可使用的“共享”临时目录 |
| /proc | 虚拟文件系统，例如系统内核、进程、外部设备及网络状态等 |
| /usr/local | 用户自行安装的软件 |
| /usr/sbin | Linux 系统开机时不会使用到的软件、命令、脚本 |
| /usr/share | 帮助与说明文件，也可放置共享文件 |
| /var | 主要存放经常变化的文件，如日志 |
| /lost+found | 当文件系统发生错误时，将一些丢失的文件片段存放在这里 |

### 路径

路径指的是如何定位到某个文件，分为绝对路径与相对路径。绝对路径指的是从根目录（/）开始写起的文件或目录名称，而相对路径则指的是相对于当前路径的写法。

## 物理设备的命名规则

系统内核中的 udev 设备管理器会自动把硬件名称规范起来，目的是让用户通过设备文件的名字可以猜出设备大致的属性以及分区信息等；这对于陌生的设备来说特别方便。另外，udev 设备管理器的服务会一直以守护进程的形式运行并侦听内核发出的信号来管理 `/dev` 目录下的设备文件。

### 常见的硬件设备及其文件名称

| 硬件设备 | 文件名称 |
| --------- | --------- |
| IDE 设备 | /dev/hd[a-d] |
| SCSI/SATA/U 盘 | /dev/sd[a-p] |
| 软驱 | /dev/fd[0-1] |
| 打印机 | /dev/lp[0-15] |
| 光驱 | /dev/cdrom |
| 鼠标 | /dev/mouse |
| 磁带机 | /dev/st0 或/dev/ht0 |

由于现在的 IDE 设备已经很少见了，所以一般的硬盘设备都会是以“/dev/sd”开头的。而一台主机上可以有多块硬盘，因此系统采用 a～p 来代表 16 块不同的硬盘（默认从 a 开始分配），而且硬盘的分区编号也很有讲究：

- 主分区或扩展分区的编号从 1 开始，到 4 结束；
- 逻辑分区从编号 5 开始。

`/dev` 目录中 sda 设备之所以是 a，并不是由插槽决定的，而是由系统内核的识别顺序来决定的，而恰巧很多主板的插槽顺序就是系统内核的识别顺序，因此才会被命名为 `/dev/sda`。在使用 iSCSI 网络存储设备时会发现，明明主板上第二个插槽是空着的，但系统却能识别到 `/dev/sdb` 这个设备

分区的编号不一定代表分区的个数，也有可能是手工指定的。因此 sda3 只能表示是编号为 3 的分区，而不能判断 sda 设备上已经存在了 3 个分区。

![sda5](https://i.loli.net/2020/12/30/EOuDMYathNVZBfm.png)

首先，`/dev/` 目录中保存的应当是硬件设备文件；其次，sd 表示是存储设备；然后，a 表示系统中同类接口中第一个被识别到的设备，最后，5 表示这个设备是一个逻辑分区。一言以蔽之，“/dev/sda5”表示的就是“这是系统中第一块被识别到的硬件设备中分区编号为 5 的逻辑分区的设备文件”。

![](https://i.loli.net/2020/12/30/4abOxU6nSeqfwQk.png)

硬盘设备是由大量的扇区组成的，每个扇区的容量为 512 字节。其中第一个扇区最重要，它里面保存着主引导记录与分区表信息。就第一个扇区来讲，主引导记录需要占用 446 字节，分区表为 64 字节，结束符占用 2 字节；其中分区表中每记录一个分区信息就需要 16 字节，这样一来最多只有 4 个分区信息可以写到第一个扇区中，这 4 个分区就是 4 个主分区。

为了解决分区个数不够的问题，可以将第一个扇区的分区表中 16 字节（原本要写入主分区信息）的空间（称之为扩展分区）拿出来指向另外一个分区。也就是说，扩展分区其实并不是一个真正的分区，而更像是一个占用 16 字节分区表空间的指针—一个指向另外一个分区的指针。这样一来，用户一般会选择使用 3 个主分区加 1 个扩展分区的方法，然后在扩展分区中创建出数个逻辑分区，从而来满足多分区（大于 4 个）的需求。

![](https://i.loli.net/2020/12/30/XwO71zgi8a9SmeC.png)

## /dev/shm

/dev/shm/ 是 linux 下一个非常有用的目录，因为这个目录不在硬盘上，而是在内存里。因此在 linux 下，就不需要大费周折去建 ramdisk，直接使用 /dev/shm/ 就可达到很好的优化效果。

/dev/shm/ 需要注意的一个是容量问题，在 linux 下，它默认最大为内存的一半大小，使用 `df -h` 命令可以看到。但它并不会真正的占用这块内存，如果 /dev/shm/ 下没有任何文件，它占用的内存实际上就是 0 字节；如果它最大为 1G，里头放有 100M 文件，那剩余的 900M 仍然可为其它应用程序所使用，但它所占用的 100M 内存，是绝不会被系统回收重新划分的。

默认系统就会加载 /dev/shm，它就是所谓的 tmpfs，跟 ramdisk 虚拟磁盘一样，tmpfs 可以使用 RAM，但它也可以使用交换分区来存储。而且传统的虚拟磁盘是个块设备，并需要一个 mkfs 之类的命令才能真正地使用它，tmpfs 是一个文件系统，而不是块设备；只是安装它，它就可以使用了。

tmpfs 有以下优势：

- 动态文件系统的大小。
- tmpfs 的另一个主要的好处是它闪电般的速度。因为典型的 tmpfs 文件系统会完全驻留在 RAM 中，读写几乎可以是瞬间的。
- tmpfs 数据在重新启动之后不会保留，因为虚拟内存本质上就是易失的。所以有必要做一些脚本做诸如加载，绑定的操作。

## 文件系统与数据资料

用户在硬件存储设备中执行的文件建立、写入、读取、修改、转存与控制等操作都是依靠文件系统来完成的。**文件系统的作用是合理规划硬盘**，以保证用户正常的使用需求。

日常在硬盘需要保存的数据实在太多了，因此 Linux 系统中有一个名为 super block 的“硬盘地图”。Linux 并不是把文件内容直接写入到这个“硬盘地图”里面，而是在里面记录着整个文件系统的信息。因为如果把所有的文件内容都写入到这里面，它的体积将变得非常大，而且文件内容的查询与写入速度也会变得很慢。Linux 只是把每个文件的权限与属性记录在 inode 中，而且每个文件占用一个独立的 inode 表格，该表格的大小默认为 128 字节，里面记录着如下信息：

- 该文件的访问权限（read、write、execute）；
- 该文件的所有者与所属组（owner、group）；
- 该文件的大小（size）；
- 该文件的创建或内容修改时间（ctime）；
- 该文件的最后一次访问时间（atime）；
- 该文件的修改时间（mtime）；
- 文件的特殊权限（SUID、SGID、SBIT）；
- 该文件的真实数据地址（point）。

而文件的实际内容则保存在 block 块中（大小可以是 1KB、2KB 或 4KB），一个 inode 的默认大小仅为 128B（Ext3），记录一个 block 则消耗 4B。当文件的 inode 被写满后，Linux 系统会自动分配出一个 block 块，专门用于像 inode 那样记录其他 block 块的信息，这样把各个block 块的内容串到一起，就能够让用户读到完整的文件内容了。对于存储文件内容的 block 块，有下面两种常见情况（以 4KB 的 block 大小为例进行说明）。

- 情况 1：文件很小（1KB），但依然会占用一个 block，因此会潜在地浪费 3KB。 
- 情况 2：文件很大（5KB），那么会占用两个 block（5KB-4KB 后剩下的 1KB 也要占用一个 block）。

计算机系统在发展过程中产生了众多的文件系统，为了使用户在读取或写入文件时不用关心底层的硬盘结构，Linux 内核中的软件层为用户程序提供了一个 VFS（Virtual File System，虚拟文件系统）接口，这样用户实际上在操作文件时就是统一对这个虚拟文件系统进行操作了。

详细介绍见[虚拟文件系统](vfs.md)。

## 挂载硬件设备

在拿到一块全新的硬盘存储设备后要先分区，然后格式化，最后才能挂载并正常使用。当用户需要使用硬盘设备或分区中的数据时，需要先将其与一个已存在的目录文件进行关联，而这个关联动作就是“挂载”。

详细介绍见[虚拟文件系统](vfs.md)。

## 添加硬盘设备

首先需要在虚拟机中模拟添加入一块新的硬盘存储设备，然后再进行分区、格式化、挂载等操作，最后通过检查系统的挂载状态并真实地使用硬盘来验证硬盘设备是否成功添加。

### fdisk 命令

详细介绍见[fdisk](fdisk.md) 命令。


### mkfs 命令

如果硬件存储设备没有进行格式化，则 Linux 系统无法得知怎么在其上写入数据。因此，在对存储设备进行分区后还需要进行格式化操作。

详细介绍见[mkfs](mkfs.md) 命令。

完成了存储设备的分区和格式化操作，接下来就是要来挂载并使用存储设备了。与之相关的步骤也非常简单：首先是创建一个用于挂载设备的挂载点目录；然后使用 `mount` 命令将存储设备与挂载点进行关联；最后使用 `df -h` 命令来查看挂载状态和硬盘使用量信息。

```bash
$ mkdir /newFS
$ mount /dev/sdb1 /newFS
$ df -h
Filesystem                    Size  Used Avail Use% Mounted on
/dev/mapper/rhel_redhat-root   18G  4.9G   13G  28% /
devtmpfs                      985M     0  985M   0% /dev
tmpfs                         994M   92K  994M   1% /dev/shm
tmpfs                         994M  8.8M  986M   1% /run
tmpfs                         994M     0  994M   0% /sys/fs/cgroup
/dev/sda1                     497M  119M  379M  24% /boot
/dev/sdb1                     2.0G   33M  2.0G   2% /newFS
```

### du 命令

详细介绍见[du](du.md) 命令。

## 添加交换分区

SWAP（交换）分区是一种通过在硬盘中预先划分一定的空间，然后将把内存中暂时不常用的数据临时存放到硬盘中，以便腾出物理内存空间让更活跃的程序服务来使用的技术，其设计目的是为了解决真实物理内存不足的问题。

但由于交换分区毕竟是通过硬盘设备读写数据的，速度肯定要比物理内存慢，所以只有当真实的物理内存耗尽后才会调用交换分区的资源。交换分区的创建过程与前文讲到的挂载并使用存储设备的过程非常相似。在生产环境中，交换分区的大小一般为真实物理内存的 1.5～2 倍。

1. 取出一个大小为 5GB 的主分区作为交换分区资源

```bash
$ fdisk /dev/sdb
Welcome to fdisk (util-linux 2.23.2).
Changes will remain in memory only, until you decide to write them.
Be careful before using the write command.
Device does not contain a recognized partition table
Building a new DOS disklabel with disk identifier 0xb3d27ce1.
Command (m for help): n
Partition type:
p primary (1 primary, 0 extended, 3 free)
e extendedSelect (default p): p
Partition number (2-4, default 2):
First sector (4196352-41943039, default 4196352):
Using default value 4196352
Last sector, +sectors or +size{K,M,G} (4196352-41943039, default 41943039): +5G
Partition 2 of type Linux and of size 5 GiB is set
Command (m for help): p
Disk /dev/sdb: 21.5 GB, 21474836480 bytes, 41943040 sectors
Units = sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disk label type: dos
Disk identifier: 0xb0ced57f
Device Boot Start End Blocks Id System
/dev/sdb1 2048 4196351 2097152 83 Linux
/dev/sdb2 4196352 14682111 5242880 83 Linux
Command (m for help): w
The partition table has been altered!
Calling ioctl() to re-read partition table.
WARNING: Re-reading the partition table failed with error 16: Device or resource busy.
The kernel still uses the old table. The new table will be used at
the next reboot or after you run partprobe(8) or kpartx(8)
Syncing disks.
```

2. 创建交换分区

```bash
$  mkswap /dev/sdb2
Setting up swapspace version 1, size = 5242876 KiB
no label, UUID=2972f9cb-17f0-4113-84c6-c64b97c40c75
```

3. 把准备好的 SWAP 分区设备正式挂载到系统中

```bash
$  free -h
             total       used       free     shared    buffers     cached
Mem:          1.9G       1.1G       833M       9.6M       1.7M       304M
-/+ buffers/cache:       848M       1.1G
Swap:         2.0G         0B       2.0G

$ swapon /dev/sdb2
$ free -h
             total       used       free     shared    buffers     cached
Mem:          1.9G       1.1G       824M       9.6M       1.7M       304M
-/+ buffers/cache:       857M       1.1G
Swap:         7.0G         0B       7.0G
```

4. 设置为永久，将配置写入 `/etc/fstab`

```conf
/dev/sdb2 swap swap defaults 0 0
```

## 磁盘容量配额

Linux 系统的设计初衷就是让许多人一起使用并执行各自的任务，从而成为多用户、多任务的操作系统。但是，硬件资源是固定且有限的，如果某些用户不断地在 Linux 系统上创建文件或者存放电影，硬盘空间总有一天会被占满。针对这种情况，root 管理员就需要使用磁盘容量配额服务来限制某位用户或某个用户组针对特定文件夹可以使用的最大硬盘空间或最大文件个数，一旦达到这个最大值就不再允许继续使用。可以使用 quota 命令进行磁盘容量配额管理，从而限制用户的硬盘可用容量或所能创建的最大文件个数。quota 命令还有软限制和硬限制的功能。

- 软限制：当达到软限制时会提示用户，但仍允许用户在限定的额度内继续使用。
- 硬限制：当达到硬限制时会提示用户，且强制终止用户的操作。

RHEL 7 系统中已经安装了 quota 磁盘容量配额服务程序包，但存储设备却默认没有开启
对 quota 的支持，此时需要手动编辑配置文件，让 RHEL 7 系统中的 `/boot` 目录能够支持 quota 磁盘配额技术。

```conf
UUID=14f3b676-db7e-45ba-946c-d2d7c6c9590f /boot                   xfs     defaults,uquota        1 2
```

然后重启。

```bash
$ reboot
```

```bash
$ mount | grep boot
/dev/sda1 on /boot type xfs (rw,relatime,seclabel,attr2,inode64,usrquota)
```

创建一个用于检查 quota 磁盘容量配额效果的用户 tom，并针对/boot 目录增加其他人的写权限，保证用户能够正常写入数据：

```bash
$ useradd tom
$ chmod -Rf o+w /boot
```

### xfs_quota 命令

详细介绍见[xfs_quota](xfs_quota.md) 命令。

### edquota 命令

详细介绍见[edquota](edquota.md) 命令。

## 软硬方式链接

在 Linux 系统中存在硬链接和软连接两种文件。

- **硬链接（Hard Link）**：可以将它理解为一个“指向原始文件 inode 的指针”，系统不为它分配独立的 inode 和文件。所以，**硬链接文件与原始文件其实是同一个文件**，只是名字不同。我们每添加一个硬链接，该文件的 inode 连接数就会增加 1；而且只有当该文件的 inode 连接数为 0 时，才算彻底将它删除。换言之，由于硬链接实际上是指向原文件 inode 的指针，因此即便原始文件被删除，依然可以通过硬链接文件来访问。需要注意的是，由于技术的局限性，我们**不能跨分区对目录文件进行链接**。

- **软链接（符号链接，Symbolic Link）**：仅仅包含所链接文件的路径名，因此能链接目录文件，也**可以跨越文件系统进行链接**。但是，当原始文件被删除后，链接文件也将失效，从这一点上来说与 Windows 系统中的“快捷方式”具有一样的性质。

### ln 命令

详细介绍见[ln](ln.md) 命令。
