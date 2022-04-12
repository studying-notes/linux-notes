# vgdisplay 命令

> 显示卷组信息

## 格式

```bash
vgdisplay
	[-A|--activevolumegroups]
	[-c|--colon | -s|--short | -v|--verbose]
	[-d|--debug]
	[-h|--help]
	[--ignorelockingfailure]
	[--ignoreskippedcluster]
	[--nosuffix]
	[-P|--partial]
	[--units hHbBsSkKmMgGtTpPeE]
	[--version]
	[VolumeGroupName [VolumeGroupName...]]

vgdisplay --columns|-C
	[--aligned]
	[-d|--debug]
	[-h|--help]
	[--ignorelockingfailure]
	[--ignoreskippedcluster]
	[--noheadings]
	[--nosuffix]
	[-o|--options [+]Field[,Field]]
	[-O|--sort [+|-]key1[,[+|-]key2[,...]]]
	[-P|--partial]
	[--separator Separator]
	[--unbuffered]
	[--units hHbBsSkKmMgGtTpPeE]
	[--verbose]
	[--version]
	[VolumeGroupName [VolumeGroupName...]]
```

## 示例

1. 显示卷组信息

```bash
$ vgdisplay
  --- Volume group ---
  VG Name               storage
  System ID
  Format                lvm2
  Metadata Areas        2
  Metadata Sequence No  1
  VG Access             read/write
  VG Status             resizable
  MAX LV                0
  Cur LV                0
  Open LV               0
  Max PV                0
  Cur PV                2
  Act PV                2
  VG Size               39.99 GiB
  PE Size               4.00 MiB
  Total PE              10238
  Alloc PE / Size       0 / 0
  Free  PE / Size       10238 / 39.99 GiB
  VG UUID               z6ONpA-vBmR-LzTs-8ZyA-wUZ2-hCkJ-Wqi0OX

  --- Volume group ---
  VG Name               rhel_redhat
  System ID
  Format                lvm2
  Metadata Areas        1
  Metadata Sequence No  3
  VG Access             read/write
  VG Status             resizable
  MAX LV                0
  Cur LV                2
  Open LV               2
  Max PV                0
  Cur PV                1
  Act PV                1
  VG Size               19.51 GiB
  PE Size               4.00 MiB
  Total PE              4994
  Alloc PE / Size       4994 / 19.51 GiB
  Free  PE / Size       0 / 0
  VG UUID               JRF02S-y1IR-Eba0-RhaO-zUkl-djcm-pbjexx
```
