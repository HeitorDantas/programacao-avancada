#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int compare (void const* a,void const* b){
   return ( *(float*)a - *(float*)b );
}

void bubble(float v[],int n,int (*compara)(void const*,void const*)){
  int i,j;
  float temp;
  for(i = 0;i < n-1;i++){
    for(j = 0;j < n-1;j++){
      if((compara(&v[j],&v[j+1])) > 0){
        temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
      }
    }
  }
}



int main(){
  srand(time(NULL));
<<<<<<< HEAD
=======
  clock_t t;
>>>>>>> d0f6e3893bdea6b49b2821470f2999d12822df7e
  float *v;
  int n,a;
  scanf("%d",&n);
  v = (float*)malloc(n*sizeof(int));
<<<<<<< HEAD
=======

>>>>>>> d0f6e3893bdea6b49b2821470f2999d12822df7e
  for (int i=0;i<n;i++) {
    a = rand()%50;
    v[i] = (float)a;

<<<<<<< HEAD
    //scanf("%f",&v[i]);
  }
  for (int i=0;i<n;i++) {
    printf("%2.0f ",v[i]);
  }
  printf("\n");

  bubble(v,n,compare);


  for (int i=0;i<n;i++) {
    printf("%2.0f ",v[i]);
  }
  printf("\n");
=======
  }
  // for (int i=0;i<n;i++) {
  //   printf("%2.0f ",v[i]);
  // }
 
  // printf("\n");
   t = clock();
  for(int i=0;i<1;i++){
    for (int i=0;i<n;i++) {
    a = rand()%50;
    v[i] = (float)a;

  }
    bubble(v,n,compare);
  }
  t = clock() - t;
  printf("tempo bubble:%f\n",(float)t/CLOCKS_PER_SEC);
  //bench 2
  t = clock();
  for(int i=0;i<1;i++){
    for (int i=0;i<n;i++) {
    a = rand()%50;
    v[i] = (float)a;

  }
    qsort ((void*)v, n, sizeof(float),compare);
  }
  t = clock() - t;
  printf("tempo qsort:%f\n",(float)t/CLOCKS_PER_SEC);
  // for (int i=0;i<n;i++) {
  //   printf("%2.0f ",v[i]);
  // }
  // printf("\n");



>>>>>>> d0f6e3893bdea6b49b2821470f2999d12822df7e

  free(v);

  return 0;
}
