#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0; 
    long long *a = (long long*)malloc(n * sizeof(long long));
    if (a == NULL) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]); 
        int inicio_janela = (i < k) ? 0 : (i - k + 1);
        long long menor = a[i];
        for (int j = inicio_janela; j <= i; j++) {
            if (a[j] < menor) {
                menor = a[j];
            }
        }
        printf("%lld\n", menor);
    }

    free(a); 
    return 0;
}