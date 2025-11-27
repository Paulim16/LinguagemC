#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double **double_mat_new(int nl, int nc){
    int i;
    double **M = NULL;
    M = (double **)malloc(nl*sizeof(double*));
    for(i=0;i<nl;i++) M[i]=(double*)malloc(nc*sizeof(double));
    return M;
}
char **str_mat_new(int nl, int nc){
    int i;
    char **M = NULL;
    M = (char **)malloc(nl*sizeof(char*));
    for(i=0;i<nl;i++) M[i]=(char*)malloc(nc*sizeof(char));
    return M;
}
int *int_vect_new(int n){
    int *N = NULL;
    N = (int*)malloc(n*sizeof(int));
    return N;
}
double *double_vect_new(double n){
    double *N = NULL;
    N = (double*)malloc(n*sizeof(double));
    return N;
}
char *str_vect_new(int n){
    char *N = NULL;
    N = (char*)malloc(n*sizeof(char));
    return N;
}
int main(){
    int N, M, P, i,z,y;

    scanf("%d%*c",&N);
    for(i=0;i<N;i++){
        scanf("%d%*c",&M);
        double * precos = double_vect_new(M); 
        char ** frutas = str_mat_new(M,51);
        char *compra = str_vect_new(51);
        double * qnt = double_vect_new(M);
        double soma = 0;
        for(z=0;z<M;z++)scanf("%s %lf%*c",frutas[z],&precos[z]);

        scanf("%d",&P);
        for(z=0;z<P;z++){
            scanf("%s %lf%*c",compra,&qnt[z]);
            for(y=0;y<M;y++){
                if(strcmp(frutas[y],compra)==0){
                    soma += (qnt[z]*precos[y]);
                }
            }
        } 

        printf("R$ %.2lf\n",soma);

        free(precos);
        for(z=0;z<M;z++)free(frutas[z]);
        free(frutas); 
        free(qnt);
        free(compra);

    }

    return 0;
}