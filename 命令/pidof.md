# pidof 命令

> 查询某个指定服务进程名称的全部 PID 值，然后打印在标准输出中

## 格式

```bash
pidof  [-s]  [-c]  [-n]  [-x] [-o omitpid[,omitpid..]]  [-o omitpid[,omitpid..]..] program [program..]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -s | Single shot - this instructs the program to only return one pid. |
| -c | Only return process ids that are running  with  the  same  root  directory. This  option is ignored for non-root users, as they will be unable to check the current root directory of processes they do not own. |
| -n | Avoid stat(2) system function call on all binaries  which  are  located  on network  based file systems like NFS.  Instead of using this option the the variable PIDOF_NETFS may be set and exported. |
| -x | Scripts too - this causes the program to also return process id's of shells running the named scripts. |
| -o omitpid | Tells  pidof  to omit processes with that process id. The special pid %PPID can be used to name the parent process of the pidof program, in other words the calling shell or shell script. |

## 退出状态

- 0 - At least one program was found with the requested name.
- 1 - No program was found with the requested name.

## 示例

1. 输出 sshd 服务名的全部 PID

```bash
$ pidof sshd
3623 839
```

2. 输出指定进程名的一个 PID

```bash
$ sleep 10000 &
[1] 4900

$ pidof -s sleep
4900
```
