#include <stdio.h>
#include <math.h>
 
void raizesEq2Grau(double a, double b, double c, double *raizes){
    double x1,x2,delta,aux;
    
    delta = (b*b) - (4 * a * c);
 
    if (delta<0){
        raizes[2] = 11;
    
    }
    else {
        x1 = ((-b) - (sqrt(delta)))/(2*a);
        x2 = ((-b) + (sqrt(delta)))/(2*a);
        
        if (x1>x2){
            aux = x2;
            x2 = x1;
            x1 = aux;
        }
        raizes[0] = x1;
        raizes[1] = x2;
    }
    
 
    
}
 
int main(){
    double raizes[3];
    double a,b,c;
    scanf("%lf %lf %lf", &a,&b,&c);
    raizesEq2Grau( a,b,c,raizes);
    
    if (raizes[2] == 11){
        printf("RAIZES IMAGINARIAS");
        return 0;
    }
    
    if(raizes[0] == raizes[1]){
        printf("RAIZ UNICA\nX1 = %.2lf\n", raizes[0]);
    }
    else {
        printf("RAIZES DISTINTAS\nX1 = %.2lf\nX2 = %.2lf",raizes[0],raizes[1]);
    }
    
    return 0;
 
}