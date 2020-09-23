//2020.07.06
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){

  int opt;
  char str[100] = "";

  while((opt = getopt(argc, argv, "i:o:")) != -1){
    switch(opt){
    case 'i':
      printf("option is %c and the argument is : %s\n", opt, optarg);
      break;
    case 'o':
      printf("option is %c and the argument is : %s\n", opt, optarg);
      break;
    case '?':
      printf("parameter err\n");
      break;
    default:
      printf("err, opt : %c\n", opt);
    }
  }
  
  printf("hello world\n");
  printf("%s\n", str);
  return 0;
}
