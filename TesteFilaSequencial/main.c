#include "Fila.h"
#include <stdio.h>

int main() {
  Queue *queue = createQueue();
  int element;

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  displayFront(queue);

  element = dequeue(queue);
  displayFront(queue);

  enqueue(queue, 40);
  displayFront(queue);

  element = dequeue(queue);
  element = dequeue(queue);
  element = dequeue(queue);
  element = dequeue(queue);

  destroyQueue(queue);

  return 0;
}
