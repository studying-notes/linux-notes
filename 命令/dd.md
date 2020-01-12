# dd 命令

> 按照指定大小和个数的数据块来复制文件或转换文件

## 格式

```bash
dd [OPERAND]...

dd OPTION
```

## 参数

### OPERAND

| 参数 | 作用 |
| --------- | --------- |
| bs=BYTES | read and write up to BYTES bytes at a time (default: 512); overrides ibs and obs |
| cbs=BYTES | convert BYTES bytes at a time |
| conv=CONVS | convert the file as per the comma separated symbol list |
| count=N | copy only N input blocks |
| ibs=BYTES | read up to BYTES bytes at a time (default: 512) |
| if=FILE | read from FILE instead of stdin |
| iflag=FLAGS | read as per the comma separated symbol list |
| obs=BYTES | write BYTES bytes at a time (default: 512) |
| of=FILE | write to FILE instead of stdout |
| oflag=FLAGS | write as per the comma separated symbol list |
| seek=N | skip N obs-sized blocks at start of output |
| skip=N | skip N ibs-sized blocks at start of input |
| status=LEVEL | The LEVEL of information to print to stderr; 'none' suppresses everything but error messages, 'noxfer' suppresses the final transfer statistics, 'progress' shows periodic transfer statistics |

- N and BYTES may be followed by the following multiplicative suffixes:
c =1, w =2, b =512, kB =1000, K =1024, MB =1000\*1000, M =1024\*1024, xM =M,
GB =1000\*1000\*1000, G =1024\*1024\*1024, and so on for T, P, E, Z, Y.

### CONV

| 参数 | 作用 |
| --------- | --------- |
| append | append mode (makes sense only for output; conv=notrunc suggested) |
| direct | use direct I/O for data |
| directory | fail unless a directory |
| dsync | use synchronized I/O for data |
| sync | likewise, but also for metadata |
| fullblock | accumulate full blocks of input (iflag only) |
| nonblock | use non-blocking I/O |
| noatime | do not update access time |
| nocache | Request to drop cache.  See also oflag=sync |
| noctty | do not assign controlling terminal from file |
| nofollow | do not follow symlinks |
| count_bytes | treat 'count=N' as a byte count (iflag only) |
| skip_bytes | treat 'skip=N' as a byte count (iflag only) |
| seek_bytes | treat 'seek=N' as a byte count (oflag only) |

### OPTIONS

| 参数 | 作用 |
| --------- | --------- |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 从 /dev/zero 中取出一个大小为 560 MB 数据块，然后保存为 560_file

```bash
$ dd if=/dev/zero of=560_file count=1 bs=560M
1+0 records in
1+0 records out
587202560 bytes (587 MB, 560 MiB) copied, 5.89275 s, 99.6 MB/s

$ ls -lh 560_file
-rw-r--r-- 1 root root 560M Jan 10 13:06 560_file
```

2. 将光驱设备中的光盘制作成虚拟光盘文件

```bash
$ dd if=/dev/cdrom of=ubuntu-18.04.3-desktop-amd64.iso
records in
4068000+0 records out
2082816000 bytes (2.1 GB) copied, 112.291 s, 18.5 MB/s
```
