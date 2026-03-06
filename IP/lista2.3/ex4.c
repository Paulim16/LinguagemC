#include <stdio.h>
#include <stdlib.h>
 
//cria matrizes
/*int **mat_new(int nl, int nc){
    int i;
    int **M = NULL;
    M = (int **)malloc(nl*sizeof(int*));
    for(i=0;i<nl;i++) M[i]=(int*)malloc(nc*sizeof(int));
}
 
int *vect_new(int n){
    nums = (int*)malloc((2*2)*sizeof(int));
}
*/
 
int main(){
 
    int i,z,y,k,primeiro;
    float *nums = NULL;
    float **matriz = NULL;
    //scanf("%d",&2);
 
    //ALOCAÇÕES
    matriz = (float**)malloc(2*sizeof(float*));
    for(i=0;i<2;i++) matriz[i] = (float*)malloc(2*sizeof(float));
    nums = (float*)malloc((2*2)*sizeof(float));
    //-----------------------------------------(sim, isso n é de gpt, fui eu que fiz)
 
    for(i=0;i<2;i++){
        for(z=0;z<2;z++){
            scanf("%f",&matriz[i][z]);
        } 
    }
    z=0;
    for(i=0;i<2;i++){
        for(k=0;k<2;k++){
            nums[z]=0;
            for(y=0;y<2;y++){
                nums[z] += matriz[i][y] * matriz[y][k];
            }
            z++;
        }
    }
    for(i=0;i<(2*2);i++){ 
        printf("%.3f ",nums[i]);
        if((i+1)>=2 && (i+1)%2==0) printf("\n");
    }
   
    for(i=0;i<2;i++){
        free(matriz[i]);
    }
    free(matriz);
    free(nums);
    
    
    return 0;
}