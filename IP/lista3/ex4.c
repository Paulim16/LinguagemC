#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
typedef struct vetor{
    double u,x,y,z;
    double norma;
} Vetor;
 
 
int main() {
 
    int i,j,N,flag;
    scanf("%d", &N);
    double * norma = NULL;
 
    Vetor * vetor = (Vetor*)malloc(N*sizeof(Vetor));
    Vetor temp;
    for (i=0;i<N;i++){
        scanf("%lf %lf %lf %lf",&vetor[i].u, &vetor[i].x, &vetor[i].y, &vetor[i].z);
        vetor[i].norma = sqrt(pow(vetor[i].u,2)+pow(vetor[i].x,2)+pow(vetor[i].y,2)+pow(vetor[i].z,2));  
        //printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n",vetor[i].u,vetor[i].x,vetor[i].y,vetor[i].z,norma[i]);
    }
 
    for(i = 0; i < N; i++){
        for(j=0;j<N-i-1;j++){
            if(vetor[j].norma > vetor[j+1].norma) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
        for (i=0;i<N;i++){
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n",vetor[i].u,vetor[i].x,vetor[i].y,vetor[i].z, vetor[i].norma);
 
    }
    
    free(vetor);
 
    return 0;
}