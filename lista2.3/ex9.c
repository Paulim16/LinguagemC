#include <stdio.h>
#include <stdlib.h>
 
//-----------------------CRIA ESPAÇOS-------------------------
//MATRIZ
int **int_mat_new(int nl, int nc){
    int i;
    int **M = NULL;
    M = (int **)malloc(nl*sizeof(int*));
    for(i=0;i<nl;i++) M[i]=(int*)malloc(nc*sizeof(int));
    return M;
}
char **str_mat_new(int nl, int nc){
    int i;
    char **M = NULL;
    M = (char **)malloc(nl*sizeof(char*));
    for(i=0;i<nl;i++) M[i]=(char*)malloc(nc*sizeof(char));
    return M;
}
//VETOR
int *vect_new(int n){
    int *N = NULL;
    N = (int*)malloc(n*sizeof(int));
    return N;
}
//-----------------------------------------------------------
//FUNC EXERCICIO
//-----------------------------------------------------------

int main(){

    int i,z,ordemMat,traco=0;

    scanf("%d%*c\n", &ordemMat);
    if (ordemMat>1000 || ordemMat<=1)return 0;
    
    int **matriz = int_mat_new(ordemMat,ordemMat);
    int **matrizT = int_mat_new(ordemMat,ordemMat);

    for(i=0;i<ordemMat;i++){
        for(z=0;z<ordemMat;z++){
            scanf("%d", &matriz[i][z]);
            if(i == z)traco+=matriz[i][z];     
        }
    }

    for(i=0;i<ordemMat;i++){
        for(z=0;z<ordemMat;z++){
            matrizT[i][z] = matriz[z][i]; 
        }
    }
    
    for(i=0;i<ordemMat;i++){
        for(z=0;z<ordemMat;z++){
            matriz[i][z] *=traco;
            matriz[i][z] += matrizT[i][z];
            printf("%d ",matriz[i][z]);
            if(z==ordemMat-1)printf("\n");
        }
    }

    //---LIBERAR ESPAÇO---
    for(i=0;i<ordemMat;i++){
        free(matriz[i]);
        free(matrizT[i]);
    }
    free(matriz);
    free(matrizT);
    return 0;
    //--------------------
}