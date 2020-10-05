# sed 

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
```
