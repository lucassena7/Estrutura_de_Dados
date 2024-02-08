typedef struct no tNo;
typedef struct LDEC tLDEC;

/*
  Retorna TRUE (1) ou FALSE (0) dependendo se a lista
  duplamente encadeada com nó cabeça {pL} é classificada ou não,
  respectivamente.
*/
int lstDEC_isClassif(tLDEC *pL);

/*
  Retorna TRUE (1) ou FALSE (0) dependendo se a lista
  duplamente encadeada com nó cabeça {pL} permite ou não repetição,
  respectivamente.
*/
int lstDEC_comRepet(tLDEC *pL);

/*
  Retorna TRUE (<>0) ou FALSE (0) dependendo se a lista
  duplamente encadeada com nó cabeça {pL} está ou não vazia,
  respectivamente.
*/
int lstDEC_isVazia(tLDEC *pL);

/*
  Cria e retorna uma lista duplamente encadeada com nó cabeça.
  {isClassif, comRepet} determinam, respectivamente, se
  a lista é classificada e se pode haver repetição de
  elementos. (0 = Não; <>0 = Sim)
*/
tLDEC *lstDEC_criaLista(int isClassif, int comRepet);

/*
Tenta inserir o ID {id} na lista duplamente encadeada com nó cabeça
  {pL}, retornando TRUE (1) ou FALSE (0) dependendo se a
  operação foi bem-sucedida ou não, respectivamente.

  Possíveis impedidores: memória insuficiente; {id} já
  existe e {pL} não permite repetição; etc.
*/
int lstDEC_inclui(tLDEC *pL, int id);

/*
  Imprime no console os elementos de uma lista
  duplamente encadeada com nó cabeça {pL}.
*/
void lstDEC_imprime(tLDEC *pL);

/*
  Remove todas as ocorrências do ID {id} na lista
  duplamente encadeada com nó cabeça {pL}, retornando a quantidade
  de instâncias excluídas.
*/
int lstDEC_exclui(tLDEC *pL, int id);

/*
  Libera todos os nós da lista duplamente encadeada com nó cabeça {pL}.
*/
void lstDEC_destroi(tLDEC *pL);
