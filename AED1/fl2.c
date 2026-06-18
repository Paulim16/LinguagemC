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

int olharFrente(Fila *f) {
    if (f->size == 0) {
        return -1;
    }
    return f->front->valor;
}

int olharFim(Fila *f) {
    if (f->size == 0) {
        return -1;
    }
    return f->back->valor;
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

void imprimir(Fila *f) {
    if (f->size == 0) {
        printf("\n");
        return;
    }

    No *atual = f->front;
    int aux = 1;
    while (atual != NULL) {
        if (aux == 0) {
            printf(" ");
        }
        printf("%d", atual->valor);
        aux = 0;
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    int k, n, i;
    scanf("%d %d", &n, &k);

    Fila f;
    inicializar(&f);
    for(i=1; i<=n ; i++){
        inserir(&f, i);
    }

    while(f.size > 1){
        int voltas = (k -1) % f.size;
        for (i = 0; i < voltas; i++){
            No *temp = f.front;
            int pessoa = remover(&f); 
            inserir(&f, pessoa);
           
        }
        printf("%d", f.front->valor);
        remover(&f);
        if (f.size != 1)printf(" ");
    }
    if(n !=1) printf("\n");
    printf("%d\n", f.front->valor);
    limpar(&f);
    return 0;
    
}