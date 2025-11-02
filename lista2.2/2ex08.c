#include <stdio.h>
#include <math.h>
 
int next_power(int n, int p){
    int i, a=0;
    long int dif;
 
    if(n == 1 || p == 0) {
        a = 1;
        return a;
    }
    
    int menor = 999999;
    for(i=1;i<=n/2;i++){
        dif = n - pow(i,p);
        if(dif < 0) dif = - dif;
 
        if (dif<menor) {
            menor = dif;
            a = i;
        } else break;
        
    }
    return a;
    
 
}
 
int main(){
    int n,p;
    scanf("%d %d",&n, &p);
    int i = next_power(n,p);
    printf("%d -> %d^%d = %.0lf\n", n, i, p, pow(i,p));
    return 0;
}