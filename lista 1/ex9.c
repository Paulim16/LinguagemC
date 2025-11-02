#include <stdio.h>
int main(){
 
    int i,a,b;
 
 
    scanf("%d", &a);
    scanf("%d", &b);
    
    for(i=0;b>a;i++){
        a *= 1.03;
        b *= 1.015;
    }
    printf("ANOS = %d\n",i);
    
    return 0;
 
}