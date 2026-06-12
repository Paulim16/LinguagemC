#include <stdio.h>
#include <stdlib.h>

#define MAX 200005

int contador[MAX] = {0};

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        contador[num]++;
    }

    int primeiro = 1;
    for (int i = 0; i < MAX; i++) {
        while (contador[i] > 0) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", i);
            primeiro = 0;
            contador[i]--;
        }
    }
    printf("\n");

    return 0;
}