/*文件ex03-fstat-01.c,
使用stat获得文件的状态*/
#include <cstdio>
#include <sys/stat.h>

int main() {
  struct stat st{};
  if (-1 == stat("test.txt", &st)) {
    printf("获得文件状态失败\n");
    return -1;
  }

  printf("包含此文件的设备ID：%lu\n", st.st_dev);
  printf("此文件的节点：%lu\n", st.st_ino);
  printf("此文件的保护模式：%d\n", st.st_mode);
  printf("此文件的硬链接数：%lu\n", st.st_nlink);
  printf("此文件的所有者ID：%d\n", st.st_uid);
  printf("此文件的所有者的组ID：%d\n", st.st_gid);
  printf("设备ID（如果此文件为特殊设备）：%lu\n", st.st_rdev);
  printf("此文件的大小：%ld\n", st.st_size);
  printf("此文件的所在文件系统块大小：%ld\n", st.st_blksize);
  printf("此文件的占用块数量：%ld\n", st.st_blocks);
  printf("此文件的最后访问时间：%ld\n", st.st_atime);
  printf("此文件的最后修改时间：%ld\n", st.st_mtime);
  printf("此文件的最后状态改变时间：%ld\n", st.st_ctime);

  return 0;
}
