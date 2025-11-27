#include <stdio.h>

int main(){
    int i,k,N,y;
    int quadra = 0, quina = 0, sexta = 0;
    int sena[6];
    int chute[6];

    for(i=0;i<6;i++) scanf("%d", &sena[i]);
    
    scanf("%d",&N);

    for(k=0;k<N;k++){
        int acertos = 0;
        
        
        for(i=0;i<6;i++)scanf("%d", &chute[i]);
        
        for(i=0;i<6;i++){
            for(y=0;y<6;y++){
                if(chute[i]==sena[y]) acertos++;
            }
        }
        if(acertos==4) quadra++;
        if(acertos==5) quina++;
        if(acertos==6) sexta++;
    }
    if(sexta==0) printf("Nao houve acertador para sena\n");
    else printf("Houve %d acertador(es) da sena\n",sexta);

    if(quina==0) printf("Nao houve acertador para quina\n");
    else printf("Houve %d acertador(es) da quina\n",quina);

    if(quadra==0) printf("Nao houve acertador para quadra\n");
    else printf("Houve %d acertador(es) da quadra\n",quadra);

    return 0;
}