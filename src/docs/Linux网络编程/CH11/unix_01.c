#include <linux/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

/*错误处理函数*/
static void display_err(const char *on_what) {
  perror(on_what);
  exit(1);
}

int main(int argc, char **argv) {
  int error;                        /* 错误值 */
  int sock_unix;                    /* socket */
  struct sockaddr_un addr_unix;     /* AF_UNIX族地址 */
  int len_unix;                     /* AF_UNIX族地址长度 */
  const char path[] = "/root/path"; /* 路径名 */

  /*建立套接字*/
  sock_unix = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sock_unix == -1) {
    display_err("socket()");
  }

  /*
  * 由于可能之前已经使用了path路径用于其他用途
  * 需要将之前的绑定取消
  */
  unlink(path);

  /*填充地址结构*/
  memset(&addr_unix, 0, sizeof(addr_unix));

  addr_unix.sun_family = AF_LOCAL;
  strcpy(addr_unix.sun_path, path);
  len_unix = sizeof(struct sockaddr_un);

  /*绑定地址到socket sock_unix*/
  error = bind(sock_unix, (struct sockaddr *) &addr_unix, len_unix);
  if (error == -1) {
    display_err("bind()");
  }

  /*关闭socket*/
  close(sock_unix);
  unlink(path);

  return 0;
}
