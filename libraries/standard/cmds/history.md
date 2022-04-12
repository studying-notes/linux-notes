# history 命令

> 显示、管理以前执行过的命令

## 格式

```bash
history [-c] [-d offset] [n]

history -anrw [filename]

history -ps arg [arg...]
```

- `filename` 默认为 `~/.bash_history`

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -c | clear the history list by deleting all of the entries |
| -d offset | delete the history entry at position OFFSET. |
| -a | append history lines from this session to the history file |
| -n | read all history lines not already read from the history file and append them to the history list |
| -r | read the history file and append the contents to the history list |
| -w | write the current history to the history file |
| -p | perform history expansion on each ARG and display the result without storing it in the history list |
| -s | append the ARGs to the history list as a single entry |

## 示例

1. 显示历史命令

```bash
$ history
```

1. 清空历史命令

```bash
$ history -c
```
