#include <stdio.h>
#define M 1000
 
int main(void){
    int N=0,K,V[M],i,qtd=0;
    
    while(N<1||N>1000){
        scanf("%d",&N);
    }
    for(i=0;i<N;i++){
        scanf("%d",&V[i]);
            
    }
    scanf("%d",&K);
    for(i=0;i<N;i++){  
        if(V[i]>=K){
            qtd++;
        }
    }
    printf("%d\n",qtd);
    
    return 0;
}