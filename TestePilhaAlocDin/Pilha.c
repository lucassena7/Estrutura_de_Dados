#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct tipoNo {
  int dado;
  struct tipoNo *proximo;
};

struct tipoPilha {
  tNo *topo;
};

tPilha *criarPilha() {
  tPilha *pilha = (tPilha *)malloc(sizeof(tPilha));
  if (pilha != NULL) {
    pilha->topo = NULL;
  }
  return pilha;
}

void destruirPilha(tPilha *pilha) {
  tNo *atual = pilha->topo;
  while (atual != NULL) {
    tNo *proximo = atual->proximo;
    free(atual);
    atual = proximo;
  }
  free(pilha);
}

void empilhar(tPilha *pilha, int valor) {
  tNo *novoNo = (tNo *)malloc(sizeof(tNo));
  if (novoNo != NULL) {
    novoNo->dado = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
  } else {
    printf("Erro: falha na alocação de memória.\n");
  }
}

int desempilhar(tPilha *pilha) {
  if (vazia(pilha)) {
    printf("Erro: pilha vazia.\n");
    return -1; // Valor de erro
  }
  tNo *noRemovido = pilha->topo;
  int valor = noRemovido->dado;
  pilha->topo = noRemovido->proximo;
  free(noRemovido);
  return valor;
}

int vazia(tPilha *pilha) { return (pilha->topo == NULL); }

int topo(tPilha *pilha) {
  if (vazia(pilha)) {
    printf("Erro: pilha vazia.\n");
    return -1; // Valor de erro
  }
  return (pilha->topo->dado);
}
