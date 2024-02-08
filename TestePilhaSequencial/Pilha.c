#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct tStack {
  int data[MAX_SIZE];
  int top;
};

Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (stack != NULL) {
    stack->top = -1;
  }
  return stack;
}

void destroyStack(Stack *stack) {
  free(stack->data);
  free(stack);
}

int isEmpty(Stack *stack) { return (stack->top == -1); }

int isFull(Stack *stack) { return (stack->top == MAX_SIZE - 1); }

void push(Stack *stack, int value) {
  if (isFull(stack)) {
    printf("Erro: pilha cheia.\n");
    exit(1); // Valor de erro.
  }
  stack->top++;
  stack->data[stack->top] = value;
}

int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Erro: pilha vazia.\n");
    return -1; // Valor de erro
  }
  int value = stack->data[stack->top];
  stack->top--;
  return value;
}

int topo(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Erro: pilha vazia.");
    exit(1);
  }
  return stack->data[stack->top];
}
