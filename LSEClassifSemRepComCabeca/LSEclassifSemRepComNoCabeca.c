
#include "LSEclassifSemRepComNoCabeca.h"
struct elemento {
int valor;
struct elemento * prox;
};
struct lseCSR {
  tNo* prim;
};
// FUNÇÔES AUXILIARES DO TAD
tNo* cria_no(int inf){
  tNo *tmp;
  tmp = (tNo * ) malloc( sizeof (tNo));
  if (tmp!=NULL){
    tmp->valor = inf; //preencher infs
    tmp-> prox = NULL; // sucessor

  }
  return tmp;
}
int busca_No(tLista*lst, int val, tNo**pNo){
  // Se tem um nó com a inf buscada: pNo é o endereço do nó, reorna 1
  // Se naõtem um nó com a inf buscada: pNo é o antecessor, retorna 0
  tNo * pAnt, *p;
  // percorre  a lsita até chegar no nó com o valor ou no 1º maior
  for(pAnt=lst->prim, p=lst->prim->prox; (p!=NULL) && (p->valor < val) ; pAnt=p,p=p->prox);
  //Em função de onde parou, decide se o val existe ou não
  if(p && p->valor==val){ // achou o valor na lista
    *pNo=p;
    return 1;
  }
  else { // retorna o antecessor de onde um nó com val deveria estar
    *pNo=pAnt;
    return 0;
    }
}
   
//FUNÇOES DA INTERFACE
tLista * lista_cria(void){
  tLista *lst=(tLista*)malloc(sizeof(tLista));
  lst->prim=cria_no(-1); // criando o cabeça
  return lst;
}
void lista_exibe(tLista*lst){
  tNo * p;
  int pos;
  printf("\n==================================");
  for(pos=1, p=lst->prim->prox; p!=NULL;pos++,p=p->prox){
    printf("\n%dº) Inf: %d",pos,p->valor);
  }
  printf("\n==================================");
}
int lista_vazia(tLista * lst){
  return lst->prim->prox==NULL;
}
int lista_inclui(tLista *lst, int valor){
  tNo * p;
  tNo *pNovo;
  if (busca_No(lst, valor, &p)==1){
    return -1; // inclusão de já existente
  }
  else{
    pNovo=cria_no(valor);
    
    // lista incorpora o novo
    pNovo->prox=p->prox; // novo se conecta
    p->prox=pNovo;
    }
    return 1;
  }
