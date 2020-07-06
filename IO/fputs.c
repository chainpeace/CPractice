// 2020.07.05
// fputs

#include <stdio.h>
#include <string.h>

#define MAX_BUF_SIZE 100

int main(){

  FILE * fpr;
  FILE * fpw;
  char * inputname = "test.out";
  char * outputname = "testout.out";
  char * suf = "_test";

  char buf[MAX_BUF_SIZE];

  int strlen;

  fpr = fopen(inputname, "r");
  fpw = fopen(outputname, "a");

  if(fpr == NULL || fpw == NULL)
    return -1;

  while(!feof(fpr)){

    strlen = fgets(buf, MAX_BUF_SIZE, fpr);
    
    strcat(buf, suf);
    fputs(buf, fpw);
   
  }
  
  fclose(fpr);
  fclose(fpw);
 
  return 0;
}
