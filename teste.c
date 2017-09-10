#include <stdio.h>
#include <stdlib.h>
void delay(){
    for(int i=0;i<1000000000;i++);
}


int main(){
    char str[] = "HELLO WORLD";
    int i=0;
        printf("%c",str[i++]);
        delay();
        printf("%c",str[i++]);
        delay();
        
    
    return 0;
}

