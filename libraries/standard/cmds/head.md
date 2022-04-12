# head 命令

> 默认打印每个文件的前 10 行到标准输出

## 格式

```bash
head [OPTION]... [FILE]...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -c, --bytes=[-]NUM | print the first NUM bytes of each file; with the leading '-', print all but the last NUM bytes of each file |
| -n, --lines=[-]NUM | print the first NUM lines instead of the first 10; with the leading '-', print all but the last NUM lines of each file |
| -q, --quiet, --silent | never print headers giving file names |
| -v, --verbose | always print headers giving file names |
| -z, --zero-terminated | line delimiter is NUL, not newline |
| --help | display this help and exit |
| --version | output version information and exit |


## 示例

1. 输出文件前 20 行

```bash
$ head -n 20 FILE
```

## 相关命令

- [tail](tail.md)
