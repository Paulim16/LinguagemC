#include <stdio.h>
#include <math.h>
int main(){
    double a,b,c,x1,x2,delta, aux; 
 
    scanf("%lf %lf %lf", &a,&b,&c);
    delta = (b*b) - (4 * a * c);
    
    if (delta<0){
        printf("RAIZES IMAGINARIAS\n");
    }
    else if(a == 0){
        if (b > 1){
            printf("RAIZES IMAGINARIAS\n");
        }
        else{
            x1 = (-c)/b;
            printf("RAIZ UNICA\nX1 = %.2lf\n", x1);
        }
    }
    else{
        x1 = ((-b) - (sqrt(delta)))/(2*a);
        x2 = ((-b) + (sqrt(delta)))/(2*a);
        
        if (x1>x2){
            aux = x2;
            x2 = x1;
            x1 = aux;
        }
        
    
        if (delta == 0){
            printf("RAIZ UNICA\nX1 = %.2lf\n", x1);
        }
        else {
            printf("RAIZES DISTINTAS\nX1 = %.2lf\nX2 = %.2lf",x1,x2);
        }
    }
    return 0;
}