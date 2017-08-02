#include <stdio.h>

void swap(int *x,int *y){
    /*Troca o valor de duas variaveis*/
    int aux;
    aux = *y;

    *y = *x;
    *x = aux;
}
void ordena(int *a,int *b,int *c){
    if(a<b)
        swap(&a,&b);
    if(b<c)
        swap(&b,&c);
    if(a<b)
        swap(&a,&b);

}

int main(){
    int a,b,c;
    a=3;b=4;c=2;

    ordena(&a,&b,&c);

    printf("%d, %d, %d\n",a,b,c);




    return 0;
}




//%%%%%%%% - notes - %%%%%%%%
//http://www.devfuria.com.br/#categorias
/*  int x;int *px;
   &x : endereco de x
   *px : conteudo de px



*/
