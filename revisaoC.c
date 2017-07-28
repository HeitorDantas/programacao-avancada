#include <stdio.h>
#include <string.h>

int global;



int main(int argc,char *argv[]){
    char hello[]="HELLO WORLD \0";
    char str[100],nome[50];
    FILE *nomes;
    nomes = fopen("nomes.txt","r");
    if(nomes == NULL) {
        printf("erro\n");
        return 1;
    }
    strcpy(str,hello);

    fgets(nome , 50 , nomes);
      // puts(nome);
   // printf("%s",str);
    for(int c=0;str[c]!=0;c++){
        fgets(nome , 50 , nomes);
       // strcat(str,nome)
        for(int i=0;i<100000000;i++);
        putchar(str[c]);
        if(str[c+1]==0) {c=-1;
            puts(nome);
        }
    }

    int x = 30;

    printf("%d\n",x);

    fclose(nomes);
    return 0;
}
