#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float c;
    int e;
} Poly;

int main(){
    int N, i, z, k, j, flag;
    char op;
    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf(" %c", &op);
        if(op == '+') flag = 1;
        else flag = -1;
        
        int n1;
        scanf("%d", &n1);
        
        Poly * poly1 = (Poly *)calloc(n1, sizeof(Poly));
        int maior = -1;
        
        for(z=0; z<n1; z++){
            scanf("%f %d", &poly1[z].c, &poly1[z].e);
            if (poly1[z].e > maior) maior = poly1[z].e;
        }

        int n2;
        scanf("%d", &n2);
        Poly * poly2 = (Poly *)calloc(n2, sizeof(Poly));

        for(z=0; z<n2; z++){
            scanf("%f %d", &poly2[z].c, &poly2[z].e);
            if (poly2[z].e > maior) maior = poly2[z].e;
        }
        
        Poly * poly3 = NULL;
        int y = 0; 

        for(z=maior; z>=0; z--){
            float soma_temp = 0;
            int existe = 0;

            for(k=0; k<n1; k++){
                if(poly1[k].e == z){
                    soma_temp += poly1[k].c;
                    existe = 1;
                }
            }

            for(j=0; j<n2; j++){
                if(poly2[j].e == z){
                    soma_temp += (poly2[j].c * flag);
                    existe = 1;
                }
            }

            if(existe && soma_temp != 0){
                y++;
                poly3 = (Poly *)realloc(poly3, y * sizeof(Poly));
                poly3[y-1].c = soma_temp;
                poly3[y-1].e = z;
            }
        }

        for(z=0; z<y; z++){
            float valor = poly3[z].c;
            int expoente = poly3[z].e;

            if(z == 0) {
                if(valor < 0) printf("-");
            } else {
                if(valor >= 0) printf("+");
                else printf("-");
            }

            if(valor < 0) valor = -valor;
            printf("%.2f", valor);

            if(expoente != 0) {
                printf("X ^%d", expoente);
            }
        }
        printf("\n");

        free(poly1);
        free(poly2);
        free(poly3);
    }

    return 0;
}
