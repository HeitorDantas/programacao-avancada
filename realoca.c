#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int *realoca(int *pont,int atual,int novo){
	//1 - guardar o meus dados num ponteiro auxiliar
	//2 - alocar um novo bloco de memoria
	int *aux,i;
	
	if(atual == novo){
		return pont;
	}
	if(novo > atual){
		aux = (int*) malloc(novo * sizeof(int));
		memcpy(aux,pont,atual*sizeof(int));
		for(i=atual;i<novo;i++){
			aux[i] = 0;
		}
	}
	if(novo < atual){
		aux = (int*) malloc(novo * sizeof(int));
		memcpy(aux,pont,novo*sizeof(int));
	}
	free(pont);
	return aux;

}



int main(){
   int *ptr,n,i,novo;
   n = 10;
   novo = 15;
   ptr = (int*) malloc(n * sizeof(int));

   for(i = 0;i < n;i++){
   	ptr[i] = i+1;
   }

   printf("conteudo de ptr:\n\t");
   for(i = 0;i < n;i++){
   	printf("%d ",ptr[i]);
   }
   printf("\n\n");
   ptr = realoca(ptr,n,novo);
   printf("relocando...\n\nconteudo de ptr:\n\t");
   for(i = 0;i < novo;i++){
   	printf("%d ",ptr[i]);
   }
   printf("\n\n");
   free(ptr);
   return 0;
}

