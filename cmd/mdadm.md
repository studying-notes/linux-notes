# mdadm 命令

> 管理 RAID 硬盘阵列

## 格式

```bash
mdadm [mode] <raiddevice> [options] <component-devices>
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a | 自动创建设备文件 |
| -n | 指定设备数量 |
| -l | 指定 RAID 级别 |
| -C | 创建一个 RAID 阵列卡 |
| -v | 显示创建的过程 |
| -f | 模拟设备损坏 |
| -r | 移除设备 |
| -Q | 查看摘要信息 |
| -D | 查看详细信息 |
| -S | 停止 RAID 磁盘阵列 |

## 示例

1. 部署 RAID 磁盘阵列

```bash
$ mdadm -Cv /dev/md0 -a yes -n 4 -l 10 /dev/sdb /dev/sdc /dev/sdd /dev/sde
mdadm: layout defaults to n2
mdadm: layout defaults to n2
mdadm: chunk size defaults to 512K
mdadm: /dev/sdb appears to be part of a raid array:
    level=raid0 devices=0 ctime=Wed Dec 31 19:00:00 1969
mdadm: partition table exists on /dev/sdb but will be lost or
       meaningless after creating array
mdadm: size set to 20954624K
Continue creating array? yes
mdadm: Defaulting to version 1.2 metadata
mdadm: array /dev/md0 started.
```

- `-C` 参数代表创建一个 RAID 阵列卡
- `-v` 参数显示创建的过程，同时在后面追加一个设备名称 `/dev/md0`，这样 `/dev/md0` 就是创建后的 RAID 磁盘阵列的名称
- `-a yes` 参数代表自动创建设备文件
- `-n 4` 参数代表使用 4 块硬盘来部署这个 RAID 磁盘阵列
- `-l 10` 参数则代表 RAID 10 方案
- 最后再加上 4 块硬盘设备的名称

2. 把制作好的 RAID 磁盘阵列格式化为 ext4 格式

```bash
$ mkfs.ext4 /dev/md0
mke2fs 1.42.9 (28-Dec-2013)
Filesystem label=
OS type: Linux
Block size=4096 (log=2)
Fragment size=4096 (log=2)
Stride=128 blocks, Stripe width=256 blocks
2621440 inodes, 10477312 blocks
523865 blocks (5.00%) reserved for the super user
First data block=0
Maximum filesystem blocks=2157969408
320 block groups
32768 blocks per group, 32768 fragments per group
8192 inodes per group
Superblock backups stored on blocks: 
	32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632, 2654208, 
	4096000, 7962624

Allocating group tables: done                            
Writing inode tables: done                            
Creating journal (32768 blocks): done
Writing superblocks and filesystem accounting information: done
```

3. 创建挂载点然后把硬盘设备进行挂载操作

```bash
$ mkdir /raid
$ mount /dev/md0 /raid

$ df -h
Filesystem                    Size  Used Avail Use% Mounted on
/dev/mapper/rhel_redhat-root   18G  4.9G   13G  28% /
devtmpfs                      985M     0  985M   0% /dev
tmpfs                         994M   92K  994M   1% /dev/shm
tmpfs                         994M  8.8M  986M   1% /run
tmpfs                         994M     0  994M   0% /sys/fs/cgroup
/dev/md0                       40G   49M   38G   1% /raid
```

4. 磁盘阵列的详细信息

```bash
$ mdadm -D /dev/md0
/dev/md0:
        Version : 1.2
  Creation Time : Sun Jan 19 02:38:03 2020
     Raid Level : raid10
     Array Size : 41909248 (39.97 GiB 42.92 GB)
  Used Dev Size : 20954624 (19.98 GiB 21.46 GB)
   Raid Devices : 4
  Total Devices : 4
    Persistence : Superblock is persistent

    Update Time : Sun Jan 19 02:44:16 2020
          State : clean 
 Active Devices : 4
Working Devices : 4
 Failed Devices : 0
  Spare Devices : 0

         Layout : near=2
     Chunk Size : 512K

           Name : redhat:0  (local to host redhat)
           UUID : 3e16a2ff:0c39ed76:5ea9fa4a:5aaa0322
         Events : 19

    Number   Major   Minor   RaidDevice State
       0       8       16        0      active sync   /dev/sdb
       1       8       32        1      active sync   /dev/sdc
       2       8       48        2      active sync   /dev/sdd
       3       8       64        3      active sync   /dev/sde
```

5. 把挂载信息写入到配置文件中，使其永久生效

```bash
$ echo "/dev/md0 /RAID ext4 defaults 0 0" >> /etc/fstab
```
