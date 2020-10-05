# lsattr 命令

> 显示文件的隐藏权限

## 格式

```bash
lsattr [-RVadlpv] [files...]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -R | Recursively list attributes of directories and their contents. |
| -V | Display the program version. |
| -a | List all files in directories, including files that start with `.'. |
| -d | List directories like other files, rather than listing their contents. |
| -l | Print the options using long names instead of single character abbreviations. |
| -p | List the file's project number. |
| -v | List the file's version/generation number. |

## 示例

```bash
$ echo 'cxfans' > demo

$ chattr +a demo

$ rm demo
rm: cannot remove 'demo': Operation not permitted

$ lsattr demo
-----a------------ demo

$ chattr -a demo
$ lsattr demo
------------------ demo
```
