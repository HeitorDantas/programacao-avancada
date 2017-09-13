#include <stdio.h>
#include <stdlib.h>

void swap(float *x,float *y){
    /*Troca o valor de duas variaveis*/
    float aux;
    aux = *y;

    *y = *x;
    *x = aux;
}

void bubble(float v[],float n){
  int i,j;
  for(i = 0;i<n-1;i++){
    for(j = 0;j<n-1;j++){
      if(v[j]>v[j+1])
        swap(&v[j],&v[j+1]);
    }//end in-for
  }//end out-for
}

int main(){
	float x,*pf;
	int n;
	printf("quantos numeros deseja escrever > ");
	scanf("%d",&n);
  pf = malloc(n * sizeof(float));
	
  //ler os n valores 
  for(int i=0;i<n;i++) scanf("%f",(pf+i));//ou &pf[i]
  for(int i=0;i<n;i++) printf("%.2f ",pf[i]);
  printf("\n");
  bubble(pf,n);
  for(int i=0;i<n;i++) printf("%.2f ",pf[i]);
  printf("\n");
  free(pf);
	return 0;
}