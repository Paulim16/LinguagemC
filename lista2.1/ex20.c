#include <stdio.h>

int main(){
    int N,i,z,flag,tam=0,num;
    int numb[1001];

    scanf("%d", &N);

    for (i=0;i<N;i++){
        scanf("%d",&num);
        flag=0;
        for(z=0;z<tam;z++){
            if(num==numb[z]) flag=1;
        }
        if(flag==0){
            numb[tam]=num;
            tam++;
            //printf("%d\n",num);
        }
        
    }
    for(i=0;i<tam;i++) printf("%d\n",numb[i]);
    return 0;
}