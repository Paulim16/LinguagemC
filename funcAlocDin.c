#include <stdio.h>
#include <stdlib.h>
//cria vetores
int *vect_new(int n){

    int *v = NULL;
    v = (int *) malloc(n*sizeof(int));
    return v;
}
//cria matrizes
int **mat_new(int nl, int nc){
    int i;
    int **M = NULL;
    M = (int **)malloc(nl*sizeof(int*));
    for(i=0;i<nl;i++) M[i]=(int*)malloc(nc*sizeof(int));
}
//liberta matrizes
void mat_free(int **M, int nl){
    int i;
    for(i=0;i<nl;i++){
        free(M[i]);
    }
    free(M);
}

