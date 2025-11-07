#include <stdio.h>
 
 
int main(void){
    int N, K, tempo,noTempo=0,i,z;
    int ordem[1001];
 
    scanf("%d %d", &N, &K);
        if(0>N||0>K||N>1000||K>1000){
            return 0;
        }
    for(i=0;i<N;i++){
        
        scanf("%d", &tempo);
        
        if(tempo<=0){
            ordem[i] = 1;
            noTempo++;
        }
        else ordem[i] = 2;
    }
 
    if (noTempo<K){
        printf("SIM\n");
    }
    else{
        printf("NAO\n");
        for(z=i;z>=0;z--){
            if(ordem[z] == 1) printf("%d\n",z+1);
        }
    }
    return 0;
}