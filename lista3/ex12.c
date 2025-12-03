#include <stdio.h>
#include <stdlib.h>

struct tRacional{
  int num;
  int den;
};

int MDC(int x, int y){
  int mdc = 1;
  int flag;
  while (x % 2 == 0 || y % 2 == 0){
    int flag=0;
    if (x % 2 == 0) x/=2; flag++;
    if (y % 2 == 0) x/=2;flag++;
    if (flag==2)mdc*=2;
  }
  while (x % 3 == 0 || y % 3 == 0){
    int flag=0;
    if (x % 3 == 0) x/=3;flag++;
    if (y % 3 == 0) x/=3;flag++;
    if (flag==3)mdc*=3;
  }
  while (x % 5 == 0 || y % 5 == 0){
    int flag=0;
    if (x % 5 == 0) x/=5;flag++;
    if (y % 5 == 0) x/=5;flag++;
    if (flag==5)mdc*=5;
  }
  while (x % 7 == 0 || y % 7 == 0){
    int flag=0;
    if (x % 7 == 0) x/=7;flag++;
    if (y % 7 == 0) x/=7;flag++;
    if (flag==7)mdc*=7;
  }
  return mdc;
}
 
struct tRacional racional(int a, int b){
  struct tRacional razao;
  razao.num = a;
  razao.den = b;
  return razao;
}
 
struct tRacional negativo(struct tRacional r){

  struct tRacional neg;
  neg.num = -(r.num);
  neg.den = -(r.num);
  return neg;  
}

struct tRacional soma(struct tRacional r1, struct tRacional r2){
  struct tRacional sum;
  sum.num = (r1.num*r2.den) + (r2.num*r1.den);
  sum.den = r1.den*r2.den;
  return racional(sum.num,sum.den);
}

struct tRacional mult(struct tRacional r1, struct tRacional r2){
  struct tRacional multiplica;
  multiplica.num = r1.num*r2.num;
  multiplica.den = r1.den*r2.den;
  return racional(multiplica.num,multiplica.den);
}

struct tRacional div(struct tRacional r1, struct tRacional r2){
  struct tRacional divide;
  divide.num = r1.num*r2.den;
  divide.den = r1.den*r2.num;
  return racional(divide.num,divide.den);
}

void reduzFracao( struct tRacional  r){
  int mdc = MDC(r.num,r.den);
  struct tRacional reduzida;
  reduzida.num = r.num/mdc;
  reduzida.den = r.den/mdc;
  return reduzida;
}

int main(){
  int a,b;
  while(scanf("%d %d",&a, &b)!= EOF){
    struct tRacional fracao;
  
  }
  return 0;
}