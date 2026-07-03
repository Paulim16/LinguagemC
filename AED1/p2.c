#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

void push(No** topo, int x) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = x;
    novo->proximo = *topo;
    *topo = novo;
}

int pop(No** topo) {
    No* temp = *topo;
    int val = temp->valor;
    *topo = (*topo)->proximo;
    free(temp);
    return val;
}

void limpar(No** topo) {
    while (*topo != NULL) {
        pop(topo);
    }
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    No* pilha_in = NULL;
    No* pilha_out = NULL;
    int tam_in = 0;
    int tam_out = 0;

    char comando;
    int x;

    for (int i = 0; i < q; i++) {
        scanf(" %c", &comando);

        if (comando == 'I') {
            scanf("%d", &x);
            push(&pilha_in, x);
            tam_in++;
        }
        else if (comando == 'R' || comando == 'F') {
            if (pilha_out == NULL) {
                while (pilha_in != NULL) {
                    push(&pilha_out, pop(&pilha_in));
                    tam_in--;
                    tam_out++;
                }
            }

            if (pilha_out == NULL) {
                printf("-1\n");
            }
            else {
                printf("%d\n", pilha_out->valor);

                if (comando == 'R') {
                    pop(&pilha_out);
                    tam_out--;
                }
            }
        }
        else if (comando == 'S') {
            printf("%d\n", tam_in + tam_out);
        }
        else if (comando == 'C') {
            limpar(&pilha_in);
            limpar(&pilha_out);
            tam_in = 0;
            tam_out = 0;
        }
    }

    limpar(&pilha_in);
    limpar(&pilha_out);
    return 0;
}
