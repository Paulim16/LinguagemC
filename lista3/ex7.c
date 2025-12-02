#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
typedef struct vetor{
    double u,x,y,z;
} Vetor;
 
 
int main() {
 
    int i,N;
    scanf("%d", &N);
    
    double * distancias = NULL;
    Vetor * vetor = NULL;
    distancias = (double*)malloc(N*sizeof(double));
    vetor = (Vetor*)malloc(N*sizeof(Vetor));

    for (i=0;i<N;i++){
        scanf("%lf %lf %lf %lf",&vetor[i].u, &vetor[i].x, &vetor[i].y, &vetor[i].z);
    }
 
    for(i=0;i<N-1;i++){
        distancias[i] = sqrt((pow(vetor[i].u-vetor[i+1].u,2))+(pow(vetor[i].x-vetor[i+1].x,2))+(pow(vetor[i].y-vetor[i+1].y,2))+(pow(vetor[i].z-vetor[i+1].z,2)));
    }
        
    for(i=0;i<N-1;i++)printf("%.2lf\n",distancias[i]);

    free(vetor);
    free(distancias);
 
    return 0;
}