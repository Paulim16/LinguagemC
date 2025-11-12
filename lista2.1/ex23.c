#include <stdio.h>

void dançante(char * string){

    int i,y, flag=0;

    for(i=0;string[i]!='\0';i++){
        if(string[i]!=' '){
            if(string[i]>='a' && string[i]<='z'){
                flag=1;
                break;
            }
            else if(string[i]>='A' && string[i]<='Z'){
                flag=0;
                break;
            }
             
        }
    }
    if(flag==1){

        for(y=i+1;string[y]!='\0';y++){
            if(string[y]!=' '){
                if(flag==1){
                    string[y]+=32;
                    flag = 0;
                }
            }
                if(flag==1){
                    string[y]+=32;
                    flag = 0;
                }
            }
        }
    }
    for(i=0;string[i]!='\0';i++){
        if(string[i]!=' '){
            if(string[i]>='a' && string[i]<='z')flag=1;
            else if(string[i]>='A' && string[i]<='Z')flag=0;
            if 
        }
    }

    
    
}        


int main(){

    char str[257]; // string original
    char clr[257]; // lista de caracteres indesejados
    scanf("%[^\n]%*c", str);
    scanf("%[^\n]%*c", clr);
    str_clean(str, clr);
    printf("%s\n", str);
    return 0;
}