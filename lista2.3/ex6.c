#include <stdio.h>
#include <stdlib.h>
 
//-----------------------CRIA ESPAÇOS-------------------------
//MATRIZ
int **mat_new(int nl, int nc){
    int i;
    int **M = NULL;
    M = (int **)malloc(nl*sizeof(int*));
    for(i=0;i<nl;i++) M[i]=(int*)malloc(nc*sizeof(int));
    return M;
}
//VETOR
int *vect_new(int n){
    int *N = NULL;
    N = (int*)malloc(n*sizeof(int));
    return N;
}
//-----------------------------------------------------------
int main(){


 
    int i,z,y,k,l,cl,ln,largBorda,borda;

    scanf("%d %d %d %d", &cl, &ln, &largBorda, &borda);

    int **matriz = mat_new(ln,cl);


    
    
    for(i=0;i<ln;i++){
        for(z=0;z<cl;z++){
            if(i<largBorda || i >= ln-largBorda) matriz[i][z]=borda;
            else if(z<largBorda || z >= cl-largBorda) matriz[i][z]=borda;
            else matriz[i][z] = 0;
        } 
    }
    printf("P2\n%d %d\n255\n",cl,ln);

   for(i=0;i<ln;i++){
        for(z=0;z<cl;z++){
            printf("%d ",matriz[i][z]);
            if(z+1==cl) printf("\n");
        }
    }
//---LIBERAR ESPAÇO---
    for(i=0;i<ln;i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
//--------------------
}