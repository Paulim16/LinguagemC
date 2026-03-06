#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cod;
    float ValorCredito;
    char nome[100];
} Curso;

typedef struct{
    char nome[500];
    int codigo;
    int numCred;
} Aluno;



int main(){
    int i,j,N,M;
    float mensalidade;
    scanf("%d",&N);

    Curso * cursos = NULL;
    cursos = (Curso *) malloc(N*sizeof(Curso));

    for (i=0;i<N;i++){
        scanf("%d",&cursos[i].cod);
        scanf("%f",&cursos[i].ValorCredito);
        scanf(" %[^\n]",cursos[i].nome);
    }
    scanf("%d",&M);

    Aluno * alunos = NULL;
    alunos = (Aluno *) malloc(M*sizeof(Aluno));

    for (i=0;i<M;i++){
        scanf(" %[^\n]",alunos[i].nome);
        scanf("%d",&alunos[i].codigo);
        scanf("%d",&alunos[i].numCred);

    }

    for (i=0;i<M;i++){
        for(j=0;j<N;j++)if(alunos[i].codigo == cursos[j].cod)break;
        mensalidade = alunos[i].numCred*cursos[j].ValorCredito;

        printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2f Mensalidade: %.2f\n",
                alunos[i].nome,
                cursos[j].nome,
                alunos[i].numCred,
                cursos[j].ValorCredito,
                mensalidade);
    }
    
    free(alunos); 
    free(cursos);
    return 0;
}