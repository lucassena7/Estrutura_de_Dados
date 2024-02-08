typedef struct tipoQueue Queue;
typedef struct tipoNode Node;

Queue* createQueue();
int isEmpty(Queue* queue);
void enqueue(Queue* queue, int element);
int dequeue(Queue* queue);
void displayFront(Queue* queue);
void destroyQueue(Queue* queue);

