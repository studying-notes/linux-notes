# lvextend 命令

> 扩展供 LVM 使用的物理卷

## 格式

```bash
lvextend
	[-A|--autobackup y|n]
	[--alloc AllocationPolicy]
	[-d|--debug]
	[-f|--force]
	[-h|--help]
	[-i|--stripes Stripes [-I|--stripesize StripeSize]]
	{-l|--extents [+]LogicalExtentsNumber[%{VG|LV|PVS|FREE|ORIGIN}] |
	 -L|--size [+]LogicalVolumeSize[bBsSkKmMgGtTpPeE]}
	 --poolmetadatasize [+]MetadataVolumeSize[bBsSkKmMgG]}
	[-m|--mirrors Mirrors]
	[--nosync]
	[--use-policies]
	[-n|--nofsck]
	[--noudevsync]
	[-r|--resizefs]
	[-t|--test]
	[--type VolumeType]
	[-v|--verbose]
	[--version]
	LogicalVolume[Path] [ PhysicalVolumePath... ]
```

## 示例

```bash
$ lvextend -L 290M /dev/storage/vo
  Rounding size to boundary between physical extents: 292.00 MiB
  Extending logical volume vo to 292.00 MiB
  Logical volume vo successfully resized
```
