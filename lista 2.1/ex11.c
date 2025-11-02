#include <stdio.h>
 
int main(void){
    int N,y,a,num,i,z,k,maior=-1,rep=0,aparece;
    int bin[100000],freq[100000],aux;
 
    scanf("%d",&N);
    if(N<0||N>1000000) return 0;
 
    for(i=0;i<N;i++){
        scanf("%d",&num);
        bin[i] = num;
        if(num<0||num>100) return 0;
 
    }
 
    for(y=0;y<N;y++){
        rep = 0;
        for(z=0;z<N;z++){
            if(bin[y] == bin[z])rep++;
        }
 
        freq[y] = rep;
 
        if(rep>maior){
            maior=rep;
            aparece = bin[y];
 
        }
 
    }
    for(k=0;k<N;k++){
        if (freq[k] == maior){
            if(bin[k] < aparece) aparece = bin[k];
        }
    }
 
    printf("%d\n%d\n", aparece,maior);
 
    return 0;
}