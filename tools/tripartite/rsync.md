---
date: 2022-05-15T14:01:12+08:00
author: "Rustle Karl"

title: "rsync 同步文件"
url:  "posts/linux/tools/tripartite/rsync"  # 永久链接
tags: [ "Linux" ]  # 标签
series: [ "Linux 学习笔记" ]  # 系列
categories: [ "学习笔记" ]  # 分类

toc: true  # 目录
draft: false  # 草稿
---

> 远程数据同步工具

rsync 命令是一个远程数据同步工具，可通过 LAN/WAN 快速同步多台主机间的文件。rsync 使用所谓的“rsync 算法”来使本地和远程两个主机之间的文件达到同步，这个算法只传送两个文件的不同部分，而不是每次都整份传送，因此速度相当快。 

## 语法

```shell
rsync [OPTION]... SRC DEST
rsync [OPTION]... SRC [USER@]host:DEST
rsync [OPTION]... [USER@]HOST:SRC DEST
rsync [OPTION]... [USER@]HOST::SRC DEST
rsync [OPTION]... SRC [USER@]HOST::DEST
rsync [OPTION]... rsync://[USER@]HOST[:PORT]/SRC [DEST]
```

对应于以上六种命令格式，rsync 有六种不同的工作模式：

1.  拷贝本地文件。当SRC和DES路径信息都不包含有单个冒号":"分隔符时就启动这种工作模式。如：`rsync -a /data /backup`
2.  使用一个远程shell程序(如rsh、ssh)来实现将本地机器的内容拷贝到远程机器。当DST路径地址包含单个冒号":"分隔符时启动该模式。如：`rsync -avz *.c foo:src`
3.  使用一个远程shell程序(如rsh、ssh)来实现将远程机器的内容拷贝到本地机器。当SRC地址路径包含单个冒号":"分隔符时启动该模式。如：`rsync -avz foo:src/bar /data`
4.  从远程rsync服务器中拷贝文件到本地机。当SRC路径信息包含"::"分隔符时启动该模式。如：`rsync -av root@192.168.78.192::www /databack`
5.  从本地机器拷贝文件到远程rsync服务器中。当DST路径信息包含"::"分隔符时启动该模式。如：`rsync -av /databack root@192.168.78.192::www`
6.  列远程机的文件列表。这类似于rsync传输，不过只要在命令中省略掉本地机信息即可。如：`rsync -v rsync://192.168.78.192/www`

## 选项

```shell
-v, --verbose 详细模式输出。
-q, --quiet 精简输出模式。
-c, --checksum 打开校验开关，强制对文件传输进行校验。
-a, --archive 归档模式，表示以递归方式传输文件，并保持所有文件属性，等于-rlptgoD。
-r, --recursive 对子目录以递归模式处理。
-R, --relative 使用相对路径信息。
-b, --backup 创建备份，也就是对于目的已经存在有同样的文件名时，将老的文件重新命名为~filename。可以使用--suffix选项来指定不同的备份文件前缀。
--backup-dir 将备份文件(如~filename)存放在在目录下。
-suffix=SUFFIX 定义备份文件前缀。
-u, --update 仅仅进行更新，也就是跳过所有已经存在于DST，并且文件时间晚于要备份的文件，不覆盖更新的文件。
-l, --links 保留软链结。
-L, --copy-links 想对待常规文件一样处理软链结。
--copy-unsafe-links 仅仅拷贝指向SRC路径目录树以外的链结。
--safe-links 忽略指向SRC路径目录树以外的链结。
-H, --hard-links 保留硬链结。
-p, --perms 保持文件权限。
-o, --owner 保持文件属主信息。
-g, --group 保持文件属组信息。
-D, --devices 保持设备文件信息。
-t, --times 保持文件时间信息。
-S, --sparse 对稀疏文件进行特殊处理以节省DST的空间。
-n, --dry-run现实哪些文件将被传输。
-w, --whole-file 拷贝文件，不进行增量检测。
-x, --one-file-system 不要跨越文件系统边界。
-B, --block-size=SIZE 检验算法使用的块尺寸，默认是700字节。
-e, --rsh=command 指定使用rsh、ssh方式进行数据同步。
--rsync-path=PATH 指定远程服务器上的rsync命令所在路径信息。
-C, --cvs-exclude 使用和CVS一样的方法自动忽略文件，用来排除那些不希望传输的文件。
--existing 仅仅更新那些已经存在于DST的文件，而不备份那些新创建的文件。
--delete 删除那些DST中SRC没有的文件。
--delete-excluded 同样删除接收端那些被该选项指定排除的文件。
--delete-after 传输结束以后再删除。
--ignore-errors 及时出现IO错误也进行删除。
--max-delete=NUM 最多删除NUM个文件。
--partial 保留那些因故没有完全传输的文件，以是加快随后的再次传输。
--force 强制删除目录，即使不为空。
--numeric-ids 不将数字的用户和组id匹配为用户名和组名。
--timeout=time ip超时时间，单位为秒。
-I, --ignore-times 不跳过那些有同样的时间和长度的文件。
--size-only 当决定是否要备份文件时，仅仅察看文件大小而不考虑文件时间。
--modify-window=NUM 决定文件是否时间相同时使用的时间戳窗口，默认为0。
-T --temp-dir=DIR 在DIR中创建临时文件。
--compare-dest=DIR 同样比较DIR中的文件来决定是否需要备份。
-P 等同于 --partial。
--progress 显示备份过程。
-z, --compress 对备份的文件在传输时进行压缩处理。
--exclude=PATTERN 指定排除不需要传输的文件模式。
--include=PATTERN 指定不排除而需要传输的文件模式。
--exclude-from=FILE 排除FILE中指定模式的文件。
--include-from=FILE 不排除FILE指定模式匹配的文件。
--version 打印版本信息。
--address 绑定到特定的地址。
--config=FILE 指定其他的配置文件，不使用默认的rsyncd.conf文件。
--port=PORT 指定其他的rsync服务端口。
--blocking-io 对远程shell使用阻塞IO。
-stats 给出某些文件的传输状态。
--progress 在传输时显示传输过程。
--log-format=formAT 指定日志文件格式。
--password-file=FILE 从FILE中得到密码。
--bwlimit=KBPS 限制I/O带宽，KBytes per second。
-h, --help 显示帮助信息。
```

