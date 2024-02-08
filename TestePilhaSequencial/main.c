#include <stdio.h>
#include "Pilha.h"

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    printf("Topo: %d\n", topo(stack));
    push(stack, 20);
    printf("Topo: %d\n", topo(stack));
    push(stack, 30);
    printf("Topo: %d\n", topo(stack));  
    
    printf("Elemento desempilhado: %d\n", pop(stack));
    printf("Elemento desempilhado: %d\n", pop(stack));
    printf("Elemento desempilhado: %d\n", pop(stack));

    printf("Topo: %d\n", topo(stack));

    destroyStack(stack);

    return 0;
}
