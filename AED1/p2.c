#include <stdio.h>
#include <stdlib.h>

int main() {
    int q;
    scanf("%d", &q);

    int *pilha_in = (int*)malloc(200005 * sizeof(int));
    int *pilha_out = (int*)malloc(200005 * sizeof(int));
    
    int topo_in = -1;
    int topo_out = -1;

    char comando;
    int x;

    for (int i = 0; i < q; i++) {
        scanf(" %c", &comando);

        if (comando == 'I') {
            scanf("%d", &x);
            topo_in++;
            pilha_in[topo_in] = x;
        } 
        else if (comando == 'R' || comando == 'F') {
            if (topo_out == -1) {
                while (topo_in > -1) {
                    topo_out++;
                    pilha_out[topo_out] = pilha_in[topo_in];
                    topo_in--;
                }
            }

            if (topo_out == -1) {
                printf("-1\n");
            } 
            else {
                printf("%d\n", pilha_out[topo_out]);
            
                if (comando == 'R') {
                    topo_out--;
                }
            }
        } 
        else if (comando == 'S') {
            int tamanho_total = (topo_in + 1) + (topo_out + 1);
            printf("%d\n", tamanho_total);
        } 
        else if (comando == 'C') {
            topo_in = -1;
            topo_out = -1;
        }
    }

    free(pilha_in);
    free(pilha_out);
    return 0;
}