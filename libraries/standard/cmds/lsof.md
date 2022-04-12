## 端口占用情况

```shell
lsof -i:8000
lsof -i:10800
```

```shell
netstat -tunlp | grep 8000
netstat -tunlp | grep 10032
```


```shell
netstat -tunlp | grep 55400
netstat -tunlp | grep 10032
```


```shell
lsof -i:55400
lsof -i:10032
```
