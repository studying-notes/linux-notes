# useradd 命令

> 修改用户的属性

## 格式

```bash
usermod [options] LOGIN
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -c, --comment COMMENT | new value of the GECOS field |
| -d, --home HOME_DIR | new home directory for the user account |
| -e, --expiredate EXPIRE_DATE | set account expiration date to EXPIRE_DATE |
| -f, --inactive INACTIVE | set password inactive after expiration to INACTIVE |
| -g, --gid GROUP | force use GROUP as new primary group |
| -G, --groups GROUPS | new list of supplementary GROUPS |
| -a, --append | append the user to the supplemental GROUPS mentioned by the -G option without removing him/her from other groups |
| -h, --help | display this help message and exit |
| -l, --login NEW_LOGIN | new value of the login name |
| -L, --lock | lock the user account |
| -m, --move-home | move contents of the home directory to the new location (use only with -d) |
| -o, --non-unique | allow using duplicate (non-unique) UID |
| -p, --password PASSWORD | use encrypted password for the new password |
| -R, --root CHROOT_DIR | directory to chroot into |
| -s, --shell SHELL | new login shell for the user account |
| -u, --uid UID | new UID for the user account |
| -U, --unlock | unlock the user account |
| -v, --add-subuids FIRST-LAST | add range of subordinate uids |
| -V, --del-subuids FIRST-LAST | remove range of subordinate uids |
| -w, --add-subgids FIRST-LAST | add range of subordinate gids |
| -W, --del-subgids FIRST-LAST | remove range of subordinate gids |
| -Z, --selinux-user SEUSER | new SELinux user mapping for the user account |

## 说明

Linux 系统中的一切都是文件，因此在系统中创建用户也就是修改配置文件的过程。用户的信息保存在 `/etc/passwd` 文件中，可以直接用文本编辑器来修改其中的用户参数项目，也可以用 `usermod` 命令修改已经创建的用户信息，诸如用户的 UID、基本/扩展用户组、默认终端等。

## 示例

1. 将用户加入 root 用户组

```bash
$ id cxfans
uid=1314(cxfans) gid=1314(cxfans) groups=1314(cxfans)

$ usermod -G root cxfans

$ id cxfans
uid=1314(cxfans) gid=1314(cxfans) groups=1314(cxfans),0(root)
```

2. 修改用户的默认终端

```bash
$ which fish
/usr/bin/fish

$ usermod -s /usr/bin/fish root
```

另外方法：

```bash
$ which fish
/usr/bin/fish

$ chsh -s /usr/bin/fish

$ chsh -s `which fish`
```
