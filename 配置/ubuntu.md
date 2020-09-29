# Ubuntu 初始配置

- [Ubuntu 初始配置](#ubuntu-初始配置)
  - [基础配置](#基础配置)
    - [WSL 默认 root 用户](#wsl-默认-root-用户)
    - [换镜像源](#换镜像源)
    - [VMWare Tools](#vmware-tools)
    - [启用 SSH 登录 root](#启用-ssh-登录-root)
    - [安装 Fish 终端](#安装-fish-终端)
  - [开发环境](#开发环境)
    - [Git / Curl](#git--curl)
    - [Python](#python)
      - [安装 pip](#安装-pip)
      - [更换源](#更换源)
    - [Go](#go)
      - [模块代理](#模块代理)

## 基础配置

### WSL 默认 root 用户

```shell
ubuntu config --default-user root
ubuntu2004 config --default-user root
```

### 换镜像源

1. 执行脚本

```shell
./sources.sh
```

2. 更新系统

```shell
apt update && apt upgrade
```

### VMWare Tools

> 针对特殊情况下的虚拟机

```shell
# GUI
apt-get install open-vm-tools-desktop

# Server
apt-get install open-vm-tools
```

### 启用 SSH 登录 root

> 针对非 WSL 的系统

1. 安装 SSH 服务

```shell
apt install openssh-server

# 启动服务
systemctl start ssh
```

2. 配置开机自启

```shell
systemctl enable ssh.service
```

3. 设置 root 用户密码

```shell
passwd root
```

4. 添加设置

```shell
echo "PermitRootLogin yes" >> /etc/ssh/sshd_config
sed -i "s/PermitRootLogin prohibit-password/#PermitRootLogin prohibit-password/g" /etc/ssh/sshd_config
```

```shell
# 重启服务
systemctl restart ssh
```

5. 客户端生成一对公钥密钥

> Windows 可以用 git-bash.exe 执行命令。

```shell
ssh-keygen -t rsa

# 把公钥放到服务器上
ssh-copy-id -i ~/.ssh/id_rsa.pub root@192.168.134.129

ssh-copy-id -i ~/.ssh/id_rsa.pub root@192.168.134.133
```

然后可以不输密码登录

```shell
ssh root@192.168.134.129

ssh root@192.168.134.133
```

6. 永久修改主机名

```shell
echo ubuntu > /etc/hostname

# 重启
reboot
```

7. 不显示登录标语

```
touch ~/.hushlogin
```

### 安装 Fish 终端

1. 安装

```
apt-add-repository ppa:fish-shell/release-3
apt-get update
apt-get install fish
```

2. 去掉欢迎语句

```shell
set fish_greeting
```

在 Fish 中设置生效。

3. 设置别名，自定义变量

```shell
./alias.sh
```

4. 修改默认终端

```shell
usermod -s `which fish`  root
usermod -s `which bash`  root
```

## 开发环境

### Git / Curl

```shell
apt install git
```

```shell
$ git --version
git version 2.25.1
```

```shell
apt install curl
```

### Python

一般默认安装了 Python3。

#### 安装 pip

```shell
apt install python3-pip
```

#### 更换源

```shell
$ pip install toolkit-py
$ chs
```

### Go

#### 模块代理

```shell
go env -w GOPROXY=https://goproxy.cn,direct
go env -w GOSUMDB=off

go env -w GO111MODULE=on
go env -w GOPATH=C:\Developer\gopath
go env -w GOPATH=C:\Developer\gopath

# go env -w GOBIN=/usr/local/go/bin
```

```shell

```

```shell

```

```shell

```
