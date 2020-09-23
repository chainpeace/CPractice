//2020.07.06

#include <stdio.h>



int main(int argc, char* argv[]){

  if(argc!=0){

    printf("argument count : %d\n", argc);
    int i;
    for(i=0;i<argc;i++){
      printf("argument %d : %s\n", i, argv[i]);
    }

  }

  return 0;
}
