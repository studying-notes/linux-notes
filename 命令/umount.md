# umount 命令

> 卸载文件系统

## 格式

```bash
umount [-hV]
umount -a [options]
umount [options] <source> | <directory>
```

## 参数

### Options

| 参数 | 作用 |
| --------- | --------- |
| -a, --all | unmount all filesystems |
| -A, --all-targets | unmount all mountpoints for the given device in the current namespace |
| -c, --no-canonicalize | don't canonicalize paths |
| -d, --detach-loop | if mounted loop device, also free this loop device |
| --fake | dry run; skip the umount(2) syscall |
| -f, --force | force unmount (in case of an unreachable NFS system) |
| -i, --internal-only | don't call the umount.<type> helpers |
| -n, --no-mtab | don't write to /etc/mtab |
| -l, --lazy | detach the filesystem now, clean up things later |
| -O, --test-opts <list> | limit the set of filesystems (use with -a) |
| -R, --recursive | recursively unmount a target with all its children |
| -r, --read-only | in case unmounting fails, try to remount read-only |
| -t, --types <list> | limit the set of filesystem types |
| -v, --verbose | say what is being done |
| -h, --help | display this help |
| -V, --version | display version |

## 示例

1. 卸载硬盘设备

```bash
$ umount /dev/sdb2
```
