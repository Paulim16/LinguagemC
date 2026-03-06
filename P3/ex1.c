#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    int idade;
    int numFilhos;
    char sexo;
    double salario;
} FUNCIONARIO;

int main(){
    int n,i,medIdade=0,medFilhos=0;
    int p=0,s=0,t=0,q=0;
    scanf("%d",&n);
    FUNCIONARIO * func = NULL;
    func = (FUNCIONARIO*)malloc(n*sizeof(FUNCIONARIO));

    for(i=0;i<n;i++){
        scanf("%d %d %d %c %lf",&func[i].matricula,&func[i].idade,
        &func[i].numFilhos,&func[i].sexo,&func[i].salario);
        medIdade += func[i].idade;
        medFilhos += func[i].numFilhos;
    }

    medIdade /= n;
    medFilhos /= n;

    for(i=0;i<n;i++){
        if(func[i].idade > medIdade && func[i].salario>3600) p++;
        if(func[i].sexo == 'F' && func[i].numFilhos>medFilhos) s++;
        if(func[i].sexo == 'M' && func[i].numFilhos>medFilhos) t++;
        if(func[i].idade > 47 && (func[i].salario/(1+func[i].numFilhos))<2400) q++;
        
    } 

    printf("%d %d %d %d\n",p,s,t,q);
    return 0;
}