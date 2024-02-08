
#include "LSEclassifSemRepComNoCabecaCircular.h"
struct elemento {
  int valor;
  struct elemento *prox;
};
struct lseCSR {
  tNo *prim;
};
// FUNÇÔES AUXILIARES DO TAD
tNo *cria_no(int inf) {
  tNo *tmp;
  tmp = (tNo *)malloc(sizeof(tNo));
  if (tmp != NULL) {
    tmp->valor = inf; // preencher infs
    tmp->prox = NULL; // sucessor
  }
  return tmp;
}
int busca_No(tLista *lst, int val, tNo **pNo) {
  // Se tem um nó com a inf buscada: pNo é o endereço do nó antecessor, retorna
  // 1 Se naõ tem um nó com a inf buscada: pNo é o antecessor, retorna 0
  tNo *pAnt, *p;
  lst->prim->valor = val; // coloca no cabeça o valor da chave procurada
  // percorre  a lista até chegar no nó com o valor ou no 1º maior
  for (pAnt = lst->prim, p = lst->prim->prox; p->valor < val;
       pAnt = p, p = p->prox)
    ;
  // Em função de onde parou, decide se o val existe ou não
  *pNo = pAnt;
  return (p != lst->prim && p->valor == val);
}

// FUNÇOES DA INTERFACE
tLista *lista_cria(void) {
  tLista *lst = (tLista *)malloc(sizeof(tLista));
  lst->prim = cria_no(-1);     // criando o cabeça
  lst->prim->prox = lst->prim; // circula
  return lst;
}
void lista_exibe(tLista *lst) {
  tNo *p;
  int pos;
  printf("\n==================================");
  for (pos = 1, p = lst->prim->prox; p != lst->prim; pos++, p = p->prox) {
    printf("\n%dº) Inf: %d", pos, p->valor);
  }
  printf("\n==================================");
}
int lista_vazia(tLista *lst) { return lst->prim->prox == lst->prim; }
int lista_inclui(tLista *lst, int valor) {
  tNo *p;
  tNo *pNovo;
  if (busca_No(lst, valor, &p) == 1) {
    return -1; // inclusão de já existente
  }

  pNovo = cria_no(valor);

  pNovo->prox = p->prox; // novo se conecta
  p->prox = pNovo;       // lista incorpora o novo

  return 1;
}
