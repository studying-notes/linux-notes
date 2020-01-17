# chmod 命令

> 设置文件或目录的权限

## 格式

```bash
chmod [OPTION]... MODE[,MODE]... FILE...

chmod [OPTION]... OCTAL-MODE FILE...

chmod [OPTION]... --reference=RFILE FILE...
```

- MODE - [ugoa]*([-+=]([rwxXst]*|[ugo]))+|[-+=][0-7]+

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -c, --changes | like verbose but report only when a change is made |
| -f, --silent, --quiet | suppress most error messages |
| -v, --verbose | output a diagnostic for every file processed |
| --no-preserve-root | do not treat '/' specially (the default) |
| --preserve-root | fail to operate recursively on '/' |
| --reference=RFILE | use RFILE's mode instead of MODE values |
| -R, --recursive | change files and directories recursively |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 赋予可执行权限

```bash
$ chmod +x example.sh
```

2. 递归赋予权限，忽略大部分错误信息

```bash
$ chmod -Rf 777 dir
```

3. 设置 SGID 特殊权限位

```bash
$ chmod -Rf g+s sharedir
$ ls -ld sharedir
drwxrwsrwx 2 root root 4096 Jan 15 18:28 sharedir
```

4. 设置 SBIT 特殊权限位

```bash
$ chmod -R o+t sharedir
$ ls -ld sharedir
drwxrwsrwt 2 root root 4096 Jan 15 18:28 sharedir
```
