typedef struct tipoNo tNo;
typedef struct tipoPilha tPilha;

tPilha *criarPilha();
void destruirPilha(tPilha *pilha);
void empilhar(tPilha *pilha, int valor);
int desempilhar(tPilha *pilha);
int vazia(tPilha *pilha);
int topo(tPilha *pilha);
