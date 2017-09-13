<<<<<<< HEAD
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
=======
#include <stdio.h>

int soma(int a, int b){
    return a+b;
}




int main(int argc, char const *argv[]) {
  int (*pont)(int, int);
  int a,b;
  a = 3;b=4;
  pont = soma;
  printf("end soma = %p\n",&soma);
  printf("end pont = %p\n",&pont);

  printf("pont = %p\n",pont);




  printf("soma = %d\n",soma(a,b));
  printf("soma = %d\n",pont(a,b));
  return 0;
}
>>>>>>> f07731d6dd922e1fdf6a4e0b0e7ab6b44edbe067
