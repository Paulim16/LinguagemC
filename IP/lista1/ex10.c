#include <stdio.h>
int main(){
    int soma, dado1,dado2,p;
    p = 0;
    scanf("%d",&soma);
    for(dado1=1;dado1<=6;dado1++){
        for(dado2=1;dado2<=6;dado2++){
            if (dado1 != dado2 && dado1 + dado2 == soma){
                printf("D1: %d, D2: %d\n", dado1,dado2);
                p+=1;
            }
        }
    }
    if (p != 0){
        printf("Ha %d possibilidades\n", p);
    }
    else{
        printf("Combinacao impossivel\n");
    }
    return 0; 
 
}