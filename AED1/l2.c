#include <stdio.h>
#include <stdlib.h>

/* Lista DUPLAMENTE encadeada: cada no conhece o proximo E o anterior.
   Guardamos ponteiros para as duas pontas (inicio e fim). */
typedef struct No {
    int valor;
    struct No* proximo;    /* -> */
    struct No* anterior;   /* <- */
} No;

No* inicio = NULL;
No* fim = NULL;
int tamanho = 0;

/* I p x -> insere x na posicao p (base zero). Valido: 0 <= p <= tamanho. */
void inserir(int p, int x) {
    if (p < 0 || p > tamanho) { printf("-1\n"); return; }

    No* novo = (No*) malloc(sizeof(No));
    novo->valor = x;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if (tamanho == 0) {                 /* lista vazia: novo eh a lista toda */
        inicio = fim = novo;
    } else if (p == 0) {                /* insere na frente */
        novo->proximo = inicio;
        inicio->anterior = novo;
        inicio = novo;
    } else if (p == tamanho) {          /* insere no fim */
        novo->anterior = fim;
        fim->proximo = novo;
        fim = novo;
    } else {                            /* meio: insere ANTES do no atual em p */
        No* atual = inicio;
        for (int i = 0; i < p; i++) atual = atual->proximo;
        No* ant = atual->anterior;
        novo->anterior = ant;
        novo->proximo = atual;
        ant->proximo = novo;
        atual->anterior = novo;
    }
    tamanho++;
}

/* R p -> remove a posicao p. Valido: 0 <= p <= tamanho-1. */
void remover(int p) {
    if (p < 0 || p > tamanho - 1) { printf("-1\n"); return; }

    No* alvo = inicio;
    for (int i = 0; i < p; i++) alvo = alvo->proximo;

    if (alvo->anterior) alvo->anterior->proximo = alvo->proximo;
    else                inicio = alvo->proximo;          /* removeu a cabeca */

    if (alvo->proximo)  alvo->proximo->anterior = alvo->anterior;
    else                fim = alvo->anterior;            /* removeu a cauda  */

    free(alvo);
    tamanho--;
}

/* G p -> imprime o valor na posicao p. */
void get(int p) {
    if (p < 0 || p > tamanho - 1) { printf("-1\n"); return; }
    No* atual = inicio;
    for (int i = 0; i < p; i++) atual = atual->proximo;
    printf("%d\n", atual->valor);
}

/* PL -> imprime da esquerda para a direita (seguindo proximo). */
void imprimir_L(void) {
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

/* PR -> imprime da direita para a esquerda (seguindo anterior). */
void imprimir_R(void) {
    No* atual = fim;
    int primeiro = 1;
    while (atual != NULL) {
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;
        atual = atual->anterior;
    }
    printf("\n");
}

int main(void) {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    char cmd[8];
    int p, x;

    for (int i = 0; i < q; i++) {
        scanf("%s", cmd);

        if (cmd[0] == 'I')      { scanf("%d %d", &p, &x); inserir(p, x); }
        else if (cmd[0] == 'R') { scanf("%d", &p);        remover(p);    }
        else if (cmd[0] == 'G') { scanf("%d", &p);        get(p);        }
        else if (cmd[0] == 'T') { printf("%d\n", tamanho);               }
        else if (cmd[0] == 'P') {                          /* PL ou PR */
            if (cmd[1] == 'L') imprimir_L();
            else               imprimir_R();
        }
    }

    while (inicio != NULL) { No* t = inicio; inicio = inicio->proximo; free(t); }
    return 0;
}
