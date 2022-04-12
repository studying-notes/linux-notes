# swapon 命令

> 针对 XFS 文件系统的 quota 磁盘容量配额管理服务

## 格式

```bash
xfs_quota [ -x ] [ -p prog ] [ -c cmd ] ... [ -d project ] ... [ path ... ]
xfs_quota -V
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -c cmd | xfs_quota commands may be run interactively (the default) or as arguments on the command line. Multiple -c arguments may be given. The commands are run in the sequence given, then the program exits. |
| -p prog | Set the program name for prompts and some error messages, the default value is xfs_quota. |
| -x | Enable expert mode. All of the administrative commands (see the ADMINISTRATOR COMMANDS section below) which allow modifications to the quota system are available only in expert mode. |
| -d project | Project names or numeric identifiers may be specified with this option, which restricts the output of the individual xfs_quota commands to the set of projects specified. Multiple -d arguments may be given. |
| -V | Prints the version number and exits. |

## 示例

1. 设置用户 tom 对 `/boot` 目录的 quota 磁盘容量配额：硬盘使用量的软限制和硬限制分别为 3MB 和 6MB；创建文件数量的软限制和硬限制分别为 3 个和 6 个：

```bash
$ xfs_quota -x -c 'limit bsoft=3m bhard=6m isoft=3 ihard=6 tom' /boot
$  xfs_quota -x -c report /boot
User quota on /boot (/dev/sda1)
                               Blocks
User ID          Used       Soft       Hard    Warn/Grace
---------- --------------------------------------------------
root            95344          0          0     00 [--------]
tom                 0       3072       6144     00 [--------]
```

```bash
$ xfs_quota -x -c 'limit bsoft=3m bhard=6m isoft=3 ihard=6 tom' /boot
$  xfs_quota -x -c report /boot
User quota on /boot (/dev/sda1)
                               Blocks
User ID          Used       Soft       Hard    Warn/Grace
---------- --------------------------------------------------
root            95344          0          0     00 [--------]
tom                 0       3072       6144     00 [--------]
```

2. 切换到这个普通用户，然后分别尝试创建一个体积为 5MB 和 10MB 的文件。可以发现，在创建 10MB 的文件时受到了系统限制：

```bash
$ su - tom
Last login: Sat Jan 18 04:47:45 EST 2020 on pts/0

$  dd if=/dev/zero of=/boot/tom bs=5M count=1
1+0 records in
1+0 records out

$ dd if=/dev/zero of=/boot/tom bs=5M count=2
dd: error writing ‘/boot/tom’: Disk quota exceeded
2+0 records in
1+0 records out
6291456 bytes (6.3 MB) copied, 0.0121724 s, 517 MB/s
```
