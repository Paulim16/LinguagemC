#include <stdio.h>
 
int semzero(int x) {
    int novo = 0, mult = 1, d;
    
 
    if (x == 0) return 0;
    while (x > 0) {
        d = x % 10;
        if (d != 0) {
            novo = d * mult + novo;
            mult *= 10;
        }
        x /= 10;
    }
    return novo;
}
 
int main() {
    int m=1, n=2;
    while (1){
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0) break;
        
 
        int soma = m + n;            
        int resultado = semzero(soma); 
 
        printf("%d\n", resultado);
    }
    return 0;
}