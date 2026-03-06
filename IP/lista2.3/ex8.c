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
int ehPermutacao( int **matriz, int n, int *soma ){
    int i,z,k,flag=0;
    int *num = vect_new(n);
    for(k=0; k<n; k++) num[k] = 0;
    for(i=0;i<n;i++){
        flag = 0;
        for(z=0;z<n;z++){
            if (matriz[i][z] != 0) {
                flag+=matriz[i][z];
                if(matriz[i][z]==num[z]) num[z] = 11;
                else num[z] = matriz[i][z];
                
            }
            *soma += matriz[i][z];        
        }
        if(flag == 0) num[i] = 11;
    }
    for(k=0;k<n;k++){
        if (num[k]!=1){
            free(num);
            return 0;
        } 
    }
    free(num);
    return 1;
}
//-----------------------------------------------------------

int main(){

    int i,z,ordemMat,somas=0,flag;

    scanf("%d%*c\n", &ordemMat);
    if (ordemMat>500 || ordemMat<=1)return 0;

    int **matriz = int_mat_new(ordemMat,ordemMat);
    for(i=0;i<ordemMat;i++){
        for(z=0;z<ordemMat;z++){
             scanf("%d", &matriz[i][z]);        
            }
    }
    printf("%d\n",ordemMat);
    flag = ehPermutacao(matriz,ordemMat,&somas);
    if (flag==0) printf("NAO EH PERMUTACAO\n");
    else printf("PERMUTACAO\n");
    printf("%d\n", somas);


    //---LIBERAR ESPAÇO---
    for(i=0;i<ordemMat;i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
    //--------------------
}