#include <memory.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/socket.h>

#define CMD_DISCOVERY "CMD_DISCOVERY"         /*IP发现命令*/
#define CMD_DISCOVERY_ACK "CMD_DISCOVERY_ACK" /*IP发现应答命令*/

#define BUFFER_LEN 32
#define MCAST_PORT 54321

void HandleIPFound(void *arg) {
  int ret = -1;
  int sock = -1;
  struct sockaddr_in local_addr; /*本地地址*/
  struct sockaddr_in from_addr;  /*客户端地址*/
  int from_len;
  int count = -1;
  fd_set readfd;
  char buff[BUFFER_LEN];
  struct timeval timeout;
  timeout.tv_sec = 2; /*超时时间2秒*/
  timeout.tv_usec = 0;
  printf("==>HandleIPFound\n");
  sock = socket(AF_INET, SOCK_DGRAM, 0); /*建立数据报套接字*/
  if (sock < 0) {
    printf("HandleIPFound: socket init error\n");
    return;
  }
  /*数据清零*/
  memset((void *) &local_addr, 0, sizeof(struct sockaddr_in));
  local_addr.sin_family = AF_INET;                /*协议族*/
  local_addr.sin_addr.s_addr = htonl(INADDR_ANY); /*本地地址*/
  local_addr.sin_port = htons(MCAST_PORT);        /*侦听端口*/
  /*绑定*/
  ret = bind(sock, (struct sockaddr *) &local_addr, sizeof(local_addr));
  if (ret != 0) {
    printf("HandleIPFound:bind error\n");
    return;
  }
  /*主处理过程*/
  while (1) {
    /*文件描述符集合清零*/
    FD_ZERO(&readfd);
    /*将套接字文件描述符加入读集合*/
    FD_SET(sock, &readfd);
    /*select侦听是否有数据到来*/
    ret = select(sock + 1, &readfd, NULL, NULL, &timeout);
    switch (ret) {
    case -1:
      /*发生错误*/
      break;
    case 0:
      /*超时*/
      //DO timeout THING
      break;
    default:
      /*有数据到来*/
      if (FD_ISSET(sock, &readfd)) {
        /*接收数据*/
        count = recvfrom(sock, buff, BUFFER_LEN, 0, (struct sockaddr *) &from_addr, &from_len);
        printf("Recv msg is %s\n", buff);
        if (strstr(buff, CMD_DISCOVERY)) /*判断是否吻合*/
        {
          /*将应答数据考入*/
          memcpy(buff, CMD_DISCOVERY_ACK, strlen(CMD_DISCOVERY_ACK) + 1);
          /*发送给客户端*/
          count = sendto(sock, buff, strlen(buff), 0, (struct sockaddr *) &from_addr, from_len);
        }
      }
    }
  }
}
