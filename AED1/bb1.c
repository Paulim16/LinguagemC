#include <stdio.h>

int buscaBinaria(int A[], int x, int n) {
    int e = 0;
    int d = n - 1;
    int c;
    
    while (e <= d) {
        c = e + (d - e) / 2;
        
        if (x == A[c]) {
            return 1;
        } else if (x < A[c]) {
            d = c - 1;
        } else {
            e = c + 1;
        }
    }
    return 0;
}

int main() {
    int N, Q;

    if (scanf("%d %d", &N, &Q) != 2) return 0;

    int vetor[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < Q; i++) {
        int consulta;
        scanf("%d", &consulta);
        
        if (buscaBinaria(vetor, consulta, N)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}