"""
Date: 2022.04.21 14:23:20
LastEditors: Rustle Karl
LastEditTime: 2022.04.21 14:44:37
"""
from scapy.layers.inet import IP, ICMP, sr1,raw

# 回显
icmp = IP(dst="192.168.4.1") / ICMP()

# 时间戳的请求应答格式
icmp = IP(dst="192.168.4.1") / ICMP(type=13)

icmp.show()
icmp.summary()

# 发送和接收数据包
timestamp_reply = sr1(icmp)

raw(icmp).hex()
