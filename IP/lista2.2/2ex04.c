#include <stdio.h>\
 
int somaDivisores(int x, int *A, char *B, int *y){
 
    int i,z=0, soma=0;
    for(i=1;i<=x/2;i++) {
        if (x % i == 0){
            soma += i;
            *(A+z) = i;
            z++;           
        }
        *y = z;
        int j = 0;
        char *texto;
        if (soma == x)
            texto = "(NUMERO PERFEITO)";
        else
            texto = "(NUMERO NAO E PERFEITO)";
 
        while (texto[j] != '\0') {
            B[j] = texto[j];
            j++;
        }
        B[j] = '\0';
       
    }
    return soma;
}
 
 
int main() {
    int num,a,k,divisores[1000],y;
    char decisao[25];
    scanf("%d",&num);
    somaDivisores(num,divisores,decisao,&y);
    printf("%d = ", num);
    for (k=0;k<y;k++){
        if(k==y-1){
            printf("%d = %d ",divisores[k],somaDivisores(num,divisores,decisao,&y));
        }
        else printf("%d + ",divisores[k]);
    } 
    printf("%s\n",decisao);
    //printf("\n");
    
    return 0;
} 