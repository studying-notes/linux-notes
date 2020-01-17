# sudo 命令

> 给普通用户提供额外的权限

## 格式

```bash
sudo -h | -K | -k | -V
sudo -v [-AknS] [-g group] [-h host] [-p prompt] [-u user]
sudo -l [-AknS] [-g group] [-h host] [-p prompt] [-U user] [-u user] [command]
sudo [-AbEHknPS] [-r role] [-t type] [-C num] [-g group] [-h host] [-p prompt] [-T timeout] [-u
            user] [VAR=value] [-i|-s] [<command>]
sudo -e [-AknS] [-r role] [-t type] [-C num] [-g group] [-h host] [-p prompt] [-T timeout] [-u user]
            file ...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -A, --askpass | use a helper program for password prompting |
| -b, --background | run command in the background |
| -C, --close-from=num | close all file descriptors >= num |
| -E, --preserve-env | preserve user environment when running command |
| --preserve-env=list | preserve specific environment variables |
| -e, --edit | edit files instead of running a command |
| -g, --group=group | run command as the specified group name or ID |
| -H, --set-home | set HOME variable to target user's home dir |
| -h, --help | display help message and exit |
| -h, --host=host | run command on host (if supported by plugin) |
| -i, --login | run login shell as the target user; a command may also be specified |
| -K, --remove-timestamp | remove timestamp file completely |
| -k, --reset-timestamp | invalidate timestamp file |
| -l, --list | list user's privileges or check a specific command; use twice for longer format |
| -n, --non-interactive | non-interactive mode, no prompts are used |
| -P, --preserve-groups | preserve group vector instead of setting to target's |
| -p, --prompt=prompt | use the specified password prompt |
| -r, --role=role | create SELinux security context with specified role |
| -S, --stdin | read password from standard input |
| -s, --shell | run shell as the target user; a command may also be specified |
| -t, --type=type | create SELinux security context with specified type |
| -T, --command-timeout=timeout | terminate command after the specified time limit |
| -U, --other-user=user | in list mode, display privileges for user |
| -u, --user=user | run command (or edit file) as specified user name or ID |
| -V, --version | display version information and exit |
| -v, --validate | update user's timestamp without running a command |
| -- | stop processing command line arguments |

## 功能

- 限制用户执行指定的命令。
- 记录用户执行的每一条命令。
- 配置文件（/etc/sudoers）提供集中的用户管理、权限与主机等参数。

```conf
#
# This file MUST be edited with the 'visudo' command as root.
#
# Please consider adding local content in /etc/sudoers.d/ instead of
# directly modifying this file.
#
# See the man page for details on how to write a sudoers file.
#
Defaults	env_reset
Defaults	mail_badpass
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

# Host alias specification

# User alias specification

# Cmnd alias specification

# User privilege specification
root	ALL=(ALL:ALL) ALL

# Members of the admin group may gain root privileges
%admin ALL=(ALL) ALL

# Allow members of group sudo to execute any command
%sudo	ALL=(ALL:ALL) ALL

# See sudoers(5) for more information on "#include" directives:

#includedir /etc/sudoers.d
```

- 验证密码的后 5 分钟内（默认值）无须再让用户再次验证密码。
- 可以使用 sudo 命令提供的 visudo 命令来配置用户权限。这条命令在配置用户权限时将禁止多个用户同时修改 sudoers 配置文件，还可以对配置文件内的参数进行语法检查，并在发现参数错误时进行报错。
- 让某个用户只能使用 root 管理员的身份执行指定的命令，可以如下配置：

```conf
root	ALL=(ALL:ALL) ALL
cxfans	ALL=(ALL:ALL) /usr/bin/docker
```

- 可以添加 NOPASSWD 参数，使得用户执行 sudo 命令时不再需要密码验证：

```conf
cxfans	ALL=NOPASSWD: /usr/bin/docker
```

## 示例

```bash
$ sudo docker ps
```
