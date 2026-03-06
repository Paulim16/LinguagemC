#include <stdio.h>
 
int main(){
    int num, imp;
    imp = 1;
 
    scanf("%d", &num);
 
    int i,x;
 
 
    for (i = 1; i <= num; i++){
        printf("%d*%d*%d =", i, i, i);
        
        for (x = 0; x < i; x++){
            if (x == 0){
               printf(" %d", imp);
 
            } 
            else {
                printf("+%d", imp);
            }
            imp += 2;
        }
        printf("\n");
    }
    return 0;
}