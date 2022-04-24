"""
Date: 2022.04.21 11:26:28
LastEditors: Rustle Karl
LastEditTime: 2022.04.21 11:41:49
"""
from scapy.layers.inet import Ether, raw
from scapy.data import *

# 0x800 表示此帧的数据为 IP 数据
# 0x0806 表示此帧为 ARP 请求应答

ether = Ether(dst="ff:ff:ff:ff:ff:ff", src="b4:2e:c4:20:cd:0b", type=0x800)
# ether = Ether(type=ETH_P_IP)
# ether = Ether(type=ETH_P_IPV6)
ether.show()

# ether = Ether(type=0x0806)
ether = Ether(type=ETH_P_ARP)
ether.show()

ether_raw = raw(ether)

print(ether_raw)
print(len(ether_raw))  # 以太网的封包在 IP 数据的基础上增加了共 14 个字节
