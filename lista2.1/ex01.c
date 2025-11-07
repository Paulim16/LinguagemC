#include <stdio.h>
#define N 100000
#define M 1000
int main(void){
    int m,k,y,size,a,V[N],i;
    scanf("%d",&size);
    if(size<0 || size>N){
        return 0;
    }
    for(y=0;y<size;y++){
        scanf("%d",&V[y]); 
    }      
    scanf("%d",&m);
    if(m<0 || m>M){
        return 0;
    }
    for(i=0;i<m;i++){
        scanf("%d",&a);
        for(k=0;k<size;k++){
            if(a==V[k]){
                printf("ACHEI\n");
                break;
            }
        }   
        if(k==size){ 
        printf("NAO ACHEI\n");
        }
    }
    
    return 0;
}