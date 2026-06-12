#include <stdio.h>
#include <stdlib.h>

void merge(long long int A[], int l, int c, int r) {
    int i, j, k;
    int n1 = c - l + 1;
    int n2 = r - c;
    
    long long int *L = (long long int*)malloc(n1 * sizeof(long long int));
    long long int *R = (long long int*)malloc(n2 * sizeof(long long int));

    for (i = 0; i < n1; i++) L[i] = A[l + i];
    for (j = 0; j < n2; j++) R[j] = A[c + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(long long int A[], int l, int r) {
    if (l < r) {
        int c = l + (r - l) / 2;
        mergeSort(A, l, c);
        mergeSort(A, c + 1, r);
        merge(A, l, c, r);
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    long long int *A = (long long int*)malloc(N * sizeof(long long int));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    mergeSort(A, 0, N - 1);

    long long int x = A[N / 2];
    long long int soma_distancias = 0;

    for (int i = 0; i < N; i++) {
        long long int diferenca = x - A[i];
        if (diferenca < 0) {
            diferenca = -diferenca;
        }
        soma_distancias += diferenca;
    }

    printf("%lld\n", soma_distancias);

    free(A);
    return 0;
}