# pvcreate 命令

> 初始化供 LVM 使用的物理卷

## 格式

```bash
pvcreate
	[--norestorefile]
	[--restorefile file]
	[-d|--debug]
	[-f[f]|--force [--force]]
	[-h|-?|--help]
	[--labelsector sector]
	[-M|--metadatatype 1|2]
	[--pvmetadatacopies #copies]
	[--bootloaderareasize BootLoaderAreaSize[bBsSkKmMgGtTpPeE]]
	[--metadatasize MetadataSize[bBsSkKmMgGtTpPeE]]
	[--dataalignment Alignment[bBsSkKmMgGtTpPeE]]
	[--dataalignmentoffset AlignmentOffset[bBsSkKmMgGtTpPeE]]
	[--setphysicalvolumesize PhysicalVolumeSize[bBsSkKmMgGtTpPeE]
	[-t|--test]
	[-u|--uuid uuid]
	[-v|--verbose]
	[-y|--yes]
	[-Z|--zero {y|n}]
	[--version]
	PhysicalVolume [PhysicalVolume...]
```

## 示例

1. 让新添加的两块硬盘设备支持 LVM 技术

```bash
$ pvcreate /dev/sdb /dev/sdc
  Physical volume "/dev/sdb" successfully created
  Physical volume "/dev/sdc" successfully created
```

2. 把两块硬盘设备加入到 storage 卷组中

```bash
$ vgcreate storage /dev/sdb /dev/sdc
  Volume group "storage" successfully created
```
