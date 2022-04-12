# touch 命令

> 更新文件的访问、修改时间为当前时间，常用来创建空白文件

## 格式

```bash
touch [OPTION]... FILE...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a | change only the access time |
| -c, --no-create | do not create any files |
| -d, --date=STRING | parse STRING and use it instead of current time |
| -f | (ignored) |
| -h, --no-dereference | affect each symbolic link instead of any referenced file (useful only on systems that can change the timestamps of a symlink) |
| -m | change only the modification time |
| -r, --reference=FILE | use this file's times instead of current time |
| -t STAMP | use `[[CC]YY]MMDDhhmm[.ss]` instead of current time |
| --time=WORD | change the specified time: WORD is access, atime, or use: equivalent to -a; WORD is modify or mtime: equivalent to -m |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 创建空白文件

```bash
$ touch demo
$ ls -l demo
-rw-r--r-- 1 root root 12 Jan 10 12:08 demo
```
