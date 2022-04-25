#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#define MYPORT 3490 /*端口地址*/

int main(int argc, char *argv[]) {
  int sockfd;                 /*套接字文件描述符变量*/
  struct sockaddr_in my_addr; /*以太网套接字地址结构*/

  sockfd = socket(AF_INET, SOCK_STREAM, 0); /*初始化 socket*/

  if (sockfd == -1) { /*检查是否正常初始化socket*/
    perror("socket");
    exit(EXIT_FAILURE);
  }

  my_addr.sin_family = AF_INET;                         /*地址结构的协议族*/
  my_addr.sin_port = htons(MYPORT);                     /*地址结构的端口地址,网络字节序*/
  my_addr.sin_addr.s_addr = inet_addr("192.168.4.171"); /*IP,将字符串的IP地址转化为网络字节序*/

  bzero(&(my_addr.sin_zero), 8); /*将my_addr.sin_zero 置为0*/

  if (bind(sockfd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr)) == -1) { /*判断是否绑定成功*/
    perror("bind");
    exit(EXIT_FAILURE);
  }

  /*进行侦听队列长度的绑定*/
  if (listen(sockfd, 5) == -1) { /*判断是否listen成功*/
    perror("listen");            /*打印错误信息*/
    exit(EXIT_FAILURE);          /*退出程序*/
  }

  close(sockfd); /*关闭套接字文件描述符*/
}
