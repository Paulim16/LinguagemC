#include <stdio.h>
 
int main(void){
    int N,i,z,t,h,r,e,o,n,w;
    char palavra[10];
    scanf("%d",&N);
    if(N<1||N>1000) return 0;
    for(i=0;i<N;i++){
        t=0;
        h=0;
        r=0;
        e=0;
        o=0;
        n=0;
        w=0;
        scanf("%s",palavra);
        for(z=0;palavra[z]!='\0';z++){
            if(palavra[z] == 't')t++;
            else if(palavra[z] == 'h')h++;
            else if(palavra[z] == 'r')r++;
            else if(palavra[z] == 'e')e++;
            else if(palavra[z] == 'o')o++;
            else if(palavra[z] == 'n')n++;
            else if(palavra[z] == 'w')w++;
 
        }
        if((o>=1 && e >=1||n>=1 && e >=1||o>=1 && n >=1)&&(palavra[0] == 'o' && palavra[2] == 'e' ||palavra[1] == 'n' && palavra[2] == 'e' ||palavra[0] == 'o' && palavra[1] == 'n')){
            printf("1\n");
        }
        else if((o>=1 && w>=1||t>=1 && w>=1||o>=1 && t>=1)&&(palavra[0] == 't' && palavra[2] == 'o' ||palavra[1] == 'w' && palavra[2] == 'o' ||palavra[0] == 't' && palavra[1] == 'w')){
            printf("2\n");
        }
        else if((t>=1 && h>=1 && r >= 1 && e >= 1||t>=1 && h>=1 && e >= 2||h>=1 && r>=1 && e >= 2 || t>=1 && r>=1 && e >= 2)&&(palavra[0] == 't' && palavra[1] == 'h' && palavra[2] == 'r' && (palavra[3] == 'e' ||palavra[4] == 'e')) || (palavra[1] == 'h' && palavra[2] == 'r' && (palavra[3] == 'e' ||palavra[4] == 'e')) || (palavra[0] == 't' && palavra[2] == 'r' && (palavra[3] == 'e' || palavra[4] == 'e'))|| (palavra[1] == 'h' && palavra[0] == 't' && (palavra[3] == 'e' ||palavra[4] == 'e'))){
            printf("3\n");
        }
        
 
    }
    
    
    return 0;
}