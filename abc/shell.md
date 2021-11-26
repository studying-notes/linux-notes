# Shell 脚本

- [Shell 脚本](#shell-脚本)
  - [概述](#概述)
  - [编写简单脚本](#编写简单脚本)
  - [接受用户参数](#接受用户参数)
  - [判断用户的参数](#判断用户的参数)
    - [文件测试所用的参数](#文件测试所用的参数)
    - [整数比较运算符](#整数比较运算符)
    - [整数比较运算符](#整数比较运算符-1)
  - [流程控制语句](#流程控制语句)
    - [if 条件测试语句](#if-条件测试语句)
      - [单分支结构](#单分支结构)
      - [双分支结构](#双分支结构)
      - [多分支结构](#多分支结构)
    - [for 条件循环语句](#for-条件循环语句)
    - [while 条件循环语句](#while-条件循环语句)
    - [case 条件测试语句](#case-条件测试语句)
  - [计划任务服务程序](#计划任务服务程序)
    - [一次性计划任务](#一次性计划任务)
    - [长期性计划任务](#长期性计划任务)

## 概述

Shell 脚本命令的工作方式有两种：交互式和批处理。
- 交互式（Interactive）：用户每输入一条命令就立即执行。
- 批处理（Batch）：由用户事先编写好一个完整的 Shell 脚本，Shell 会一次性执行脚本中诸多的命令。

**当前系统的命令行终端解释器：**

```bash
$ echo $SHELL
/bin/bash
```

## 编写简单脚本

1. 编辑脚本

```bash
$ vim example.sh
#!/bin/bash
#For Example BY linuxprobe.com
pwd
ls -al
```

2. 赋予执行权限

```bash
$ chmod +x example.sh
```

3. 运行脚本

```bash
$ ./example.sh

# 其他方法
$ bash example.sh
$ source example.sh
```

## 接受用户参数

- `$0` - 当前 Shell 脚本程序的名称
- `$#` - 总共有几个参数
- `$*` - 所有位置的参数值
- `$?` - 显示上一次命令的执行返回值
- `$1`、`$2`、`$3`……`$N` - 第 N 个位置的参数值

```bash
$ ./example.sh 1 2 3 4 5 6
```

- **变量之间空格间隔**

## 判断用户的参数

![](../插图/expression.png)

按照测试对象来划分，条件测试语句可以分为 4 种：
- 文件测试语句：判断文件是存在或权限是否满足
- 逻辑测试语句
- 整数值比较语句
- 字符串比较语句

### 文件测试所用的参数

| 运算符 | 作用 |
| --------- | --------- |
| -d | 测试文件是否为目录类型 |
| -e | 测试文件是否存在 |
| -f | 判断是否为一般文件 |
| -r | 测试当前用户是否有权限读取 |
| -w | 测试当前用户是否有权限写入 |
| -x | 测试当前用户是否有权限执行 |

| 返回状态码 | 表示 |
| --------- | --------- |
| 0 | 是 |
| 1 | 否 |

**示例**

1. 判断 `/etc/fstab` 是否为一个目录类型的文件

```bash
$ [ -d /etc/fstab ]
$ echo $?
1

$ [ -f /etc/fstab ] && echo 'yes'
yes
```

- 逻辑“与”的运算符号 &&，表示当前面的命令执行成功，即退出状态码为0，才会执行它后面的命令。

2. 判断当前用户是否为 user 用户

```bash
$ [ $USER = root ] || echo "user"
user
```

- 逻辑“或”的运算符号 ||，表示当前面的命令执行失败，即退出状态码不为0，才会执行它后面的命令。

3. 判断当前用户是否为 root 用户

```bash
$ [ ! $USER = root ] || echo "root"
root
```

- 逻辑“非”的运算符号 !，表示把条件测试中的判断结果取相反值。

4. 综合判断

```bash
$ [ ! $USER = root ] && echo "user" || echo "root"
```

### 整数比较运算符

| 运算符 | 作用 |
| --------- | --------- |
| -eq | 是否等于 |
| -ne | 是否不等于 |
| -gt | 是否大于 |
| -lt | 是否小于 |
| -le | 是否等于或小于 |
| -ge | 是否大于或等于 |

**示例**

1. 比较测试

```bash
$ [ 10 -gt 10 ] && echo "true" || echo "false"
false

$ [ 10 -eq 10 ] && echo "true" || echo "false"
true
```

2. 获取内存可用量

```bash
$ echo `free -m | grep Mem: | awk '{print $4}'`

$ [ `free -m | grep Mem: | awk '{print $4}'` -lt 1024 ] && echo "Insufficient Memory"
Insufficient Memory
```

### 整数比较运算符

| 运算符 | 作用 |
| --------- | --------- |
| = | 比较字符串内容是否相同 |
| != | 比较字符串内容是否不同 |
| -z | 判断字符串内容是否为空 |

**示例**

```bash
$ echo $LANG
en_US.UTF-8

$ [ $LANG = "en_US.UTF-8" ] && echo "true"
```

## 流程控制语句

### if 条件测试语句

#### 单分支结构

if 条件语句的单分支结构由 if、then、fi 关键词组成，而且只在条件成立后才执行预设的命令。

**示例**：判断 `/media/cdrom` 文件是否存在，不存在就创建

```bash
#!/bin/bash
DIR="/media/cdrom"
if [ ! -e $DIR ]; then
    mkdir -p $DIR
fi
```

#### 双分支结构

if 条件语句的双分支结构由 if、then、else、fi 关键词组成，它进行一次条件匹配判断，如果与条件匹配，则去执行相应的预设命令；反之则去执行不匹配时的预设命令。

**示例**：验证某台主机是否在线

```bash
#!/bin/bash
ping -c 3 -i 0.2 -W 3 $1 &>/dev/null
if [ $? -eq 0 ]; then
    echo "Host $1 is On-line."
else
    echo "Host $1 is Off-line."
fi
```

#### 多分支结构

if 条件语句的多分支结构由 if、then、else、elif、fi 关键词组成，它进行多次条件匹配判断，这多次判断中的任何一项在匹配成功后都会执行相应的预设命令。

**示例**：判断用户输入的分数在哪个成绩区间内

```bash
#!/bin/bash
read -p "Enter your score（0-100）：" GRADE
if [ $GRADE -ge 85 ] && [ $GRADE -le 100 ]; then
    echo "$GRADE is Excellent"
elif [ $GRADE -ge 70 ] && [ $GRADE -le 84 ]; then
    echo "$GRADE is Pass"
else
    echo "$GRADE is Fail"
fi
```

### for 条件循环语句

for 循环语句允许脚本一次性读取多个信息，然后逐一对信息进行操作处理

**示例**：从列表文件中读取多个用户名，然后为其逐一创建用户账户并设置密码

1. 准备好用户名文件 `users`

```bash
$ cat users
andy
barry
carl
duke
eric
george
```

2. 编辑脚本文件 `add_users.sh`

```bash
#!/bin/bash
read -p "Enter The Users Password : " PASSWD
for UNAME in $(cat users); do
    id $UNAME &>/dev/null
    if [ $? -eq 0 ]; then
        echo "Already exists"
    else
        useradd $UNAME &>/dev/null
        echo "$PASSWD" | passwd --stdin $UNAME &>/dev/null
        if [ $? -eq 0 ]; then
            echo "$UNAME , Create success"
        else
            echo "$UNAME , Create fail"
        fi
    fi
done
```

3. 执行脚本

```bash
$ bash add_users.sh
```

4. 删除全部用户

```bash
#!/bin/bash
for UNAME in $(cat users); do
    id $UNAME &>/dev/null
    if [ $? -eq 0 ]; then
        userdel $UNAME &>/dev/null
        if [ $? -eq 0 ]; then
            echo "$UNAME, delete success"
        else
            echo "$UNAME, delete fail"
        fi
    else
        echo "$UNAME doesn't exist"
    fi
done
```

### while 条件循环语句

while 条件循环语句是一种让脚本根据某些条件来重复执行命令的语句，它的循环结构往往在执行前并不确定最终执行的次数，完全不同于 for 循环语句中有目标、有范围的使用场景。while 循环语句通过判断条件测试的真假来决定是否继续执行命令，若条件为真就继续执行，为假就结束循环。

**示例**：编写一个用来猜测数值大小的脚本

```bash
#!/bin/bash
PRICE=$(expr $RANDOM % 1000)
TIMES=0
echo "商品实际价格为 0-999 之间，猜猜看是多少？"
while true; do
    read -p "请输入您猜测的价格数目：" INT
    let TIMES++
    if [ $INT -eq $PRICE ]; then
        echo "恭喜您答对了，实际价格是 $PRICE"
        echo "您总共猜 g $TIMES 次"
        exit 0
    elif [ $INT -gt $PRICE ]; then
        echo "太高了！"
    else
        echo "太低了！"
    fi
done
```

### case 条件测试语句

case 语句是在多个范围内匹配数据，若匹配成功则执行相关命令并结束整个条件测试；而如果数据不在所列出的范围内，则会去执行星号（*）中所定义的默认命令。

**示例**：提示用户输入一个字符并将其赋值给变量 KEY，然后根据变量 KEY 的值向用户显示其值是字母、数字还是其他字符

```bash
#!/bin/bash
read -p "请输入一个字符，并按 Enter 键确认：" KEY
case "$KEY" in
[a-z] | [A-Z])
    echo "您输入的是 字母。"
    ;;
[0-9])
    echo "您输入的是 数字。"
    ;;
*)
    echo "您输入的是 空格、功能键或其他控制字符。"
    ;;
esac
```

## 计划任务服务程序

设置服务器的计划任务服务，把周期性、规律性的工作交给系统自动完成。计划任务分为一次性计划任务与长期性计划任务。

### 一次性计划任务

1. 编写计划任务

```bash
$ at 20:00
warning: commands will be executed using /bin/sh
at> systemctl restart docker
at> <EOT>  # Ctrl + D 组合键结束编写计划任务
job 1 at Mon Jan 13 20:00:00 2020
```

2. 列出全部计划任务

```bash
$ at -l
2       Mon Jan 13 20:00:00 2020 a root

# 等价
$ atq
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

### 长期性计划任务

> 每周一至周五的凌晨 1 点钟自动清空 `/tmp` 目录内的所有文件

1. 编辑配置文件

```bash
$ crontab -e
# 写入内容
# 0 1 * * 1-5 /usr/bin/rm -rf /tmp/*
crontab: installing new crontab
```

2. 显示已设置计划

```bash
$ crontab -l
0 1 * * 1-5 /usr/bin/rm -rf /tmp/*
```
