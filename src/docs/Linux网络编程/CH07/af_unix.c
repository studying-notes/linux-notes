#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define MY_SOCK_PATH "/path"

#define UNIX_PATH_MAX 108

struct sockaddr_un {
  sa_family_t sun_family;       /*协议族,应该设置为AFUNIX*/
  char sun_path[UNIX_PATH_MAX]; /*路径名,UNIXPATHMAX的值为108*/
};

int main(int argc, char *argv[]) {
  int sfd;
  struct sockaddr_un addr; /*AF_UNIX对应的结构*/

  sfd = socket(AF_UNIX, SOCK_STREAM, 0);

  /*初始化一个AF_UNIX族的流类型 socket*/
  if (sfd == -1) { /*检查是否正常初始化socket*/
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset(&addr, 0, sizeof(struct sockaddr_un)); /*将变量addr置0*/

  addr.sun_family = AF_UNIX;                                       /*协议族为AF_UNIX*/
  strncpy(addr.sun_path, MY_SOCK_PATH, sizeof(addr.sun_path) - 1); /*复制路径到地址结构*/

  if (bind(sfd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1) { /*判断是否绑定成功*/
    perror("bind");
    exit(EXIT_FAILURE);
  }

  /*数据接收发送及处理过程*/

  close(sfd); /*关闭套接字文件描述符*/
}
