#include <stdio.h>
 
void print_byte(unsigned char *pc){
    int i;
    int w=128;
    unsigned char x = *pc;
 
    for(i=0;i<8;i++){
        printf("%d", x/w);
        x = x % w;
        w = w/2;
    }
}
 
void pbytes(unsigned char *v, int n){
    int i;
    for(i=0;i<n;i++){
        print_byte(v+i);
        printf(" ");
    }
}
 
int main(){
    double d;
    scanf("%lf", &d);
    float f = d;
    int i = d;
    short s = d;
    char c = d;
 
    pbytes((unsigned char*)&c, sizeof(char)); printf("\n");
    pbytes((unsigned char*)&s, sizeof(short)); printf("\n");
    pbytes((unsigned char*)&i, sizeof(int)); printf("\n");
    pbytes((unsigned char*)&f, sizeof(float)); printf("\n");
    pbytes((unsigned char*)&d, sizeof(double)); printf("\n");
 
 
    return 0;
}