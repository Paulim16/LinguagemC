#include <stdio.h>
int main(){
 
    int n,tabuleiro;
 
    scanf("%d", &n);
    tabuleiro = (((n*4)+((n*2)*4))*8)-n;
    printf("%d",tabuleiro);
   
    return 0;
}