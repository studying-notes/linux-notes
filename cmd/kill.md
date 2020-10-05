# kill 命令

> 终止某个指定 PID 的服务进程

## 格式

```bash
kill [options] <pid> [...]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| <pid> [...] | send signal to every <pid> listed |
| -<signal>, -s, --signal <signal> | specify the <signal> to be sent |
| -l, --list=[<signal>] | list all signal names, or convert one to a name |
| -L, --table | list all signal names in a nice table |
| -h, --help | display this help and exit |
| -V, --version | output version information and exit |

## 示例

1. 终止指定 PID 的服务进程

```bash
$ sleep 10000 &
[1] 4900

$ pidof -s sleep
4900

$ kill 4900
```

## 相关命令

- [killall](killall.md)
