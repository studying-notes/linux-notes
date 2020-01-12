# mkdir 命令

> 创建目录

## 格式

```bash
mkdir [OPTION]... DIRECTORY...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -m, --mode=MODE | set file mode (as in chmod), not a=rwx - umask |
| -p, --parents | no error if existing, make parent directories as needed |
| -v, --verbose | print a message for each created directory |
| -Z | set SELinux security context of each created directory to the default type |
| --context[=CTX] | like -Z, or if CTX is specified then set the SELinux or SMACK security context to CTX |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 创建目录

```bash
$ mkdir demo
```

2. 创建多层目录

```bash
$ mkdir -p demo/a/b/c/d/e/f/g/h/i/j/k/l/m/n
```
