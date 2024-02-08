#include "LSCC.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct no {
  int id;
  struct no *prox;
};

struct lscc {
  tNo *prim;
  int qtdNos;
  int isClassif, comRepet;
};

int busca(tLSCC *pL, int id, tNo **pAnt) {
  int isClassif = lstSCC_isClassif(pL);
  int comRepet = lstSCC_comRepet(pL);
  tNo *p, *pRast;

  if (isClassif) {
    for (p = pL->prim->prox, pRast = pL->prim; p != pL->prim && p->id < id;
         pRast = p, p = p->prox)
      ;
  } else {
    for (p = pL->prim->prox, pRast = pL->prim; p != pL->prim && p->id != id;
         pRast = p, p = p->prox)
      ;
  }
  (*pAnt) = pRast;

  return (p != pL->prim && p->id == id);
}

tNo *criaNo(int id) {
  tNo *no = (tNo *)malloc(sizeof(tNo));

  no->id = id;
  no->prox = NULL;

  return no;
}

int lstSCC_isClassif(tLSCC *pL) { return pL->isClassif; }

int lstSCC_comRepet(tLSCC *pL) { return pL->comRepet; }

int lstSCC_isVazia(tLSCC *pL) { return pL->qtdNos == 0; }

tLSCC *lstSCC_criaLista(int isClassif, int comRepet) {
  tLSCC *pL = (tLSCC *)malloc(sizeof(tLSCC));
  if (pL) {
    pL->qtdNos = 0;
    pL->isClassif = isClassif;
    pL->comRepet = comRepet;
    pL->prim = criaNo(0);      // Cria o nó cabeça com ID 0
    pL->prim->prox = pL->prim; // Faz o nó cabeça apontar para si mesmo
  }
  return pL;
}

int lstSCC_inclui(tLSCC *pL, int id) {
  tNo *pNovo, *pAnt, *pAtual;
  int isClassif, comRepet, sit;

  isClassif = lstSCC_isClassif(pL);
  comRepet = lstSCC_comRepet(pL);

  if (!isClassif && comRepet) {
    pAnt = pL->prim;
    sit = FALSE;
  } else {
    sit = busca(pL, id, &pAnt);
  }
  if (sit && !comRepet)
    return -1;

  pNovo = criaNo(id);
  if (pAnt == NULL) {
    pNovo->prox = pL->prim->prox;
    pL->prim->prox = pNovo;
  } else {
    pNovo->prox = pAnt->prox;
    pAnt->prox = pNovo;
  }

  pL->qtdNos += 1;
  return TRUE;
}

void lstSCC_imprime(tLSCC *pL) {
  if (pL->prim->prox == pL->prim) {
    printf("Lista vazia.\n");
    return;
  }

  tNo *p = pL->prim->prox;

  while (p != pL->prim) {
    printf("%d ", p->id);
    p = p->prox;
  }

  printf("\n");
}

int lstSCC_exclui(tLSCC *pL, int id) {
  tNo *pAnt = pL->prim;
  tNo *pAtual = pAnt->prox;
  int qtdDel = 0;

  while (pAtual != pL->prim) {
    if (pAtual->id == id) {
      pAnt->prox = pAtual->prox;
      free(pAtual);
      pAtual = pAnt->prox;
      qtdDel++;
      pL->qtdNos--;
    } else {
      pAnt = pAtual;
      pAtual = pAtual->prox;
    }
  }
  return qtdDel;
}
