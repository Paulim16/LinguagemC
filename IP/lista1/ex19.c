#include <stdio.h>
#include <math.h>
int main(){
    int cc, dr, rt, aux=0, grau; 
 
    scanf("%d", &cc);
    scanf("%d", &dr);
    scanf("%d", &rt);
 
    if(cc<7){
        aux++;
    }
    if(dr>50){
        aux += 2;
    }
    if(rt>80000){
        aux+=4;
    }
    if(aux==7){
        grau = 10;
    }
    else if(aux==3){
        grau=9;
    }
    else if(aux==1){
        grau=8;
    }
    else{
        grau=7;
    }
    printf("ACO DE GRAU = %d",grau);
    return 0;
}