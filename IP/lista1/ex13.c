#include <stdio.h>
int main()
{
    int num,np = -1,ni = 0;
    double par, impar, mp, mi;
    
    scanf("%d", &num);
    if (num != 0){
        if (num % 2 == 0){
            par += num;
            np++;
        }
        else{
            impar += num;
            ni++;
        }
        
        while(num!=0){
            scanf("%d", &num);
            if (num % 2 == 0){
                par += num;
                np++;
            }
            else{
                impar += num;
                ni++;
            }
        }
    }
    if (np == 0){
        mp = 0.0;
        mi = impar / ni;
    }
    else if (ni == 0){
        mi == 0.0;
        mp = par / np;
    }
    else if( np==0 && ni==0){
        mi = 0.0;
        mp = 0.0;
    }
    else{
        mp = par / np;
        mi = impar / ni;
    }
    printf("MEDIA PAR: %lf\n", mp);
    printf("MEDIA IMPAR: %lf\n", mi);
    
    return 0;
}