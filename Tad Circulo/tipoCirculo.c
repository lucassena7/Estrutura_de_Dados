#include "tipoCirculo.h"
#include "tipoPonto.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/* TAD: Circulo (x1,y1) R)*/
/* Tipo exportado */
struct cir {
  Ponto *C;
  float raio;
};

/* Funções exportadas */
/* Função cria - Aloca e retorna um triângulo com coordenadas (x,y) */
Circulo *cir_cria(float x1, float y1, float c) {
  Circulo *p = (Circulo *)malloc(sizeof(Circulo));
  // considerando sempres que os ptos são não colineraes
  p->C = pto_cria(x1, y1);
  p->raio = c;
  return p;
}

/* Função libera - Libera a memória de um triangulo previamente criado */
void cir_libera(Circulo *p) {
  pto_libera(p->C);
  free(p);
}

/* Função acessa - Retorna os valores das coordenadas ds pontos do circulo */
void cir_acessa(Circulo *p, float *x1, float *y1, float *c) {
  pto_acessa(p->C, x1, y1);
  (*c) = p->raio;
}

/* Função atribui - Atribui novos valores às coordenadas ds pontos do triângulo
 */
void cir_atribui(Circulo *p, float x1, float y1, float c) {
  pto_atribui(p->C, x1, y1);
  p->raio = c;
}

/* Função getTriangulo - Retorna uma string com os valores do triângulo
 * formato(x,y)*/
char *cir_getCirculo(Circulo *p) {
  char *pt;
  int tam = sizeof(*p) + 20;
  pt = (char *)malloc(tam);
  sprintf(pt, "C: %s \n Raio: %f", pto_getPonto(p->C), p->raio);
  return pt;
}

/* Função exibe -Escreve na tela o triangulo */
void cir_exibe(Circulo *p) {
  printf("\nC: %s", pto_getPonto(p->C));
  printf("\nRaio: %.2f", p->raio);
}

/* Função clona -recebe um tri e retorna um novo tri com os mesmos valores do
 * tri recebido*/
Circulo *cir_clona(Circulo *p);
/* Função perimetro -recebe um tri e retorna o perimetro*/

float cir_perimetro(Circulo *p) { return 2 * M_PI * p->raio; }
/* Função area -recebe um tri e retorna a area*/
float cir_area(Circulo *p) { return M_PI * p->raio * p->raio; }
