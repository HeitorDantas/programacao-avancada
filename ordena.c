#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 30

void swap(int *x,int *y){
    /*Troca o valor de duas variaveis*/
    int aux;
    aux = *y;

    *y = *x;
    *x = aux;
}
void ordena(int *x,int *y,int *z){
    if(*x>*y)
        swap(x,y);
    if(*y>*z)
        swap(y,z);
    if(*x>*y)
        swap(x,y);

}
void bubble(int v[],int n){
  int i,j;
  for(i = 0;i<n-1;i++){
    for(j = 0;j<n-1;j++){
      if(v[j]>v[j+1])
        swap(&v[j],&v[j+1]);
    }//end in-for
  }//end out-for
}
//12 14 3 9 7

void imprimeV(int v[],int n){
  printf("[");
  for(int i = 0;i<n;i++){
    printf("%d, ",v[i]);

  }
  printf("\b\b]\n");
}
int verify(int v[],int n){
  for(int i=0;i<TAM-1;i++){
    if(v[i+1]< v[i]) return 0;
  }
  return 1;

}

int main(){
    int a,b,c;
    a=3;b=4;c=2;
    srand(time(NULL));
    int v[TAM];
    for(int i=0;i<TAM;i++){
      v[i] = rand()%50;
    }
    imprimeV(v,TAM);
    bubble(v,TAM);
    printf("\n\n");
    imprimeV(v,TAM);
    //ordena(&a,&b,&c);
    printf("ordenado ? (s/n)(1/0) %d\n",verify(v,TAM));
    //printf("%d, %d, %d\n",a,b,c);




    return 0;
}




//%%%%%%%% - notes - %%%%%%%%
//http://www.devfuria.com.br/#categorias
/*  int x;int *px;
   &x : endereco de x
   *px : conteudo de px



*/
