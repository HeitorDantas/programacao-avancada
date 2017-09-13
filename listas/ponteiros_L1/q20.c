#include "gc.h"
<<<<<<< HEAD
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

 int main()
 {
  int i;



  GC_INIT();	/* Optional on Linux/X86; see below.  */
  for (i = 0; i < 10000000; ++i)
   {
     int **p = (int **) GC_MALLOC(sizeof(int *));
     int *q = (int *) GC_MALLOC_ATOMIC(sizeof(int));
    assert(*p == 0);
     *p = (int *) GC_RE ALLOC(q, 2 * sizeof(int));
     if (i % 100000 == 0)
       printf("Heap size = %d\n", GC_get_heap_size());
   }
  return 0;
   }
=======
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
>>>>>>> f07731d6dd922e1fdf6a4e0b0e7ab6b44edbe067
