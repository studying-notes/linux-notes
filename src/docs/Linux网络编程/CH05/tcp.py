"""
Date: 2022.04.21 16:43:08
LastEditors: Rustle Karl
LastEditTime: 2022.04.21 22:39:50
"""
from scapy.layers.inet import IP, TCP

# SYN
syn = IP(dst="192.168.4.1") / TCP(dport=80, sport=1080, flags="S", seq=1)
syn.show()

# ACK
syn = IP(dst="192.168.4.1") / TCP(dport=80, sport=1080, flags="A", seq=1)
syn.show()
