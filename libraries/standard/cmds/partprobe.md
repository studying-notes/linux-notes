# partprobe 命令

> 通知操作系统分区表的更改

## 格式

```bash
partprobe [OPTION] [DEVICE]...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -d, --dry-run | do not actually inform the operating system |
| -s, --summary | print a summary of contents |
| -h, --help | display this help and exit |
| -v, --version | output version information and exit |

## 示例

1. 不给出 DEVICE 时，默认检测全部分区

```bash
$ partprobe
```
