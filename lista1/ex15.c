#include <stdio.h>
int main(){
    double a, b, c, menor, meio, maior;
    scanf("%lf%lf%lf", &a,&b,&c);
    maior = a;
    meio = a;
    menor = a;
    if(b>a){
        maior = b;
    }
    else if(b<a){
        menor = b;
    }
    if(c>=maior){
        maior = c;
    }
    else if(c<=menor){
        menor = c;
    }
    else{
        meio = c;
    }
    if(a>=maior){
        maior = a;
    }
    else if(a<=menor){
        menor = a; 
    }
    else{
        meio = a;
    }
    if (b<maior && b>menor){
        meio = b;
    }
    printf("%.2lf, %.2lf, %.2lf", menor, meio, maior);
    return 0;
}