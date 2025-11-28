#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct vetor{
    double u,x,y,z;
} Vetor;


int main() {

    int i,N,flag;
    scanf("%d", &N);
    double * norma = NULL;

    Vetor * vetor = (Vetor*)malloc(N*sizeof(Vetor));
    norma = (double*)malloc(N*sizeof(double));
    for (i=0;i<N;i++){
        scanf("%lf %lf %lf %lf",&vetor[i].u, &vetor[i].x, &vetor[i].y, &vetor[i].z);
        norma[i] = sqrt(pow(vetor[i].u,2)+pow(vetor[i].x,2)+pow(vetor[i].y,2)+pow(vetor[i].z,2));  
        //printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n",vetor[i].u,vetor[i].x,vetor[i].y,vetor[i].z,norma[i]);
    }

    for()
    
    free(vetor);
    free(norma);

    return 0;
}
