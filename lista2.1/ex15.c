#include <stdio.h>
 
 
int main(void){
    int z,q,i,t,k,y,N, B, E;
    int numeros[12222];
    char inv[1000000];
    scanf("%d",&N);
    for(z=0;z<N;z++){
        k=0;
        scanf("%d %d", &B, &E);
        if(0>B||B>E||E>12221){
            return 0;
        }
        for(y=B;y<=E;y++){
            printf("%d", y);
            numeros[k]=y;
            k++;
        }
        k--;
        for (t=k;t>=0;t--){
            sprintf(inv, "%d", numeros[t]);
            
            for(q=0;inv[q]!='\0';q++);
 
 
            for(q-=1;q>=0;q--){
                printf("%c", inv[q]);
            }
        }
 
        printf("\n");
    }
 
 
    return 0;
}