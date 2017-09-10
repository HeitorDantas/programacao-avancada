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
