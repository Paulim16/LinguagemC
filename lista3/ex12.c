


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

  int mdc = MDC(a,b);
  struct tRacional frac;
  frac.num = a/mdc;
  frac.den = b/mdc;
  return frac;
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


  Recebe dois racionais e retorna o quociente de ambos (r1/r2).
  param r1 numerador
  param r2 denominador
  return

struct tRacional div(struct tRacional r1, struct tRacional r2){
  struct tRacional divide;
  divide.num = r1.num*r2.den;
  divide.den = r1.den*r2.num;
  return racional(divide.num,divide.den);
}


  Recebe um racional e reduz a fração ao máximo.
  param r o número racional a ser reduzido

 void reduzFracao( struct tRacional  r);