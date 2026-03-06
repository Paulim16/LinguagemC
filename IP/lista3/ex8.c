#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cod;
    float ValorCredito;
    char *nome;
} Curso;

typedef struct{
    char *nome;
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
        cursos[i].nome = (char *)malloc(1001*sizeof(char));
        scanf(" %[^\n]",cursos[i].nome);
        cursos[i].nome = (char *) realloc(cursos[i].nome,(strlen(cursos[i].nome)+1)*sizeof(char));
    }
    scanf("%d",&M);

    Aluno * alunos = NULL;
    alunos = (Aluno *) malloc(M*sizeof(Aluno));

    for (i=0;i<M;i++){
        alunos[i].nome = (char*) malloc(1001*sizeof(char));
        scanf(" %[^\n]",alunos[i].nome);
        alunos[i].nome = (char*) realloc(alunos[i].nome,(strlen(alunos[i].nome)+1)*sizeof(char));
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
    for(i=0;i<N;i++)free(cursos[i].nome);
    for(i=0;i<M;i++)free(alunos[i].nome);
    free(alunos); 
    free(cursos);
    return 0;
}