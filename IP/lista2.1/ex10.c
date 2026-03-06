#include <stdio.h>
 
int main(void){
    int N,y,a,num,i,z;
    int bin[33],aux;
    while(scanf("%d",&N) != EOF){
        if (N == 0) {
        printf("0\n");
        continue;
        }
 
        if(N<0||N>4294967295) return 0;
 
        for(i=0;N>0;i++){
            bin[i] = N%2;
            N /=2;
            
        }
        i--;
        a=i;
        for(z=0;z<=a/2;z++){
            aux = bin[z];
            bin[z] = bin[i];
            bin[i] = aux;
            i--;
        }
        
        for (y = 0; y <= a; y++)printf("%d", bin[y]);
            
        printf("\n");
 
    }
    return 0;
}