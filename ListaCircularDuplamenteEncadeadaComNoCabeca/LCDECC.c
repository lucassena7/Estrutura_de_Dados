#include "LCDECC.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct no {
  int id;
  struct no *prox;
  struct no *ant;
};

struct LDEC {
  int qtdNos;
  int isClassif, comRepet;
  tNo *cabeca;
};

int lstDEC_isClassif(tLDEC *pL) { return pL->isClassif; }

int lstDEC_comRepet(tLDEC *pL) { return pL->comRepet; }

int lstDEC_isVazia(tLDEC *pL) { return pL->cabeca->prox == pL->cabeca; }

tLDEC *lstDEC_criaLista(int isClassif, int comRepet) {
  tLDEC *pL = (tLDEC *)malloc(sizeof(tLDEC));
  pL->qtdNos = 0;
  pL->isClassif = isClassif;
  pL->comRepet = comRepet;

  pL->cabeca = (tNo *)malloc(sizeof(tNo));
  pL->cabeca->prox = pL->cabeca;
  pL->cabeca->ant = pL->cabeca;
  return pL;
}

tNo *lstDEC_busca(tLDEC *pL, int id) {
  int isClassif = lstDEC_isClassif(pL);
  int comRepet = lstDEC_comRepet(pL);
  tNo *p;

  if (isClassif) {
    for (p = pL->cabeca->prox; p != pL->cabeca && p->id < id; p = p->prox)
      ;
  } else {
    for (p = pL->cabeca->prox; p != pL->cabeca && p->id != id; p = p->prox)
      ;
    if (p == pL->cabeca) {
      return p->ant; // Elemento não encontrado, retorna o nó que será usado
                     // para inclusão
    }
  }
  return p->ant;
}

int lstDEC_inclui(tLDEC *pL, int id) {
  if (!pL->comRepet) {
    tNo *atual = pL->cabeca->prox;
    while (atual != pL->cabeca) {
      if (atual->id == id) {
        return 0; // Impedimento de repetição
      }
      atual = atual->prox;
    }
  }

  tNo *novoNo = (tNo *)malloc(sizeof(tNo));
  novoNo->id = id;

  tNo *atual = pL->cabeca->prox;
  while (atual != pL->cabeca) {
    if (pL->isClassif) {
      if (id < atual->id) {
        break;
      }
    } else {
      if (id == atual->id) {
        break;
      }
    }
    atual = atual->prox;
  }

  novoNo->prox = atual;
  novoNo->ant = atual->ant;
  atual->ant->prox = novoNo;
  atual->ant = novoNo;

  pL->qtdNos += 1;
  return 1;
}


void lstDEC_imprime(tLDEC *pL) {
  if (lstDEC_isVazia(pL)) {
    printf("Lista vazia.\n");
  } else {
    tNo *atual = pL->cabeca->prox;
    while (atual != pL->cabeca) {
      printf("%d ", atual->id);
      atual = atual->prox;
    }
    printf("\n");
  }
}

int lstDEC_exclui(tLDEC *pL, int id) {
  int contExclusoes = 0;

  tNo *atual = pL->cabeca->prox;
  while (atual != pL->cabeca) {
    if (atual->id == id) {
      tNo *remover = atual;
      atual->ant->prox = atual->prox;
      atual->prox->ant = atual->ant;
      atual = atual->prox;
      free(remover);
      contExclusoes++;
    } else {
      atual = atual->prox;
    }
  }

  return contExclusoes;
}

void lstDEC_destroi(tLDEC *pL) {
  tNo *atual = pL->cabeca->prox;
  while (atual != pL->cabeca) {
    tNo *remover = atual;
    atual = atual->prox;
    free(remover);
  }
  free(pL->cabeca);
  free(pL);
}
