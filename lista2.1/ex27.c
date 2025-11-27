#include <stdio.h>
int main(){

    int T,i,z,y,soma;
    int anoes[9];
    scanf("%d", &T);
    for(i=0;i<T;i++){
        soma=0;
        for(z=0;z<9;z++){
            scanf("%d",&anoes[z]);
            soma +=anoes[z];
        }
        int diff = soma-100;
        int flag = 0;
        for(z=0;z<9;z++){
            for(y=0;y<9;y++){
                if(z!=y){
                    if(anoes[z]+anoes[y] == diff){
                        anoes[z] = 0;
                        anoes[y] = 0;
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag==1)break;
        }
        for(z=1;z<=99;z++){
            for(y=0;y<9;y++){
                if(anoes[y]==z) printf("%d\n",anoes[y]);
            }
        } 

    }
    return 0;
}