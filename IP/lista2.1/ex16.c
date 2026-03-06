#include <stdio.h>
 
int main(void){
    int ta=0,tb=0,a[101],b[101],z,i,tam=0,sub[101],flag=1,aux=1;
    while(ta<1 || ta>100) scanf("%d",&ta);
    //printf("ta:%d\n",ta);
    while(tb<1 || tb>100) scanf("%d",&tb);
    //printf("tb:%d\n",tb);
 
    for(z=0;z<ta;z++){
        flag = 1;
        aux = 1;
        while(flag != 0){
            scanf("%d",&a[z]);
            for(i=0;i<z;i++){ 
                if(a[z]==a[i])flag++;
            }
            if(flag == aux) flag = 0;
            else aux = flag;
        }            
    }
    
    for(i=0;i<ta;i++){
        if(ta == 1)printf("(%d)\n",a[i]);
        else if(i==ta-1)printf("%d)\n",a[i]);
        else if(i==0)printf("(%d,",a[i]);
        else printf("%d,",a[i]);
    }
    
    for(z=0;z<tb;z++){
        flag = 1;
        aux = 1;
        while(flag != 0){
            scanf("%d",&b[z]);
            for(i=0;i<z;i++){
                if(b[z]==b[i])flag++;
            }
            if(flag == aux) flag = 0;
            else aux = flag;
        }
                
    }
    for(z=0;z<tb;z++){
        if(tb == 1)printf("(%d)\n",b[z]);
        else if(z==tb-1)printf("%d)\n",b[z]);
        else if(z==0)printf("(%d,",b[z]);
        else printf("%d,",b[z]); 
    }
 
    for(z=0;z<ta;z++){
        for(i=0;i<tb;i++){
            if(a[z]==b[i])flag++;
        }
    }
    if(flag!=ta && ta!=tb){
        for(z=0;z<ta;z++){
            flag=0;
            for(i=0;i<tb;i++){
                if(a[z]==b[i])flag++;
            }
            if(flag==0) {
                sub[tam]=a[z];
                tam++;
            }
 
        }
    }
    printf("(");
    if(tam>0){
        for(z=0;z<tam;z++){
            if(z==tam-1)printf("%d",sub[z]);
            else printf("%d,",sub[z]);      
        }
    }
    printf(")\n");
 
    for(z=0;z<ta;z++){
        for(i=0;i<tb;i++){
            if(ta==1 && tb == 1) printf("((%dx%d))\n",a[z],b[i]);
            else if(z==ta-1 && i==tb-1) printf("(%dx%d))\n",a[z],b[i]);
            else if(z==0 && i==0)printf("((%dx%d),",a[z],b[i]);
            else printf("(%dx%d),",a[z],b[i]);
        }
    }
 
    return 0;
}