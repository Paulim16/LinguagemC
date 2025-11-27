#include <stdio.h>
#include <string.h>

int main(void) {
    char str[2049];
    char str_copia[2049]; 
    char palavras[2049][500];
    int rep[2049] = {0};
    int totalUnicas = 0;
    int i, k;

    scanf("%[^\n]", str);
    strcpy(str_copia, str); 

    const char *delimitadores = " .,!?()[]{}";
    
    char *palavraAtual = strtok(str, delimitadores);
    
    while (palavraAtual != NULL) {
        int encontrou = 0;
        for (i = 0; i < totalUnicas; i++) {
            if (strcmp(palavraAtual, palavras[i]) == 0) {
                rep[i]++;
                encontrou = 1;
                break;
            }
        }
        
        if (encontrou == 0) {
            strcpy(palavras[totalUnicas], palavraAtual);
            rep[totalUnicas] = 1;
            totalUnicas++;
        }
        palavraAtual = strtok(NULL, delimitadores);
    }

    palavraAtual = strtok(str_copia, delimitadores);

    while (palavraAtual != NULL) {
        for (k = 0; k < totalUnicas; k++) {
            if (strcmp(palavraAtual, palavras[k]) == 0) {
                printf("(%s)%d\n", palavras[k], rep[k]);
                break;
            }
        }
        palavraAtual = strtok(NULL, delimitadores);
    }

    return 0;
}