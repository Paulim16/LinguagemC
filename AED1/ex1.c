#include <stdio.h>
#include <stdlib.h>

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
            if(i == n) i = 0;
        
        }
        
        matriz[i][j] = k;
            
        
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", matriz[i][j]); 
        }
        printf("\n");
    }

    for(k=0;k<n;k++){
        free(matriz[k]);
    }
    free(matriz);
    return 0;
}



