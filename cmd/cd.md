# cd 命令

> 改变当前工作目录

## 格式

```bash
cd [-L|[-P [-e]]] [dir]
```

- `dir` 默认为 `HOME`

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -L | Use the logical working directory, without resolving symlinks (default behavior) |
| -P | Use the physical working directory, with symlinks resolved |
| -e | Supply with -P, and the current working directory cannot be successfully determined after a successful directory change, cd will return an unsuccessful status. |

## 示例

```bash
$ cd
```
