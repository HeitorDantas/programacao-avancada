#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void atobit(char v[],unsigned char *pc){
  *pc = 0;
  for(int i=0;i<8;i++){
    *pc += v[i] & 1;
    if(i<7) *pc<<=1;
  }
}

void printbyte(unsigned char *pc){
  for(int i=0;i<8;i++){
    printf("%d ",!!(0x80 & *pc));
    *pc<<=1;
  }
  printf("\n");

}

int main(){
  unsigned char *pc;
  char a,v[8];
  srand(time(NULL));
  for(int i=0;i<8;i++) v[i] = rand()%2;
  a=1;
  pc = &a;


  atobit(v,pc);
  printf("Array: \n");
  for(int i=0;i<8;i++) printf("%d ",v[i]);
  printf("sizeof v:%d",sizeof v);
  printf("\nByte: \n");
  printbyte(pc);
  printf("sizeof char:%d\n",sizeof a);

}
