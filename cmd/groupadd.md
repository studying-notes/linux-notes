# useradd 命令

> 创建新的用户组

## 格式

```bash
groupadd [options] GROUP
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -f, --force | exit successfully if the group already exists, and cancel -g if the GID is already used |
| -g, --gid GID | use GID for the new group |
| -h, --help | display this help message and exit |
| -K, --key KEY=VALUE | override /etc/login.defs defaults |
| -o, --non-unique | allow to create groups with duplicate (non-unique) GID |
| -p, --password PASSWORD | use this encrypted password for the new group |
| -r, --system | create a system account |
| -R, --root CHROOT_DIR | directory to chroot into |
| --extrausers | Use the extra users database |

## 示例

1. 创建一个用户组

```bash
$ groupadd workers
```

## 相关命令

- [id](id.md)
- [useradd](useradd.md)
- [reboot](reboot.md)
- [ctrlaltdel](ctrlaltdel.md)
