#include <stdio.h>
 
void leitor(int *A,  char *B){
    scanf("%d %[^\n]", A, B);
}
 
int main(void){
    int A,i,N,z;
    char B[500],lido[500];
 
    scanf("%d", &N);
 
    for(i=0;i<N;i++){
 
        leitor(&A,B);
        for(z=0;z<A;z++){
            if(B[z]=='\0') break;
            printf("%c", B[z]);
        }
        printf("\n");
    }
}