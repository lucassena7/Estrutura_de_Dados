#include <stdio.h>
#include "Pilha.h"
int main(void) {
  tPilha * minhaPilha;
  tPilha * testePilha;
  tPilha * tuaPilha;
  int i;
  int inf;
  testePilha = pilha_cria(4);
  minhaPilha=pilha_cria(4);
  tuaPilha=pilha_cria(2);
  if (pilha_tavazia(minhaPilha))
    printf("Pilha Vazia");
  for(i=0;i<4;i++)
    pilha_inclui(minhaPilha,2*i);
  // consultar o topo
  /*
  pilha_exclui(minhaPilha,&inf);
  printf("\n\nvalor do topo: %d",inf);
  pilha_inclui(minhaPilha,inf);
  */
  pilha_consultaTopo(minhaPilha,&inf);
  printf("\n\nvalor do topo: %d\n",inf);
  while (!pilha_tavazia(minhaPilha)) { //enquanto minha pilha não estiver vazia
    pilha_exclui(minhaPilha,&inf);
    printf ("\n%d", inf);
    pilha_inclui(testePilha, inf);
  }
  printf ("\n\n");
  while (!pilha_tavazia(testePilha)) { //enquanto minha pilha não estiver vazia
    pilha_exclui(testePilha,&inf);
    printf ("\n%d", inf);
    pilha_inclui(minhaPilha, inf);
  }
}
