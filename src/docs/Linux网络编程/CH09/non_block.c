#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 9992 /* 侦听端口地址 */
#define BACKLOG 4 /* 侦听队列长度 */

int main(int argc, char *argv[]) {
  int ss, sc; /* ss为服务器的socket描述符,sc为客户端的socket描述符 */

  struct sockaddr_in server_addr; /* 服务器地址结构 */
  struct sockaddr_in client_addr; /* 客户端地址结构 */

  socklen_t addrlen = sizeof(struct sockaddr);

  int err; /* 返回值 */

  /* 建立一个流式套接字 */
  ss = socket(AF_INET, SOCK_STREAM, 0);
  if (ss < 0) { /* 出错 */
    printf("socket error\n");
    return -1;
  }

  /* 设置服务器地址 */
  bzero(&server_addr, sizeof(server_addr)); /* 清0 */
  server_addr.sin_family = AF_INET;         /* 协议族 */
  server_addr.sin_addr.s_addr = htonl(0);   /* 0.0.0.0 */
  server_addr.sin_port = htons(PORT);       /* 服务器端口 */

  /*设置非阻塞方式*/
  fcntl(ss, F_SETFL, O_NONBLOCK);

  /* 绑定地址结构到套接字描述符 */
  err = bind(ss, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if (err < 0) { /* 出错 */
    printf("bind error\n");
    return -1;
  }

  /* 设置侦听 */
  err = listen(ss, BACKLOG);
  if (err < 0) { /* 出错 */
    printf("listen error\n");
    return -1;
  }

  printf("listening on %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

  for (;;) {
    /*轮询接收客户端*/
    while (sc < 0) { /*等待客户端到来*/
      sc = accept(ss, (struct sockaddr *) &client_addr, &addrlen);
    }

    char buffer[1024] = {0};

    while (1) {
      ssize_t n;

      /*轮询接收，当接收到数据的时候退出while循环*/
      while ((n = recv(sc, buffer, 1024, 0)) <= 0)
        ;

      err = send(sc, "OK", 3, 0) + send(sc, buffer, n, 0); /*发送响应*/
      if (err < 0) {                                       /* 出错 */
        printf("send error\n");
        break; /*退出主循环*/
      }

      if (strcmp(buffer, "SHUTDOWN") == 0) { /*判断是否为SHUTDOWN字符串*/
        send(sc, "BYE", 3, 0);               /*发送BYE字符串*/
        close(sc);                           /*关闭客户端连接*/
        break;                               /*退出主循环*/
      }
    }
  }

  close(ss);
  return 0;
}
