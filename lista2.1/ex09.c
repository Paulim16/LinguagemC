#include <stdio.h>
 
int main(void){
    int N,i,z,a,y,k;
    char texto[1001],aux;
    
    scanf("%d",&N);
    getchar();
    if(N<0||N>10000) return 0;
 
    for(y=0;y<N;y++){
        scanf("%[^\n]",texto);
        getchar();
            
        for(i=0;texto[i]!= '\0';i++){
            if(texto[i]>='a'&&texto[i]<='z'||texto[i]>='A'&&texto[i]<='Z'){
                texto[i]+= 3;            
            }
                
        }
        a=i;
        i--;
        for(z=0;z<a/2;z++){
            aux = texto[z];
            texto[z]=texto[i];
            texto[i] = aux;
            i--;
    
        }
         
        for(k=0;k<a;k++){
            if(k>=a/2)texto[k]--;
                  
        }
        printf("%s\n", texto);            
    }
    
    
    return 0;
}