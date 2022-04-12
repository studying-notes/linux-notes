# awk 文本处理

在 Linux 系统下默认 awk 是 gawk，它是 awk 的 GNU 版本。

## Usage

```bash
awk option 'pattern {action}' file
```

其中 pattern 表示 awk 在数据中查找的内容，而 action 是在找到匹配内容时所执行的一系列命令。花括号用于根据特定的模式对一系列指令进行分组。

awk 处理的工作方式与数据库类似，**支持对记录和字段处理**，这也是 grep 和 sed 不能实现的。在 awk 中，缺省的情况下**将文本文件中的一行视为一个记录**，逐行放到内存中处理，而将一行中的某一部分作为记录中的一个字段。用 1,2,3... 数字的方式顺序的表示行（记录）中的不同字段。用 $ 后跟数字，引用对应的字段，以逗号分隔，0 表示整个行。

## Options

| 选项 | 描述 |
| -------- | -------- |
| -f program-file | 从文件中读取 awk 程序源文件 |
| -F fs | 指定 fs 为输入字段分隔符 |
| -v var=value | 变量赋值 |
| --posix | 兼容 POSIX 正则表达式 |
| --dump-variables=[file] | 把 awk 命令时的全局变量写入文件，默认文件是 awkvars.out |
| --profile=[file] | 格式化 awk 语句到文件，默认是 awkprof.out |

## Patterns

| Pattern | Description |
| -------- | -------- |
| BEGIN{ } | 给程序赋予初始状态，先执行的工作 |
| END{ } | 程序结束之后执行的一些扫尾工作 |
| /regular expression/ | 为每个输入记录匹配正则表达式 |
| pattern && pattern | 逻辑 and，满足两个模式 |
| pattern \|\| pattern | 逻辑 or，满足其中一个模式 |
| ! pattern | 逻辑 not，不满足模式 |
| pattern1, pattern2 | 范围模式，匹配所有模式 1 的记录，直到匹配到模式 2 |

## 示例

1. 从文件读取 awk 程序处理文件

```bash
# vim test.awk
# tail -n1 /etc/services |awk -f test.awk
60179/tcp
```

2. 指定分隔符，打印指定字段

**打印第二字段，默认以空格分隔**

```bash
# tail -n3 /etc/services |awk '{print $2}'
60179/tcp
```

**指定冒号为分隔符打印第一字段**

```bash
# awk -F ':' '{print $1}' /etc/passwd
root
daemon
bin
sys
sync
……
```

```bash

```

```bash

```

```bash

```

```bash

```

```bash

```

```bash

```

```bash

```

```bash

```

```bash

```

```bash

```
