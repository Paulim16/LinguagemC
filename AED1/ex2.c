#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ind;
    float val;
} mat_spr;

void insere( mat_spr *M, int i, int *n, float v );
void consul( mat_spr *M, int i, int n, float *v );
int lugar( mat_spr *M, int i, int n );
void compacta( mat_spr *M, int i, int *n );
void atrib( mat_spr *M,int i,int *n,float v );

int main(){
    int Q, i, j, k;
    char a;
    float x;
    scanf("%d",&Q);
    int t = 0;
    mat_spr *M = (mat_spr*)calloc(Q,sizeof(mat_spr));
    
    for(k=0;k<Q;k++){

        scanf(" %c",&a);

        if(a == 'A'){
            scanf(" %d %f",&i,&x);
            atrib(M, i, &t, x);
        }
        else if(a == 'C'){
            scanf(" %d",&i);
            consul(M, i,t, &x);
            printf("%f\n", x);
        }
    }
    free(M);

    return 0;
}

void insere( mat_spr *M, int i, int *n, float v ){
    int j = 0, k = 0;

    while ( j < *n && M[j].ind < i )
        j++;

    for ( k = *n; k > j; k-- )
        M[k] = M[k - 1];

    M[j].ind = i;
    M[j].val = v;
    (*n)++;
    

}

void consul( mat_spr *M, int i, int n, float *v ){
    int j = 0;

    if ( i < 0 )
    {
        printf( "Indice %d \n invalido!!!", i );
        exit( EXIT_FAILURE );
    }

    j = lugar( M, i, n );
    if ( j == -1 )
        *v = 0.0;
    else
        *v = M[j].val; 
}

int lugar( mat_spr *M, int i, int n ){
           
    int j = 0, pos = -1;

    for ( j = 0; j < n; j++ )
        if ( M[j].ind == i )
            pos = j;

    return pos;
}

void compacta( mat_spr *M, int i, int *n ){
    int j = 0;

    for ( j = i; j < (*n)-1; j++ )
        M[j] = M[j + 1];
    M[(*n)-1] = (mat_spr){-1, 0.0};
    (*n)--;
}
void atrib( mat_spr *M, int i,int *n,float v ){
    int j = 0;

    if ( i < 0 ){
        printf( "Indice %d \n invalido!!!", i );
        exit( EXIT_FAILURE );
    }

    j = lugar( M, i, *n );
    if ( j == -1 ){
        if ( v != 0.0 ){
            insere( M, i, n, v );
        }
    }
    else{
        if ( v == 0.0 ){
            compacta( M, j, n );
        }
        else{
            M[j].val = v;
        }
    }
}

