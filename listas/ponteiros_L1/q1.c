//questao 1 - lista ponteiros

#include <stdio.h>

int main(){
	int i=3,j=5;
	int *p, *q;//dois ponteiros pra inteiro
	p = &i;
	q = &j;	


	/*determinar o valor :
	1)  p == &i
	 		p aponta para i entao ele guarda o endereco de i
			e &i é o valor do endereco de i, entao o valor
			da expressao é 1 ou true
	*/
	printf("p == &i : %d\n\n",p == &i);//confirmacao			
	/*
	2)	*p - *q
			*p quer dizer: o conteudo do endereço para qual
			p esta apontando, o mesmo pra *q.
			 Entao *p - *q == i - j	== 3 - 5 == -2
	*/
	printf("*p - *q : %d\n\n",*p - *q);//confirmacao	 
	/*
	3)	**&p 
			&p representa o endereco onde esta armazenado a variavel ponteiro p
			se eu uso *&p estou acessando o conteudo do endereco de p(que seria o endereco de i),
			entao **&p é o conteudo do endereço *&p, entao **&p == i == 3;
	*/
	printf("**&p : %d\n\n",**&p);//confirmacao
	/*
	4) 	3 - *p/(*q) + 7;
			*p == i == 3 e *q == j == 5
			3 - 3/5 + 7 = 3 - 0 + 7 = 10
	*/
	printf("3 - *p/(*q) + 7 : %d\n",3 - *p/(*q) + 7);//confirmacao
}