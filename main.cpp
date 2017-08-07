#include <stdio.h>
#include <stdlib.h>
//casa - guardar um array de 8 posicoes ,com 0s ou 1s
//contido nele, para um uchar,e o inverso

void printchar(unsigned char x){
    for(unsigned char c=0;c<8;c++){
        printf("%d", !!(x & 0x80));
        x = x << 1;
    }


}

void printbin(int x){
    unsigned char *pu,aux=1;

    pu = (unsigned char *)&x;
    for(int c=0;c<8;c++){
        printf("%d",)
    }

}

void printint(int x){
    unsigned char *pu;

    pu = (unsigned char *)&x;
    printf("%d\n",x);
    for(int i=0;i<4;i++){
        printf("byte %d: %3d --",i,*pu);
        printchar(*pu);
        printf("\n");
        pu++;
    }

}




int main(){
    //unsigned char* pu;
    int x;

    //x = rand();
    x = 204;

    printint(x);
    x = 256;
    printint(x);


    return 0;
}
