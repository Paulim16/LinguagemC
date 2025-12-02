#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[200];
    int matricula, dia, mes, ano;
} Aluno;

int ComparaDataNasc(Aluno A, Aluno B){
    if (A.ano > B.ano) return 1;
    else if(A.ano == B.ano){
        if(A.mes>B.mes) return 1;
        else if(A.mes==B.mes){
            if(A.dia>B.dia || A.dia==B.dia)return 1;
            else return 0;
        }
        else return 0;
    }
    else return 0;
}

void Ordena(Aluno * A, int N){
    int i,j;
    Aluno temp;
    for(i = 0; i < N; i++){
        for(j=0;j<N-i-1;j++){
            if(ComparaDataNasc(A[j],A[j+1])==0) {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int i,N,M;
    float mensalidade;
    scanf("%d",&N);

    Aluno * alunos = NULL;
    alunos = (Aluno *) malloc(N*sizeof(Aluno));

    for (i=0;i<N;i++){
        scanf("%d",&alunos[i].matricula);
        scanf("%d",&alunos[i].dia);
        scanf("%d",&alunos[i].mes);
        scanf("%d",&alunos[i].ano); 
        scanf(" %[^\n]",alunos[i].nome);
    }
    
    Ordena(alunos,N);
    for (i=0;i<N;i++){

        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n",
                alunos[i].matricula,
                alunos[i].nome,
                alunos[i].dia,
                alunos[i].mes,
                alunos[i].ano);
    }
    
     
    free(alunos);
    return 0;
}