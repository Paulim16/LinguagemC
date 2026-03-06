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

    int i,z,ordemMat,primeiro;
    int *nums = NULL;
    int **matriz = NULL;
    scanf("%d",&ordemMat);

    //ALOCAÇÕES
    matriz = (int**)malloc(ordemMat*sizeof(int*));
    for(i=0;i<ordemMat;i++) matriz[i] = (int*)malloc(ordemMat*sizeof(int));
    nums = (int*)malloc(ordemMat*sizeof(int));
    //-----------------------------------------

    for(i=0;i<ordemMat;i++){
        for(z=0;z<ordemMat;z++){
            scanf("%d",&matriz[i][z]);
            if(i==z){
                nums[i] = matriz[i][z];
                

            } 
        }
    }
    for(i=0;i<ordemMat;i++){ 
        printf("%d\n",nums[i]);
    }
   
    for(i=0;i<ordemMat;i++){
        free(matriz[i]);
    }
    free(matriz);
    free(nums);
    
    
    return 0;
}



