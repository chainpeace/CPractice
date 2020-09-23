//2020.07.06
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

  char str[10] = "default";
  char* str2 = "default2";
  
  strcpy(str, "src");
  printf("copied string : %s//%d\n", str, strlen(str));

  strcpy(str,"12345678901123123");
  printf("copied string : %s//%d\n", str, strlen(str));

  strncpy(str,"abcdefgda1123123", 3);
  printf("copied string : %s//\n", str);
  
  strncpy(str,"12345678901123123", 20);
  printf("copied string : %s//%d\n", str,strlen(str));

  printf("%s\n", str2);

  //these occurs error
  //strcpy(str2, "src");
  //printf("copied string : %s//\n", str2);

  //strcpy(str2,"12345678901123123");
  //printf("copied string : %s//\n", str2);

  //strncpy(str2,"abcdefgda1123123", 3);
  //printf("copied string : %s//\n", str2);
  
  //strncpy(str2,"12345678901123123", 20);
  //printf("copied string : %s//\n", str2);

  char * dest = malloc(100*sizeof(char));
  printf("dest size : %d\n",strlen(dest));

  strcpy(dest, "src");
  printf("copied string : %s//%d\n", dest, strlen(dest));

  strcpy(dest,"12345678901123123");
  printf("copied string : %s//\n", dest);

  strncpy(dest,"abcdefgda1123123", 3);
  printf("copied string : %s//\n", dest);
  
  strncpy(dest,"12345678901123123", 20);
  printf("copied string : %s//%d\n", dest, strlen(dest));

  return 0;

}
