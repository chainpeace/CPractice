// 2020.07.05
// fgets reads one line

#include <stdio.h>

#define MAX_BUF_SIZE 100

int main(){

  FILE * fp;
  char * filename = "test.out";
  char buf[MAX_BUF_SIZE];
  unsigned long inst;
  unsigned long addr;
  char mode;

  int n;

  fp = fopen(filename, "r");

  while(!feof(fp)){
    n = fscanf(fp, "%lx: %c %lx", &inst, &mode, &addr);
    
   
    if(n>0){
      printf("n is %d\n", n);
      printf("result : %lx: %c %lx\n", inst, mode, addr);
    }
  }
  
  fclose(fp);
 
  return 0;
}
