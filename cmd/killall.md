# killall 命令

> 终止某个指定名称的服务所对应的全部进程

## 格式

```bash
killall [ -Z CONTEXT ] [ -u USER ] [ -y TIME ] [ -o TIME ] [ -eIgiqrvw ] [ -s SIGNAL | -SIGNAL ] NAME...

killall -l, --list

killall -V, --version
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -e,--exact | require exact match for very long names |
| -I,--ignore-case | case insensitive process name match |
| -g,--process-group | kill process group instead of process |
| -y,--younger-than | kill processes younger than TIME |
| -o,--older-than | kill processes older than TIME |
| -i,--interactive | ask for confirmation before killing |
| -l,--list | list all known signal names |
| -q,--quiet | don't print complaints |
| -r,--regexp | interpret NAME as an extended regular expression |
| -s,--signal SIGNAL | send this signal instead of SIGTERM |
| -u,--user USER | kill only process(es) running as USER |
| -v,--verbose | report if the signal was successfully sent |
| -V,--version | display version information |
| -w,--wait | wait for processes to die |
| -n,--ns PID | match processes that belong to the same namespaces as PID or 0 for all namespaces |
| -Z,--context REGEXP | kill only process(es) having context (must precede other arguments) |

## 示例

1. 终止指定名称的服务所对应的全部进程

```bash
$ sleep 10000 &
[1] 4918
$ sleep 10000 &
[2] 4919
$ sleep 10000 &
[3] 4920
$ sleep 10000 &
[4] 4921
$ sleep 10000 &
[5] 4922
$ sleep 10000 &
[6] 4923
$ sleep 10000 &
[7] 4924
$ sleep 10000 &
[8] 4925
$ sleep 10000 &
[9] 4926

$ pidof sleep
4926 4925 4924 4923 4922 4921 4920 4919 4918 4917

$ killall sleep
[1]   Terminated              sleep 10000
[2]   Terminated              sleep 10000
[3]   Terminated              sleep 10000
[4]   Terminated              sleep 10000
[5]   Terminated              sleep 10000
[6]   Terminated              sleep 10000
[7]   Terminated              sleep 10000
[8]   Terminated              sleep 10000
[9]   Terminated              sleep 10000
```

## 相关命令

- [kill](kill.md)
