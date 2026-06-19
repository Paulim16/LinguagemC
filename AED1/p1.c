#include <stdio.h>
#include <stdlib.h>

void inserir(int *pilha, int *topo, int x) {
    (*topo)++;
    pilha[*topo] = x;
}

void remover(int *pilha, int *topo) {
    if (*topo > -1) {
        printf("%d\n", pilha[*topo]);
        (*topo)--;
    } else {
        printf("-1\n");
    }
}

void imprimir_topo(int *pilha, int topo) {
    if (topo > -1) {
        printf("%d\n", pilha[topo]);
    } else {
        printf("-1\n");
    }
}

void limpar(int *topo) {
    *topo = -1;
}

void imprimir(int *pilha, int topo) {
    if (topo > -1) {
        for (int i = topo; i >= 0; i--) {
            printf("%d", pilha[i]);
            if (i != 0) {
                printf(" ");
            }
        }
        printf("\n");
    } else {
        printf("\n");
    }
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;
    
    int *pilha = (int*)malloc(200005 * sizeof(int));
    int topo_idx = -1;
    char comando;
    int x;

    for (int i = 0; i < q; i++) {
        scanf(" %c", &comando);

        if (comando == 'I') {
            scanf("%d", &x);
            inserir(pilha, &topo_idx, x);
        } else if (comando == 'R') {
            remover(pilha, &topo_idx);
        } else if (comando == 'T') {
            imprimir_topo(pilha, topo_idx);
        } else if (comando == 'S') {
            printf("%d\n", topo_idx + 1);
        } else if (comando == 'C') {
            limpar(&topo_idx);
        } else if (comando == 'P') {
            imprimir(pilha, topo_idx);
        }
    }

    free(pilha);
    return 0;
}