/* uma funçao tem que ser armazenada na memoria, 
	entao podemos usar um ponteiro que guarde o endereco dessa funcao
	e assim podemos usar ela indiretamente.
	Podemos agora passa um ponteiro pra funcao, como parametro para
	outra funcao, ou usar a funçao chamando o ponteiro.
	segue o code exemplo abaixo.
		o programa deve 
*/

#include <stdio.h>

int soma(int a,int b){
	return a + b;
}
int sub(int a,int b){
	return a - b;
}

int mult(int a,int b){
	return a * b;
}

int div(int a,int b){
	return a / b;
}

int opera(int a,int b,int (*pfunc)(int x,int y)){
	return pfunc(a,b);
}

int main(){
	int a,b,ans;
	char op;
	
	printf("\n\n\t\t/ * - + ==CALCULADORA SIMPLES== + - * / \n\n");
	printf("USO: X 'OPERADOR' Y  - ex. 5 / 4\n\n");
	
	printf("\n-> ");	
	scanf("%d %c %d",&a,&op,&b);
		switch(op){
			case '+':
				printf("\n%d + %d = %d\n",a,b,opera(a,b,soma));
				break;
			case '-':
				printf("\n%d - %d = %d\n",a,b,opera(a,b,sub));
				break;
			case '*':
				printf("\n%d * %d = %d\n",a,b,opera(a,b,mult));
				break;
			case '/':
				printf("\n%d / %d = %d\n",a,b,opera(a,b,div));
				break;

			default:
				printf("operaçao invalida\n");
				break;
		}
	
	return 0;
}