#include <stdio.h>
int main(){
 
    int dia, mes, ano, data, aux22,aux11;
    
 
    scanf("%d", &data);
    if(data>31129999 || data<100000){
      printf("Data invalida!\n");
        return 0;
    }
    
    dia = data/1000000.0;
    mes = (data / 10000) % 100;
    ano = data % 10000;
 
    if(mes>12){
        printf("Data invalida!\n");
        return 0;
    }
    else if (mes==1 ||mes==3 ||mes==5 ||mes==7 ||mes==8 ||mes==10 ||mes==12){
        if(dia>31 || dia<1){
            printf("Data invalida!\n");
            return 0;
        }
    }
    else if (mes==2 ||mes==4 ||mes==6 ||mes==9 ||mes==11){
        if(mes ==2 && dia>28){
            printf("Data invalida!\n");
            return 0;     
        }
        else if(dia>30 || dia<1){
            printf("Data invalida!\n");
            return 0;
        }       
    }
    
    if (mes == 1){
        printf("%d de janeiro de %d\n",dia, ano);
    }   
    else if (mes == 2){
        printf("%d de fevereiro de %d\n",dia, ano);
    }   
    else if (mes == 3){
        printf("%d de marco de %d\n",dia, ano);
    }   
    else if (mes == 4){
        printf("%d de abril de %d\n",dia, ano);
    }   
    else if (mes == 5){
        printf("%d de maio de %d\n",dia ,ano);
    }   
    else if (mes == 6){
        printf("%d de junho de %d\n",dia ,ano);
    }   
    else if (mes == 7){
        printf("%d de julho de %d\n",dia ,ano);
    }   
    else if (mes == 8){
        printf("%d de agosto de %d\n",dia ,ano);
    }   
    else if (mes == 9){
        printf("%d de setembro de %d\n",dia, ano);
    }   
    if (mes == 10){
        printf("%d de outubro de %d\n",dia ,ano);
    }   
    else if (mes == 11){
        printf("%d de novembro de %d\n",dia, ano);
    }   
    else if (mes == 12){
        printf("%d de dezembro de %d\n",dia, ano);
    }
 
    return 0;
}