#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
  fd_set rd;         /*读文件集和*/
  struct timeval tv; /*时间间隔*/
  int err;           /*错误值*/

  /*监视标准输入是否可以读数据*/

  FD_ZERO(&rd);
  FD_SET(0, &rd);// 添加标准输入

  /*设置5s的等待超时*/
  tv.tv_sec = 5;
  tv.tv_usec = 0;

  err = select(1, &rd, NULL, NULL, &tv);

  if (err == -1) {
    perror("select");
  } else if (err) { /*标准输入有数据输入，可读*/
    printf("data is available.\n");
  } else {
    printf("no data available within 5 seconds.\n");
  }

  return 0;
}
