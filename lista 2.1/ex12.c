#include <stdio.h>
 
int main(void){
    int N,y,l,a,num,i,z,k;
    int bin[100000],aux;
    double soma = 0;
 
    scanf("%d",&N);
    if(N<0||N>1000000) return 0;
 
    for(i=0;i<N;i++){
        scanf("%d",&num);
        bin[i] = num;
    
    }
    if(num<-4294967296||N>4294967296) return 0;
    
    for(y=0;y<N;y++){
        for(z=0;z<N;z++){
            if(y>z && bin[y]> bin[z]){
                aux = bin[z];
                bin[z] = bin[y];
                bin[y] = aux;
            }
            if(y<z && bin[y] < bin[z]){
                aux = bin[z];
                bin[z] = bin[y];
                bin[y] = aux;
            }
        }
    }
 
    a = y;
    y--;
    for(k=0;k<a-1;k++){
        if (a%2==0){
            if(k==(a/2)-1&&y==(a/2)){
                soma = (bin[k]+bin[y])/2.0;
                printf("%.2lf",soma);
                return 0;
            }
        }
            
        else if (a%2==1){
            if(k==y){
                soma = (bin[k]+bin[y])/2.0;
                printf("%.2lf",soma);
                return 0;
            }
        }
        y--;
    }
 
    return 0;
}