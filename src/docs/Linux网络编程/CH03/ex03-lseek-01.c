/*文件ex03-lseek-01.c,
使用lseek函数测试标准输入是否可以进行seek操作*/
#include <cstdio>

int main() {
  off_t offset;

  /*将标准输入文件描述符的文件偏移量设为当前值*/
  offset = fseek(stdin, 0, SEEK_CUR);

  if (-1 == offset) {
    /*设置失败，标准输入不能进行seek操作*/
    printf("STDIN can't seek\n");
    return -1;
  } else {
    /*设置成功，标准输入可以进行seek操作*/
    printf("STDIN CAN seek\n");
  };

  return 0;
}
