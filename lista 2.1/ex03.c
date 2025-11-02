#include <stdio.h>
#define N 1000
 
int main(void){
    int K,V[N],i,qtd=0;
    scanf("%d",&K);
    if(K<1||K>1000){
        return 0;
    }
    for(i=0;i<K;i++){
        scanf("%d",&V[i]);
        if(V[i]%2==0){
            printf("%d ",V[i]);
            qtd++;
        }
    }
    printf("%d\n",qtd);
    
    return 0;
}