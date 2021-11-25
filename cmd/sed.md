# sed 

```shell
sed -i 's/search_string/replacement_string/g' input_file
```

- `-i`：默认情况下，`sed` 打印结果到标准输出，该参数表示输出到文件。添加一个后缀（比如 `-i.bak`）时，就会创建原始文件的备份。
- `s`：字母 `s` 是一个替换命令。
- `search_string`：搜索一个给定的字符串或正则表达式。
- `replacement_string`：替换的字符串。
- `g`：全局替换标志。默认情况下，`sed` 命令替换每一行第一次出现的模式，它不会替换行中的其他的匹配结果。但是，提供了该替换标志时，所有匹配都将被替换。
- `/`：分界符。
- `input_file`：要执行操作的文件名。

```shell
sed -i "s/PermitRootLogin prohibit-password/# PermitRootLogin prohibit-password/g" /etc/ssh/sshd_config
```





## 示例

1. 批量替换多个文件中的字符串

```shell
sed -i "s/oldstring/newstring/g" `grep oldstring -rl yourdir`
```

替换当前目录下所有文件中的 baidu 为 google

```shell
sed -i "s/baidu/google/g" `grep google -rl ./`

# 带括号的可能需要引号
sed -i "s/SyncOk(sync.Key)/SyncOk(sync.ID)/g" `grep "SyncOk(sync.Key)" -rl ./`

sed -i "s/SyncOk(sync.ID)/\/\/SyncOk(sync.ID)/g" `grep "SyncOk(sync.ID)" -rl ./`
sed -i "s/\/\/SyncOk(sync.ID)/SyncOk(sync.ID)/g" `grep "\/\/SyncOk(sync.ID)" -rl ./`
```
