# chown 命令

> 设置文件或目录的所有者和所属组

## 格式

```bash
chown [OPTION]... [OWNER][:[GROUP]] FILE...

chown [OPTION]... --reference=RFILE FILE...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -c, --changes | like verbose but report only when a change is made |
| -f, --silent, --quiet | suppress most error messages |
| -v, --verbose | output a diagnostic for every file processed |
| --dereference | affect the referent of each symbolic link (this is the default), rather than the symbolic link itself |
| -h, --no-dereference | affect symbolic links instead of any referenced file (useful only on systems that can change the ownership of a symlink) |
| --from=CURRENT_OWNER:CURRENT_GROUP | change the owner and/or group of each file only if its current owner and/or group match those specified here. Either may be omitted, in which case a match is not required for the omitted attribute |
| --no-preserve-root | do not treat '/' specially (the default) |
| --preserve-root | fail to operate recursively on '/' |
| --reference=RFILE | use RFILE's owner and group rather than specifying OWNER:GROUP values |
| -R, --recursive | operate on files and directories recursively |
| -H | if a command line argument is a symbolic link to a directory, traverse it |
| -L | traverse every symbolic link to a directory encountered |
| -P | do not traverse any symbolic links (default) |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 设置文件或目录的所有者和所属组

```bash
$ chown root:bin example.sh
```
