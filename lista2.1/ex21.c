#include <stdio.h>
#include <string.h>

int main(){
    int N,i,z,maior=0;
    int qntds[26];
    char frase[201];

    scanf("%d", &N);

    for(i=0;i<26;i++)qntds[i] = 0;

    for(i=0;i<N;i++){
        scanf("[^\n]",&frase);
        for(z=0;frase[z]!='\0';z++){

            if (frase[z]>='A' && frase[z]<='Z')frase[z] += 32;
            qntds[(int)frase[z]-97]++;
            if (qntds[(int)frase[z]-97]>maior)maior=qntds[(int)frase[z]-97];     
        }
        for(i=0;i<26;i++){
            if(qntds[i]=maior)printf("%c",(char)(qntds[i]+97));
        }
    }
    return 0;
}