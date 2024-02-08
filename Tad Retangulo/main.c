#include <stdio.h>
#include "lado.h"

int main(void) {
  Lado * l1;
  float base, altura;
  char* retTexto;
  l1 = ldo_cria(5.0, 10.0);
  ldo_exibe(l1);
  printf("\nPerímetro: %.2f",ldo_perim(l1));
  printf("\nÁrea: %.2f",ldo_area(l1));
  return 0;
}
