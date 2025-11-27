
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int somatorio(int a, int b){
    int i;
    long long int soma=0;
    for(i=a;i<=b;i++)soma+=i;
    return soma;
}

long long int produtorio(int a, int b){
    int i;
    long long int produto=1;
    for(i=a;i<=b;i++)produto*=i;
    return produto;
}
int minimo(int a, int b){
    if(a<=b)return a;
    else if(b<=a)return b;
    
}
int maximo(int a, int b){
    int max;
    if(a>=b)max=a;
    else if(b>=a)max=b;
    return max;
}

int main(){
    int a,b;
    char op[4];
    scanf("%d %s %d",&a,op,&b);

    if (strcmp(op,"S") == 0) printf("%lld\n",somatorio(a,b));
    else if (strcmp(op,"P") == 0) printf("%lld\n", produtorio(a,b));
    else if (strcmp(op,"max") == 0) printf("%d\n",maximo(a,b));
    else if (strcmp(op,"min") == 0) printf("%d\n",minimo(a,b));

    return 0;
}