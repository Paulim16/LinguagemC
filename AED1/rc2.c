#include <stdio.h>

int n;
int permutacao_atual[10];
int tamanho = 0;
int usado[10]; 

void permuta() {
    
    if (tamanho == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", permutacao_atual[i]);
            if (i == n - 1) {
                printf("\n");
                return;
            }
            printf(" ");
        }
        
    }

    for (int i = 1; i <= n; i++) {
        if (usado[i] == 0) {
            
            usado[i] = 1; 
            permutacao_atual[tamanho] = i; 
            tamanho++; 

            // Recursividade
            permuta();

            // Da backtrack pra tentar outra permutação no número antes
            tamanho--; 
            usado[i] = 0; // libera o numero pra usar nesse backtrack
        }
    }
}

int main() {
    int i;
    scanf("%d", &n);
    for(i = 0; i <= n; i++) {
        usado[i] = 0;
    }

    permuta();

    return 0;
}