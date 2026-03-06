#include <stdio.h>
int main (){
 
    int mat;
    double NF,p1,p2,p3,p4,p5,p6,p7,p8,l1,l2,l3,l4,l5,NT,pres;
 
    while(mat != -1){
        scanf("%d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &mat,&p1,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&l1,&l2,&l3,&l4,&l5,&NT,&pres);
        NF = (0.7*((p1+p2+p3+p4+p5+p6+p7+p8)/8)) + (0.15*((l1+l2+l3+l4+l5)/5)) + (0.15*NT);
        if (mat != -1){
            if (NF >= 6 && pres/128 >= 0.75){
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: APROVADO\n",mat,NF );
            }
            if (NF >= 6 && pres/128 < 0.75){
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: REPROVADO POR FREQUENCIA\n",mat,NF );
            }
            if (NF < 6 && pres/128 >= 0.75){
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: REPROVADO POR NOTA\n",mat,NF );
            }
            if (NF < 6 && pres/128 < 0.75){
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: REPROVADO POR NOTA E POR FREQUENCIA\n",mat,NF );
            }
        } 
        else{
            break;
        }   
    }
 
    return 0;
}