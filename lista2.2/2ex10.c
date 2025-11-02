#include <stdio.h>
 
 
double compute_pi(int n){
    int i;
    double a=2,b=1;
    double pi=1;
    for(i=1;i<=n;i++){
        pi *= a/b;
        if(i%2==1){
            b+=2;
        }
        else{
            a+=2;
        } 
 
    }
    return pi;
}
 
int main(void){
    int n;
    scanf("%d",&n);
    printf("%.12lf\n",compute_pi(n)*2);
    return 0;
}