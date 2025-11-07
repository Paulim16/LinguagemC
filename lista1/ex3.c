#include <stdio.h>
int main(){
    int cliente;
    float agua, valor, x;
    char cons;
 
 
    scanf("%d %f %c", &cliente, &agua, &cons);
 
    if(cons == 'C')  {
        if (agua > 80){
            x = agua - 80;
            valor = 500 + (x * 0.25);
        } 
        else{
            valor = 500;
        } 
    }
 
    else if(cons == 'I'){
          if (agua > 100){
            x = agua - 100;
            valor = 800 + x * 0.04;
        } 
        else{
            valor = 800;
        } 
    }
    else {
        valor = 5 + (agua * 0.05);
    }
    printf("CONTA = %d\n", cliente);
    printf("VALOR DA CONTA = %.2f\n", valor);
    
    return 0;
 
}