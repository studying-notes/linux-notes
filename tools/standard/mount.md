---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "mount 挂载文件系统"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/mount"  # 设置网页永久链接
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

> 挂载文件系统

挂载是在使用硬件设备前所执行的最后一步操作，即把硬盘设备或分区与一个目录文件进行关联，然后就能在这个目录中看到硬件设备中的数据了。

- [格式](#格式)
- [参数](#参数)
  - [Options](#options)
  - [Source](#source)
  - [Operations](#operations)
- [基本用法](#基本用法)
- [示例](#示例)
- [挂载虚拟文件系统](#挂载虚拟文件系统)
- [挂载虚拟块设备（Loop Device）](#挂载虚拟块设备loop-device)
  - [列出所有虚拟块设备](#列出所有虚拟块设备)
  - [挂载 ISO 文件](#挂载-iso-文件)
  - [挂载虚拟硬盘](#挂载虚拟硬盘)
  - [挂载一个设备到多个目录](#挂载一个设备到多个目录)
- [绑定挂载（Bind Mount）](#绑定挂载bind-mount)
  - [将源目录绑定到目的目录](#将源目录绑定到目的目录)
  - [绑定自己，让当前目录只读](#绑定自己让当前目录只读)
  - [绑定挂载单个文件](#绑定挂载单个文件)
  - [移动一个挂载点到另一个地方](#移动一个挂载点到另一个地方)

## 格式

```bash
mount [-lhV]
mount -a [options]
mount [options] [--source] <source> | [--target] <directory>
mount [options] <source> <directory>
mount <operation> <mountpoint> [<target>]
```

## 参数

### Options

| 参数 | 作用 |
| -------- | -------- |
| -a, --all | mount all filesystems mentioned in `/etc/fstab` |
| -c, --no-canonicalize | don't canonicalize paths |
| -f, --fake | dry run ; skip the mount(2) syscall |
| -F, --fork | fork off for each device (use with -a) |
| -T, --fstab `<path>` | alternative file to /etc/fstab |
| -i, --internal-only | don't call the mount.`<type>` helpers |
| -l, --show-labels | show also filesystem labels |
| -n, --no-mtab | don't write to /etc/mtab |
| -o, --options `<list>` | comma-separated list of mount options |
| -O, --test-opts `<list>` | limit the set of filesystems (use with -a) |
| -r, --read-only | mount the filesystem read-only (same as -o ro) |
| -t, --types `<list>` | limit the set of filesystem types |
| --source `<src>` | explicitly specifies source (path, label, uuid) |
| --target `<target>` | explicitly specifies mountpoint |
| -v, --verbose | say what is being done |
| -w, --rw, --read-write | mount the filesystem read-write (default) |
| -h, --help | display this help |
| -V, --version | display version |

### Source

| 参数 | 作用 |
| -------- | -------- |
| -L, --label `<label>` | synonym for LABEL = `<label>` |
| -U, --uuid `<uuid>` | synonym for UUID = `<uuid>` |
| LABEL = `<label>` | specifies device by filesystem label |
| UUID = `<uuid>` | specifies device by filesystem UUID |
| PARTLABEL = `<label>` | specifies device by partition label |
| PARTUUID = `<uuid>` | specifies device by partition UUID |
| `<device>` | specifies device by path |
| `<directory>` | mountpoint for bind mounts (see --bind/rbind) |
| `<file>` | regular file for loopdev setup |

### Operations

| 参数 | 作用 |
| -------- | -------- |
| -B, --bind | mount a subtree somewhere else (same as -o bind) |
| -M, --move | move a subtree to some other place |
| -R, --rbind | mount a subtree and all submounts somewhere else |
| --make-shared | mark a subtree as shared |
| --make-slave | mark a subtree as slave |
| --make-private | mark a subtree as private |
| --make-unbindable | mark a subtree as unbindable |
| --make-rshared | recursively mark a whole subtree as shared |
| --make-rslave | recursively mark a whole subtree as slave |
| --make-rprivate | recursively mark a whole subtree as private |
| --make-runbindable | recursively mark a whole subtree as unbindable |

## 基本用法

Mount 命令最常用的标准格式如下：

```bash
mount -t type -o options device directory
```

- type：文件系统类型（可选）。大部分情况下都不用指定该参数，系统会自动推断设备的文件系统类型；
- options：挂载参数（可选）；
- device：挂载的设备（必填）。有些文件系统不需要指定具体的设备，这里可以随便填一个字符串。
- directory: 挂载到哪个目录（必填）。

## 示例

1. 挂载硬盘设备

```bash
mount /dev/sdb2 /backup
```

按照上面的方法执行 `mount` 命令后就能立即使用文件系统了，但系统在重启后挂载就会失效。如果想让硬件设备和目录永久地进行自动关联，就必须把挂载信息按照指定的填写格式“设备文件 挂载目录 格式类型 权限选项 是否备份 是否自检”写入到 `/etc/fstab` 文件中。这个文件中包含着挂载所需的诸多信息项目，一旦配置好之后就能一劳永逸了。

| 字段     | 描述                                                                                 |
| -------- | ------------------------------------------------------------------------------------ |
| 设备文件 | 一般为设备的路径+设备名称，也可以写唯一识别码（UUID，Universally Unique Identifier） |
| 挂载目录 | 指定要挂载到的目录，需在挂载前创建好                                                 |
| 格式类型 | 指定文件系统的格式，比如 Ext3、Ext4、XFS、SWAP、iso9660（此为光盘设备）等            |
| 权限选项 | 若设置为 defaults，则默认权限为：rw, suid, dev, exec, auto, nouser, async            |
| 是否备份 | 若为 1 则开机后使用 dump 进行磁盘备份，为 0 则不备份                                 |
| 是否自检 | 若为 1 则开机后自动进行磁盘自检，为 0 则不自检                                       |

比如将文件系统为 ext4 的硬件设备 `/dev/sdb2` 在开机后自动挂载到 `/backup` 目录上，并保持默认权限且无需开机自检，则可以添加配置：

```conf
/dev/sdb2 /backup ext4 defaults 0 0
```

## 挂载虚拟文件系统

`proc`、`tmpfs`、`sysfs`、`devpts` 等都是 Linux 内核映射到用户空间的虚拟文件系统，它们不和具体的物理设备关联，但它们具有普通文件系统的特征，应用层程序可以像访问普通文件系统一样来访问它们。

1. 挂载 `proc` 文件系统

```bash
mount -t proc none /mnt
```

将内核的 `proc` 文件系统挂载到 `/mnt` ，这样就可以在 `/mnt` 目录下看到系统当前运行的所有进程的信息，由于 `proc` 是内核虚拟的一个文件系统，并没有对应的设备，所以 `-t` 参数必须要指定。`none` 可以是自定义字符串，用 `mount` 命令查看挂载点信息时第一列显示的就是这个字符串。

2. 挂载 `tmpfs` 文件系统

```bash
mount -t tmpfs -o size=2g tmpfs /mnt/memory
```

在内存中创建一个 2g 的 `tmpfs` 文件系统，并挂载到 `/mnt` 下，这样所有写到 `/mnt` 目录下的文件都存储在内存中，速度非常快，不过由于数据存储在内存中，断电后数据会丢失掉。

```bash
dd if=/dev/zero of=test bs=1M count=1500
```

```
1500+0 records in
1500+0 records out
1572864000 bytes (1.6 GB, 1.5 GiB) copied, 0.40924 s, 3.8 GB/s
```

## 挂载虚拟块设备（Loop Device）

在 Linux 中，硬盘、光盘、软盘等都是常见的块设备，它们在 Linux 下的目录一般是 `/dev/hda1`, `/dev/cdrom`, `/dev/sda1`，`/dev/fd0` 这样的。而 `loop device` 是虚拟的块设备，目的是让用户可以像访问上述块设备那样访问一个文件。新内核所有硬盘都是 `/dev/sda` 开头。

虚拟块设备的路径一般是 `/dev/loop0`, `dev/loop1`，……，具体的个数跟内核的配置有关，不够时可以修改内核参数增加个数。

### 列出所有虚拟块设备

```bash
losetup -a
```

### 挂载 ISO 文件

```bash
# 制作一个用于测试的文件
mkdir -p data/sub
```

```bash
mkisofs -o data.iso data
```

```bash
ls
```

```
data/  data.iso
```

```bash
# 挂载到目录 `/mnt`
mount data.iso /mnt
```

```
mount: /mnt: WARNING: device write-protected, mounted read-only.
```

```bash
# 挂载成功，可以看到里面的文件
ls /mnt
```

```
sub/
```

### 挂载虚拟硬盘

尝试 `btrfs` 文件系统

```bash
# `btrfs` 对分区的大小有最小要求，首先创建一个128M的文件
dd if=/dev/zero bs=1M count=128 of=vdisk.img
128+0 records in
128+0 records out
134217728 bytes (134 MB, 128 MiB) copied, 0.076348 s, 1.8 GB/s

mkfs.btrfs vdisk.img
# 输出一些信息，提示创建成功

# 挂载虚拟硬盘
mount vdisk.img /mnt

# 尝试在虚拟硬盘中创建文件
touch /mnt/Dockerfile
ls /mnt
Dockerfile
```

> **挂载多个设备到一个文件夹**：正如上面两个例子所展示的，Linux 支持将多个设备挂载到一个文件夹，默认后者覆盖前者，只有卸载后者，前者才能重新看到。

### 挂载一个设备到多个目录

```bash
# 卸载之前的设备
umount /mnt

# 新建两个目录用于挂载点
mkdir /mnt/disk1 /mnt/disk2

# 将 `vdisk.img` 依次挂载到 `disk1` 和 `disk2`
mount vdisk.img /mnt/disk1 && mount vdisk.img /mnt/disk2
tree /mnt
/mnt
├── disk1
│   └── Dockerfile
└── disk2
    └── Dockerfile

# 在 `disk1` 中创建一个新文件
touch /mnt/disk1/README.md

# 这个文件在 `disk2` 中也能看到
tree /mnt
/mnt
├── disk1
│   ├── Dockerfile
│   └── README.md
└── disk2
    ├── Dockerfile
    └── README.md

umount /mnt/disk*
```

> 原来文件夹里的文件仍然是存在的，只是看不到而已。因此平时挂载设备的时候不用专门去创建空目录了，随便找个暂时不用的目录挂上去就可以了。

## 绑定挂载（Bind Mount）

> 可以将任何一个挂载点、普通目录或者文件（原目录）挂载到其他地方（目的目录），然后就可以在目的目录下就可以看到源目录里的文件。

### 将源目录绑定到目的目录

```bash
# 准备两个目录
mkdir -p bind/disk1/sub1 bind/disk2/sub2
tree bind/
bind/
├── disk1
│   └── sub1
└── disk2
    └── sub2

4 directories, 0 files

# 将 `bind/disk1` 绑定到 `bind/disk2`
mount --bind bind/disk1 bind/disk2

# 然后在 `bind/disk2` 显示的就是 `bind/disk1` 里的内容
tree bind/
bind/
├── disk1
│   └── sub1
└── disk2
    └── sub1

umount bind/disk2
```

### 绑定自己，让当前目录只读

```bash
mount -o bind,ro bind/disk1 bind/disk1

# 创建新文件失败
touch bind/disk1/sub1/Dockerfile
touch: cannot touch 'bind/disk1/sub1/Dockerfile': Read-only file system

umount bind/disk1
```

### 绑定挂载单个文件

```bash
# 创建两个用于测试的文件
echo 1st > bind/1st && echo 2nd > bind/2nd

# 将文件 `bind/1st` 绑定到 `bind/2nd`
mount --bind bind/1st bind/2nd
cat bind/2nd
1st

# 即使删除 `bind/1st` 文件，也在 `bind/2nd` 可以看到其内容

umount bind/2nd
```

### 移动一个挂载点到另一个地方

```bash
# 将 `bind/disk1` 绑定到 `bind/disk2`
mount --bind bind/disk1 bind/disk2
ls bind/disk*
bind/disk1:
sub1/

bind/disk2:
sub1/

# 移动操作要求挂载点的父挂载点不能是 `shared` 类型
 findmnt -o TARGET,PROPAGATION /
TARGET PROPAGATION
/      shared

mount --make-private /
findmnt -o TARGET,PROPAGATION /
TARGET PROPAGATION
/      private

# 移动
mount --move bind/disk2 /mnt

ls /mnt
sub1/

umount /mnt
```
