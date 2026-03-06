#include <stdio.h>
#include <stdlib.h>
 
 
int main(){
 
    int n,m,i,z,y,flag;
    scanf("%d",&n);
 
    for(i=0;i<n;i++){
        scanf("%d",&m);
        flag = 0;
        int *num = NULL;
        int *den = NULL;
        num = (int*)malloc(m*sizeof(int));
        den = (int*)malloc(m*sizeof(int));
        for(z=0;z<m;z++){
            scanf("%d/%d",&num[z],&den[z]);
        }
        printf("Caso de teste %d\n",i+1);
        for(z=0;z<m;z++){
            for(y=z+1;y<m;y++){
                if(num[z]*den[y]==num[y]*den[z]){
                    flag++;
                    printf("%d/%d equivalente a %d/%d\n",num[z],den[z],num[y],den[y]);
                }
            }
        }
        if(flag==0)printf("Nao ha fracoes equivalentes na sequencia\n");
        free(num);
        free(den);
    }
 
    return 0;
}