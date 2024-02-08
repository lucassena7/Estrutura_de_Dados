/* Tipo exportado */
#include "lado.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct lado{
  float base,altura;
};

/* Funções exportadas */

//Função criar - aloca e retorna um 'struct' com os lados (base e altura);
Lado* ldo_cria(float base, float altura) {
  Lado* l = (Lado*) malloc (sizeof(Lado));

  if (l == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  l->base = base;
  l->altura = altura;
  return l;
}

/* Função libera - Libera a memória de um 'struct' previamente criado */
void ldo_libera(Lado* l) {
  free (l);
}

/* Função acessa - Retorna os valores dos lados de um struct */
void ldo_acessa(Lado* l, float* base, float* altura) {
  (*base) = l->base;
  (*altura) = l->altura;
  return;
}

/* Função atribui - Atribui novos valores aos lados de um struct*/
void ldo_atribui(Lado* l, float base, float altura) {
  l->base = base;
  l->altura = altura;
}

/* Função area - Retorna o valor da area do retângulo*/
float ldo_area (Lado* l) {
  return ((l->base)*(l->altura));
}

/* Função perímetro - Retorna o valor do perímetro do retângulo*/
float ldo_perim(Lado* l) {
  return ((l->base*2) + (l->altura*2));
}

/* Função getPonto - Retorna uma string com os valores do struct formato(base,altura)*/
char* ldo_pontos(Lado* l) {
  char* retAux;
  int qtCaracteres = sizeof(*l) + 8;
  retAux=(char*)malloc(qtCaracteres);
  sprintf(retAux,"(%.2f , %.2f)",l->base,l->altura);
  return retAux;
}

void ldo_exibe(Lado* l) {
  printf ("(%.2f , %.2f)",l->base,l->altura);
  return;
}
