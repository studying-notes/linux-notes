# Linux 命令分类索引

## 输入与输出

- [alias](alias.md) - 设置别名
- [unalias](unalias.md) - 取消别名

- [awk](awk.md) - 强大的文本处理工具
- [cat](cat.md) - 将一个或多个文件的内容打印到标准输出
- [cut](cut.md) - 按列提取文本字符
- [diff](diff.md) - 按行比较多个文本文件的内容差异
- [echo](echo.md) - 显示一行文本，在标准输出回显字符串
- [export](export.md) - 在当前会话新增、修改或删除环境变量
- [find](find.md) - 按照指定条件查找文件
- [grep](grep.md) - 在文本中搜索匹配的关键词，显示结果
- [head](head.md) - 默认打印每个文件的前 10 行到标准输出
- [history](history.md) - 显示、管理以前执行过的命令
- [more](more.md) - CRT 文件浏览器
- [read](read.md) - 从标准输入读取一行，依次赋值
- [stat](stat.md) - 查询文件、文件系统状态信息
- [tail](tail.md) - 默认打印每个文件的后 10 行到标准输出
- [tr](tr.md) - 字符替换
- [wc](wc.md) - 统计指定文本的行数、单词数、字符数、字节数等

## 文件管理

- [cd](cd.md) - 改变当前工作目录
- [cp](cp.md) - 复制
- [dd](dd.md) - 按照指定大小和个数的数据块来复制文件或转换文件
- [du](du.md) - 显示指定文件的大小
- [file](file.md) - 确定文件类型
- [ln](ln.md) - 创建链接文件
- [ls](ls.md) - 列出目录下文件的权限和属性信息
- [mkdir](mkdir.md) - 创建目录
- [mv](mv.md) - 移动，重命名
- [pwd](pwd.md) - 输出当前工作目录
- [rm](rm.md) - 移除项目
- [tar](tar.md) - 对文件进行打包压缩或解压
- [touch](touch.md) - 更新文件的访问、修改时间为当前时间，常用来创建空白文件

## 存储管理

- [df](df.md) - 显示文件系统的信息
- [du](du.md) - 对一组文件的磁盘使用情况进行汇总
- [fdisk](fdisk.md) - 管理硬盘设备，提供添加、删除、转换分区等功能
- [mkfs](mkfs.md) - 格式化硬盘，创建文件系统
- [mkswap](mkswap.md) - 创建交换分区
- [partprobe](partprobe.md) - 通知操作系统分区表的更改
- [swapon](swapon.md) - 挂载 SWAP 分区
- [xfs_quota](xfs_quota.md) - 针对 XFS 文件系统的 quota 磁盘容量配额管理服务
- [edquota](edquota.md) - 编辑用户的 quota 配额限制

- [mount](mount.md) - 挂载文件系统
- [umount](umount.md) - 卸载文件系统

- [mdadm](mdadm.md) - 管理 RAID 硬盘阵列
- [pvcreate](pvcreate.md) - 初始化供 LVM 使用的物理卷
- [lvextend](lvextend.md) - 扩展供 LVM 使用的物理卷
- [e2fsck](e2fsck.md) - 检查文件系统
- [vgdisplay](vgdisplay.md) - 显示卷组信息

## 计划与执行

- [at](at.md) - 设置一次性定时执行任务
- [crontab](crontab.md) - 设置长期性计划任务
- [source](source.md) - 在当前终端执行来自一个文件的命令

## 开关机

- [ctrlaltdel](ctrlaltdel.md) - 设置组合键 `Ctrl+Alt+Del` 的功能
- [halt](halt.md) - 中断系统
- [poweroff](poweroff.md) - 关闭操作系统，然后切断系统电源
- [reboot](reboot.md) - 重启系统
- [shutdown](shutdown.md) - 关闭操作系统

## 进程负载

- [free](free.md)
- [kill](kill.md)
- [killall](killall.md)
- [pidof](pidof.md)
- [ps](ps.md)
- [top](top.md)
- [uptime](uptime.md)

## 网络

- [ifconfig](ifconfig.md)
- [wget](wget.md)

## 用户管理

- [groupadd](groupadd.md) - 创建新的用户组
- [id](id.md) - 显示指定用户的相关信息
- [last](last.md) - 显示用户的登录日志
- [passwd](passwd.md) - 修改用户名密码
- [su](su.md) - 切换用户
- [useradd](useradd.md) - 创建新的用户
- [userdel](userdel.md) - 删除用户
- [usermod](usermod.md) - 修改用户的属性
- [who](who.md) - 显示当前用户名及其启动的终端信息

## 权限管理

- [chattr](chattr.md) - 设置文件的隐藏权限
- [chmod](chmod.md) - 设置文件或目录的权限
- [chown](chown.md) - 设置文件或目录的所有者和所属组
- [getfacl](getfacl.md) - 显示文件上设置的 ACL 信息
- [lsattr](lsattr.md) - 显示文件的隐藏权限
- [setfacl](setfacl.md) - 管理文件的 ACL 规则
- [sudo](sudo.md) - 给普通用户提供额外的权限

## 系统信息

- [date](date.md)
- [ifconfig](ifconfig.md)
- [sosreport](sosreport.md)
- [uname](uname.md)
- [whereis](whereis.md) - 定位二进制执行文件、源文件、手册主页文件的位置

- [scp](scp.md) - 在网络之间进行安全传输数据
