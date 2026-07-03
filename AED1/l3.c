#include <stdio.h>
#include <stdlib.h>

/* Le N valores, guarda numa lista DUPLAMENTE encadeada JA em ordem
   crescente (insercao ordenada) e imprime da esquerda para a direita. */
typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

No* inicio = NULL;
No* fim = NULL;

/* Insere x mantendo a lista ordenada de forma crescente. */
void inserir_ordenado(int x) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = x;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if (inicio == NULL) {              /* lista vazia */
        inicio = fim = novo;
        return;
    }

    /* acha o primeiro no com valor MAIOR que x: novo entra antes dele.
       (<= mantem os iguais na ordem de chegada) */
    No* atual = inicio;
    while (atual != NULL && atual->valor <= x) atual = atual->proximo;

    if (atual == NULL) {               /* x eh o maior -> vai pro fim */
        novo->anterior = fim;
        fim->proximo = novo;
        fim = novo;
    } else if (atual == inicio) {      /* x eh o menor -> vai pra frente */
        novo->proximo = inicio;
        inicio->anterior = novo;
        inicio = novo;
    } else {                           /* meio */
        No* ant = atual->anterior;
        novo->anterior = ant;
        novo->proximo = atual;
        ant->proximo = novo;
        atual->anterior = novo;
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        inserir_ordenado(x);
    }

    No* atual = inicio;
    int primeiro = 1;
    while (atual != NULL) {
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;
        atual = atual->proximo;
    }
    printf("\n");

    while (inicio != NULL) { No* t = inicio; inicio = inicio->proximo; free(t); }
    return 0;
}
