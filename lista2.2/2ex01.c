#include <stdio.h>\
 
unsigned long int fat(unsigned int n){
    int i;
    if(n==0) return 1;
    else{
        for(i=n-1;i>0;i--) n *= i;
        return n;
    }
}
 
 
int main(void) {
    int num;
    scanf("%d",&num);
    printf("%d! = %lu\n",num, fat(num));
    return 0;
}