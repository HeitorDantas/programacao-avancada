#include <stdio.h>
#include <stdlib.h>

int main(){
    int *x;
    int n;
    n=40;

    x = (int*) malloc(n * sizeof(int));


    return 0;
}








/*
    alocacao dinamica

    * malloc/free

    malloc - aloca um bloco de bytes e retorna um ponteiro para o primeiro byte do bloco

    free - depois de usar a memoria alocada, a funcao free libera a memoria



00000000 00000000 00000000 00000011

00000000 00000000 00000001 00000000

*/
