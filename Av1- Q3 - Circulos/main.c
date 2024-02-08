#include "LSCC.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// void vetorRand(int v[], int tam, int min, int max);

int main(void) {
  tLSCC *l1 = lstSCC_criaLista(1, 0);
  tLSCC *l2 = lstSCC_criaLista(1, 0);

  // Inclusão de elementos nas listas
  lstSCC_inclui(l1, 1);
  lstSCC_inclui(l1, 2);
  lstSCC_inclui(l1, 3);
  lstSCC_inclui(l1, 4);
  lstSCC_inclui(l1, 5);

  lstSCC_inclui(l2, 2);
  lstSCC_inclui(l2, 3);

  // Impressão das listas antes da remoção da sublista
  printf("Lista 1 antes da remocao: ");
  lstSCC_imprime(l1);

  printf("Lista 2 antes da remocao: ");
  lstSCC_imprime(l2);

  // Remoção da sublista
  Retira_sublista(l1, l2);

  // Impressão das listas após a remoção da sublista
  printf("Lista 1 depois da remocao: ");
  lstSCC_imprime(l1);

  printf("Lista 2 depois da remocao: ");
  lstSCC_imprime(l2);
}
