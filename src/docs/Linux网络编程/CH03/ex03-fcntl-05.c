/*文件ex03-fcntl-05.c,
使用fcntl设置接收信号的进程ID*/
#include <fcntl.h>
#include <unistd.h>

int main() {
  int uid;
  /*打开文件test.txt*/
  int fd = open("test.txt", O_RDWR);

  /*获得接收信号的进程ID*/
  uid = fcntl(fd, F_SETOWN, 10000);

  close(fd);

  return 0;
}
