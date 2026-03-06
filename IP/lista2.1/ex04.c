#include <stdio.h>
#include <math.h>
 
int main(void){
    int N,i,z,qtd;
    char num[101];
    scanf("%d",&N);
    if(N<1||N>1000){
        return 0;
    }
    for(i=0;i<N;i++){
        scanf("%s",num);
        qtd=0;
        for(z=0;num[z]!='\0';z++){
            if(num[z]== '0') qtd+=6;
            else if(num[z]== '1') qtd+=2;
            else if(num[z]== '2') qtd+=5;
            else if(num[z]== '3') qtd+=5;
            else if(num[z]== '4') qtd+=4;
            else if(num[z]== '5') qtd+=5;
            else if(num[z]== '6') qtd+=6;
            else if(num[z]== '7') qtd+=3;
            else if(num[z]== '8') qtd+=7;
            else if(num[z]== '9') qtd+=6;
            
 
        }
        printf("%d leds\n",qtd);
    }
    
    
    return 0;
}