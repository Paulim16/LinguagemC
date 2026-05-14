#include <stdio.h>
#include <stdlib.h>

typedef struct{
    long long int ind;
    int val;
} mat_spr;

void insere( mat_spr *M, long long int i, int *n, int v );
void consul( mat_spr *M, long long int i, int n, int *v );
int lugar( mat_spr *M, long long int i, int n );
void compacta( mat_spr *M, long long int i, int *n );
void atrib( mat_spr *M,long long int i,int *n,int v );

int main(){
    int Q, j, k;
    long long int i;
    char a;
    int x;
    scanf("%d",&Q);
    int t = 0;
    mat_spr *M = (mat_spr*)calloc(Q,sizeof(mat_spr));
    
    for(k=0;k<Q;k++){

        scanf(" %c",&a);

        if(a == 'A'){
            scanf(" %lld %d",&i,&x);
            atrib(M, i, &t, x);
        }
        else if(a == 'C'){
            scanf(" %lld",&i);
            consul(M, i,t, &x);
            printf("%d\n", x);
        }
    }
    free(M);

    return 0;
}

void insere( mat_spr *M, long long int i, int *n, int v ){
    int j = 0, k = 0;

    while ( j < *n && M[j].ind < i )
        j++;

    for ( k = *n; k > j; k-- )
        M[k] = M[k - 1];

    M[j].ind = i;
    M[j].val = v;
    (*n)++;
    

}

void consul( mat_spr *M, long long int i, int n, int *v ){
    int j = 0;

    if ( i < 0 )
    {
        printf( "Indice %lld \n invalido!!!", i );
        exit( EXIT_FAILURE );
    }

    j = lugar( M, i, n );
    if ( j == -1 )
        *v = 0;
    else
        *v = M[j].val; 
}

int lugar( mat_spr *M, long long int i, int n ){
    int esq = 0, dir = n - 1;

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        
        if (M[meio].ind == i) 
            return meio;
        else if (M[meio].ind < i) 
            esq = meio + 1;
        else 
            dir = meio - 1;
    }
    return -1;
}

void compacta( mat_spr *M, long long int i, int *n ){
    int j = 0;

    for ( j = i; j < (*n)-1; j++ )
        M[j] = M[j + 1];
    M[(*n)-1] = (mat_spr){-1, 0};
    (*n)--;
}
void atrib( mat_spr *M, long long int i,int *n,int v ){
    int j = 0;

    if ( i < 0 ){
        printf( "Indice %lld \n invalido!!!", i );
        exit( EXIT_FAILURE );
    }

    j = lugar( M, i, *n );
    if ( j == -1 ){
        if ( v != 0 ){
            insere( M, i, n, v );
        }
    }
    else{
        if ( v == 0 ){
            compacta( M, j, n );
        }
        else{
            M[j].val = v;
        }
    }
}

