// 2020.07.05

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define OFFSET_BIT 12

void compressMemRef(FILE* inputP, FILE * outputP, int mode_sep){

  unsigned long inst;
  unsigned long addr;
  char mode=0;
  char prev_mode;
  unsigned long prev_pageaddr=0;
  unsigned long pageaddr;
  int n;
  int cnt = 1;
  int total = 1;

  n = fscanf(inputP, "%lx: %c %lx", &inst, &prev_mode, &addr);
  if(n<1) return;
  prev_pageaddr = addr >> OFFSET_BIT; 

  if(mode_sep==1){

    while(!feof(inputP)){
      n = fscanf(inputP, "%lx: %c %lx", &inst, &mode, &addr);
   
      if(n<1){
        break;
      }

      pageaddr = addr >> OFFSET_BIT; 
     
      if(prev_pageaddr == pageaddr && prev_mode == mode){
        cnt++;
      } else{
        fprintf(outputP, "mem ref : %c %lx : %d times\n", prev_mode, prev_pageaddr, cnt);
        cnt = 1;
        prev_mode = mode;
        prev_pageaddr = pageaddr;
      }

    total++;
    }
  
    fprintf(outputP, "mem ref : %c %lx : %d times\n", mode, pageaddr, cnt);
    fprintf(outputP, "total ref cnt: %d\n", total);
  
  } else if(mode_sep==0){

    while(!feof(inputP)){
      n = fscanf(inputP, "%lx: %c %lx", &inst, &mode, &addr);
   
      if(n<1){
        break;
      }

      pageaddr = addr >> OFFSET_BIT; 
     
      if(prev_pageaddr == pageaddr){
        cnt++;
      } else{
        fprintf(outputP, "mem ref : %lx : %d times\n", prev_pageaddr, cnt);
        cnt = 1;
        prev_pageaddr = pageaddr;
      }

    total++;
    }
  
    fprintf(outputP, "mem ref : %lx : %d times\n", pageaddr, cnt);
    fprintf(outputP, "total ref cnt: %d\n", total);
  }


  return;
}

int main(int argc, char** argv){

  FILE * inputP;
  FILE * outputP;
  char difilename[100] = "test.out";
  char dofilename[100] = "test.out.out";
  int opt;
  int sep=0;

  char * ifilename = malloc(100*sizeof(char));
  char * ofilename = malloc(100*sizeof(char));

  while((opt = getopt(argc, argv, "i:o:s")) != -1){
    switch(opt){
    case 'i': 
      strncpy(ifilename, optarg, strlen(optarg));
      break;
    case 'o':
      strncpy(ofilename, optarg, strlen(optarg));
      break;
    case 's':
      sep=1;
      break;
    default:
      return -1;
    }
  }
  if(strlen(ifilename)==0){
    strncpy(ifilename, difilename, strlen(difilename));
  }

  if(strlen(ofilename)==0){
    strncpy(ofilename, dofilename, strlen(dofilename));
  }

  printf("input file name : %s, output file name: %s\n", ifilename, ofilename);

  inputP = fopen(ifilename, "r");
  outputP = fopen(ofilename, "w");

  compressMemRef(inputP, outputP, sep);

  fclose(inputP);
  fclose(outputP); 
  return 0;
}
