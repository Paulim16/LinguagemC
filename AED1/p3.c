#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int prioridade(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);

    char exp[1005];
    char pilha[1005];

    for (int i = 0; i < t; i++) {

        scanf(" %[^\n]", exp);

        int valido = 1;
        int cont_parenteses = 0;
        
        for (int j = 0; exp[j] != '\0'; j++) {
            if (exp[j] == '(') cont_parenteses++;
            else if (exp[j] == ')') cont_parenteses--;
            
            if (cont_parenteses < 0) {
                valido = 0;
                break;
            }
        }
        if (cont_parenteses != 0) valido = 0;

        if (!valido) {
            printf("Expressao invalida\n\n");
            continue; 
        }

        int topo = -1;

        for (int j = 0; exp[j] != '\0'; j++) {
            char c = exp[j];

            if (c == ' ' || c == '\n' || c == '\r') continue;

            if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                printf("%c", c);
            }
            else if (c == '(') {
                topo++;
                pilha[topo] = c;
            }
            else if (c == ')') {
                while (topo != -1 && pilha[topo] != '(') {
                    printf("%c", pilha[topo]);
                    topo--;
                }
                if (topo != -1) topo--;
            }
            else {
                while (topo != -1 && prioridade(pilha[topo]) >= prioridade(c)) {
                    printf("%c", pilha[topo]);
                    topo--;
                }
                topo++;
                pilha[topo] = c;
            }
        }
        while (topo != -1) {
            printf("%c", pilha[topo]);
            topo--;
        }
        printf("\n");
    }

    return 0;
}