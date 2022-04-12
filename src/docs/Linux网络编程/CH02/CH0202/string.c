/*
 * @Date: 2022.04.11 09:06
 * @Description: Omit
 * @LastEditors: Rustle Karl
 * @LastEditTime: 2022.04.11 09:06
 */

int StrLen(char *string) {
  int len = 0;
  while (*string++ != '\0')
    len++;
  return len;
}
