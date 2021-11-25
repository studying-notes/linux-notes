# ifconfig 命令

> 获取网卡配置与网络状态等信息

## 格式

```bash
ifconfig [-v] [-a] [-s] [interface]
ifconfig [-v] interface [aftype] options | address ...
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -a | display all interfaces which are currently available, even if down |
| -s | display a short list (like netstat -i) |
| -v | be more verbose for some error conditions |
| interface | The name of the interface.  This is usually a driver  name  followed  by  a unit  number,  for  example  eth0 for the first Ethernet interface. If your kernel supports alias interfaces, you can specify  them  with  syntax  like eth0:0  for  the  first  alias  of  eth0.  You  can use them to assign more addresses. To delete an alias interface use ifconfig  eth0:0  down.   Note: for  every  scope  (i.e.  same  net  with  address/netmask combination) all aliases are deleted, if you delete the first (primary). |
| up | This flag causes the interface to be activated.  It is implicitly specified if  an address is assigned to the interface; you can suppress this behavior when using an alias  interface  by  appending  an  -  to  the  alias  (e.g. eth0:0-).  It is also suppressed when using the IPv4 0.0.0.0 address as the kernel will use this to implicitly delete alias interfaces. |
| down | This flag causes the driver for this interface to be shut down. |
| [-]arp | Enable or disable the use of the ARP protocol on this interface. | 
| [-]promisc | Enable or disable the promiscuous mode of the interface. If selected, all packets on the network will be received by the interface. | 
| [-]allmulti | Enable or disable all-multicast mode. If selected, all multicast packets on the network will be received by the interface. | 
| mtu N | This parameter sets the Maximum Transfer Unit (MTU) of an interface. | 
| dstaddr addr | Set the remote IP address for a point-to-point link (such as PPP). This keyword is now obsolete; use the pointopoint keyword instead. | 
| netmask addr | Set the IP network mask for this interface. This value defaults to the usual class A, B or C network mask (as derived from the interface IP address), but it can be set to any value. | 
| add addr/prefixlen | Add an IPv6 address to an interface. | 
| del addr/prefixlen | Remove an IPv6 address from an interface. | 
| tunnel ::aa.bb.cc.dd | Create a new SIT (IPv6-in-IPv4) device, tunnelling to the given destination. cally change their IRQ setting. | 
| io_addr addr | Set the start address in I/O space for this device. | 
| mem_start addr | Set the start address for shared memory used by this device. Only a few devices need this. | 
| media type | Set the physical port or medium type to be used by the device. Not all devices can change this setting, and those that can vary in what values they support. Typical values for type are 10base2 (thin Ethernet), 10baseT (twisted-pair 10Mbps Ethernet), AUI (external transceiver) and so on. The special medium type of auto can be used to tell the driver to auto-sense the media. Again, not all drivers can do this. | 
| [-]broadcast [addr] | If the address argument is given, set the protocol broadcast address for this interface. Otherwise, set (or clear) the IFF_BROADCAST flag for the interface. | 
| [-]pointopoint [addr] | This keyword enables the point-to-point mode of an interface, meaning that it is a direct link between two machines with nobody else listening on it. If the address argument is also given, set the protocol address of the other side of the link, just like the obsolete dstaddr keyword does. Otherwise, set or clear the IFF_POINTOPOINT flag for the interface. | 
| hw class address | Set the hardware address of this interface, if the device driver supports this operation. The keyword must be followed by the name of the hardware class and the printable ASCII equivalent of the hardware address. Hardware classes currently supported include ether (Ethernet), ax25 (AMPR AX.25), ARCnet and netrom (AMPR NET/ROM). | 
| multicast | Set the multicast flag on the interface. This should not normally be needed as the drivers set the flag correctly themselves. | 
| address | The IP address to be assigned to this interface. | 
| txqueuelen length | Set the length of the transmit queue of the device. It is useful to set this to small values for slower devices with a high latency (modem links, ISDN) to prevent fast bulk transfers from disturbing interactive traffic like telnet too much. | 

## 示例

1. 立即关机

```bash
$ ifconfig

eth0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 172.18.172.99  netmask 255.255.240.0  broadcast 172.18.175.255
        ether 00:16:3e:06:95:29  txqueuelen 1000  (Ethernet)
        RX packets 5978568  bytes 7804985247 (7.8 GB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 998731  bytes 157945287 (157.9 MB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 121696  bytes 75569302 (75.5 MB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 121696  bytes 75569302 (75.5 MB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```
