---
date: 2022-05-09T08:50:06+08:00
author: "Rustle Karl"

title: "Linux 串口与 USB 转串口问题"
url:  "posts/linux/docs/base/serial_port"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

## 驱动是否支持

```shell
lsmod | grep usbserial
```

如果有 usbserial，说明系统支持 USB 转串口。否则需要手动安装。

```shell
uname -a

ls /lib/modules
ls /lib/modules/$(uname -r)/kernel/drivers/usb/serial

cp /lib/modules/$(uname -r)/kernel/drivers/usb/serial/pl2303.ko /usr/src/linux-headers-$(uname -r)/drivers/usb/serial/

cd /usr/src/linux-headers-$(uname -r)/drivers/usb/serial/
modprobe usbserial
modprobe pl2303
```

## 识别串口

插上 USB 转串口，在终端输入命令

```shell
dmesg | grep ttyUSB0
```

如果出现连接成功信息，则说明 ubuntu 系统已经识别该设备了。

系统的一些信息引用：

```shell
dmesg | tail -f 
```

## 串口名称

一般 USB 转串口设备 /dev/ttyUSB *，如果是普通的串口设备会是 /dev/ttyS *

一般情况下串口的名称全部在 dev 下面，如果你没有外插串口卡的话默认是 dev 下的 ttyS *, 一般 ttyS0 对应 com1，ttyS1 对应 com2，当然也不一定是必然的；

```shell
ls -l /dev/tty*
ls -l /dev/ttyS*
ls -l /dev/ttyUSB*

python -m serial.tools.list_ports
python3 -m serial.tools.list_ports
```

## 测试串口

### 查看串口是否可用

```shell
echo helloworld > /dev/ttyS0
```

### 可以将 TX RX 短接

开两个终端，一个接收

```shell
cat /dev/ttyS0
```

另一个发送数据

```shell
echo helloworld > /dev/ttyS0
```

## Minicom 的安装和使用

minicom 是 linux 下串口通信的软件，它的使用完全依靠键盘的操作。

```shell
apt install -y minicom
```

在使用 minicom 之前，首先要保证你对串口有读 / 写的权限。我们知道，Linux 的设备对应于 /dev/ 目录中的某个文件，串口 COM1 对应 ttyS0，COM2 对应 ttyS1，使用以下命令来查看你对 COM1 的权限

```shell
ls -l /dev/ttyS0
```
