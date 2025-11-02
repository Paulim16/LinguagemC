#include <stdio.h>
#include <math.h>
 
 
double absoluto( double n ){
    if(n>=0) return n;
    else return -n;
}
 
double raiz( double n, double p ){
    int i;
    double novo,antigo=1,aux;
    for(i=0;absoluto(n-(pow(antigo,2)))>p;i++){
        novo = (antigo + (n/antigo))/2;
        printf("r: %.9lf, err: %.9lf\n",novo,absoluto(n-(pow(novo,2))));
        antigo = novo;
 
    }
    return novo;
}
 
 
int main(){
    double n,p;
    scanf("%lf %lf",&n,&p);
    raiz(absoluto(n),p);
    
    return 0;
}