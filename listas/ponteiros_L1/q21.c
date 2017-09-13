#include "gc.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
  int i,n = 100;
  clock_t t;
  GC_INIT();	/* Optional on Linux/X86; see below.  */
  int *p;
  t = clock();
  for(i = 0;i<1000000;i++){
    p = (int*) GC_MALLOC(n * sizeof(int));
  }
  t = clock() - t;
  printf("tempo do GC_MALLOC: %f \n",(float)t/CLOCKS_PER_SEC);
  t = clock();
  for(i = 0;i<1000000;i++){
    p = (int*) malloc(n * sizeof(int));
    free(p);
  }
  t = clock() - t;
  printf("tempo do malloc-free: %f \n",(float)t/CLOCKS_PER_SEC);
  return 0;
}
