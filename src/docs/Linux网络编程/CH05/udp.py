"""
Date: 2022.04.21 16:43:08
LastEditors: Rustle Karl
LastEditTime: 2022.04.21 22:39:53
"""
from scapy.layers.inet import IP, UDP

udp = IP(dst="192.168.0.1") / UDP(dport=80, sport=1080)
udp.show()
