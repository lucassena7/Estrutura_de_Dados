#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4

struct Queue {
  int elements[MAX_SIZE];
  int front;
  int rear;
};

Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue != NULL) {
    queue->front = -1;
    queue->rear = -1;
  }
  return queue;
}

int isEmpty(Queue *queue) { return (queue->front == -1); }

int isFull(Queue *queue) { return (queue->rear == MAX_SIZE - 1); }

void enqueue(Queue *queue, int element) {
  if (isFull(queue)) {
    printf("A fila está cheia.\n");
    return;
  }
  if (isEmpty(queue))
    queue->front = 0;
  queue->rear++;
  queue->elements[queue->rear] = element;
  printf("Elemento %d inserido na fila.\n", element);
}

int dequeue(Queue *queue) {
  int element;
  if (isEmpty(queue)) {
    printf("A fila está vazia.\n");
    return -1;
  }
  element = queue->elements[queue->front];
  if (queue->front == queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  } else {
    queue->front++;
  }
  printf("Elemento %d removido da fila.\n", element);
  return element;
}

void destroyQueue(Queue *queue) {
  free(queue->elements);
  free(queue);
}

// Função para exibir o primeiro elemento da fila
void displayFront(Queue *queue) {
  if (isEmpty(queue)) {
    printf("A fila está vazia.\n");
    return;
  }
  printf("Primeiro elemento da fila: %d\n", queue->elements[queue->front]);
}
