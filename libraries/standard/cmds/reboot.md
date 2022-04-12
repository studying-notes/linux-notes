# reboot 命令

> 重启系统

## 格式

```bash
reboot [OPTIONS...] [ARG]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| --help | Show this help |
| --halt | Halt the machine |
| -p --poweroff | Switch off the machine |
| --reboot | Reboot the machine |
| -f --force | Force immediate halt/power-off/reboot |
| -w --wtmp-only | Don't halt/power-off/reboot, just write wtmp record |
| -d --no-wtmp | Don't write wtmp record |
| --no-wall | Don't send wall message before halt/power-off/reboot |

## 示例

1. 重启系统

```bash
$ reboot
```

2. 不重启，只是写入重启记录

```bash
$ reboot -w
```

## 相关命令

- [shutdown](shutdown.md)
- [halt](halt.md)
- [poweroff](poweroff.md)
- [ctrlaltdel](ctrlaltdel.md)
