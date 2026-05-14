#include <stdio.h>
#include <stdlib.h>


int main(){
    int K, i, j, v, temp, Q, s=1;
    char a;
    float x;
    scanf("%d",&K);
    int t = 0;
    
    int *S = (int*)malloc(K*sizeof(int));
    int *cord = (int*)malloc(K*sizeof(int));
    for(i=0;i<K;i++){
        scanf(" %d", &S[i]);
        s *= S[i];
    }

    int *M = (int*)malloc(s*sizeof(int));
    for(i=0;i<s;i++){
        scanf(" %d", &M[i]);
    }

    scanf("%d", &Q);

    for(i=0;i<Q;i++){
        scanf(" %c", &a);
        for(j=0;j<=K;j++){
            if(j==K) scanf("%d",&v);
            else scanf("%d",&cord[j]);
        }
        int indice = 0;
        for(j=0;j<K;j++){
            indice = (indice * S[j]) + cord[j];
        }
        M[indice] = v;
    }
    for(i=0;i<s;i++){
        printf("%d ",M[i]);
        if((i+1)%S[K-1]==0)printf("\n");
    }

    free(S);
    free(cord);
    free(M);

    return 0;
}

