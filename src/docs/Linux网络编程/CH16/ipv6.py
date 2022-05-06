"""
Date: 2022.04.21 10:36:18
LastEditors: Rustle Karl
LastEditTime: 2022.04.21 13:35:59
"""
from scapy.compat import raw
from scapy.layers.inet6 import IPv6
from scapy.layers.inet import IP

"""
scapy -H
"""

# 构造 IP 数据包
ipv4 = IP()
ipv6 = IPv6()

# 显示 IP 数据包
ipv4.show()
ipv6.show()

# 打印16进制字节数据
raw(ipv6)
