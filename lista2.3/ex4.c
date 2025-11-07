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

    int i,z,y,k,ordemMat,primeiro;
    int *nums = NULL;
    int **matriz = NULL;
    scanf("%d",&ordemMat);

    //ALOCAÇÕES
    matriz = (int**)malloc(ordemMat*sizeof(int*));
    for(i=0;i<ordemMat;i++) matriz[i] = (int*)malloc(ordemMat*sizeof(int));
    nums = (int*)malloc((ordemMat*ordemMat)*sizeof(int));
    //-----------------------------------------

    for(i=0;i<ordemMat;i++){
        for(z=0;z<ordemMat;z++){
            scanf("%d",&matriz[i][z]);
        } 
    }
    z=0;
    for(i=0;i<ordemMat;i++){
        for(k=0;k<ordemMat;k++){
            for(y=0;y<ordemMat;y++){
                nums[z] += matriz[i][y] * matriz[y][k];
                
            }
            z++;
        }
    }
    for(i=0;i<(ordemMat*ordemMat);i++){ 
        printf("%d ",nums[i]);
        if((i+1)>=ordemMat && (i+1%ordemMat==0)) printf("\n");
    }
   
    for(i=0;i<(ordemMat*ordemMat);i++){
        free(matriz[i]);
    }
    free(matriz);
    free(nums);
    
    
    return 0;
}



