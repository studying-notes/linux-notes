# df 命令

> 显示文件系统的信息

## 格式

```bash
df [OPTION]... [FILE]...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a, --all | include pseudo, duplicate, inaccessible file systems |
| -B, --block-size=SIZE | scale sizes by SIZE before printing them; e.g., '-BM' prints sizes in units of 1,048,576 bytes; see SIZE format below |
| -h, --human-readable | print sizes in powers of 1024 (e.g., 1023M) |
| -H, --si | print sizes in powers of 1000 (e.g., 1.1G) |
| -i, --inodes | list inode information instead of block usage |
| -k | like --block-size=1K |
| -l, --local | limit listing to local file systems |
| --no-sync | do not invoke sync before getting usage info (default) |
| --output[=FIELD_LIST] | use the output format defined by FIELD_LIST, or print all fields if FIELD_LIST is omitted. |
| -P, --portability | use the POSIX output format |
| --sync | invoke sync before getting usage info |
| --total | elide all entries insignificant to available space, and produce a grand total |
| -t, --type=TYPE | limit listing to file systems of type TYPE |
| -T, --print-type | print file system type |
| -x, --exclude-type=TYPE | limit listing to file systems not of type TYPE |
| -v | (ignored) |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 默认显示全部的文件系统信息

```bash
$ df -h
Filesystem      Size  Used Avail Use% Mounted on
udev            471M     0  471M   0% /dev
tmpfs            99M  5.4M   94M   6% /run
/dev/vda1        40G   16G   22G  43% /
tmpfs           493M     0  493M   0% /dev/shm
tmpfs           5.0M     0  5.0M   0% /run/lock
tmpfs           493M     0  493M   0% /sys/fs/cgroup
overlay          40G   16G   22G  43% /var/lib/docker/overlay2/62ec7aacbc058a26baa11db6fdeafacdd781315136cf77b39014fbb2f611cc47/merged
shm              64M     0   64M   0% /var/lib/docker/containers/28e0b7f562fd76c1de5482cae4c13df72867f4cb2d0efc677e5ed3afc34fa7ee/mounts/shm
tmpfs            99M     0   99M   0% /run/user/0
```
