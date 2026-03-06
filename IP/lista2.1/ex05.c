#include <stdio.h>
#include <string.h>
int main(void){
    int N,i,z,consoante,vogal,letras;
    char frase[10001];
    scanf("%d%*c",&N);
    
    
    for(i=0;i<N;i++){
        fgets(frase,10001,stdin);
        
        consoante=0;
        vogal=0;
        letras=0;
        for(z=0;frase[z]!='\0';z++){
 
            if(frase[z]== 'a'|| frase[z]== 'A') letras++, vogal++;
            else if(frase[z]== 'b'|| frase[z]== 'B') letras++, consoante++;
            else if(frase[z]== 'c'|| frase[z]== 'C') letras++, consoante++;
            else if(frase[z]== 'd'|| frase[z]== 'D') letras++, consoante++;
            else if(frase[z]== 'e'|| frase[z]== 'E') letras++, vogal++;
            else if(frase[z]== 'f'|| frase[z]== 'F') letras++, consoante++;
            else if(frase[z]== 'g'|| frase[z]== 'G') letras++, consoante++;
            else if(frase[z]== 'h'|| frase[z]== 'H') letras++, consoante++;
            else if(frase[z]== 'i'|| frase[z]== 'I') letras++, vogal++;
            else if(frase[z]== 'j'|| frase[z]== 'J') letras++, consoante++;
            else if(frase[z]== 'k'|| frase[z]== 'K') letras++, consoante++;
            else if(frase[z]== 'l'|| frase[z]== 'L') letras++, consoante++;
            else if(frase[z]== 'm'|| frase[z]== 'M') letras++, consoante++;
            else if(frase[z]== 'n'|| frase[z]== 'N') letras++, consoante++;
            else if(frase[z]== 'o'|| frase[z]== 'O') letras++, vogal++;
            else if(frase[z]== 'p'|| frase[z]== 'P') letras++, consoante++;
            else if(frase[z]== 'q'|| frase[z]== 'Q') letras++, consoante++;
            else if(frase[z]== 'r'|| frase[z]== 'R') letras++, consoante++;
            else if(frase[z]== 's'|| frase[z]== 'S') letras++, consoante++;
            else if(frase[z]== 't'|| frase[z]== 'T') letras++, consoante++;
            else if(frase[z]== 'u'|| frase[z]== 'U') letras++, vogal++;
            else if(frase[z]== 'v'|| frase[z]== 'V') letras++, consoante++;
            else if(frase[z]== 'w'|| frase[z]== 'W') letras++, consoante++;
            else if(frase[z]== 'x'|| frase[z]== 'X') letras++, consoante++;
            else if(frase[z]== 'y'|| frase[z]== 'Y') letras++, consoante++;
            else if(frase[z]== 'z'|| frase[z]== 'Z') letras++, consoante++;
 
        }
        printf("Letras = %d\nVogais = %d\nConsoantes = %d\n",letras,vogal,consoante);
    }
    
    
    return 0;
}