#include <stdio.h>
#include "stdlib.h"
#include <time.h>

int main(){
  int *z,*x,n;
  n=10;

  z = malloc(n*sizeof *z);
  x = malloc(n*sizeof *x);
  printf("x = %p\n",x);
  printf("z = %p\n",z);

  srand(time(NULL));
  //
  for(int i = 0;i<n;i++) *(z+i) = rand()%100;

  for(int i=0;i<n;i++){
    *(x+i) = *(z+i);
  }
  printf("x:\n");
  for(int i=0;i<n;i++){
    printf("endereco: %x -- %d\n",(x+i),*(x+i));
  }
  printf("z:\n");
  for(int i=0;i<n;i++){
    printf("endereco: %x -- %d\n",(z+i),*(z+i));
  }
  return 0;
}












// int main(int argc, char const *argv[]) {
//   int *x,y[10]={0};
//   x = (int*) malloc(40*sizeof(int));
//
//   srand(time(NULL));
//
//   for(int i = 0;i<40;i++) x[i] = rand()%100;
//
//   for(int i = 0;i<40;i++) printf("endereço: %2X  <- %d \n",(x+i),*(x+i));
//
//   free(x);
//   printf("y:\n");
//   for(int i = 0;i<10;i++) printf("endereço: %2X  <- %d \n",&y[i],y[i]);
//   return 0;
//
// }
