#include <stdio.h>
#include <math.h>

double string2double( const char * str ){

    double div=0,n1=0, n2=0;
    int i;
    int aux=1;
    for(i=0;str[i]!='\0';i++){
        if(str[i]=='.'){
            i++;
            break;
        }
        n1*=10;
        if(str[i]=='-'){
            aux = -1;
        }
        else{
            n1 += str[i]-48;
        }
    }
    if(str[i-1]=='.'){
        for(i=i;str[i]!='\0';i++){
            n2*=10;
            n2 += str[i]-48;
            div++;

        }
    }
    n1*=aux;
    n2*=aux;
    n2/=pow(10,div);
    return n1+n2;
}



int main(void){

    char str[129]/*= "0.5"*/;
    while( scanf("%s%*c", str) != EOF ) { 
        double n = string2double(str);
        printf("%.3lf %.3lf\n", n, n*2); 
    }
    //double n = string2double(str);
    //printf("%.3lf %.3lf\n", n, n*n);
    return 0;
}
