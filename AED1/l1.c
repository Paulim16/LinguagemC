#include <stdio.h>
#include <stdlib.h>

/* Lista simplesmente encadeada. Cada no aponta so para o proximo. */
typedef struct No {
    int valor;
    struct No* proximo;
} No;

No* inicio = NULL;   /* cabeca da lista (NULL = vazia) */
int tamanho = 0;

/* I p x -> insere x na posicao p (base zero). Valido: 0 <= p <= tamanho. */
void inserir(int p, int x) {
    if (p < 0 || p > tamanho) { printf("-1\n"); return; }

    No* novo = (No*) malloc(sizeof(No));
    novo->valor = x;

    if (p == 0) {                     /* vira a nova cabeca */
        novo->proximo = inicio;
        inicio = novo;
    } else {                          /* anda ate o no anterior (p-1) */
        No* ant = inicio;
        for (int i = 0; i < p - 1; i++) ant = ant->proximo;
        novo->proximo = ant->proximo; /* costura: novo -> quem estava em p */
        ant->proximo = novo;          /* costura: anterior -> novo */
    }
    tamanho++;
}

/* R p -> remove a posicao p. Valido: 0 <= p <= tamanho-1. */
void remover(int p) {
    if (p < 0 || p > tamanho - 1) { printf("-1\n"); return; }

    No* alvo;
    if (p == 0) {
        alvo = inicio;
        inicio = inicio->proximo;
    } else {
        No* ant = inicio;
        for (int i = 0; i < p - 1; i++) ant = ant->proximo;
        alvo = ant->proximo;
        ant->proximo = alvo->proximo; /* anterior pula por cima do alvo */
    }
    free(alvo);
    tamanho--;
}

/* G p -> imprime o valor da posicao p. */
void get(int p) {
    if (p < 0 || p > tamanho - 1) { printf("-1\n"); return; }
    No* atual = inicio;
    for (int i = 0; i < p; i++) atual = atual->proximo;
    printf("%d\n", atual->valor);
}

/* P -> imprime todos os valores; lista vazia imprime linha em branco. */
void imprimir(void) {
    No* atual = inicio;
    int primeiro = 1;
    while (atual != NULL) {
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;
        atual = atual->proximo;
    }
    printf("\n");
}

int main(void) {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    char cmd;
    int p, x;

    for (int i = 0; i < q; i++) {
        scanf(" %c", &cmd);

        if (cmd == 'I')      { scanf("%d %d", &p, &x); inserir(p, x); }
        else if (cmd == 'R') { scanf("%d", &p);        remover(p);    }
        else if (cmd == 'G') { scanf("%d", &p);        get(p);        }
        else if (cmd == 'T') { printf("%d\n", tamanho);               }
        else if (cmd == 'P') { imprimir();                            }
    }

    while (inicio != NULL) { No* t = inicio; inicio = inicio->proximo; free(t); }
    return 0;
}
