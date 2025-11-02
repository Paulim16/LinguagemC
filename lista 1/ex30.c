#include <stdio.h>
double fatorial(int x){
    double fat = 1;
    int z;
    for(z=1;z<=x;z++){
        fat *=z;
    } 
    if(x==0){
        fat = 1;
    }
    return fat;
 
}
int main() {
    double formula,fat,sub,fat2;
    int a, b, i, z;
 
    scanf("%d %d", &a,&b);
    
    for(i=a;i<=b;i++){
        for(z=0;z<=i;z++){
            double sub = i-z;
            fat = ((fatorial(z))*(fatorial(sub)));
            fat2 = fatorial(i)/fat;
            if(z==i){
                printf("%0.lf",fat2);  
            }
            else{      
                printf("%0.lf,",fat2);
            }
        }
        printf("\n");
    }
    
    return 0;
}