# cut 命令

> 按列提取文本字符

## 格式

```bash
cut OPTION... [FILE]...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -b, --bytes=LIST | select only these bytes |
| -c, --characters=LIST | select only these characters |
| -d, --delimiter=DELIM | use DELIM instead of TAB for field delimiter |
| -f, --fields=LIST | select only these fields; also print any line that contains no delimiter character, unless the -s option is specified |
| -n | (ignored) |
| --complement | complement the set of selected bytes, characters or fields |
| -s, --only-delimited | do not print lines not containing delimiters |
| --output-delimiter=STRING | use STRING as the output delimiter the default is to use the input delimiter |
| -z, --zero-terminated | line delimiter is NUL, not newline |
| --help | display this help and exit |
| --version | output version information and exit |

- N     N'th byte, character or field, counted from 1
- N-    from N'th byte, character or field, to end of line
- N-M   from N'th to M'th (included) byte, character or field
- -M    from first to M'th (included) byte, character or field

## 示例

1. 提取以 `:` 为间隔符号的第一列内容

```bash
$ head -n2 /etc/passwd
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin

$ cut -d: -f1 /etc/passwd
root
daemon
……
```
