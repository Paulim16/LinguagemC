#include <stdio.h>
 
int fibonacci( int t1, int t2, int n){
    int i,num;
    for (i=2;i<n;i++){
        num =  t1 + t2;
        t1 = t2;
        t2 = num;
    }
    return num;
 
}
 
 
int main(void) {
    int num,t1,t2,n;
    scanf("%d %d %d",&t1,&t2,&n);
    printf("%d\n",fibonacci(t1,t2,n));
    return 0;
}