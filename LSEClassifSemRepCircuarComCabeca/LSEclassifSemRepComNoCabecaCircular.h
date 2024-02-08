#include <stdio.h>
#include <stdlib.h>
typedef struct elemento tNo;

typedef struct lseCSR tLista;
tLista *lista_cria(void);
void lista_exibe(tLista *lst);
int lista_vazia(tLista *lst);
int lista_inclui(tLista *lst, int valor);
