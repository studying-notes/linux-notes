# alias 命令

> 设置别名

## 格式

```bash
alias [-p] [name[=value] ... ]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -p | print all defined aliases in a reusable format |

## 示例

1. 显示全部已设置的别名

```bash
$ alias
alias cls='clear'
alias egrep='egrep --color=auto'
alias fgrep='fgrep --color=auto'
alias grep='grep --color=auto'
alias l='ls -CF'
alias la='ls -A'
alias ll='ls -alF'
alias ls='ls --color=auto'
```

2. 设置别名

```bash
$ alias c='clear'

$ echo "alias c='clear'" >> ~/.profile
```

## 相关命令

- [unalias](unalias.md)
