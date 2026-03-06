 #include <stdio.h>

void dancante(char * string){

    int i,y, flag=0;

    for(i=0;string[i]!='\0';i++){
        if(string[i]!=' '){
            if(string[i]>='a' && string[i]<='z'){
                flag=1;
            }
            break;
        }
    }
    
    // flag 1 = letra minuscula -> precisa ir para maiuscula
    // flag 0 = letra maiuscula -> precisa ir para minuscula, com excessão da primeira letra
    if(flag==1){

        for(y=i;string[y]!='\0';y++){
            if(string[y]!=' '){
                if(y == i){

                    string[y]-=32;
                    flag = 0;
            
                }

                else if(flag == 1 & (string[y]>='A' && string[y]<='Z')){
                    flag = 0;
                }

                else if(flag == 0 & (string[y]>='a' && string[y]<='z')){
                    flag = 1;
                }

                else if(flag == 0){
                    string[y]+=32;
                    flag = 1;
                }

                else if(flag == 1){
                    string[y]-=32;
                    flag = 0;
                }
            }
        }
    }
    else if (flag==0){

        for(y=i;string[y]!='\0';y++){
            if(string[y]!=' '){

                if(y == i){
                    flag = 0;
                }

                else if(flag == 1 && (string[y]>='A' && string[y]<='Z')){
                    flag = 0;
                }

                else if(flag == 0 && (string[y]>='a' && string[y]<='z')){
                    flag = 1;
                }

                else if(flag == 0){
                    string[y]+=32;
                    flag = 1;
                }

                else if(flag == 1){
                    string[y]-=32;
                    flag = 0;
                }
            }
        }
    }



}        


int main(){

    int i;
    char str[51];

    while(scanf("%[^\n]%*c", str) != EOF){ 
        dancante(str);
        for(i=0;str[i]!='\0';i++) printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}