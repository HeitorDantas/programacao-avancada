#include "gc.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
  int i,n;
  n = 100;
  GC_INIT();	/* Optional on Linux/X86; see below.  */
  int **p;
  p = (int**) GC_MALLOC(n*sizeof(int*));
  for(i = 0;i<n;i++){
    p[i] = (int*) GC_MALLOC(n*sizeof(int));
  }

  // nao é necessario comandar a liberacao de memoria
  // a mesma ja é feita automaticamente


  printf("Heap size = %d\n", GC_get_heap_size());
  printf("\n");
  return 0;
}
