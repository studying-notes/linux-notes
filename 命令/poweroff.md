# poweroff 命令

> 关闭操作系统，然后切断系统电源

## 格式

```bash
poweroff [OPTIONS...]
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

1. 立即关机

```bash
$ poweroff
```

## 相关命令

- [shutdown](shutdown.md)
- [halt](halt.md)
- [reboot](reboot.md)
- [ctrlaltdel](ctrlaltdel.md)
