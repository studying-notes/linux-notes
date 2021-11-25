# setfacl 命令

> 管理文件的 ACL 规则

## 格式

```bash
setfacl [-bkndRLP] { -m|-M|-x|-X ... } file ...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -m, --modify=acl | modify the current ACL(s) of file(s) |
| -M, --modify-file=file | read ACL entries to modify from file |
| -x, --remove=acl | remove entries from the ACL(s) of file(s) |
| -X, --remove-file=file | read ACL entries to remove from file |
| -b, --remove-all | remove all extended ACL entries |
| -k, --remove-default | remove the default ACL |
| --set=acl | set the ACL of file(s), replacing the current ACL |
| --set-file=file | read ACL entries to set from file |
| --mask | do recalculate the effective rights mask |
| -n, --no-mask | don't recalculate the effective rights mask |
| -d, --default | operations apply to the default ACL |
| -R, --recursive | recurse into subdirectories |
| -L, --logical | logical walk, follow symbolic links |
| -P, --physical | physical walk, do not follow symbolic links |
| --restore=file | restore ACLs (inverse of `getfacl -R') |
| --test | test mode (ACLs are not modified) |
| -v, --version | print version and exit |
| -h, --help | this help text |

## 示例

1. 设置用户在 `/root` 目录上的权限

```bash
$ setfacl -Rm u:cxfans:rwx /root

$ su - cxfans
# 该用户可以对 /root 目录进行读写
```
