#include <stdio.h>
 
int igual(char a, char b){
    if(a>='a' && a<='z' ){
        if ( a == b || a == b+32){
            return 1;
        } 
        else return 0;
    }
    else if(a>='A' && a<='Z'){
 
        if ( a == b || a == b-32) {
            return 1;
        }
        else return 0;
    }
    else{
        if(a == b) return 1;
        else return 0;
    }
    return 0;
 
}
 
int main(void){
    int parada=0,y,maior,z,alit=0,i,seq=0;
    char teste[100001],inicio;
 
    while((scanf("%[^\n]%*c", teste)) != EOF){
    //for (y=0;parada!=1;y++){
      //  if(scanf("%[^\n]",teste)==EOF) parada = 1;
        alit = 0;
        seq = 0;
        for(i=0;teste[i]!='\0';i++){
 
            if (i==0) inicio = teste[0];
            else{
                if(teste[i]==' '){
                    i++;
                    if(seq==0){
                        if(igual(inicio,teste[i]) == 1){
                            alit++;
                            seq++;
                        }
                        else{
                            seq = 0;
                            inicio = teste[i];  
                        }
                    }
                    else{
                        if(igual(inicio,teste[i]) == 0){
                            inicio = teste[i];
                            seq=0;
                        }
                    }
 
                }
   
            }
        }
    
        printf("%d\n",alit);
    }
    
    return 0;
}