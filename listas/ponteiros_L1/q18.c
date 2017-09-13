#include <stdio.h>
#include <stdlib.h>

void somaVet(int *v1,int *v2,int *v3,int tam){
    int i;
    for(i = 0;i < tam;i++){
      v1[i] = v2[i] + v3[i];
    }
}

int main(){
  int *v1,*v2,*v3;
  int i,tam;
  printf("- v1 = v2 + v3\n\ndigite o tamanho do vetor: ");

  scanf("%d",&tam);

  v1 = (int*) malloc(tam * sizeof(int));
  v2 = (int*) malloc(tam * sizeof(int));
  v3 = (int*) malloc(tam * sizeof(int));

  //ler v2
  printf("v2 ->");
  for(i = 0;i < tam;i++){
    scanf("%d",&v2[i]);
  }
  // ler v3
  printf("v3 ->");
  for(i = 0;i < tam;i++){
    scanf("%d",&v3[i]);
  }
  // efetuar soma
  somaVet(v1,v2,v3,tam);

  printf("resultado: ");
  for(i = 0;i < tam;i++){
    printf("%d ",v1[i]);
  }
  printf("\n");
  //liberar memoria alocada
  free(v1);
  free(v2);
  free(v3);

  return 0;
}
