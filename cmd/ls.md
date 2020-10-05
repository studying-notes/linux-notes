# cd 命令

> 列出目录下文件的权限和属性信息

## 格式

```bash
ls [OPTION]... [FILE]...
```

- 默认列出当前工作目录的文件信息

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a, --all | do not ignore entries starting with . |
| -A, --almost-all | do not list implied . and .. |
| --author | with -l, print the author of each file |
| -b, --escape | print C-style escapes for nongraphic characters |
| --block-size=SIZE | scale sizes by SIZE before printing them; e.g., '--block-size=M' prints sizes in units of 1,048,576 bytes; see SIZE format below |
| -B, --ignore-backups | do not list implied entries ending with ~ |
| -c | with -lt: sort by, and show, ctime (time of last modification of file status information); with -l: show ctime and sort by name; otherwise: sort by ctime, newest first |
| -C | list entries by columns |
| --color[=WHEN] | colorize the output; WHEN can be 'never', 'auto', or 'always' (the default); more info below |
| -d, --directory | list directories themselves, not their contents |
| -D, --dired | generate output designed for Emacs' dired mode |
| -f | do not sort, enable -aU, disable -ls --color |
| -F, --classify | append indicator (one of */=>@|) to entries |
| --file-type | likewise, except do not append '*' |
| --format=WORD | across -x, commas -m, horizontal -x, long -l, single-column -1, verbose -l, vertical -C |
| --full-time | like -l --time-style=full-iso |
| -g | like -l, but do not list owner |
| --group-directories-first | group directories before files; can be augmented with a --sort option, but any use of --sort=none (-U) disables grouping |
| -G, --no-group | in a long listing, don't print group names |
| -h, --human-readable | with -l, print sizes in human readable format (e.g., 1K 234M 2G) |
| --si | likewise, but use powers of 1000 not 1024 |
| -H, --dereference-command-line | follow symbolic links listed on the command line |
| --dereference-command-line-symlink-to-dir | follow each command line symbolic link that points to a directory |
| --hide=PATTERN | do not list implied entries matching shell PATTERN (overridden by -a or -A) |
| --indicator-style=WORD | append indicator with style WORD to entry names: none (default), slash (-p), file-type (--file-type), classify (-F) |
| -i, --inode | print the index number of each file |
| -I, --ignore=PATTERN | do not list implied entries matching shell PATTERN |
| -k, --kibibytes | default to 1024-byte blocks for disk usage |
| -l | use a long listing format |
| -L, --dereference | when showing file information for a symbolic link, show information for the file the link references rather than for the link itself |
| -m | fill width with a comma separated list of entries |
| -n, --numeric-uid-gid | like -l, but list numeric user and group IDs |
| -N, --literal | print raw entry names (don't treat e.g. control characters specially) |
| -o | like -l, but do not list group information |
| -p, --indicator-style=slash | append / indicator to directories |
| -q, --hide-control-chars | print ? instead of nongraphic characters |
| --show-control-chars | show nongraphic characters as-is (the default, unless program is 'ls' and output is a terminal) |
| -Q, --quote-name | enclose entry names in double quotes |
| --quoting-style=WORD | use quoting style WORD for entry names: literal, locale, shell, shell-always, c, escape |
| -r, --reverse | reverse order while sorting |
| -R, --recursive | list subdirectories recursively |
| -s, --size | print the allocated size of each file, in blocks |
| -S | sort by file size |
| --sort=WORD | sort by WORD instead of name: none (-U), size (-S), time (-t), version (-v), extension (-X) |
| --time=WORD | with -l, show time as WORD instead of default modification time: atime or access or use (-u) ctime or status (-c); also use specified time as sort key if --sort=time |
| --time-style=STYLE | with -l, show times using style STYLE: full-iso, long-iso, iso, locale, or +FORMAT; FORMAT is interpreted like in 'date'; if FORMAT is FORMAT1<newline>FORMAT2, then FORMAT1 applies to non-recent files and FORMAT2 to recent files; if STYLE is prefixed with 'posix-', STYLE takes effect only outside the POSIX locale |
| -t | sort by modification time, newest first |
| -T, --tabsize=COLS | assume tab stops at each COLS instead of 8 |
| -u | with -lt: sort by, and show, access time; with -l: show access time and sort by name; otherwise: sort by access time |
| -U | do not sort; list entries in directory order |
| -v | natural sort of (version) numbers within text |
| -w, --width=COLS | assume screen width instead of current value |
| -x | list entries by lines instead of by columns |
| -X | sort alphabetically by entry extension |
| -1 | list one file per line |

## 示例

1. 列出当前目录下全部文件的详细信息

```bash
$ ls -al
total 20
drwxr-xr-x  4 root root 4096 Jan  9 18:57 ./
drwxr-xr-x 26 root root 4096 Jan  9 18:55 ../
-rw-r--r--  1 root root 2652 Dec 19 19:57 config.json
drwxr-xr-x  7 root root 4096 Jan  9 18:57 .git/
drwxr-xr-x 12 root root 4096 Dec 19 19:57 rootfs/
```

2. 显示目录的详细信息，而非目录下的文件

```bash
$ ls -ld /etc
drwxr-xr-x 94 root root 4096 Jan  9 18:10 /etc/
```
