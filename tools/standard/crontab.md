---
date: 2020-10-20T09:26:21+08:00  # 创建日期
author: "Rustle Karl"  # 作者

# 文章
title: "crontab 设置长期性计划任务"  # 文章标题
# description: "文章描述"
url:  "posts/linux/tools/standard/crontab"  # 设置网页永久链接
tags: [ "linux", "cmd" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

# 章节
weight: 20 # 排序优先级
chapter: false  # 设置为章节

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
----

> 设置长期性计划任务

> https://crontab.guru/

## 格式

```bash
crontab [-u user] file
crontab [ -u user ] [ -i ] { -e | -l | -r }
```

- [分、时、日、月、星期] [命令]
- 除了用逗号（,）来分别表示多个时间段，例如“8,9,12”表示 8 月、9 月 和 12 月。还可以用减号（-）来表示一段连续的时间周期（例如字段“日”的取值为“12-15”，则表示每月的 12～15 日）。以及用除号（/）表示执行任务的间隔时间（例如“*/2”表示每隔 2 分钟执行一次任务）。
- 计划任务中的“分”字段必须有数值，绝对不能为空或是*号，而“日”和“星期”字段不能同时使用，否则就会发生冲突。
- 同时包含多条计划任务的命令语句，应每行仅写一条。

| 字段 | 说明 |
| ---- | ---- |
| 分 | 取值为 0 ～ 59 的整数 |
| 时 | 取值为 0 ～ 23 的任意整数 |
| 日 | 取值为 1 ～ 31 的任意整数 |
| 月 | 取值为 1 ～ 12 的任意整数 |
| 星期 | 取值为 0 ～ 7 的任意整数，其中 0 与 7 均为星期日 |
| 命令 | 要执行的命令或程序脚本 |

## 参数

| 参数 | 作用 |
| ---- | ---- |
| -e | edit user's crontab |
| -l | list user's crontab |
| -r | delete user's crontab |
| -i | prompt before deleting user's crontab |

## 示例

1. 编辑配置文件

```bash
crontab -e
# 写入内容
# 0 1 * * 1-5 /usr/bin/rm -rf /tmp/*
```

```
crontab: installing new crontab
```

2. 显示已设置计划

```bash
crontab -l
```

```
0 1 * * 1-5 /usr/bin/rm -rf /tmp/*
```

> 每周一至周五的凌晨 1 点钟自动清空 `/tmp` 目录内的所有文件

3. 修改默认编辑器

```bash
select-editor
```

## 实例

### 每隔 5 秒同步一次系统时间

```bash
crontab -e
# 写入内容
```

```bash
*/5 * * * * ntpdate time2.aliyun.com
```

### 每隔5秒执行一次

```shell
*/5 * * * * ?
```

### 每隔1分钟执行一次

```shell
0 */1 * * * ?
```

### 每1小时执行一次

```shell
0 */1 * * *
```

### 每天10点执行

```shell
0 10 * * *
```

### 每天5-15点整点触发

```shell
0 0 5-15 * * ?
```

### 每三分钟触发一次

```shell
0 0/3 * * * ?
```

### 在每天下午2点到下午2:05期间的每1分钟触发

```shell
0 0-5 14 * * ?
```

### 在每天下午2点到下午2:55期间的每5分钟触发

```shell
0 0/5 14 * * ?
```

### 在每天下午2点到2:55期间和下午6点到6:55期间的每5分钟触发

```shell
0 0/5 14,18 * * ?
```

### 朝九晚五工作时间内每半小时

```shell
0 0/30 9-17 * * ?
```

### 每天上午10点，下午2点，4点

```shell
0 0 10,14,16 * * ?
```

### 表示每个星期三中午12点

```shell
0 0 12 ? * WED
```

### 每周二、四、六下午五点

```shell
0 0 17 ? * TUES,THUR,SAT
```

### 每年三月的星期三的下午2:10和2:44触发

```shell
0 10,44 14 ? 3 WED
```

### 周一至周五的上午10:15触发

```shell
0 15 10 ? * MON-FRI
```

### 每月最后一天23点执行一次

```shell
0 0 23 L * ?
```

### 每月最后一日的上午10:15触发

```shell
0 15 10 L * ?
```

### 每月的最后一个星期五上午10:15触发

```shell
0 15 10 ? * 6L
```

### 2005年的每天上午10:15触发

```shell
0 15 10 * * ? 2005
```

### 2002年至2005年的每月的最后一个星期五上午10:15触发

```shell
0 15 10 ? * 6L 2002-2005
```

### 每月的第三个星期五上午10:15触发

```shell
0 15 10 ? * 6#3
```

### 每半分钟触发任务

```shell
"30 * * * * ?"
```

### 每小时的10分30秒触发任务

```shell
"30 10 * * * ?"
```

### 每天1点10分30秒触发任务

```shell
"30 10 1 * * ?"
```

### 每月20号1点10分30秒触发任务

```shell
"30 10 1 20 * ?"
```

### 每年10月20号1点10分30秒触发任务

```shell
"30 10 1 20 10 ? *"
```

### 2011年10月20号1点10分30秒触发任务

```shell
"30 10 1 20 10 ? 2011"
```

### 2011年10月每天1点10分30秒触发任务

```shell
"30 10 1 ? 10 * 2011"
```

### 2011年10月每周日1点10分30秒触发任务

```shell
"30 10 1 ? 10 SUN 2011"
```

### 每15秒，30秒，45秒时触发任务

```shell
"15,30,45 * * * * ?"
```

### 15到45秒内，每秒都触发任务

```shell
"15-45 * * * * ?"
```

### 每分钟的每15秒开始触发，每隔5秒触发一次

```shell
"15/5 * * * * ?"
```

### 每分钟的15秒到30秒之间开始触发，每隔5秒触发一次

```shell
"15-30/5 * * * * ?"
```

### 每小时的第0分0秒开始，每三分钟触发一次

```shell
"0 0/3 * * * ?"
```

### 星期一到星期五的10点15分0秒触发任务

```shell
"0 15 10 ? * MON-FRI"
```

### 每个月最后一天的10点15分0秒触发任务

```shell
"0 15 10 L * ?"
```

### 每个月最后一个工作日的10点15分0秒触发任务

```shell
"0 15 10 LW * ?"
```

### 每个月最后一个星期四的10点15分0秒触发任务

```shell
"0 15 10 ? * 5L"
```

### 每个月第三周的星期四的10点15分0秒触发任务

```shell
"0 15 10 ? * 5#3"
```
