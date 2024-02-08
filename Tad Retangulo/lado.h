//Typedef
//Protótipo das funções

typedef struct lado Lado;

//Funções exportadas
//Função criar - aloca e retorna um 'struct' com os lados (base e altura);
Lado* ldo_cria(float base, float altura);

/* Função libera - Libera a memória de um 'struct' previamente criado */
void ldo_libera(Lado* l);

/* Função acessa - Retorna os valores dos lados de um struct */
void ldo_acessa(Lado* l, float* base, float* altura);

/* Função atribui - Atribui novos valores aos lados de um struct*/
void ldo_atribui(Lado* l, float base, float altura);

/* Função area - Retorna o valor da area do retângulo*/
float ldo_area (Lado* l);

/* Função perímetro - Retorna o valor do perímetro do retângulo*/
float ldo_perim(Lado* l);

/* Função getPonto - Retorna uma string com os valores do struct formato(base,altura)*/
char* ldo_pontos(Lado* l);

void ldo_exibe(Lado* l);
