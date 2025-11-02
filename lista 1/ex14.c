#include <stdio.h>
int main(){
    int i, num, resto;
 
    scanf("%d", &num);
    if(num<0){
        printf("Numero invalido!");
        return 0;
    }
    for(i=1;i<=num;i++){
        if(num % i == 0){
            resto++;
        } 
    }
    if(resto == 2){
        printf("PRIMO");
    }
    else{
        printf("NAO PRIMO");
    }
    
    return 0;
}