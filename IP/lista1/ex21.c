#include <stdio.h>
int main(){
 
    int i,T,A,Ai,B,Bi;
 
    scanf("%d", &T);
    for(i=0;i<T;i++){
        scanf("%d %d",&A, &B);
        Ai = (A/100) + (((A/10)%10)*10) + ((A%10)*100);
        Bi = (B/100) + (((B/10)%10)*10) + ((B%10)*100);
        if(Ai>Bi){
            printf("%d\n",Ai);
        }
        else{
            printf("%d\n",Bi);
        }
    }
    return 0;
}