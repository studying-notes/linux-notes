# 管道符与输入输出

- [管道符与输入输出](#管道符与输入输出)
  - [输入输出重定向](#输入输出重定向)
    - [输入重定向中用到的符号及其作用](#输入重定向中用到的符号及其作用)
    - [输出重定向中用到的符号及其作用](#输出重定向中用到的符号及其作用)
  - [管道命令符](#管道命令符)
    - [示例](#示例)
  - [命令行的通配符](#命令行的通配符)
    - [示例](#示例-1)
  - [转义字符](#转义字符)
    - [示例](#示例-2)

## 输入输出重定向

输入重定向是把文件导入到命令中，而输出重定向是把原本要输出到屏幕的数据信息写入到指定文件中。输出重定向分为标准输出重定向和错误输出重定向两种不同的技术，以及清空写入与追加写入两种模式。

- 标准输入重定向（`STDIN`，文件描述符为 0）：默认从键盘输入，也可从其他文件或命令输入。
- 标准输出重定向（`STDOUT`，文件描述符为 1）：默认输出到屏幕。
- 错误输出重定向（`STDERR`，文件描述符为 2）：默认输出到屏幕。

### 输入重定向中用到的符号及其作用

| 符号 | 作用 |
| --------- | --------- |
| 命令 < 文件 | 将文件作为命令的标准输入 |
| 命令 << 分界符 | 从标准输入中读入，直到遇见分界符才停止 |
| 命令 < 文件 1 > 文件 2 | 将文件 1 作为命令的标准输入并将标准输出到文件 2 |

```bash
$ wc -l < demo
4

# 等价于
$ cat demo | wc -l
4
```

### 输出重定向中用到的符号及其作用

| 符号 | 作用 |
| --------- | --------- |
| 命令 > 文件 | 将标准输出重定向到一个文件中（清空原有文件的数据） |
| 命令 2> 文件 | 将错误输出重定向到一个文件中（清空原有文件的数据） |
| 命令 &> 文件 | 将标准输出与错误输出共同写入到文件中（清空原有文件的数据） |
| 命令 >> 文件 | 将标准输出重定向到一个文件中（追加到原有内容的后面） |
| 命令 2>> 文件 | 将错误输出重定向到一个文件中（追加到原有内容的后面） |
| 命令 >> 文件 2>&1，命令 &>> 文件 | 将标准输出与错误输出共同写入到文件中（追加到原有内容的后面） |

## 管道命令符

管道命令符可以把前一个命令的标准输出作为后一个命令的标准输入。

```bash
$ grep "/sbin/nologin" /etc/passwd | wc -l
25
```

```bash
$ ls -l /etc/ | more
```

### 示例

1. 通过把管道符和 `passwd` 命令的 `--stdin` 参数相结合，可以用一条命令来修改用户密码

```bash
$ echo "root" | passwd --stdin admin
Changing password for user admin.
passwd: all authentication tokens updated successfully.
```

Ubuntu 18.04 LTS 不支持 `--stdin` 参数，但仍可以通过其他方法实现一条命令修改密码：

```bash
$ echo -e "admin\nadmin" | passwd admin
Enter new UNIX password: Retype new UNIX password: passwd: password updated successfully
```

2. 通过管道把编辑好的内容与标题一起打包，用一条命令向其他用户发送邮件

```bash
$ echo "Content" | mail -s "Subject" admin
$ su - admin
Last login: Fri Jan 10 20:32:54 EST 2020 on pts/0
$ mail
Heirloom Mail version 12.5 7/5/10.  Type ? for help.
"/var/spool/mail/admin": 1 message 1 new
>N  1 root                  Fri Jan 10 20:32  18/591   "Subject"
```

3. 让用户一直输入内容，直到用户输入了其自定义的分界符 `over` 时，才结束输入

```bash
$ mail -s "example" root << over
```


## 命令行的通配符

- 星号 `*` 代表匹配零个或多个字符
- 问号 `?` 代表匹配单个字符
- 中括号内包含数字区间 `[0-9]` 代表匹配 0～9 之间的单个数字的字符，字母同理
- 中括号内包含多个字母 `[abc]` 代表匹配 a、b、c 三个字符中的任意一个字符，数字同理

### 示例

```bash
$ ls -l /dev/sda*
brw-rw----. 1 root disk 8, 0 Dec  8 15:26 /dev/sda
brw-rw----. 1 root disk 8, 1 Dec  8 15:26 /dev/sda1
brw-rw----. 1 root disk 8, 2 Dec  8 15:26 /dev/sda2
```

```bash
$ ls -l /dev/sda?
brw-rw----. 1 root disk 8, 1 Dec  8 15:26 /dev/sda1
brw-rw----. 1 root disk 8, 2 Dec  8 15:26 /dev/sda2
```

```bash
$ ls -l /dev/sda[0-9]
brw-rw----. 1 root disk 8, 1 Dec  8 15:26 /dev/sda1
brw-rw----. 1 root disk 8, 2 Dec  8 15:26 /dev/sda2
```

## 转义字符

- 反斜杠（\）：使反斜杠后面的一个变量变为单纯的字符串。
- 单引号（''）：转义其中所有的变量为单纯的字符串。
- 双引号（""）：保留其中的变量属性，不进行转义处理。
- 反引号（``）：把其中的命令执行后返回结果，注意其他 Shell（比如 Fish Shell）可能不支持这个功能。

### 示例

```bash
$ PRICE=5
$ echo "Price is $PRICE"
Price is 5
```

```bash
$ echo "Price is \$$PRICE"
Price is $5
```

```bash
$ echo `uname -a`
Linux aliyun 4.15.0-70-generic #79-Ubuntu SMP Tue Nov 12 10:36:11 UTC 2019 x86_64 x86_64 x86_64 GNU/Linux
```
