# rm 命令

> 移除项目

## 格式

```bash
rm [OPTION]... [FILE]...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -f, --force | ignore nonexistent files and arguments, never prompt |
| -i | prompt before every removal |
| -I | prompt once before removing more than three files, or when removing recursively; less intrusive than -i, while still giving protection against most mistakes |
| --interactive[=WHEN] | prompt according to WHEN: never, once (-I), or always (-i); without WHEN, prompt always |
| --one-file-system | when removing a hierarchy recursively, skip any directory that is on a file system different from that of the corresponding command line argument |
| --no-preserve-root | do not treat '/' specially |
| --preserve-root | do not remove '/' (default) |
| -r, -R, --recursive | remove directories and their contents recursively |
| -d, --dir | remove empty directories |
| -v, --verbose | explain what is being done |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 强制删除目录

```bash
$ rm -rf demo
```

2. 确认每次删除操作

```bash
$ rm -ri demo
```
