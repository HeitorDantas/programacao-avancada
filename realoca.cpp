#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void realoca(int **x,int antigo,int novo){
    int *y;
    int i;
    if(antigo == novo) return;

    y= (int*)malloc(novo*sizeof(int));
    if(y == NULL)
        exit(0);
    if(antigo > novo){
        memcpy(y, *x,novo*sizeof(int));

        for(i =antigo;i<novo;i++){
            y[i] = 0;
        }
    }
    else{
        memcpy(y,*x,novo*sizeof(int));
    }

    free(x);

}

