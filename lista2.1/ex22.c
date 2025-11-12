#include <stdio.h>

void str_clean(char * string, char * letters){

    int flag,i,y=0,z;
    for(i=0;string[i]!='\0';i++){
        flag = 0;
        for(z=0;letters[z]!='\0';z++){
            if (letters[z] == string[i])flag++;
        }
        if(flag==0) {
            string[y]=string[i];
            y++;            
        }
    }
    string[y] = '\0';
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