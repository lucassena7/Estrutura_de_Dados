#include "LCDECC.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int main(void) {
  tLDEC *pL = lstDEC_criaLista(1, 0);
  int ids[TAM] = {10, 1, 10, 2, 30, 3, 30, 4, 40, 4};

  // int ids[TAM];
  // vetorRand(ids, TAM, 1, 15);

  for (int i = 0; i < TAM; ++i) {
    lstDEC_inclui(pL, ids[i]);
  }

  lstDEC_imprime(pL);
  printf("\nsem 4");
  lstDEC_exclui(pL, 4);
  puts("");

  lstDEC_imprime(pL);

  lstDEC_exclui(pL, 10);
  printf("\nsem 10\n");
  lstDEC_imprime(pL);
  printf("\nsem 40\n");
  lstDEC_exclui(pL, 40);
  lstDEC_imprime(pL);

  return 0;
}

// void vetorRand(int v[], int tam, int min, int max) {
//   srand(time(0));

//   for (int i = 0; i < tam; ++i)
//     v[i] = (rand() % (max - min + 1)) + min;

//   return;
// }
