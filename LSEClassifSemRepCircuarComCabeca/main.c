#include "LSEclassifSemRepComNoCabecaCircular.h"
#include <stdio.h>
int main(void) {
  tLista *pL;
  pL = lista_cria();

  lista_inclui(pL, 10);
  lista_exibe(pL);
  lista_inclui(pL, 20);
  lista_exibe(pL);
  lista_inclui(pL, 15);
  lista_exibe(pL);
  lista_inclui(pL, 5);
  lista_exibe(pL);
  lista_inclui(pL, 35);
  lista_exibe(pL);

  return 0;
}
