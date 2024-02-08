#include <stdio.h>
#include "Pilha.h"

int main() {
    tPilha* pilha = criarPilha();

    empilhar(pilha, 10);
    printf("Topo: %d\n", topo(pilha));
    empilhar(pilha, 20);
    printf("Topo: %d\n", topo(pilha));
    empilhar(pilha, 30);
    printf("Topo: %d\n", topo(pilha));

    printf("Elemento desempilhado: %d\n", desempilhar(pilha));
    printf("Elemento desempilhado: %d\n", desempilhar(pilha));
    printf("Elemento desempilhado: %d\n", desempilhar(pilha));

    empilhar(pilha, 45);
    printf("Topo: %d\n", topo(pilha));
  
    destruirPilha(pilha);

    return 0;
}
