#include "calculadora.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct rac {
  float numerador;
  float denominador;
};

int mdc(int a, int b) {
  if (b == 0) {
    return a;
  }
  return mdc(b, a % b);
}

Racional *rac_cria(int x, int y) {
  Racional *r = (Racional *)malloc(sizeof(Racional));
  int divisor;

  if (r == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  divisor = mdc(x, y);
  r->numerador = x / divisor;
  r->denominador = y / divisor;
  return r;
}

// Destrói um número Racional criado
void rac_libera(Racional *r) { free(r); }

// soma dois racionais
Racional *rac_add(Racional *x, Racional *y) {
  int num, den;

  num = (x->numerador * y->denominador) + (y->numerador * x->denominador);
  den = x->denominador * y->denominador;
  return rac_cria(num, den);
}

// subtrai dois racionais
Racional *rac_sub(Racional *x, Racional *y) {
  int num, den;

  num = (x->numerador * y->denominador) - (y->numerador * x->denominador);
  den = x->denominador * y->denominador;
  return rac_cria(num, den);
}

// Multiplica dois racionais
Racional *rac_mul(Racional *x, Racional *y) {
  int num, den;

  num = x->numerador * y->numerador;
  den = x->denominador * y->denominador;
  return rac_cria(num, den);
}

// divide dois racionais
Racional *rac_divide(Racional *x, Racional *y) {
  int num, den;

  num = x->numerador * y->denominador;
  den = x->denominador * y->numerador;
  return rac_cria(num, den);
}

// retorna uma string que representa o Racional
void rac_exibe(Racional *x) {
  printf("\n(%.2f/%.2f)", x->numerador, x->denominador);
}

// verifica se dois numeros racionais são iguais
int rac_iguais(Racional *x, Racional *y) {
  int resp1, resp2;

  resp1 = x->numerador / x->denominador;
  resp2 = y->numerador / y->denominador;

  if (resp1 == resp2) {
    return 0;
  }
  return 1;
}
