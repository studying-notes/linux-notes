# tail 命令

> 默认打印每个文件的后 10 行到标准输出

## 格式

```bash
tail [OPTION]... [FILE]...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -c, --bytes=[+]NUM | output the last NUM bytes; or use -c +NUM to output starting with byte NUM of each file |
| -f, --follow[={name\|descriptor}] | output appended data as the file grows; an absent option argument means 'descriptor' |
| -F | same as --follow=name --retry |
| -n, --lines=[+]NUM | output the last NUM lines, instead of the last 10; or use -n +NUM to output starting with line NUM |
| --max-unchanged-stats=N | with --follow=name, reopen a FILE which has not changed size after N (default 5) iterations to see if it has been unlinked or renamed (this is the usual case of rotated log files); with inotify, this option is rarely useful |
| --pid=PID | with -f, terminate after process ID, PID dies |
| -q, --quiet, --silent | never output headers giving file names |
| --retry | keep trying to open a file if it is inaccessible |
| -s, --sleep-interval=N | with -f, sleep for approximately N seconds (default 1.0) between iterations; with inotify and --pid=P, check process P at least once every N seconds |
| -v, --verbose | always output headers giving file names |
| -z, --zero-terminated | line delimiter is NUL, not newline |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 输出文件后 20 行

```bash
$ tail -n 20 FILE
```

2. 持续刷新一个文件的内容

```bash
$ tail -f FILE
```

## 相关命令

- [head](head.md)
