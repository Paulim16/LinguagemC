#include <stdio.h>
int main (){
 
    int x, y,i;
 
    scanf("%d %d", &x,&y);
    if (x % 2 == 0){
        for(i=y;i>0;i--) {
            printf("%d ", x);
            x += 2;
        }
    }
 
    return 0;
}