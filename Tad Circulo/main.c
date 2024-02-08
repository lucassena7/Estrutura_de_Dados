#include <stdio.h>
#include "tipoCirculo.h"
int main(void) {
  Circulo*c1;
  // Criando um círculo
  c1 = cir_cria (0, 0, 5 );
  
  cir_exibe(c1);

  // Exibindo os resultados
  printf("\nPerímetro: %.2f",cir_perimetro(c1));
  printf("\nÁrea: %.2f",cir_area(c1));

  return 0;
}
