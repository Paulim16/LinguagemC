#include <stdio.h>
int main(){
 
    int a,b,c,d, soma;
 
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    
    if(a>b && a>c && a>d){
        soma = b+c+d;
        printf("%d\n", soma);
    }
    if(b>a && b>c && b>d){
        soma = a+c+d;
        printf("%d\n", soma);
    }
    if(c>b && c>a && c>d){
        soma = b+a+d;
        printf("%d\n", soma);
    }
    if(d>b && d>c && d>a){
        soma = b+c+a;
        printf("%d\n", soma);
    }
    if(d==b && d==c && d==a){
        soma = b+c+d;
        printf("%d\n", soma);
    }
 
    return 0;
}