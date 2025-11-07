#include <stdio.h> 
int main() {
    double a, b, c, d, aux;
 
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    scanf("%lf", &d);
    if (a > b) {
        aux = a;
        a = b;
        b = aux;
    }
    if (a > c) {
        aux = a;
        a = c;
        c = aux;
    }
    if (a > d) {
        aux = a;
        a = d;
        d = aux;
    }
    if (b > c) {
        aux = b;
        b = c;
        c = aux;
    }
    if (b > d) {
        aux = b;
        b = d;
        d = aux;
    }
    if (c > d) {
        aux = c;
        c = d;
        d = aux;
    }
    printf("%.2lf, %.2lf, %.2lf, %.2lf\n", a,b,c,d);
    return 0;
}