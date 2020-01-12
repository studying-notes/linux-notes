# ps 命令

> 显示系统进程状态

## 格式

```bash
ps [options]

ps --help <simple|list|output|threads|misc|all>
ps --help <s|l|o|t|m|a>

# 显示全部命令
ps --help a
```

## 参数

### 基础

| 参数 | 作用 |
| --------- | --------- |
| -A, -e | all processes |
| -a | all with tty, except session leaders |
| a | all with tty, including other users |
| -d | all except session leaders |
| -N, --deselect | negate selection |
| r | only running processes |
| T | all processes on this terminal |
| x | processes without controlling ttys |

### 筛选

| 参数 | 作用 |
| --------- | --------- |
| -C <command> | command name |
| -G, --Group <GID> | real group id or name |
| -g, --group <group> | session or effective group name |
| -p, p, --pid <PID> | process id |
| --ppid <PID> | parent process id |
| -q, q, --quick-pid <PID> | process id (quick mode) |
| -s, --sid <session> | session id |
| -t, t, --tty <tty> | terminal |
| -u, U, --user <UID> | effective user id or name |
| -U, --User <UID> | real user id or name |

### 格式化输出

| 参数 | 作用 |
| --------- | --------- |
| -F | extra full |
| -f | full-format, including command lines |
| f, --forest | ascii art process tree |
| -H | show process hierarchy |
| -j | jobs format |
| j | BSD job control format |
| -l | long format |
| l | BSD long format |
| -M, Z | add security data (for SELinux) |
| -O <format> | preloaded with default columns |
| O <format> | as -O, with BSD personality |
| -o, o, --format <format> | user-defined format |
| s | signal format |
| u | user-oriented format |
| v | virtual memory format |
| X | register format |
| -y | do not show flags, show rss vs. addr (used with -l) |
| --context | display security context (for SELinux) |
| --headers | repeat header lines, one per page |
| --no-headers | do not print header at all |
| --cols, --columns, --width <num> | set screen width |
| --rows, --lines <num> | set screen height |

### 显示线程

| 参数 | 作用 |
| --------- | --------- |
| H | as if they were processes |
| -L | possibly with LWP and NLWP columns |
| -m, m | after processes |
| -T | possibly with SPID column |

### 其他杂项

| 参数 | 作用 |
| --------- | --------- |
| -c | show scheduling class with -l option |
| c | show true command name |
| e | show the environment after command |
| k, | --sort | specify sort order as: [+|-]key[,[+|-]key[,...]] |
| L | show format specifiers |
| n | display numeric uid and wchan |
| S, | --cumulative | include some dead child process data |
| -y | do not show flags, show rss (only with -l) |
| -V, V, --version | display version information and exit |
| -w, w | unlimited output width |

### 备注

- 在 Linux 系统中的命令参数有长短格式之分，长格式和长格式之间不能合并，长格式和短格式之间也不能合并，但短格式和短格式之间是可以合并的，合并之后仅保留一个 `-` 即可。
- `ps` 命令可允许参数不加减号 `-`。

## 进程状态

- R（运行）：进程正在运行或在运行队列中等待。
- S（中断）：进程处于休眠中，当某个条件形成后或者接收到信号时，则脱离该 
状态。
- D（不可中断）：进程不响应系统异步信号，即便用 `kill` 命令也不能将其中断。
- Z（僵死）：进程已经终止，但进程描述符依然存在, 直到父进程调用 `wait4()` 系统函数后将进程释放。
- T（停止）：进程收到停止信号后停止运行。
- X：死掉的进程。
- <：高优先级。
- N：低优先级。
- L：有些页被锁进内存。
- s：包含子进程。
- +：位于后台的进程组。
- l：多线程，克隆线程。

## 示例

1. 显示全部系统进程信息

```bash
$ ps -au
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root      2437  0.5  1.9  52180 19856 pts/1    S+   21:02   0:13 wget -r -p http://www.linuxprobe.com
root      2733  0.0  0.3  37364  3416 pts/3    R+   21:44   0:00 ps -au
```
