# id 命令

> 显示指定用户的相关信息

## 格式

```bash
id [OPTION]... [USER]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a | ignore, for compatibility with other versions |
| -Z, --context | print only the security context of the process |
| -g, --group | print only the effective group ID |
| -G, --groups | print all group IDs |
| -n, --name | print a name instead of a number, for -ugG |
| -r, --real | print the real ID instead of the effective ID, with -ugG |
| -u, --user | print only the effective user ID |
| -z, --zero | delimit entries with NUL characters, not whitespace; not permitted in default format |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

```bash
$ id
uid=0(root) gid=0(root) groups=0(root)
```

## 相关命令

- [useradd](useradd.md)
- [halt](halt.md)
- [reboot](reboot.md)
- [ctrlaltdel](ctrlaltdel.md)
