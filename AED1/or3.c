#include <stdio.h>
#include <stdlib.h>

long long int merge(int A[], int l, int c, int r) {
    int i, j, k;
    int n1 = c - l + 1;
    int n2 = r - c;
    long long int inversoes = 0;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = A[l + i];
    for (j = 0; j < n2; j++) R[j] = A[c + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
            inversoes += (n1 - i); 
        }
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];

    free(L);
    free(R);

    return inversoes;
}

long long int mergeSort(int A[], int l, int r) {
    long long int inversoes = 0;
    if (l < r) {
        int c = l + (r - l) / 2;
        inversoes += mergeSort(A, l, c);
        inversoes += mergeSort(A, c + 1, r);
        inversoes += merge(A, l, c, r);
    }
    return inversoes;
}

int main() {
    int N;
    scanf("%d", &N);

    int *A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    long long int resultado = mergeSort(A, 0, N - 1);

    printf("%lld\n", resultado);

    free(A);
    return 0;
}