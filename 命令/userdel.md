# userdel 命令

> 删除用户

## 格式

```bash
userdel [options] LOGIN
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -f, --force | force removal of files, even if not owned by user |
| -h, --help | display this help message and exit |
| -r, --remove | remove home directory and mail spool |
| -R, --root CHROOT_DIR | directory to chroot into |
| --extrausers | Use the extra users database |
| -Z, --selinux-user | remove any SELinux user mapping for the user |

## 示例

1. 强制删除用户

```bash
$ userdel cxfans
```

1. 删除用户及其主目录

```bash
$ userdel -r cxfans
```
