#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
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

void inserir(Fila *f, int x) {
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

int remover(Fila *f) {
    if (f->size == 0) {
        return -1;
    }

    No *temp = f->front;
    int valorRemovido = temp->valor;

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


void empilhar(Fila *f, int x) {
    int tam_antigo = f->size;

    inserir(f, x);

    for (int i = 0; i < tam_antigo; i++) {
        int elemento = remover(f);
        inserir(f, elemento);
    }
}

int topo(Fila *f) {
    if (f->size == 0) {
        return -1;
    }
    return f->front->valor;
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0; 
    Fila f;
    inicializar(&f);

    char comando;
    int x;


    for (int i = 0; i < q; i++) {
        scanf(" %c", &comando); 

        if (comando == 'P') { 
            scanf("%d", &x);
            empilhar(&f, x);
        } 
        else if (comando == 'O') { 
            printf("%d\n", remover(&f));
        } 
        else if (comando == 'T') { 
            printf("%d\n", topo(&f));
        } 
        else if (comando == 'S') { 
            printf("%d\n", f.size);
        } 
        else if (comando == 'C') { 
            limpar(&f);
        }
    }

    limpar(&f);
    return 0;
}