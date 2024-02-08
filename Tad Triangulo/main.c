// Atividade 1: Faça um programa que obtenha o nome de 4 pessoas e as
// coordenadas dos pontos do triângulo de cada uma delas. Exiba o nome, as
// coordenadas e o perímetro de cada uma, classificados crescentemente pelo
// valor do perímetro

#include "tipoTriangulo.h"
#include <stdio.h>
int main(void) {
  Triangulo *t1;
  t1 = tri_cria(1, 1, 0, 1, 1, 0);
  tri_exibe(t1);
  printf("\nPerímetro: %.2f", tri_perimetro(t1));
  printf("\nÁrea: %.2f", tri_area(t1));
  return 0;
}
