#include <stdio.h>
#include <stdlib.h>

//cria matrizes
/*int **mat_new(int nl, int nc){
    int i;
    int **M = NULL;
    M = (int **)malloc(nl*sizeof(int*));
    for(i=0;i<nl;i++) M[i]=(int*)malloc(nc*sizeof(int));
}
*/

int main(){
    int n, k,i,j;
    scanf("%d",&n);
    int tam = n*n;
    int **matriz;
    matriz = (int**)calloc(n,sizeof(int*));
    for(k=0;k<n;k++) matriz[k] = (int*)calloc(n,sizeof(int));

    i=0; j = n/2;
    matriz[i][j] = 1;
    for(k=2;k<=tam;k++){
        int tempi = i, tempj = j;
        i--, j--;
        if(i<0)i=n-1;
        if(j<0)j=n-1;
        if(matriz[i][j] != 0){
            i = tempi+1;
            j = tempj;
        }
        if(i>=0 && j>=0){
            matriz[i][j] = k;
            
        }
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",matriz[i][j]);
        }
        printf("\n");
    }

/*ALOCAÇÕES
    matriz = (int**)malloc(ordemMat*sizeof(int*));
    for(i=0;i<ordemMat;i++) matriz[i] = (int*)malloc(ordemMat*sizeof(int));
    nums = (int*)malloc(ordemMat*sizeof(int));
    //-----------------------------------------

    */
    for(k=0;k<n;k++){
        free(matriz[k]);
    }
    free(matriz);
    //free(nums);
    
    
    return 0;
}



