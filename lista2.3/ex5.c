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
 
// FUNÇÃO EXERCÍCIO
int ampulheta(int l,int c,int **mat){
    int soma = 0;
    soma += mat[l][c] + mat[l][c+1] + mat[l][c+2];
    soma += mat[l+1][c+1];
    soma += mat[l+2][c] + mat[l+2][c+1] + mat[l+2][c+2];
    return soma;
}
//------------------------------------------------------------
 
 
int main(){
 
    int i,z,y,k,maior=-64,l;
    int num;
    int **matriz = mat_new(6,6);
    
    /*ALOCAÇÕES
    matriz = (int**)malloc(6*sizeof(int*));
    for(i=0;i<6;i++) matriz[i] = (int*)malloc(6*sizeof(int));
    nums = (int*)malloc(36*sizeof(int));
    //-----------------------------------------*/
 
    for(i=0;i<6;i++){
        for(z=0;z<6;z++){
            scanf("%d",&matriz[i][z]);
        } 
    }
 
    for(i=0;i<4;i++){
        for(z=0;z<4;z++){
            num = ampulheta(i,z,matriz);
            if (num > maior) maior = num;
        }
    }
    printf("%d\n",maior);
//---LIBERAR ESPAÇO---
    for(i=0;i<6;i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
//--------------------
}