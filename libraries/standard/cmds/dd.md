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

## 实例

### 快速生成大文件或者小文件

```bash
dd if=/dev/zero of=test bs=1M count=1000
```

在当前目录下会生成一个 1000M 的 test 文件，文件内容为全 0（因从 /dev/zero 中读取，/dev/zero 为 0 源），但是这样为实际写入硬盘，文件产生速度取决于硬盘读写速度，如果欲产生超大文件，速度很慢。

在某种场景下，我们只想让文件系统认为存在一个超大文件在此，但是并不实际写入硬盘。

```bash
dd if=/dev/zero of=test bs=1M count=0 seek=100000
```

此时创建的文件在文件系统中的显示大小为 100000MB，但是并不实际占用 block，因此创建速度与内存速度相当，seek 的作用是跳过输出文件中指定大小的部分，这就达到了创建大文件，但是并不实际写入的目的。当然，因为不实际写入硬盘，所以你在容量只有 10G 的硬盘上创建 100G 的此类文件都是可以的。

### 随机生成 1 百万个 1K 的文件

```bash
seq 1000000 | xargs -i dd if=/dev/zero of={}.dat bs=1024 count=1
```

```bash
seq 100 | xargs -i dd if=/dev/zero of={}.dat bs=10M count=1
```
