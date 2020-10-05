# mount 命令

> 挂载文件系统

## 格式

```bash
mount [-lhV]
mount -a [options]
mount [options] [--source] <source> | [--target] <directory>
mount [options] <source> <directory>
mount <operation> <mountpoint> [<target>]
```

## 参数

### Options

| 参数 | 作用 |
| --------- | --------- |
| -a, --all | mount all filesystems mentioned in `/etc/fstab` |
| -c, --no-canonicalize | don't canonicalize paths |
| -f, --fake | dry run; skip the mount(2) syscall |
| -F, --fork | fork off for each device (use with -a) |
| -T, --fstab <path> | alternative file to /etc/fstab |
| -i, --internal-only | don't call the mount.<type> helpers |
| -l, --show-labels | show also filesystem labels |
| -n, --no-mtab | don't write to /etc/mtab |
| -o, --options <list> | comma-separated list of mount options |
| -O, --test-opts <list> | limit the set of filesystems (use with -a) |
| -r, --read-only | mount the filesystem read-only (same as -o ro) |
| -t, --types <list> | limit the set of filesystem types |
| --source <src> | explicitly specifies source (path, label, uuid) |
| --target <target> | explicitly specifies mountpoint |
| -v, --verbose | say what is being done |
| -w, --rw, --read-write | mount the filesystem read-write (default) |
| -h, --help | display this help |
| -V, --version | display version |

### Source

| 参数 | 作用 |
| --------- | --------- |
| -L, --label <label> | synonym for LABEL=<label> |
| -U, --uuid <uuid> | synonym for UUID=<uuid> |
| LABEL=<label> | specifies device by filesystem label |
| UUID=<uuid> | specifies device by filesystem UUID |
| PARTLABEL=<label> | specifies device by partition label |
| PARTUUID=<uuid> | specifies device by partition UUID |
| <device> | specifies device by path |
| <directory> | mountpoint for bind mounts (see --bind/rbind) |
| <file> | regular file for loopdev setup |

### Operations

| 参数 | 作用 |
| --------- | --------- |
| -B, --bind | mount a subtree somewhere else (same as -o bind) |
| -M, --move | move a subtree to some other place |
| -R, --rbind | mount a subtree and all submounts somewhere else |
| --make-shared | mark a subtree as shared |
| --make-slave | mark a subtree as slave |
| --make-private | mark a subtree as private |
| --make-unbindable | mark a subtree as unbindable |
| --make-rshared | recursively mark a whole subtree as shared |
| --make-rslave | recursively mark a whole subtree as slave |
| --make-rprivate | recursively mark a whole subtree as private |
| --make-runbindable | recursively mark a whole subtree as unbindable |

## 示例

1. 挂载硬盘设备

```bash
$ mount /dev/sdb2 /backup
```

按照上面的方法执行 `mount` 命令后就能立即使用文件系统了，但系统在重启后挂载就会失效。如果想让硬件设备和目录永久地进行自动关联，就必须把挂载信息按照指定的填写格式“设备文件 挂载目录 格式类型 权限选项 是否备份 是否自检”写入到 `/etc/fstab` 文件中。这个文件中包含着挂载所需的诸多信息项目，一旦配置好之后就能一劳永逸了。

| 字段 | 描述 |
| --------- | --------- |
| 设备文件 | 一般为设备的路径+设备名称，也可以写唯一识别码（UUID，Universally Unique Identifier） |
| 挂载目录 | 指定要挂载到的目录，需在挂载前创建好 |
| 格式类型 | 指定文件系统的格式，比如 Ext3、Ext4、XFS、SWAP、iso9660（此为光盘设备）等 |
| 权限选项 | 若设置为 defaults，则默认权限为：rw, suid, dev, exec, auto, nouser, async |
| 是否备份 | 若为 1 则开机后使用 dump 进行磁盘备份，为 0 则不备份 |
| 是否自检 | 若为 1 则开机后自动进行磁盘自检，为 0 则不自检 |

比如将文件系统为 ext4 的硬件设备 `/dev/sdb2` 在开机后自动挂载到 `/backup` 目录上，并保持默认权限且无需开机自检，则可以添加配置：

```conf
/dev/sdb2 /backup ext4 defaults 0 0
```
