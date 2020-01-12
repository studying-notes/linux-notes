# chmod 命令

> 改变文件的模式、权限

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

```bash
$ chmod +x example.sh
```
