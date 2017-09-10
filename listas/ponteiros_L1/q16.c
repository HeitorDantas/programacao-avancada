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
  float *v;
  int n,a;
  scanf("%d",&n);
  v = (float*)malloc(n*sizeof(int));
  for (int i=0;i<n;i++) {
    a = rand()%50;
    v[i] = (float)a;

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

  free(v);

  return 0;
}
