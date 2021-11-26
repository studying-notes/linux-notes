# 挂载（Mount）文件系统（二）

> Shared Subtrees 技术详解

Shared Subtrees 就是一种控制子挂载点能否在其他地方被看到的技术，它只会在绑定挂载时和 Mount 命名空间中用到，属于不怎么常用的功能。

## 概述

### peer group

`peer group` 是一个或多个挂载点的集合，它们之间可以共享挂载信息。目前在下面两种情况下会使两个挂载点属于同一个 `peer group` ，前提条件是挂载点的 `propagation type` 是 `shared`：

- 利用 `mount --bind` 命令，将会使**源挂载点**和目的挂载点属于同一个 `peer group` ；
- 当创建新的 Mount 命名空间时，新命名空间会拷贝一份旧命名空间的挂载点信息，于是新的和旧的命名空间里面的相同挂载点就会属于同一个 `peer group` 。

### propagation type

每个挂载点都有一个 `propagation type` 标志, 由它来决定当在一个挂载点下创建和移除挂载点时，是否会传播到属于相同 `peer group` 的其他挂载点中去，也即同一个 `peer group` 里的其他的挂载点下是不是也会创建和移除相应的挂载点。现在有4种不同类型的 `propagation type`：

- MS_SHARED: 挂载信息会在同一个 `peer group` 的不同挂载点之间共享传播。当一个挂载点下面添加或者删除挂载点的时候，同一个 `peer group` 里的其他挂载点下面也会挂载和卸载同样的挂载点；

- MS_PRIVATE: 挂载信息不共享，也即 `private` 的挂载点不属于任何 `peer group`；

- MS_SLAVE: 挂载信息的传播是单向的，在同一个 `peer group` 里面，`master` 的挂载点下面发生变化的时候，`slave` 的挂载点下面也跟着变化，但反之则不然，`slave` 下发生变化时不会通知 `master`，`master` 不会发生变化；

- MS_UNBINDABLE: 和MS_PRIVATE相同，只是这种类型的挂载点不能作为 `bind mount` 的源，用来防止递归嵌套情况的出现。

### 概念澄清

- `propagation type` 是挂载点的属性，每个挂载点都是独立的；

- 挂载点是有父子关系的，比如挂载点 `/` 和 `/mnt/cdrom`，`/mnt/cdrom` 是 `/` 的子挂载点，`/` 是 `/mnt/cdrom` 的父挂载点；

- 默认情况下，如果父挂载点是 MS_SHARED，那么子挂载点也是 MS_SHARED ，否则子挂载点将会是 MS_PRIVATE，跟爷爷挂载点没有关系。

## 示例

### 准备相关文件

```bash
# 制作4个虚拟硬盘，在上面创建 `ext4` 文件系统
$ mkdir disks && cd disks
$ dd if=/dev/zero bs=1M count=32 of=disk1.img
$ dd if=/dev/zero bs=1M count=32 of=disk2.img
$ dd if=/dev/zero bs=1M count=32 of=disk3.img
$ dd if=/dev/zero bs=1M count=32 of=disk4.img

$ mkfs.ext4 disk1.img
$ mkfs.ext4 disk2.img
$ mkfs.ext4 disk3.img
$ mkfs.ext4 disk4.img

# 准备两个目录用于挂载上面创建的虚拟硬盘
$ mkdir disk1 disk2
$ ls
disk1/  disk1.img  disk2/  disk2.img  disk3.img  disk4.img

# 确保根目录的 `propagation type` 是 `shared`
$ mount --make-shared /
```

### `propagation type` 属性继承

```bash
# 以 `shared` 方式挂载 `disk1`
$ mount --make-shared disk1.img disk1

# 以 `private` 方式挂载 `disk2`
$ mount --make-private disk2.img disk2

$ cat /proc/self/mountinfo | grep disk | sed 's/ - .*//'
28 27 7:0 / /root/disks/disk1 rw,relatime shared:22
50 27 7:1 / /root/disks/disk2 rw,relatime

# 分别在 `disk1` 和 `disk2` 目录下创建目录 `disk3` 和 `disk4`
$ mkdir disk1/disk3 disk2/disk4

# 挂载 `disk3`，`disk4` 到这两个目录
$ mount disk3.img disk1/disk3
$ mount disk4.img disk2/disk4

# 第一列的数字是挂载点 ID，第二列是父挂载点 ID
$ cat /proc/self/mountinfo | grep disk | sed 's/ - .*//'
28 27 7:0 / /root/disks/disk1 rw,relatime shared:22
50 27 7:1 / /root/disks/disk2 rw,relatime
51 28 7:2 / /root/disks/disk1/disk3 rw,relatime shared:23
52 50 7:3 / /root/disks/disk2/disk4 rw,relatime

$ umount disk1/disk3
$ umount disk2/disk4
```

### 以 `shared` 和 `private` 方式挂载

```bash
$ mkdir bind1 bind2
$ mount --bind disk1 bind1
$ mount --bind disk2 bind2

$ cat /proc/self/mountinfo | grep disk | sed 's/ - .*//'
28 27 7:0 / /root/disks/disk1 rw,relatime shared:22
50 27 7:1 / /root/disks/disk2 rw,relatime
51 27 7:0 / /root/disks/bind1 rw,relatime shared:22
52 27 7:1 / /root/disks/bind2 rw,relatime shared:23
```

