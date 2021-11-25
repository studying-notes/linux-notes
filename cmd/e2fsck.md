# e2fsck 命令

> 检查文件系统

## 格式

```bash
e2fsck [-panyrcdfvtDFV] [-b superblock] [-B blocksize]
		[-I inode_buffer_blocks] [-P process_inode_size]
		[-l|-L bad_blocks_file] [-C fd] [-j external_journal]
		[-E extended-options] device
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
|  -p | Automatic repair (no questions) |
|  -n | Make no changes to the filesystem |
|  -y | Assume "yes" to all questions |
|  -c | Check for bad blocks and add them to the badblock list |
|  -f | Force checking even if filesystem is marked clean |
|  -v | Be verbose |
|  -b superblock | Use alternative superblock |
|  -B blocksize | Force blocksize when looking for superblock |
|  -j external_journal  Set location of the external journal |
|  -l bad_blocks_file | Add to badblocks list |
|  -L bad_blocks_file | Set badblocks list |

## 示例

1. 检查文件系统的完整性

```bash
$ e2fsck -f /dev/storage/vo
e2fsck 1.42.9 (28-Dec-2013)
Pass 1: Checking inodes, blocks, and sizes
Pass 2: Checking directory structure
Pass 3: Checking directory connectivity
Pass 4: Checking reference counts
Pass 5: Checking group summary information
/dev/storage/vo: 11/74000 files (0.0% non-contiguous), 15507/299008 blocks
```
