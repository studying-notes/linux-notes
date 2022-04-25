#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#define MYPORT 3490 /*端口地址*/

int main(int argc, char *argv[]) {
  int sockfd, client_fd; /*sockfd为侦听的 socket,client_fd为连接方的socket值*/

  struct sockaddr_in my_addr;     /*本地地址信息*/
  struct sockaddr_in client_addr; /*客户端连接的地址信息*/

  socklen_t addr_length; /*int类型变量,用于保存网络地址长度量*/

  sockfd = socket(AF_INET, SOCK_STREAM, 0); /*初始化一个IPv4族的流式连接*/

  if (sockfd == -1) {   /*检查是否正常初始化socket*/
    perror("socket");   /*打印错误信息*/
    exit(EXIT_FAILURE); /*退出程序*/
  }

  my_addr.sin_family = AF_INET;         /*协议族为IPv4,主机字节序*/
  my_addr.sin_port = htons(MYPORT);     /*端口,短整形,网络字节序*/
  my_addr.sin_addr.s_addr = INADDR_ANY; /*自动IP地址获得*/

  bzero(&(my_addr.sin_zero), 8); /*置0*/

  /*绑定端口地址*/
  if (bind(sockfd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr)) == -1) { /*判断是否绑定成功*/
    perror("bind");                                                                /*打印错误信息*/
    exit(EXIT_FAILURE);                                                            /*退出程序*/
  }

  /*设置侦听队列长度为BACKLOG=10*/
  int BACKLOG = 10;
  if (listen(sockfd, BACKLOG) == -1) { /*判断是否listen成功*/
    perror("listen");                  /*打印错误信息*/
    exit(EXIT_FAILURE);                /*退出程序*/
  }

  addr_length = sizeof(struct sockaddr_in); /*地址长度*/
  client_fd = accept(sockfd, (struct sockaddr *) &client_addr, &addr_length);

  /*等待客户端连接,地址在client addr中*/
  if (client_fd == -1) { /*accept出错*/
    perror("accept");    /*打印错误信息*/
    exit(EXIT_FAILURE);  /*退出程序*/
  }

  /*处理客户端连接过程*/
  close(client_fd); /*关闭客户端连接*/

  /*其他过程*/

  close(sockfd); /*关闭服务器端连接*/
}
