# uname 命令

> 获取当前系统信息，包括当前系统的内核名称、主机名、内核发行版本、节点名、系统时间、硬件名称、硬件平台、处理器类型以及操作系统名称等信息。

## 格式

```bash
uname [OPTION]...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a, --all | print all information |
| -s, --kernel-name | print the kernel name |
| -n, --nodename | print the network node hostname |
| -r, --kernel-release | print the kernel release |
| -v, --kernel-version | print the kernel version |
| -m, --machine | print the machine hardware name |
| -p, --processor | print the processor type (non-portable) |
| -i, --hardware-platform | print the hardware platform (non-portable) |
| -o, --operating-system | print the operating system |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 显示全部信息

```bash
$ uname -a
Linux aliyun 4.15.0-70-generic #79-Ubuntu SMP Tue Nov 12 10:36:11 UTC 2019 x86_64 x86_64 x86_64 GNU/Linux
```

2. 发行版本详细信息

```bash
# Red Hat
$ cat /etc/redhat-release
Red Hat Enterprise Linux Server release 7.0 (Maipo)

# Ubuntu
$ cat /etc/issue
Ubuntu 18.04.3 LTS \n \l
```
