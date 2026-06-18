#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    long long valor; 
    struct No *proximo;
} No;

typedef struct Fila {
    No *front;
    No *back;
    int size;
} Fila;

void inicializar(Fila *f) {
    f->front = NULL;
    f->back = NULL;
    f->size = 0;
}

void inserir(Fila *f, long long x) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = x;
    novoNo->proximo = NULL;

    if (f->size == 0) {
        f->front = novoNo;
        f->back = novoNo;
    } else {
        f->back->proximo = novoNo;
        f->back = novoNo;
    }
    f->size++;
}

long long remover(Fila *f) {
    if (f->size == 0) {
        return 0; // Mudei para 0 para não interferir na soma caso dê algum bug
    }

    No *temp = f->front;
    long long valorRemovido = temp->valor;

    f->front = f->front->proximo;
    free(temp);
    f->size--;

    if (f->size == 0) {
        f->back = NULL;
    }

    return valorRemovido;
}

void limpar(Fila *f) {
    No *atual = f->front;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    f->front = NULL;
    f->back = NULL;
    f->size = 0;
}

int main() {
    int n, k;

    if (scanf("%d %d", &n, &k) != 2) return 0;

    Fila f;
    inicializar(&f);

    long long numero_atual;
    long long soma_atual = 0; 
    for (int i = 0; i < n; i++) {
        scanf("%lld", &numero_atual); 
        
        
        inserir(&f, numero_atual);
        soma_atual += numero_atual;

        if (f.size > k) {
            long long valor_velho = remover(&f);
            soma_atual -= valor_velho;
        }

        printf("%lld\n", soma_atual); 
    }

    limpar(&f);
    return 0;
}