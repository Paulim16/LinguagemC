#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int l, int c, int r) {
    int i, j, k;
    int n1 = c - l + 1;
    int n2 = r - c;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = A[l + i];
    for (j = 0; j < n2; j++) R[j] = A[c + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int A[], int l, int r) {
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
    int *A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    mergeSort(A, 0, N - 1);

    for (int i = 0; i < N; i++) printf("%d%c", A[i], (i == N - 1 ? '\n' : ' '));
    free(A);
    return 0;
}