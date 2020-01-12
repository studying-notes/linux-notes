# uptime 命令

> 查询系统负载信息。

## 格式

```bash
uptime [options]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -p, --pretty | show uptime in pretty format |
| -s, --since | system up since |
| -h, --help | display this help and exit |
| -V, --version | output version information and exit |

## 示例

1. 显示系统负载信息

```bash
$ uptime
16:56:10 up 1 day,  2:26,  0 users,  load average: 0.12, 0.07, 0.02
```

- 依次是当前系统时间、系统已运行时间、启用终端数量以及平均负载值等信息。
- 平均负载值指的是系统在最近 1分钟、 5分钟、 15分钟内的压力情况；负载值越低越好，尽量不要长期超过 1，在生产环境中不要超过 5。
