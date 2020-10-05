# 挂载（Mount）文件系统（一）

> Mount 命令详解

## 概述

挂载是在使用硬件设备前所执行的最后一步操作，即把硬盘设备或分区与一个目录文件进行关联，然后就能在这个目录中看到硬件设备中的数据了。

## 基本用法

Mount 命令最常用的标准格式如下：

```bash
$ mount -t type -o options device directory
```

- type：文件系统类型（可选）。大部分情况下都不用指定该参数，系统会自动推断设备的文件系统类型；
- options：挂载参数（可选）；
- device：挂载的设备（必填）。有些文件系统不需要指定具体的设备，这里可以随便填一个字符串。
- directory: 挂载到哪个目录（必填）。

## 挂载虚拟文件系统

`proc`、`tmpfs`、`sysfs`、`devpts` 等都是 Linux 内核映射到用户空间的虚拟文件系统，它们不和具体的物理设备关联，但它们具有普通文件系统的特征，应用层程序可以像访问普通文件系统一样来访问它们。

1. 挂载 `proc` 文件系统

```bash
$ mount -t proc none /mnt
```

将内核的 `proc` 文件系统挂载到 `/mnt` ，这样就可以在 `/mnt` 目录下看到系统当前运行的所有进程的信息，由于 `proc` 是内核虚拟的一个文件系统，并没有对应的设备，所以 `-t` 参数必须要指定。`none` 可以是自定义字符串，用 `mount` 命令查看挂载点信息时第一列显示的就是这个字符串。

2. 挂载 `tmpfs` 文件系统

```bash
$ mount -t tmpfs -o size=64m tmpfs /mnt
```

在内存中创建一个64M的 `tmpfs` 文件系统，并挂载到 `/mnt` 下，这样所有写到 `/mnt` 目录下的文件都存储在内存中，速度非常快，不过由于数据存储在内存中，断电后数据会丢失掉。

## 挂载虚拟块设备（Loop Device）

在 Linux 中，硬盘、光盘、软盘等都是常见的块设备，它们在 Linux 下的目录一般是 `/dev/hda1`, `/dev/cdrom`, `/dev/sda1`，`/dev/fd0` 这样的。而 `loop device` 是虚拟的块设备，目的是让用户可以像访问上述块设备那样访问一个文件。

虚拟块设备的路径一般是 `/dev/loop0`, `dev/loop1`，……，具体的个数跟内核的配置有关，不够时可以修改内核参数增加个数。

1. 列出所有虚拟块设备

```bash
$ losetup -a
……
# 太多不列出了
```

2. 挂载 ISO 文件

```bash
# 制作一个用于测试的文件
$ mkdir -p data/sub
$ mkisofs -o data.iso data
$ ls
data/  data.iso

# 挂载到目录 `/mnt`
$ mount data.iso /mnt
mount: /mnt: WARNING: device write-protected, mounted read-only.

# 挂载成功，可以看到里面的文件
$ ls /mnt
sub/
```

3. 挂载虚拟硬盘：尝试 `btrfs` 文件系统

```bash
# `btrfs` 对分区的大小有最小要求，首先创建一个128M的文件
$ dd if=/dev/zero bs=1M count=128 of=vdisk.img
128+0 records in
128+0 records out
134217728 bytes (134 MB, 128 MiB) copied, 0.076348 s, 1.8 GB/s

$ mkfs.btrfs vdisk.img
# 输出一些信息，提示创建成功

# 挂载虚拟硬盘
$ mount vdisk.img /mnt

# 尝试在虚拟硬盘中创建文件
$ touch /mnt/Dockerfile
$ ls /mnt
Dockerfile
```

> **挂载多个设备到一个文件夹**：正如上面两个例子所展示的，Linux 支持将多个设备挂载到一个文件夹，默认后者覆盖前者，只有卸载后者，前者才能重新看到。

4. 挂载一个设备到多个目录

```bash
# 卸载之前的设备
$ umount /mnt

# 新建两个目录用于挂载点
$ mkdir /mnt/disk1 /mnt/disk2

# 将 `vdisk.img` 依次挂载到 `disk1` 和 `disk2`
$ mount vdisk.img /mnt/disk1 && mount vdisk.img /mnt/disk2
$ tree /mnt
/mnt
├── disk1
│   └── Dockerfile
└── disk2
    └── Dockerfile

# 在 `disk1` 中创建一个新文件
$ touch /mnt/disk1/README.md

# 这个文件在 `disk2` 中也能看到
$ tree /mnt
/mnt
├── disk1
│   ├── Dockerfile
│   └── README.md
└── disk2
    ├── Dockerfile
    └── README.md

$ umount /mnt/disk*
```

> 原来文件夹里的文件仍然是存在的，只是看不到而已。因此平时挂载设备的时候不用专门去创建空目录了，随便找个暂时不用的目录挂上去就可以了。

## 绑定挂载（Bind Mount）

> 可以将任何一个挂载点、普通目录或者文件（原目录）挂载到其他地方（目的目录），然后就可以在目的目录下就可以看到源目录里的文件。

1. 将源目录绑定到目的目录

```bash
# 准备两个目录
$ mkdir -p bind/disk1/sub1 bind/disk2/sub2
$ tree bind/
bind/
├── disk1
│   └── sub1
└── disk2
    └── sub2

4 directories, 0 files

# 将 `bind/disk1` 绑定到 `bind/disk2`
$ mount --bind bind/disk1 bind/disk2

# 然后在 `bind/disk2` 显示的就是 `bind/disk1` 里的内容
$ tree bind/
bind/
├── disk1
│   └── sub1
└── disk2
    └── sub1

$ umount bind/disk2
```

2. 绑定自己，让当前目录只读

```bash
$ mount -o bind,ro bind/disk1 bind/disk1

# 创建新文件失败
$ touch bind/disk1/sub1/Dockerfile
touch: cannot touch 'bind/disk1/sub1/Dockerfile': Read-only file system

$ umount bind/disk1
```

3. 绑定挂载单个文件

```bash
# 创建两个用于测试的文件
$ echo 1st > bind/1st && echo 2nd > bind/2nd

# 将文件 `bind/1st` 绑定到 `bind/2nd`
$ mount --bind bind/1st bind/2nd
$ cat bind/2nd 
1st

# 即使删除 `bind/1st` 文件，也在 `bind/2nd` 可以看到其内容

$ umount bind/2nd
```

4. 移动一个挂载点到另一个地方

```bash
# 将 `bind/disk1` 绑定到 `bind/disk2`
$ mount --bind bind/disk1 bind/disk2
$ ls bind/disk*
bind/disk1:
sub1/

bind/disk2:
sub1/

# 移动操作要求挂载点的父挂载点不能是 `shared` 类型
$  findmnt -o TARGET,PROPAGATION /
TARGET PROPAGATION
/      shared

$ mount --make-private /
$ findmnt -o TARGET,PROPAGATION /
TARGET PROPAGATION
/      private

# 移动
$ mount --move bind/disk2 /mnt

$ ls /mnt
sub1/

$ umount /mnt
```
