#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int likes;
    int retwt;
    int menc;

} Interacao;

int main(){

    int N,M,i,j;
    scanf("%d",&N);
    scanf("%d",&M);
    Interacao *** interact = NULL;
    interact = (Interacao ***)malloc(N*sizeof(Interacao**));
    for(i=0;i<M;i++) {
        interact[i]=(Interacao**)malloc(M*sizeof(Interacao*));
        for(j = 0; j < N; j++) interact[i][j] = NULL;
        

}