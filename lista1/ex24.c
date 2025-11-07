#include <stdio.h>
#include <math.h>
int main(){
 
    int a,b,c, div, mmc;
    scanf("%d %d %d",&a,&b,&c);
    div = 2;
    mmc = 1;
 
    while(1){
        if(a% div ==0||b% div ==0||c % div ==0){
 
            printf("%d %d %d :%d\n",a,b,c,div);
            if(a%div==0){
                a /= div;
            }
            if(b%div==0){
                b /= div;
            }
            if(c%div==0){
                c /= div;
            }
            mmc *= div;
        }
        else{
            div++;
        }
        if(a==1 && b==1 && c==1){
            break;
        }
 
    }
    printf("MMC: %d\n", mmc);   
    return 0;
}