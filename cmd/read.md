# read 命令

> 从标准输入读取一行，依次赋值

## 格式

```bash
read [-ers] [-a array] [-d delim] [-i text] [-n nchars] [-N nchars] [-p prompt] [-t timeout] [-u fd] [NAME ...]
```

- 从标准输入读取一行，然后根据 `NAME` 个数分割依次赋值，剩余部分全部赋值给最后一个 `NAME`。
- 仅 `$IFS` 中的字符被视为分割符。
- 若未提供 `NAME`，则读取数据被存储在 `REPLY` 中。

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a array | assign the words read to sequential indices of the array variable ARRAY, starting at zero |
| -d delim | continue until the first character of DELIM is read, rather than newline |
| -e | use Readline to obtain the line in an interactive shell |
| -i text | use TEXT as the initial text for Readline |
| -n nchars | return after reading NCHARS characters rather than waiting for a newline, but honor a delimiter if fewer than NCHARS characters are read before the delimiter |
| -N nchars | return only after reading exactly NCHARS characters, unless EOF is encountered or read times out, ignoring any delimiter |
| -p prompt | output the string PROMPT without a trailing newline before attempting to read |
| -r | do not allow backslashes to escape any characters |
| -s | do not echo input coming from a terminal |
| -t timeout | time out and return failure if a complete line of input is not read within TIMEOUT seconds.  The value of the TMOUT variable is the default timeout.  TIMEOUT may be a fractional number.  If TIMEOUT is 0, read returns immediately, without trying to read any data, returning success only if input is available on the specified file descriptor.  The exit status is greater than 128 if the timeout is exceeded |
| -u fd | read from file descriptor FD instead of the standard input |

## 示例

1. 读取赋值

```bash
$ read -p "Enter The Users Password : " PASSWD
Enter The Users Password : 1234

$ echo $PASSWD
1234
```
