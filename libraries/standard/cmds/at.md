# at 命令

> 设置一次性定时执行任务

## 格式

```bash
at [-V] [-q queue] [-f file] [-mMlv] timespec...
at [-V] [-q queue] [-f file] [-mMkv] [-t time]
at -c job [job...]
atq [-V] [-q queue]
at [-rd] job [job...]
atrm [-V] job [job...]
batch
at -b
```

| 命令 | 作用 |
| --------- | --------- |
| at, batch | read commands from standard input or a specified file which are to be executed at a later time, using `/bin/sh`. |
| at | executes commands at a specified time. |
| atq | lists the user's pending jobs, unless the user is the superuser; in that case, everybody's jobs  are listed.  The format of the output lines (one for each job) is: Job number, date, hour, queue, and username. |
| atrm | deletes jobs, identified by their job number. |
| batch | executes commands when system load levels permit; in other words, when  the  load  average drops below 1.5, or the value specified in the invocation of atd. |

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -V | prints the version number to standard error and exit successfully. |
| -q queue | uses  the  specified  queue.  A queue designation consists of a single letter; valid queue designations range from a to z and A to Z.  The a queue is the default for at  and  the  b queue  for  batch. Queues  with higher letters run with increased niceness.  The special queue "=" is reserved for jobs which are currently running. If a job is submitted to a queue designated with an uppercase letter, the job is treated as if  it were  submitted  to  batch at the time of the job.  Once the time is reached, the batch processing rules with respect to load average apply.  If atq is given a specific queue,  it  will  only  show jobs pending in that queue. |
| -m | Send mail to the user when the job has completed even if there was no output. |
| -M | Never send mail to the user. |
| -f file | Reads the job from file rather than standard input. |
| -t time | run the job at time, given in the format [[CC]YY]MMDDhhmm[.ss] |
| -l | Is an alias for atq. |
| -r | Is an alias for atrm. |
| -d | Is an alias for atrm. |
| -b | Is an alias for batch. |
| -v | Shows the time the job will be executed before reading the job. Times displayed will be in the format "Thu Feb 20 14:50:00 1997". |
| -c | cats the jobs listed on the command line to standard output. |

## 示例

1. 编写计划任务

```bash
$ at 14:30
warning: commands will be executed using /bin/sh
at> systemctl restart docker
at> <EOT>  # Ctrl + D 组合键结束编写计划任务
job 1 at Mon Jan 13 14:30:00 2020
```

2. 列出全部计划任务

```bash
$ atq
2       Mon Jan 13 20:00:00 2020 a root

# 等价
$ at -l
2       Mon Jan 13 20:00:00 2020 a root
```

3. 删除指定编号的计划任务

```bash
$ atrm 2

# 等价
$ at -r 2
```

4. 管道方式创建一次性计划

```bash
$ echo "systemctl restart docker" | at 23:30
warning: commands will be executed using /bin/sh
job 3 at Mon Jan 13 23:30:00 2020
```
