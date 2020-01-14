# whereis 命令

> 定位二进制执行文件、源文件、手册主页文件的位置

## 格式

```bash
whereis [options] [-BMS <dir>... -f] <name>
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -b | search only for binaries |
| -B <dirs> | define binaries lookup path |
| -m | search only for manuals and infos |
| -M <dirs> | define man and info lookup path |
| -s | search only for sources |
| -S <dirs> | define sources lookup path |
| -f | terminate <dirs> argument list |
| -u | search for unusual entries |
| -l | output effective lookup paths |
| -h, --help | display this help |
| -V, --version | display version |

## 示例

```bash
$ whereis rm
rm: /bin/rm /usr/share/man/man1/rm.1.gz
```
