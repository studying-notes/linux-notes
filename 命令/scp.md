# scp 命令

> 在网络之间进行安全传输数据

## 格式

```bash
scp [-12346BCpqrv] [-c cipher] [-F ssh_config] [-i identity_file] [-l limit] [-o ssh_option] [-P port] [-S program] [[user@]host1:]file1 ... [[user@]host2:]file2
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -v | 显示详细的连接进度 |
| -P | 指定远程主机的 sshd 端口号 |
| -r | 用于传送文件夹 |
| -6 | 使用 IPv6 协议 |

## 示例

1. 从客户端上传到远程服务器

```bash
$ scp LICENSE root@120.77.220.48:/root
LICENSE                             100% 1080    32.2KB/s   00:00  
```

1. 从远程服务器下载到本地

```bash
$ scp root@120.77.220.48:/etc/hosts .
hosts                               100%  178     6.6KB/s   00:00   
```