## 实例

### 覆盖复制目录

```shell
rsync -v -r --delete --force --progress /mnt/root /
```

### 将源目录同步到目标目录

```shell
rsync -r source destination
```

上面命令中，`-r` 表示递归，即包含子目录。注意，`-r`是必须的，否则 `rsync` 运行不会成功。`source` 目录表示源目录，`destination` 表示目标目录。

### 多个文件或目录同步

```shell
rsync -r source1 source2 destination
```

上面命令中，`source1`、`source2` 都会被同步到 `destination` 目录。

### 同步元信息

`-a` 参数可以替代 `-r`，除了可以递归同步以外，还可以同步元信息（比如修改时间、权限等）。由于 `rsync` 默认使用文件大小和修改时间决定文件是否需要更新，所以 `-a` 比 `-r` 更有用。下面的用法才是常见的写法。

```shell
rsync -a source destination
```

目标目录 `destination` 如果不存在，`rsync` 会自动创建。执行上面的命令后，源目录 `source` 被完整地复制到了目标目录 `destination` 下面，即形成了 `destination/source` 的目录结构。

如果只想同步源目录 `source` 里面的内容到目标目录 `destination` ，则需要在源目录后面加上斜杠。

```shell
rsync -a source/ destination
```

上面命令执行后，`source` 目录里面的内容，就都被复制到了 `destination` 目录里面，并不会在 `destination` 下面创建一个 `source` 子目录。


### 模拟执行的结果

如果不确定 `rsync` 执行后会产生什么结果，可以先用 `-n` 或 `--dry-run` 参数模拟执行的结果。

```shell
rsync -anv source/ destination
```

上面命令中，`-n` 参数模拟命令执行的结果，并不真的执行命令。`-v` 参数则是将结果输出到终端，这样就可以看到哪些内容会被同步。

### 目标目录成为源目录的镜像副本

默认情况下，`rsync` 只确保源目录的所有内容（明确排除的文件除外）都复制到目标目录。它不会使两个目录保持相同，并且不会删除文件。如果要使得目标目录成为源目录的镜像副本，则必须使用 `--delete` 参数，这将删除只存在于目标目录、不存在于源目录的文件。

```shell
rsync -av --delete source/ destination
```

上面命令中，`--delete` 参数会使得 `destination` 成为 `source` 的一个镜像。


### 排除文件

有时，我们希望同步时排除某些文件或目录，这时可以用--exclude参数指定排除模式。

```shell
rsync -av --exclude='*.txt' source/ destination
# 或者
rsync -av --exclude '*.txt' source/ destination
```

上面命令排除了所有 `TXT` 文件。

注意，`rsync` 会同步以"点"开头的隐藏文件，如果要排除隐藏文件，可以这样写 `--exclude=".*"`。

如果要排除某个目录里面的所有文件，但不希望排除目录本身，可以写成下面这样。

```shell
rsync -av --exclude 'dir1/*' source/ destination
```

多个排除模式，可以用多个 `--exclude` 参数。

```shell
rsync -av --exclude 'file1.txt' --exclude 'dir1/*' source/ destination
```

多个排除模式也可以利用 Bash 的大扩号的扩展功能，只用一个 `--exclude` 参数。

```shell
rsync -av --exclude={'file1.txt','dir1/*'} source/ destination
```

如果排除模式很多，可以将它们写入一个文件，每个模式一行，然后用 `--exclude-from` 参数指定这个文件。

```shell
rsync -av --exclude-from='exclude-file.txt' source/ destination
```

### 指定必须同步的文件模式

`--include` 参数用来指定必须同步的文件模式，往往与 `--exclude` 结合使用。

```shell
rsync -av --include="*.txt" --exclude='*' source/ destination
```

上面命令指定同步时，排除所有文件，但是会包括 `TXT` 文件。
