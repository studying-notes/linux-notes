# mkfs 命令

> 格式化硬盘，创建文件系统

## 格式

```bash
mkfs [options] [-t <type>] [fs-options] <device> [<size>]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -t, --type=<type> | filesystem type; when unspecified, ext2 is used |
| fs-options | parameters for the real filesystem builder |
| <device> | path to the device to be used |
| <size> | number of blocks to be used on the device |
| -V, --verbose | explain what is being done; specifying -V more than once will cause a dry-run |
| -h, --help | display this help |
| -V, --version | display version |

## 示例

1. 显示可创建的文件系统

```bash
$ mkfs  # 2次 Tab 键
mkfs         mkfs.cramfs  mkfs.ext4    mkfs.msdos
mkfs.bfs     mkfs.ext2    mkfs.fat     mkfs.ntfs
mkfs.btrfs   mkfs.ext3    mkfs.minix   mkfs.vfat
```

2. 创建文件系统

```bash
$ mkfs.xfs /dev/sdb1
meta-data=/dev/sdb1              isize=256    agcount=4, agsize=131072 blks
         =                       sectsz=512   attr=2, projid32bit=1
         =                       crc=0
data     =                       bsize=4096   blocks=524288, imaxpct=25
         =                       sunit=0      swidth=0 blks
naming   =version 2              bsize=4096   ascii-ci=0 ftype=0
log      =internal log           bsize=4096   blocks=2560, version=2
         =                       sectsz=512   sunit=0 blks, lazy-count=1
realtime =none                   extsz=4096   blocks=0, rtextents=0
```
