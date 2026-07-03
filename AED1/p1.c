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

void imprimir(No* topo) {
    if (topo == NULL) {
        printf("\n");
        return;
    }
    
    No* atual = topo;
    int primeiro = 1;
    
    while (atual != NULL) {
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    No* pilha = NULL;
    int tamanho = 0;

    char comando;
    int x;

    for (int i = 0; i < q; i++) {
        scanf(" %c", &comando);

        if (comando == 'I') {
            scanf("%d", &x);
            push(&pilha, x);
            tamanho++;
        } 
        else if (comando == 'R') {
            if (pilha == NULL) {
                printf("-1\n");
            } else {
                printf("%d\n", pop(&pilha));
                tamanho--;
            }
        } 
        else if (comando == 'T') {
            if (pilha == NULL) {
                printf("-1\n");
            } else {
                printf("%d\n", pilha->valor);
            }
        } 
        else if (comando == 'S') {
            printf("%d\n", tamanho);
        } 
        else if (comando == 'C') {
            limpar(&pilha);
            tamanho = 0;
        } 
        else if (comando == 'P') {
            imprimir(pilha);
        }
    }

    limpar(&pilha);

    return 0;
}