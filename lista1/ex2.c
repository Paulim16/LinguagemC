#include <stdio.h>
 
int main(){
    int c,d,u,num;
 
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&u);
 
    num = (c*100) + (d*10) + u;
 
    if(c > 9 || d > 9 || u > 9){
        printf("DIGITO INVALIDO");
    }
 
    else {
        printf("%d, %d\n", num, num*num);
    }
    return 0;
}