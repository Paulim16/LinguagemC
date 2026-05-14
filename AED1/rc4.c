#include <stdio.h>

int N;
int total = 0;

void calcula_particoes(int resto, int max) {
    if (resto == 0) {
        total++;
        return;
    }

    for (int i = max; i >= 1; i--) {
        if (resto - i >= 0) {
            calcula_particoes(resto - i, i);
        }
    }
}

int main() {
    if (scanf("%d", &N) != 1) return 1;

    calcula_particoes(N, N);

    printf("%d\n", total);

    return 0;
}