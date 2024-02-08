#include "fracao.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct fracao {
  float numerador;
  float denominador;
  int sinal;
};


Fracao *fra_cria(float numerador, float denominador, int sinal) {
   Fracao* f = (Fracao*) malloc(sizeof(Fracao));

  if (f == NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
   }
  f->denominador = denominador;
  f->sinal = sinal;
  if (sinal == 1) {
    f->numerador = numerador;
  }
  else {
    f->numerador = -(numerador);
  }
   return f;
}

void fra_libera(Fracao *f) {
  free(f);
}

void fra_exibe(Fracao *f) {
    printf("\n(%.2f/%.2f)", f->numerador, f->denominador);
}

int maiorMenor(Fracao *fra1, Fracao *fra2) {
  double resp1, resp2;

  resp1 = fra1->numerador/fra1->denominador;
  resp2 = fra2->numerador/fra2->denominador;

  if (resp1 > resp2)
  {
    return 1;
  } else {
    return -1;
  }
}

char *fra_getNum(Fracao *f) {
  char* pt;
  int tam = sizeof(*f)+ 5;
  pt = (char*)malloc(tam);
  sprintf(pt,"( %.2f )", f->numerador);
  return pt;
}

char *fra_getDen(Fracao *f) {
  char* pt;
  int tam = sizeof(*f)+ 5;
  pt = (char*)malloc(tam);
  sprintf(pt,"( %.2f )", f->denominador);
  return pt;
}

void fra_atribuiNum(Fracao *f, float numerador) {
  f->numerador = numerador;
}

void fra_atribuiDen(Fracao *f, float denominador) {
  f->denominador = denominador;
}

void fra_atribuiFra(Fracao *f, float numerador, float denominador) {
  f->numerador = numerador;
  f->denominador = denominador;
}

char *fra_getFra(Fracao *f) {
  char* pt;
  int tam = sizeof(*f)+ 10;
  pt = (char*)malloc(tam);
  sprintf(pt,"( %d%.2f/%.2f )", f->sinal, f->numerador, f->denominador);
  return pt;
}
