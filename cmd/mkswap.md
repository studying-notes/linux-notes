# mkswap 命令

> 创建交换分区

## 格式

```bash
mkswap [options] device [size]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -c, --check | check bad blocks before creating the swap area |
| -f, --force | allow swap size area be larger than device |
| -p, --pagesize SIZE | specify page size in bytes |
| -L, --label LABEL | specify label |
| -v, --swapversion NUM | specify swap-space version number |
| -U, --uuid UUID | specify the uuid to use |
| -V, --version | output version information and exit |
| -h, --help | display this help and exit |

## 示例

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
