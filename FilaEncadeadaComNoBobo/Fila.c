#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

struct tipoNode {
    int data;
    struct tipoNode* next;
};

struct tipoQueue {
    Node* front;
    Node* rear;
};

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = (Node*)malloc(sizeof(Node));
    queue->rear->next = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    printf("Elemento %d inserido na fila.\n", element);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return -1;
    }

    Node* temp = queue->front;
    int element = temp->data;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = (Node*)malloc(sizeof(Node));
        queue->rear->next = NULL;
    }

    printf("Elemento %d removido da fila.\n", element);
    return element;
}

void displayFront(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return;
    }
    printf("Primeiro elemento da fila: ");
    printf("%d ", queue->front->data);
    printf("\n");
}

void destroyQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue->rear);
    free(queue);
}
