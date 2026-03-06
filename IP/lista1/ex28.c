#include <stdio.h>
 
int main(){
    int n1,n2,n3,maior,menor,meio;
    char x,y,z;
 
    scanf("%d %d %d",&n1,&n2,&n3);
    maior = n1;
    meio = n1;
    menor = n1;
    if(n2>=maior){
        maior = n2;
    }
    if(n3>=maior){
        maior = n3;
    }
    if(n2<=menor){
        menor = n2;
    }
    if(n3<=menor){
        menor = n3;
    }
    if (n2>menor && n2<maior ){
        meio = n2;
    }
    if (n3>menor && n3<maior ){
        meio = n3;
    }
    scanf("%*c%c%c%c",&x,&y,&z);
    if(x=='A' && y =='B' && z=='C'){
      printf("%d %d %d\n",menor,meio,maior);  
    }
    if(x=='A' && y=='C' && z=='B'){
        printf("%d %d %d\n",menor,maior,meio); 
    }
    if(x=='B' && y=='A' && z=='C'){
        printf("%d %d %d\n",meio,menor,maior);
    }
    if(x=='B' && y=='C' && z=='A'){
        printf("%d %d %d\n",meio,maior,menor);
    }
    if(x=='C' && y=='B' && z=='A'){
        printf("%d %d %d\n",maior,meio,menor);
    }
    if(x=='C' && y=='A' && z=='B'){
        printf("%d %d %d\n",maior,menor,meio); 
    } 
    
    return 0;
}