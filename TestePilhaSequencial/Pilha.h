typedef struct tStack Stack;

Stack *createStack();
void destroyStack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
int topo(Stack *stack);
