#include <stdio.h>
#include <string.h>

int main(){
    int N,i,z,maior;
    int qntds[26];
    char frase[201];

    scanf("%d%*c", &N);

    for(i=0;i<N;i++){
        maior=0;
        for(z=0;z<26;z++) qntds[z] = 0;
        scanf("%[^\n]%*c",frase);
        for(z=0;frase[z]!='\0';z++){

            if(frase[z]>='A' && frase[z]<='Z')frase[z] += 32;
            if(frase[z]>='a' && frase[z]<='z') {
                qntds[(int)frase[z]-97]++;
                if (qntds[(int)frase[z]-97]>maior)maior=qntds[(int)frase[z]-97];     
            }
            }
        for(z=0;z<26;z++){
            if(qntds[z]==maior)printf("%c",(char)(z+97));
        }
        printf("\n");
    }
    return 0;
}