#include <stdio.h>
#include <stdlib.h>

long long int contarPedacos(long long int A[], int N, long long int L) {
    long long int pedacos = 0;
    for (int i = 0; i < N; i++) {
        pedacos += A[i] / L;
    }
    return pedacos;
}

int main() {
    int N;
    long long int P;
    scanf("%d %lld", &N, &P);

    long long int *A = (long long int*)malloc(N * sizeof(long long int));
    long long int maior_cabo = 0;

    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        if (A[i] > maior_cabo) {
            maior_cabo = A[i];
        }
    }

    long long int baixo = 1;
    long long int alto = maior_cabo;
    long long int resultado = 0;

    while (baixo <= alto) {
        long long int meio = baixo + (alto - baixo) / 2;

        if (contarPedacos(A, N, meio) >= P) {
            resultado = meio;
            baixo = meio + 1;
        } else {
            alto = meio - 1;
        }
    }

    printf("%lld\n", resultado);

    free(A);
    return 0;
}