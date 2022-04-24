"""
Date: 2022.04.21 10:36:18
LastEditors: Rustle Karl
LastEditTime: 2022.04.21 13:35:59
"""
from scapy.layers.inet import IP, raw

"""
scapy -H
"""

# 构造 IP 数据包
ipv4 = IP(flags=1, frag=2, ttl=12, dst="192.168.4.1")

# 显示 IP 数据包
ipv4.show()

# 打印16进制字节数据
raw(ipv4)
