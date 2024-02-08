#include "LSCC.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// void vetorRand(int v[], int tam, int min, int max);

int main(void) {
  tLSCC *pL = lstSCC_criaLista(0, 0);
  int ids[TAM] = {10, 1, 10, 2, 30, 3, 30, 4, 40, 4};

  // int ids[TAM];
  // vetorRand(ids, TAM, 1, 15);

  for (int i = 0; i < TAM; ++i) {
    lstSCC_inclui(pL, ids[i]);
  }

  lstSCC_imprime(pL);
  printf("\nsem 4");
  lstSCC_exclui(pL, 4);
  puts("");

  lstSCC_imprime(pL);

  lstSCC_exclui(pL, 10);
  printf("\nsem 10\n");
  lstSCC_imprime(pL);
  printf("\nsem 1\n");
  lstSCC_exclui(pL, 1);
  lstSCC_imprime(pL);

  return 0;
}

// void vetorRand(int v[], int tam, int min, int max) {
//   srand(time(0));

//   for (int i = 0; i < tam; ++i)
//     v[i] = (rand() % (max - min + 1)) + min;

//   return;
// }
