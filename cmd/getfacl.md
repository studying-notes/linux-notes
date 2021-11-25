# getfacl 命令

> 显示文件上设置的 ACL 信息

## 格式

```bash
getfacl [-aceEsRLPtpndvh] file ...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a, --access | display the file access control list only |
| -d, --default | display the default access control list only |
| -c, --omit-header | do not display the comment header |
| -e, --all-effective | print all effective rights |
| -E, --no-effective | print no effective rights |
| -s, --skip-base | skip files that only have the base entries |
| -R, --recursive | recurse into subdirectories |
| -L, --logical | logical walk, follow symbolic links |
| -P, --physical | physical walk, do not follow symbolic links |
| -t, --tabular | use tabular output format |
| -n, --numeric | print numeric user/group identifiers |
| -p, --absolute-names | don't strip leading '/' in pathnames |
| -v, --version | print version and exit |
| -h, --help | this help text |

## 示例

1. 显示文件上设置的 ACL 信息

```bash
$ setfacl -Rm u:cxfans:rwx /root

$ getfacl /root
getfacl: Removing leading '/' from absolute path names
# file: root
# owner: root
# group: root
user::rwx
user:cxfans:rwx
group::---
mask::rwx
other::---
```
