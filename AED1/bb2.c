#include <stdio.h>
#include <stdlib.h>

int saddleback(int **matriz, int N, int x) {
    int linha = 0;
    int coluna = N - 1;

    while (linha<N&&coluna>=0) {
        if (matriz[linha][coluna]==x) return 1;
        
        else if (matriz[linha][coluna]>x) coluna--;
        
        else linha++;
        
    }
    return 0;
}

int main() {
    int N, Q;

    scanf("%d %d", &N, &Q);

    int **matriz = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matriz[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < Q; i++) {
        int consulta;
        scanf("%d", &consulta);
        if (saddleback(matriz, N, consulta)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    for (int i = 0; i < N; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}