#include <stdlib.h>

#include <stdio.h>

int **matrix_alloc(int **A,int nlin,int ncol){
	A = (int**) malloc(nlin * sizeof(int*));
	A[0] = (int*) malloc(nlin * ncol *sizeof(int));
	for(int i=1;i<nlin;i++)
	 	A[i] = A[0] + i * ncol;
	 return A;
}

void free_matrix(int **A){
	free(*A);
	free(A);
}



int main(){
	int **A,nlin,ncol;
	scanf("%d %d",&nlin,&ncol);
	A = matrix_alloc(A,nlin,ncol);
	for(int i=0;i<nlin;i++){
		for(int j=0;j<ncol;j++){

			A[i][j] = 0;
		}
	}
	for(int i=0;i<nlin;i++){
		for(int j=0;j<ncol;j++){
			printf("%2d ",A[i][j]);
		}
		printf("\n\n");
	}

	free_matrix(A);
	return 0;
}