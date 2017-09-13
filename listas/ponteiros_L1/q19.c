#include <stdio.h>
#include <stdlib.h>



int **matrix_alloc(int **M,int nlin,int ncol){
	/*Aloca memoria para um array bi-dimensional*/
	M = (int**)malloc(nlin*sizeof(int*));
	M[0] = (int*)malloc(nlin*ncol*sizeof(int));
	for(int i=1;i<nlin;i++){
		M[i] = M[i-1]+ncol;
	}
	return M;
}
int free_matrix(int **M){
	/*libera memoria alocada para array bi-dimensional*/
	free(*M);
	free(M);
}
void fill_matrix(int **M,int nlin,int ncol){
	/*ler valores do usuario e guarda no array*/
	for(int i=0;i<nlin;i++){
		for (int j = 0; j<ncol;j++){
			scanf("%d",&M[i][j]);
		}
	}
}
void print_matrix(int **M,int nlin,int ncol){
	/*imprime o array*/
	for(int i=0;i<nlin;i++){
		for (int j = 0; j<ncol;j++){
			printf("%2d ",M[i][j]);
		}
		printf("\n");
	}
}
int **mult_matrix(int **A,int **B,int **C,int nlin_A,int ncol_A,int ncol_B){
	/*Algoritmo de multiplicacao de matrizes*/
	int termo = 0;
	for(int i=0;i<nlin_A;i++){
		for(int j=0;j<ncol_B;j++){
			for(int k=0;k<ncol_A;k++){
				termo += A[i][k]*B[k][j];
			}
			C[i][j] = termo;
			termo = 0;
		}
	}
	return C;
}

int main(int argc,char *argv[]){
	int **A,**B,**C;
	int nlin_A,ncol_A;
	int nlin_B,ncol_B;

	printf("dimensoes da matriz A(nlin ncol): ");
	scanf("%d %d",&nlin_A,&ncol_A);
	
	printf("dimensoes da matriz B(nlin ncol): ");
	scanf("%d %d",&nlin_B,&ncol_B);
	
	//alocando espaco para as matrizes=================
	A = matrix_alloc(A,nlin_A,ncol_A);
	B = matrix_alloc(B,nlin_B,ncol_B);
	C = matrix_alloc(C,nlin_A,ncol_B);
	
	//===ler os valores para as matrizes A e B===========
	printf("entre com a matrix A:\n");
	fill_matrix(A,nlin_A,ncol_A);
	
	printf("entre com a matrix B:\n");
	fill_matrix(B,nlin_B,ncol_B);
	system("cls");
	//===================================================
	printf("print A:\n");
	print_matrix(A,nlin_A,ncol_A);
	
	printf("print B:\n");
	print_matrix(B,nlin_B,ncol_B);
	//executando o produto de A*B=====================================
	C = mult_matrix(A,B,C,nlin_A,ncol_A,ncol_B);
	printf("print C:\n");
	print_matrix(C,nlin_A,ncol_B);
	
	//liberando as memorias alocadas

	free_matrix(A);
	free_matrix(B);
	free_matrix(C);
	return 0;
}