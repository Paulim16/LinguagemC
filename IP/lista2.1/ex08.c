#include <stdio.h>
 
int main(void){
    int N,i,z,y,qtd=0, maior;
    int num[10001];
    while(1){
        maior=-1;
        scanf("%d",&N);
        if(N==0) break;
 
        if(N<0||N>10000) return 0;
            
        for(i=0;i<N;i++){
            scanf("%d",&num[i]);
            if(num[i]>maior){
                maior = num[i];  
            } 
           
        
            
        }
        for(z=0;z<=maior;z++){
            qtd = 0;
            
                for(y=0;y<N;y++){   
                    if(num[y]<=z) qtd++;
                }
                
                printf("(%d) %d\n",z,qtd);   
                
        }
            
    }
    
    
    return 0;
}