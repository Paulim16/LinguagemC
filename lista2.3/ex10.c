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

    int i,z,x,y,nl,cl,flag=0;

    scanf("%d\n%d\n", &nl, &cl);
    //if (ordemMat>1000 || ordemMat<=1)return 0;
    
    int **matriz = int_mat_new(nl,cl);

    for(i=0;i<nl;i++){
        for(z=0;z<cl;z++){
            scanf("%d", &matriz[i][z]);    
        }
    }

    for(x=0;x<nl;x++){
        for(y=0;y<cl;y++){
            if(matriz[x][y]==1111){
                if (flag==4)break;
                flag=0;
                //Cabeça
                if(x==0){
                    if(matriz[nl-1][y]==4)flag++;
                }
                else {
                    if(matriz[x-1][y]==4)flag++;
                }
                //mão esquerda
                if(y==0){
                    if(matriz[x][cl-1]==0)flag++;
                }
                else {
                    if(matriz[x][y-1]==0)flag++;
                } 
                // pés
                if(x==nl-1){
                    if(matriz[0][y]==8)flag++;
                }
                else {
                    if(matriz[x+1][y]==8) flag++;
                }
                // mão direita                
                if(y==cl-1){
                    if(matriz[x][0]==0)flag++;
                }
                else {
                    if(matriz[x][y+1]==0)flag++;
                }

                if (flag==4) printf("%d %d",x,y);
            }
        }
    }
    
    if (flag!=4)printf("WALLY NAO ESTA NA MATRIZ");
    
    //---LIBERAR ESPAÇO---
    for(i=0;i<nl;i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
    //--------------------
}