cmake_minimum_required(VERSION 3.11)

project(tcp C)

set(CMAKE_C_STANDARD 11)

add_executable(
        tcp_client
        tcp_client.c
        tcp_process.c
        tcp_process.h
)

add_executable(
        tcp_server
        tcp_server.c
        tcp_process.c
        tcp_process.h
)
