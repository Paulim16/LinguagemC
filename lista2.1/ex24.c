#include <stdio.h>
 
int main(void){

    int i;
    long int n,aux;
    char str[129];
    while( scanf("%s%*c", str) != EOF ) { 
        n=0;
        aux=1;
        for(i=0;str[i]!='\0';i++){
            n*=10;
            if(str[i]=='-'){
                aux = -1;
            }
            else{
                n += str[i]-48;
                
            }
        }
        n*=aux;
        printf("%ld %ld\n", n, n*2);
        
    }

    return 0;
}