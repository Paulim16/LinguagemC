#include <stdio.h>
 
int main(){
    int num, metade,soma=1;
 
    scanf("%d", &num);
    int i;
    metade = num/2;
 
    printf("%d = 1 ", num );
    for (i = 2; i <= metade; i++){
 
        if (num % i == 0){
            printf("+ %d ", i);
            soma += i;
        }
        
    }
 
    printf("= %d ",soma);
    if (soma==num){
        printf("(NUMERO PERFEITO)\n");
    }
    else{
        printf("(NUMERO NAO E PERFEITO)\n");
    }
    return 0;
}