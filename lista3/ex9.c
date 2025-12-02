#include <stdio.h>
#include <stdlib.h>
 
typedef struct{
    int num;
    int den;
} Frac;
int main(){
 
    int n,i,z,k,y,flag,cont;
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        cont = 0;
        flag = 0;
        z = 0;
        char a = ' ';
        Frac * fracoes = NULL;
        while(a != '\n'){
            cont++;
            fracoes = (Frac *) realloc(fracoes,cont*sizeof(Frac));
            scanf("%d/%d%c",&fracoes[z].num,&fracoes[z].den,&a);
            z++;
        }
        printf("Caso de teste %d\n",i+1);

        for(k=0;k<z;k++){
            for(y=k+1;y<z;y++){
                if(fracoes[k].num*fracoes[y].den==fracoes[y].num*fracoes[k].den){
                    flag++;
                    printf("%d/%d equivalente a %d/%d\n",fracoes[k].num,fracoes[k].den,fracoes[y].num,fracoes[y].den);
                }
            }
        }
        if(flag==0)printf("Nao ha fracoes equivalentes na sequencia\n");
        
        free(fracoes);
    }
 
    return 0;
}