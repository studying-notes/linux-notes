"""
Date: 2022.04.21 14:46:36
LastEditors: Rustle Karl
LastEditTime: 2022.04.21 16:16:17
"""
import os
import socket
import struct
import time
import select
from crc import checksum_crc16


def get_ping_packet_with_checksum(type, code, checksum, id, sequence, payload):
    """获取数据校验和，然后打包"""

    # 把字节打包成二进制数据
    packet = struct.pack(">BBHHH32s", type, code, checksum, id, sequence, payload)

    #  把校验和传入，得到填充校验和后的数据包
    return struct.pack(
        ">BBHHH32s",
        type,
        code,
        checksum_crc16(packet),
        id,
        sequence,
        payload,
    )


def send_icmp_packet(host, packet):
    """发送原始 ICMP 数据包"""
    send_begin_time = time.time()
    socket_raw = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    socket_raw.sendto(packet, (host, 80))
    return send_begin_time, socket_raw, host


def reply_ping(send_begin_time, socket_raw: socket.socket, send_sequence, timeout=3):
    while True:
        select_begin_time = time.time()
        ready = select.select([socket_raw], [], [], timeout)
        select_wait_time = time.time() - select_begin_time

        # 没有返回可读的内容，判断超时
        if not ready[0]:
            return -1

        raw_packet, address = socket_raw.recvfrom(1024)

        ip_packet = raw_packet[:20]
        icmp_header = raw_packet[20:28]
        type, code, checksum, id, sequence = struct.unpack(">BBHHH", icmp_header)

        if type == 0 and sequence == send_sequence:
            return time.time() - send_begin_time

        # 数据包的超时时间判断
        if timeout - select_wait_time < 0:
            return -1


def ping(host="baidu.com"):
    send, accept, lose = 0, 0, 0
    sum_time, short_time, long_time, avg_time = 0, 1000, 0, 0

    # 将主机名转ipv4地址格式，返回以ipv4地址格式的字符串，如果主机名称是ipv4地址，则它将保持不变
    dst = socket.gethostbyname(host)

    print("正在 Ping {0} [{1}] 具有 32 字节的数据:".format(host, dst))

    id = os.getpid()
    repeat = 4

    for i in range(1, 1 + repeat):
        packet = get_ping_packet_with_checksum(8, 0, 0, id, i, b"OK" * 16)
        send_begin_time, socket_raw, host = send_icmp_packet(dst, packet)
        cost_time = reply_ping(send_begin_time, socket_raw, i)  # 数据包传输时间

        if cost_time > 0:
            print("来自 {0} 的回复: 字节=32 时间={1}ms".format(dst, int(cost_time * 1000)))

            accept += 1
            return_time = int(cost_time * 1000)
            sum_time += return_time

            if return_time > long_time:
                long_time = return_time
            if return_time < short_time:
                short_time = return_time

            time.sleep(0.5)
        else:
            lost += 1
            print("请求超时。")

    print("{0}的Ping统计信息：".format(dst))

    print(
        "数据包：已发送={0},接收={1}，丢失={2}（{3}%丢失），\n"
        "往返行程的估计时间（以毫秒为单位）：\n"
        "最短={4}ms，最长={5}ms，平均={6}ms".format(
            repeat,
            accept,
            repeat - accept,
            (repeat - accept) / (i + 1) * 100,
            short_time,
            long_time,
            sum_time,
        )
    )

if __name__ == "__main__":
    ping("baidu.com")
