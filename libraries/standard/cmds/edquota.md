# edquota 命令

> 编辑用户的 quota 配额限制

## 格式

```bash
edquota [-rm] [-u] [-F formatname] [-p username] [-f filesystem] username ...
edquota [-rm] -g [-F formatname] [-p groupname] [-f filesystem] groupname ...
edquota [-u|g] [-F formatname] [-f filesystem] -t
edquota [-u|g] [-F formatname] [-f filesystem] -T username|groupname ...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -u, --user | edit user data |
| -g, --group | edit group data |
| -r, --remote | edit remote quota (via RPC) |
| -m, --no-mixed-pathnames | trim leading slashes from NFSv4 mountpoints |
| -F, --format=formatname | edit quotas of a specific format |
| -p, --prototype=name | copy data from a prototype user/group |
| --always-resolve | always try to resolve name, even if it is composed only of digits |
| -f, --filesystem=filesystem | edit data only on a specific filesystem |
| -t, --edit-period | edit grace period |
| -T, --edit-times | edit grace time of a user/group |
| -h, --help | display this help text and exit |
| -V, --version | display version information and exit |

## 示例

1. 把用户 tom 的硬盘使用量的硬限额提升到 12 MB：

```bash
$ edquota -u tom
Disk quotas for user tom (uid 1002):
  Filesystem                   blocks       soft       hard     inodes     soft     hard
  /dev/sda1                      6144       3072       12288          1        3        6

$ su - tom

$ dd if=/dev/zero of=/boot/tom bs=5M count=2
2+0 records in
2+0 records out
10485760 bytes (10 MB) copied, 0.018781 s, 558 MB/s

$ dd if=/dev/zero of=/boot/tom bs=7M count=2
dd: error writing ‘/boot/tom’: Disk quota exceeded
2+0 records in
1+0 records out
12582912 bytes (13 MB) copied, 0.0289904 s, 434 MB/s
```
