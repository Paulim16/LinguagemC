#include <stdio.h>
int main(){
    int unidade,p,dezena,centena1,unidadeMilhar,dezenaMilhar,dezenacontrario;
 
    scanf("%d",&p);
    unidade = p%10;
    dezena = p/10;
    centena1 =p/100;
    dezenacontrario = (unidade*10) +((p%100)/10);
    unidadeMilhar=centena1;
    dezenaMilhar = p/1000;
 
    if(p<1 || p>99999){
        printf("NUMERO INVALIDO");
    }
    else if(p<10){
        printf("PALINDROMO");
        
    }
    else if(p<100){
        if (unidade == dezena){
            printf("PALINDROMO");
        }
        else{
            printf("NAO PALINDROMO");
        }
 
    }
    else if(p<1000){
        if(centena1 == unidade){
         printf("PALINDROMO");
        }
        else{
            printf("NAO PALINDROMO");
        }
    }
    else if(p<10000){
        if(dezenacontrario == unidadeMilhar){
         printf("PALINDROMO");
        }
        else{
            printf("NAO PALINDROMO");
        }
    }
    else if(p<100000){
        if(dezenacontrario == dezenaMilhar){
         printf("PALINDROMO");
        }
        else{
            printf("NAO PALINDROMO");
        }
    }
 
    return 0;
}