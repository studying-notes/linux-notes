# cp 命令

> 复制

## 格式

```bash
cp [OPTION]... [-T] SOURCE DEST

cp [OPTION]... SOURCE... DIRECTORY

cp [OPTION]... -t DIRECTORY SOURCE...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a, --archive | same as -dR --preserve=all |
| --attributes-only | don't copy the file data, just the attributes |
| --backup[=CONTROL] | make a backup of each existing destination file |
| -b | like --backup but does not accept an argument |
| --copy-contents | copy contents of special files when recursive |
| -d | same as --no-dereference --preserve=links |
| -f, --force | if an existing destination file cannot be opened, remove it and try again (this option is ignored when the -n option is also used) |
| -i, --interactive | prompt before overwrite (overrides a previous -n option) |
| -H | follow command-line symbolic links in SOURCE |
| -l, --link | hard link files instead of copying |
| -L, --dereference | always follow symbolic links in SOURCE |
| -n, --no-clobber | do not overwrite an existing file (overrides a previous -i option) |
| -P, --no-dereference | never follow symbolic links in SOURCE |
| -p | same as --preserve=mode,ownership,timestamps |
| --preserve[=ATTR_LIST] | preserve the specified attributes (default: mode,ownership,timestamps), if possible additional attributes: context, links, xattr, all |
| --no-preserve=ATTR_LIST | don't preserve the specified attributes |
| --parents | use full source file name under DIRECTORY |
| -R, -r, --recursive | copy directories recursively |
| --reflink[=WHEN] | control clone/CoW copies. See below |
| --remove-destination | remove each existing destination file before attempting to open it (contrast with --force) |
| --sparse=WHEN | control creation of sparse files. See below |
| --strip-trailing-slashes | remove any trailing slashes from each SOURCE argument |
| -s, --symbolic-link | make symbolic links instead of copying |
| -S, --suffix=SUFFIX | override the usual backup suffix |
| -t, --target-directory=DIRECTORY | copy all SOURCE arguments into DIRECTORY |
| -T, --no-target-directory | treat DEST as a normal file |
| -u, --update | copy only when the SOURCE file is newer than the destination file or when the destination file is missing |
| -v, --verbose | explain what is being done |
| -x, --one-file-system | stay on this file system |
| -Z | set SELinux security context of destination file to default type |
| --context[=CTX] | like -Z, or if CTX is specified then set the SELinux or SMACK security context to CTX |
| --help | display this help and exit |
| --version | output version information and exit |

## 示例

1. 复制文件夹

```bash
$ cp -t demo backup
```
