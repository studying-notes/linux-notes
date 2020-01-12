# uptime 命令

> 显示当前用户名及其启动的终端信息

## 格式

```bash
who [OPTION]... [ FILE | ARG1 ARG2 ]
```

- `FILE` 默认为 `/var/run/utmp`

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a, --all | same as -b -d --login -p -r -t -T -u |
| -b, --boot | time of last system boot |
| -d, --dead | print dead processes |
| -H, --heading | print line of column headings |
| --ips | print ips instead of hostnames. with --lookup, canonicalizes based on stored IP, if available, rather than stored hostname |
| -l, --login | print system login processes |
| --lookup | attempt to canonicalize hostnames via DNS |
| -m | only hostname and user associated with stdin |
| -p, --process | print active processes spawned by init |
| -q, --count | all login names and number of users logged on |
| -r, --runlevel | print current runlevel |
| -s, --short | print only name, line, and time (default) |
| -t, --time | print last system clock change |
| -T, -w, --mesg | add user's message status as +, - or ? |
| -u, --users | list users logged in |
| --message | same as -T |
| --writable | same as -T |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 当前用户名及其启动的终端信息

```bash
$ who
admin    :0           2019-12-08 07:27 (:0)
admin    pts/0        2020-01-07 02:38 (:0)
admin    pts/1        2020-01-09 03:49 (:0)
```
