#include <stdio.h>
int main(){
    int n,i,fat,b;
    scanf("%d",&n);
    fat = n;
    if (n == 0){
        fat = 1;
    }
    else{
        for(i=(n-1);i!=0;i--){
            fat = fat*i;
        }
    }
    printf("%d! = %d",n,fat);
    return 0; 
}