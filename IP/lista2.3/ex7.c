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
int main(){


 
    int i,z,e,d,flag,ordemMat;
    char borda,interior;

    scanf("%d %c %c", &ordemMat, &borda, &interior);

    if(ordemMat>99 || ordemMat%2==0){
        printf("Dimensao invalida!");
        return 0;
    }

    char **matriz = str_mat_new(ordemMat,ordemMat);

    d = ordemMat/2; //d de direita
    e = d; //e de esquerda
    flag = 0;

    for(i=0;i<ordemMat;i++){
        for(z=0;z<ordemMat;z++){
            if (z==e || z == d) matriz[i][z] = borda;
            else if(z>e && z<d) matriz[i][z] = interior;
            else matriz[i][z] = ' ';
        } 
        if(e==0 && d==ordemMat-1) flag = 1;
        if (flag==1){
            e++;
            d--; 
        }
        else{
            e--;
            d++;
        }
    }
    for(i=0;i<ordemMat;i++){
        for(z=0;z<ordemMat;z++){
            printf("%c ",matriz[i][z]);
            if(z==ordemMat-1)printf("\n");
        }
    }
//---LIBERAR ESPAÇO---
    for(i=0;i<ordemMat;i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
//--------------------
}