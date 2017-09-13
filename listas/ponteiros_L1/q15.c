#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*
	a funcao qsort tem prototipo 
	void qsort (void* base, size_t num, size_t size,int (*compar)(const void*,const void*));
- o primeiro argumento é o ponteiro que aponta pra o primeiro elemento do array ou do bloco alocado
- o segundo é o numero de elementos a ordenar, 
- o terceiro é o tamanho em byte referente ao tipo de dado a ser ordenado
- o quarto eh um ponteiro para um funcao que compara dois elementos genericos, a funcao compare.
*/


int compare (const void * a, const void * b){
	/* essa funcao compara dois elementos */
  if ( *(float*)a <  *(float*)b ) return -1;
  if ( *(float*)a == *(float*)b ) return 0;
  if ( *(float*)a >  *(float*)b ) return 1;
}

int main(){
	float *pf;//ponteiro para alocar a memoria
	int n;//numero de elementos
	


	printf("quantos numeros deseja escrever > ");
	scanf("%d",&n);//lendo a quantidade de elementos que usuario vai digitar
	pf = malloc(n * sizeof(float));//alocando memoria para os n elementos
	
	//ler os n valores 
	for(int i=0;i<n;i++) scanf("%f",(pf+i));
	
	//printa valores antes de ordenar
	for(int i=0;i<n;i++) printf("%.2f ",pf[i]);
	printf("\n");
	
	//ordenar
	qsort((void*)pf,n,sizeof(float),compare);
	
	for(int i=0;i<n;i++) printf("%.2f ",pf[i]);
	printf("\n");
	free(pf);
	return 0;
}