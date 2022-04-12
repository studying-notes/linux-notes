# export 命令

> 在当前会话新增、修改或删除环境变量

## 格式

```bash
export [-fn] [NAME[=VALUE] ...]
export -p
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -f | 代表 [NAME] 中为函数名称 |
| -n | 删除指定的变量，仅当前会话有效 |
| -p | 列出全部导出的变量和函数 |

## 示例

1. 新增临时环境变量

```bash
$ mkdir /root/workdir
$ WORKDIR=/root/workdir
$ echo $WORKDIR
/root/workdir

$ export WORKDIR
```
