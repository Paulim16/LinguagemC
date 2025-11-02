#include <stdio.h>
int main (){
 
    int n, i;
    double f, C;
 
    scanf("%d", &n);
    for(i=0;i<n;i=i+1) {
        scanf(" %lf", &f);
        C = (5*(f-32))/9.0;
        printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", f, C);
 
    } 
 
 
    return 0;
}