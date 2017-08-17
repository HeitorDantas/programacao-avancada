#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main(void){
    int nlin,ncol;
    int **x,**y,**z;
    nlin = 3;
    ncol = 4;

    x =(int**) malloc(nlin*sizeof(int*));

    x[0] = (int*) malloc(nlin*ncol*sizeof(int));

    for(int i=1;i<nlin;i++){
        x[i] = x[i-1] + ncol;
    }
    for(int i=0;i<ncol*nlin;i++){
        x[0][i] = i+1;
    }


    //copia
    y = (int**) malloc(nlin*sizeof(int*));
    *y = (int*) malloc(nlin*ncol*sizeof(int));
    for(int i=1;i<nlin;i++){
        y[i] = y[i-1] + ncol;
    }


   memcpy((int*)*y,(int*)*x,nlin*ncol*sizeof(int));
    printf("x:\n");
    for(int i=0;i<nlin;i++){
        for(int j=0;j<ncol;j++){
            if(j==0) printf("|");
            printf("%2d ",x[i][j]);
        }
        printf("|\n");
    }
    printf("y:\n");
    for(int i=0;i<nlin;i++){
        for(int j=0;j<ncol;j++){
            if(j==0) printf("|");
            printf("%2d ",y[i][j]);
        }
        printf("|\n");
    }
    z = (int**) malloc(ncol*sizeof(int*));
    *z = (int*) malloc(nlin*ncol*sizeof(int));
    for(int i=1;i<ncol;i++){
        z[i] = z[i-1] + nlin;
    }
    printf("z:\n");
    for(int i=0;i<ncol;i++){
        for(int j=0;j<nlin;j++){
            z[i][j] = x[j][i];
        }
    }
    for(int i=0;i<ncol;i++){
        for(int j=0;j<nlin;j++){
            if(j==0) printf("|");
            printf("%2d ",z[i][j]);
        }
        printf("|\n");
    }

    free(*x);
    free(x);
    free(*y);
    free(y);
    free(*z);
    free(z);
  return 0;
}
