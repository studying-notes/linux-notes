# fdisk 命令

> 管理硬盘设备，提供添加、删除、转换分区等功能

## 格式

```bash
fdisk [options] <disk>      change partition table
fdisk [options] -l [<disk>] list partition table(s)
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -b, --sector-size <size> | physical and logical sector size |
| -B, --protect-boot | don't erase bootbits when creating a new label |
| -c, --compatibility[=<mode>] | mode is 'dos' or 'nondos' (default) |
| -L, --color[=<when>] | colorize output (auto, always or never) colors are enabled by default |
| -l, --list | display partitions and exit |
| -o, --output <list> | output columns |
| -t, --type <type> | recognize specified partition table type only |
| -u, --units[=<unit>] | display units: 'cylinders' or 'sectors' (default) |
| -s, --getsz | display device size in 512-byte sectors [DEPRECATED] |
| --bytes | print SIZE in bytes rather than in human readable format |
| -w, --wipe <mode> | wipe signatures (auto, always or never) |
| -W, --wipe-partitions <mode> | wipe signatures from new partitions (auto, always or never) |
| -C, --cylinders <number> | specify the number of cylinders |
| -H, --heads <number> | specify the number of heads |
| -S, --sectors <number> | specify the number of sectors per track |
| -h, --help | display this help |
| -V, --version | display version |

## 交互式命令

| 命令 | 描述 |
| --------- | --------- |
| m | 查看全部可用的参数 |
| n | 添加新的分区 |
| d | 删除某个分区信息 |
| l | 列出所有可用的分区类型 |
| t | 改变某个分区的类型 |
| p | 查看分区信息 |
| w | 保存并退出 |
| q | 不保存直接退出 |

## 示例

1. 添加新的分区

```bash
$ fdisk /dev/sdb
Welcome to fdisk (util-linux 2.23.2).

Changes will remain in memory only, until you decide to write them.
Be careful before using the write command.

Device does not contain a recognized partition table
Building a new DOS disklabel with disk identifier 0xb146e4bd.

Command (m for help): p

Disk /dev/sdb: 21.5 GB, 21474836480 bytes, 41943040 sectors
Units = sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disk label type: dos
Disk identifier: 0xb146e4bd

   Device Boot      Start         End      Blocks   Id  System

Command (m for help): n
Partition type:
   p   primary (0 primary, 0 extended, 4 free)
   e   extended
Select (default p): p
Partition number (1-4, default 1): 
First sector (2048-41943039, default 2048): 
Using default value 2048
Last sector, +sectors or +size{K,M,G} (2048-41943039, default 41943039): +2G
Partition 1 of type Linux and of size 2 GiB is set

Command (m for help): p

Disk /dev/sdb: 21.5 GB, 21474836480 bytes, 41943040 sectors
Units = sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disk label type: dos
Disk identifier: 0xb146e4bd

   Device Boot      Start         End      Blocks   Id  System
/dev/sdb1            2048     4196351     2097152   83  Linux

Command (m for help): w
The partition table has been altered!

Calling ioctl() to re-read partition table.
Syncing disks.

$ file /dev/sdb1
/dev/sdb1: block special
```
