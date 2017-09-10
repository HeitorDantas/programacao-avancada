#include <stdio.h>

int
main(){
float aloha[10], coisas[10][5], *pf, value = 2.2;
int i=3;

aloha[2] = value; //valido
//scanf("%f", &aloha); //invalido &aloha é endereço do ponteiro
//aloha = value; //invalido, o ponteiro de array é imutavel, nao pode atribuir
//printf("%f", aloha);//invalido , aloha é um  ponteiro
	coisas[4][4] = aloha[3];//valido
//coisas[5] = aloha;//acho que é valido,pois coisas[5] guarda um vetor de 5 posiçoes,ou seja um ponteiro
										//que aponta pra o começo da segunda dimensao do array
										//teste: é invalido, atribuiçao para ponteiro para array

//pf = value;//pf pode guardar um endereço, invalido
pf = aloha;//valido

	return 0;
}
