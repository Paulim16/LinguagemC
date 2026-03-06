#include <stdio.h>
 
int indice(char *A,  char *B){
    scanf("%*c%c %[^\n]", A, B);\
    int i;
    for(i=0;B[i]!='\0';i++){
        if (*A == B[i]) return i;
        
    }   
    return -1; 
}
 
int main(void){
    int N,z,ind;
    char A, B[500],lido[500];
 
    scanf("%d", &N);
 
    for(z=0;z<N;z++){
 
        ind = indice(&A,B);
        if (ind == -1){
            printf("Caractere %c nao encontrado.\n", A);
        }
        else{
            printf("Caractere %c encontrado no indice %d da string.\n", A,ind);
        }
    }
  
    return 0;
}