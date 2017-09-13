/*

  p = mat + 1;  valida
p = mat++;
p = ++mat;
x = (*mat)++;   valida, incremento no conteudo do primeiro elemento do array


*/
#include <stdio.h>

int main(){
  int mat[4];
  int *p,x;
  p = mat+1;
  printf("%p\n - %p\n",p,mat);
  p=++mat;// erro : nao se pode fazer modificacoes na variavel mat, pois representa um vetor
          // ou melhor,mat eh um ponteiro imutaavel que sempre aponta pra o começo do array

  return 0;
}
