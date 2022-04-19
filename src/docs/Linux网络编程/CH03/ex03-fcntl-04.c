/*文件ex03-fcntl-04.c,
使用fcntl获得接收信号的进程ID*/
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int uid;
  /*打开文件test.txt*/
  int fd = open("test.txt", O_RDWR);

  /*获得接收信号的进程ID*/
  uid = fcntl(fd, F_GETOWN);
  printf("the SIG recv ID is %d\n", uid);

  close(fd);

  return 0;
}
