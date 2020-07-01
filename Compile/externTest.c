#include <stdio.h>

extern int helloExtern();
extern int ex_num;

int main(){


  helloExtern();

  printf("the number is %d\n", ex_num);
  return 0;
}
