#include <stdio.h>

struct tRacional{
  int num;
  int den;
};

int MDC(int a, int b) { // -> vi isso na internet de mdc em peogramação
    if (a < 0) a = -a; 
    if (b < 0) b = -b; 
    if (b == 0) return a;
    return MDC(b, a % b);
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
  neg.den = r.den;
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

void reduzFracao( struct tRacional * r){
  int mdc = MDC(r->num,r->den);
  struct tRacional reduzida;
  r->num /= mdc;
  r->den /= mdc;
}

int main(){
  int a,b,c,d;
  char ope;
  while(scanf("%d %d %c %d %d",&a, &b,&ope,&c,&d)!= EOF){
    struct tRacional fracao1 = racional(a,b);
    struct tRacional fracao2 = racional(c,d);
    struct tRacional saida;
    if(ope == '+'){ 
      saida = soma(fracao1,fracao2);
      reduzFracao(&saida);
      printf("%d %d\n",saida.num, saida.den);
    }
    else if(ope == '-'){
      fracao2 = negativo(fracao2);
      saida = soma(fracao1,fracao2);
      reduzFracao(&saida);
      printf("%d %d\n",saida.num, saida.den); 
    }
    else if(ope == '*'){
      saida = mult(fracao1,fracao2);
      reduzFracao(&saida);
      printf("%d %d\n",saida.num, saida.den);
    }
    else if(ope == '/'){
      saida = div(fracao1,fracao2);
      reduzFracao(&saida);
      printf("%d %d\n",saida.num, saida.den);
    }
  }
  return 0;
}