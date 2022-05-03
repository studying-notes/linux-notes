#include <stdio.h>

/*联合类型的变量类型,用于测试字节序;
成员 value 的高低端字节可以由成员 type 按字节访问*/
typedef union {
  unsigned short int value; /*短整型变量 2 字节*/
  unsigned char byte[2];    /*字符类型  2 字节*/
} to;

int main() {
  to typeorder;             /*一个to类型变量*/
  typeorder.value = 0xabcd; /*将typeorder变量赋值为0xabcd*/

  /*小端字节序检查*/
  if (typeorder.byte[0] == 0xcd && typeorder.byte[1] == 0xab) {
    /*低字节在前*/
    printf("Low endian byte order"
           "byte[0]:0x%x,byte[1]:0x%x\n",
           typeorder.byte[0], typeorder.byte[1]);
    return 0;
  }

  /*大端字节序检查*/
  if (typeorder.byte[0] == 0xab && typeorder.byte[1] == 0xcd) {
    /*高字节在前*/
    printf("High endian byte order"
           "byte[0]:0x%x,byte[1]:0x%x\n",
           typeorder.byte[0], typeorder.byte[1]);
    return 0;
  }

  return 0;
}
