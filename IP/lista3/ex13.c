#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Complex{
    float real, img;
};
struct RaizEqu2{
    struct Complex r1;
    struct Complex r2;
};

struct RaizEqu2 calcula_raiz_equ_2( float a, float b, float c){
    struct RaizEqu2 raizes;
    float delta = (b*b) - (4 * a * c);
    
    if (delta >= 0){
        if(a==0 && c ==0){
            raizes.r1.real = 0;
            raizes.r2.real = 0;
        } 
        else {
            raizes.r1.real = (-b + sqrt(delta)) / (2 * a);
            raizes.r2.real = (-b - sqrt(delta)) / (2 * a);
        }
        raizes.r1.img = 0;
        raizes.r2.img = 0;
    }
    else{
        raizes.r1.real = -b  / (2 * a);
        raizes.r2.real = -b  / (2 * a);
        raizes.r1.img = sqrt(-delta)/ (2 * a);
        raizes.r2.img = -sqrt(-delta)/ (2 * a);
    }

    return raizes;
}

void complex_print(struct Complex c){
    if (c.img ==0 && c.real == 0){
        printf("0.00\n");
        return;
    }
    else if(c.real != 0){
        printf("%.2f",c.real);
    } 
    if(c.img == 0)printf("\n");

    else if(c.img!=0){
        if(c.img>0 && c.real!=0) printf("+");
        if(c.img == 1)printf("i\n");
        else if(c.img == -1)printf("-i\n");
        else printf("%.2fi\n",c.img);
    }
}
int main (){
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    struct RaizEqu2 resultado = calcula_raiz_equ_2(a,b,c);
    printf("x1 = ");
    complex_print(resultado.r1);
    printf("x2 = ");
    complex_print(resultado.r2);

    return 0;
}


