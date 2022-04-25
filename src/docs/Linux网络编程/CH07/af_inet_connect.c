#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#define DEST_IP "220.181.38.148" /*服务器的IP地址*/
#define DEST_PORT 80           /*服务器端口*/

int main(int argc, char *argv[]) {
  int ret = 0;
  int sockfd;                /*sockfd为连接的 socket*/
  struct sockaddr_in server; /*服务器地址的信息*/

  /*初始化一个IPv4族的流式连接*/
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) { /*检查是否正常初始化 socket*/
    perror("socket");
    exit(EXIT_FAILURE);
  }

  server.sin_family = AF_INET;             /*协议族为IPv4,主机字节序*/
  server.sin_port = htons(DEST_PORT);      /*端口,短整形,网络字节序*/
  server.sin_addr.s_addr = htonl(DEST_IP); /*服务器的IP地址*/

  bzero(&(server.sin_zero), 8); /*保留字段置0*/
  ret = connect(sockfd, (struct sockaddr *) &server, sizeof(struct sockaddr));

  /*接收或者发送数据*/

  close(sockfd);
}
