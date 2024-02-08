typedef struct Queue Queue;

Queue* createQueue();
int isEmpty(Queue* queue);
int isFull(Queue* queue);
void enqueue(Queue* queue, int element);
int dequeue(Queue* queue);
void displayFront(Queue* queue);
void destroyQueue(Queue* queue);

