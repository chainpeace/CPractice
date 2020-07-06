// 2020.07.05
// fgets reads one line

#include <stdio.h>

#define MAX_BUF_SIZE 100

int main(){

  FILE * fp;
  char * filename = "test.out";
  char buf[MAX_BUF_SIZE];

  fp = fopen(filename, "r");

  while(!feof(fp)){

    fgets(buf, MAX_BUF_SIZE, fp);
    printf("read string : %s", buf);
   
  }
  
  fclose(fp);
 
  return 0;
}
