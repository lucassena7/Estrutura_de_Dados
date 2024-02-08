//  Implemente as funções deste TAD de modo que seja possível:
// Criar e retornar um ponteiro para uma nova fração, recebendo para isto um
// número natural como numerador, um número natural maior do que zero como
// denominador e 1 ou -1 dependendo do sinal da fração. Exibir na tela uma
// fração no seguinte formato : -2/3, +1/2, +3/1 Uma função que receba 2 frações
// e retorne 1 se a primeira é maior que a segunda, -1 se a primeira é menor e 0
// se são iguais. Uma função para liberar uma fração. Acessar o numerador e
// denominador ( funções separadas) ( get) Modificar o numerador e denominador (
// funções separadas)(set) Modificar uma fração ( numerador e denominador
// simultaneamente) Acessar uma fração ( numerador e denominador
// simultaneamente)

typedef struct fracao Fracao;

Fracao *fra_cria(float numerador, float denominador, int sinal);

void fra_libera(Fracao *f);

void fra_exibe(Fracao *f);

int maiorMenor(Fracao *fra1, Fracao *fra2);

char *fra_getNum(Fracao *f);

char *fra_getDen(Fracao *f);

void fra_atribuiNum(Fracao *f, float numerador);

void fra_atribuiDen(Fracao *f, float denominador);

void fra_atribuiFra(Fracao *f, float numerador, float denominador);

char *fra_getFra(Fracao *f);
