/*
 * @Date: 2022.04.11 11:13:41
 * @LastEditors: Rustle Karl
 * @LastEditTime: 2022.04.11 11:13:42
 */
//动态加载库示例
#include <dlfcn.h>//动态加载库库头
#include <stddef.h>
#include <stdio.h>

int main(void) {
  char src[] = "Hello, World!";//要计算的字符串
  int (*pStrLenFun)(char *str);//函数指针
  void *phandle = NULL;
  char *perr = NULL;//错误信息指针

  phandle = dlopen("./libstr.so", RTLD_LAZY);//打开1ibstr.so动态链接库
  //判断是否正确打开
  if (!phandle)                      //打开错误
    printf("Failed Load library!\n");//打印库不能加载信息
  perr = dlerror();
  if (perr != NULL) {
    printf("%s\n", perr);//打印错误函数获得的错误信息
    return 0;            //返回
  }

  //正常返回
  pStrLenFun = dlsym(phandle, "StrLen");//获得函数StrLen的地址
  perr = dlerror();
  if (perr != NULL) {
    printf("%s\n", perr);//打印错误函数获得的错误信息
    return 0;            //返回
  }

  //调用函数pStrLenFunc计算字符串的长度
  printf("the string length is: %d\n", pStrLenFun(src));

  dlclose(phandle);//关闭动态加载库
  return 0;
}