默认情况下 `bind1` 和 `bind2` 的 `propagation type` 继承自父挂载点27(/)，都是 `shared`。由于 `bind2` 的源挂载点 `disk2` 是 `private` 的，所以 `bind2` 没有和 `disk2` 在同一个 `peer group` 里面，而是重新创建了一个新的 `peer group`，这个 `group` 里面就只有它一个。因为28和51都是 `shared` 类型且是通过 `bind` 方式挂载在一起的，所以它们属于同一个 `peer group` 22。

```bash
# 根目录的挂载点
$ cat /proc/self/mountinfo | grep '^27' | sed 's/ - .*//'
27 0 8:2 / / rw,relatime shared:1

# 这时 `disk3` 和 `disk4` 目录都是空的
$ ls bind1/disk3/
$ ls bind2/disk4/
$ ls disk1/disk3/
$ ls disk2/disk4/

# 挂载 `disk3` 和 `disk4` 
$ mount disk3.img disk1/disk3
$ mount disk4.img disk2/disk4

$ ls disk1/disk3/
lost+found

$ ls bind1/disk3/
lost+found
```

由于 `disk1/` 和 `bind1/` 属于同一个 `peer group`，所以在挂载了 `disk3` 后，在两个目录下都能看到 `disk3` 下的内容。

```bash
$ ls disk2/disk4/
lost+found
$ ls bind2/disk4/
```

而 `disk2/` 是 `private` 类型的，所以在它下面挂载 `disk4` 不会通知 `bind2`，于是 `bind2` 下的 `disk4` 目录是空的。

```bash
$ cat /proc/self/mountinfo | grep "disk3" | sed 's/ - .*//'
53 28 7:2 / /root/chroot/disks/disk1/disk3 rw,relatime shared:24
59 51 7:2 / /root/chroot/disks/bind1/disk3 rw,relatime shared:24 
```

由于它们父挂载点属于同一个 `peer group`，且 `disk3` 是以默认方式挂载的，所以它们属于同一个 `peer group`。

```bash
$ umount bind1/disk3
$ cat /proc/self/mountinfo | grep disk3
$ 
```

卸载 `bind1/disk3` 后，`disk1/disk3` 也相应的自动卸载掉了。

### 以 `slave` 方式挂载

1. 卸载其他文件

```bash
$ umount disk2/disk4
$ umount /root/chroot/disks/bind1
$ umount /root/chroot/disks/bind2
$ umount /root/chroot/disks/disk2

$ cat /proc/self/mountinfo | grep disk | sed 's/ - .*//'
28 27 7:0 / /root/chroot/disks/disk1 rw,relatime shared:22
```

2. 分别用 `shared` 和 `slave` 的方式绑定挂载 `disk1`

```bash
$ mount --bind --make-shared disk1 bind1
$ mount --bind --make-slave disk1 bind2
$ cat /proc/self/mountinfo | grep disk | sed 's/ - .*//'
28 27 7:0 / /root/chroot/disks/disk1 rw,relatime shared:22
50 27 7:0 / /root/chroot/disks/bind1 rw,relatime shared:22
51 27 7:0 / /root/chroot/disks/bind2 rw,relatime master:22
```

以上三者都属于同一个 `peer group`：22，`master:22` 表示 `/root/chroot/disks/bind2` 是`peer group 22` 的 `slave`。

3. 挂载 `disk3` 到 `disk1` 的子目录 `disk3` 下

```bash
$ mount disk3.img disk1/disk3
$ cat /proc/self/mountinfo | grep disk | sed 's/ - .*//'
28 27 7:0 / /root/chroot/disks/disk1 rw,relatime shared:22
50 27 7:0 / /root/chroot/disks/bind1 rw,relatime shared:22
51 27 7:0 / /root/chroot/disks/bind2 rw,relatime master:22
52 28 7:1 / /root/chroot/disks/disk1/disk3 rw,relatime shared:23
59 51 7:1 / /root/chroot/disks/bind2/disk3 rw,relatime master:23
53 50 7:1 / /root/chroot/disks/bind1/disk3 rw,relatime shared:23
$ 
```

其他两个目录 `bind1` 和 `bind2` 里面也挂载成功，说明 `master` 发生变化的时候，`slave` 会跟着变化。

4. 卸载 `disk3`，然后挂载 `disk3` 到 `bind2` 目录下

```bash
$ umount disk1/disk3
$ mount disk3.img bind2/disk3
$ cat /proc/self/mountinfo | grep disk | sed 's/ - .*//'
28 27 7:0 / /root/chroot/disks/disk1 rw,relatime shared:22
50 27 7:0 / /root/chroot/disks/bind1 rw,relatime shared:22
51 27 7:0 / /root/chroot/disks/bind2 rw,relatime master:22
52 51 7:1 / /root/chroot/disks/bind2/disk3 rw,relatime
```

由于 `bind2` 的 `propagation type` 是 `slave`，所以 `disk1` 和 `bind1` 两个挂载点下面不会挂载 `disk3`。
