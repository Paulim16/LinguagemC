#include <stdio.h>
 
void converteEmNotasMoedas(int num, int *c, int *cq, int *d, int*m){
 
    *c = num/100;
    *cq = (num%100)/50;
    *d = ((num%100)%50)/10;
    *m = (((num%100)%50)%10);
 
}
 
 
 
 
int main(){
    int c,cq,d,m,num;
    scanf("%d",&num);
    converteEmNotasMoedas(num,&c,&cq,&d,&m);
    printf("NOTAS DE 100 = %d\nNOTAS DE 50 = %d\nNOTAS DE 10 = %d\nMOEDAS DE 1 = %d\n",c,cq,d,m);
    return 0;
}