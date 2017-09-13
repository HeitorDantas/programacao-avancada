#include <stdio.h>
#include <string.h>

void delay(int time){
    for(int i=0;i<100000*time;i++);
}

void imprimeDelay(char *str,int time){
	for(int i=0;*(str+i)!=0;i++){
        putchar(*(str+i));
        delay(time);
    }

}



int main(int argc,char *argv[]){
    char hello[]="HELLO WORLD ";
    char str[100],nome[50];
    FILE *nomes;
    nomes = fopen("nomes.txt","r");
    if(nomes == NULL) {
        printf("erro\n");
        return 1;
    }
    for(int i=0;i<100;i++){
        fgets(nome,50,nomes);
        strcpy(str,hello);
        strcat(str,nome);
        imprimeDelay(str,100);
    }



    fclose(nomes);
    return 0;
}

