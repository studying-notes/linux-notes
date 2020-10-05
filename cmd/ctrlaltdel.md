# ctrlaltdel 命令

> 设置组合键 `Ctrl+Alt+Del` 的功能

## 格式

```bash
ctrlaltdel hard|soft
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -h, --help | display this help |
| -V, --version | display version |

### 备注

- Hard：当按下组合键 `Ctrl+Alt+Del` 时，立即执行重新启动操作系统的操作，而不是先执行 [`sync`](http://man.linuxde.net/sync) 系统调用和其他的标准关机操作。
- Soft：当按下组合键 `Ctrl+Alt+Del` 时，首先向 [`init`](http://man.linuxde.net/init) 进程发送 `SIGINT` 信号，然后由 `init` 进程处理关机操作。

## 相关命令

- [poweroff](poweroff.md)
- [poweroff](poweroff.md)
- [reboot](reboot.md)
- [halt](halt.md)
