"""
Date: 2022.04.21 13:47:29
LastEditors: Rustle Karl
LastEditTime: 2022.04.21 13:59:27
"""
from typing import Union


def checksum_crc16(d: Union[bytearray, bytes]):
    # CRC16, IP/ICMP 校验和算法

    checksum = 0
    length = len(d)

    if length % 2 == 1:
        length -= 1
        checksum += d[length] << 8

    while length > 0:
        checksum += d[length - 1] | (d[length - 2] << 8)
        length -= 2

    return (~((checksum >> 16) + (checksum & 0x0000FFFF))) & 0xFFFF


assert (
    checksum_crc16(
        bytearray(
            [
                0x45,
                0x00,
                0x00,
                0x3C,
                0x00,
                0x00,
                0x00,
                0x00,
                0x40,
                0x11,
                0xC0,
                0xA8,
                0x2B,
                0xC3,
                0x08,
                0x08,
                0x08,
                0x08,
                0x11,
            ]
        )
    )
    == 0x6D36
)
