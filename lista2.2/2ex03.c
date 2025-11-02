#include <stdio.h>\
 
int separaDigitos(int x){
 
    int resto, inverso=0;
    while (x != 0) {
        resto = x % 10;      
        inverso = inverso * 10 + resto; 
        x /= 10;           
    }
    
 
    return inverso;
}
 
 
int main(void) {
    int num;
    scanf("%d",&num);
    printf("%d\n", separaDigitos(num));
    return 0;
}