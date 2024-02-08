#include "LSE.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// void vetorRand(int v[], int tam, int min, int max);

int main(void) {
  tLSE *pL = lstSE_criaLista(1, 1);
  int ids[TAM] = {10, 1, 10, 2, 30, 3, 30, 4, 40, 4};

  // int ids[TAM];
  // vetorRand(ids, TAM, 1, 15);

  for (int i = 0; i < TAM; ++i) {
    lstSE_inclui(pL, ids[i]);
  }

  lstSE_imprime(pL);
  printf("\nsem 4");
  lstSE_exclui(pL, 4);
  puts("");

  lstSE_imprime(pL);

  lstSE_exclui(pL, 10);
  printf("\nsem 10\n");
  lstSE_imprime(pL);
  printf("\nsem 40\n");
  lstSE_exclui(pL, 40);
  lstSE_imprime(pL);

  return 0;
}

// void vetorRand(int v[], int tam, int min, int max) {
//   srand(time(0));

//   for (int i = 0; i < tam; ++i)
//     v[i] = (rand() % (max - min + 1)) + min;

//   return;
// }
