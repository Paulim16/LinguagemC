#include <stdio.h>
 
int main(void){
    int qnt,y,oper,i;
    char A[10001],B[10001];
    
    scanf("%d%*c",&qnt);
    
    while(qnt--){
        scanf("%s %s",A,B);
        oper = 0;
        for(y=0;B[y]!='\0';y++){
            while(A[y]!=B[y]){
                if(A[y]=='z'){
                    A[y]='a';
                    oper++;
                }
                else{
                    A[y]++;
                    oper++;
                }
            }
        }
        printf("%d\n",oper);
         
    }
    return 0;
}