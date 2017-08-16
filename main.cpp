#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

char *sobrenome(char *nome){
    char *sobre=nome;
    while(*sobre != ' '){
        sobre++;
    }
    while(*sobre == ' '){
        sobre++;
    }
    return sobre;
}


int main(){

    char nome[80];
    char *p;
    p =(char*) malloc(40*sizeof(char));

    puts("digite seu nome e sobrenome:");
    gets(nome);
    puts(nome);
    p = sobrenome(nome);
    puts(p);

    printf("memoria alocada em p: %d\n",_msize(p)/sizeof(char));
    return 0;
}
