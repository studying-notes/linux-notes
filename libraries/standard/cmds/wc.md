# wc 命令

> 统计指定文本的行数、单词数、字符数、字节数等

## 格式

```bash
wc [OPTION]... [FILE]...

wc [OPTION]... --files0-from=F
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -c, --bytes | print the byte counts |
| -m, --chars | print the character counts |
| -l, --lines | print the newline counts |
| --files0-from=F | read input from the files specified by NUL-terminated names in file F; If F is - then read names from standard input |
| -L, --max-line-length | print the maximum display width |
| -w, --words | print the word counts |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 统计行数

```bash
$ wc -l /etc/passwd
27 /etc/passwd
```
