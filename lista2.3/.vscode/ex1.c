#include <stdio.h>
 
 
int main(void){
    float matriz[2][2],determinante;
    int i = 0, z = 0;
 
    for(i=0;i<2;i++){
        for(z=0;z<2;z++)scanf("%f", &matriz[i][z]);
    }
    determinante = (matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]); 
    printf("%.2f\n",determinante);
 
 
    return 0;
}