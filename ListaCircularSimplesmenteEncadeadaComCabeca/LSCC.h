typedef struct no tNo;
typedef struct lscc tLSCC;

/* busca:
Retorna TRUE (1) ou FALSE (0) dependendo se o ID {id}
  encontra-se na lista simplesmente encadeada {pL},
  respectivamente. Se o ID for encontrado, {pAtual, pAnt}
  guardarão os endereços do nó com o ID e do nó
  imeadiatamente anterior, respectivamente.
*/
int busca(tLSCC *pL, int id, tNo **pAnt);

/* cria_no
  Cria e retorna um nó de LSE com ID {id}.
*/
tNo *criaNo(int id);

/*
  Retorna TRUE (1) ou FALSE (0) dependendo se a lista
  simplesmente encadeada circular com nó bobo {pL} é classificada ou não,
  respectivamente.
*/
int lstSCC_isClassif(tLSCC *pL);

/*
  Retorna TRUE (1) ou FALSE (0) dependendo se a lista simplesmente encadeada
  circular com nó bobo {pL} permite ou não repetição, respectivamente.
*/
int lstSCC_comRepet(tLSCC *pL);

/*
  Retorna TRUE (<>0) ou FALSE (0) dependendo se a lista
  simplesmente encadeada circular com nó bobo {pL} está ou não vazia,
  respectivamente.
*/
int lstSCC_isVazia(tLSCC *pL);

/*
  Cria e retorna uma lista simplesmente encadeada circular com nó bobo.
  {isClassif, comRepet} determinam, respectivamente, se
  a lista é classificada e se pode haver repetição de
  elementos. (0 = Não; <>0 = Sim)
*/
tLSCC *lstSCC_criaLista(int isClassif, int comRepet);

/*
Tenta inserir o ID {id} na lista simplesmente encadeada circular com nó bobo
{pL}, retornando TRUE (1) ou FALSE (0) dependendo se a operação foi bem-sucedida
ou não, respectivamente. Possíveis impedidores: memória insuficiente; {id} já
existe e {pL} não permite repetição; etc.
*/
int lstSCC_inclui(tLSCC *pL, int id);

/* Imprime no console os elementos de uma lista simplesmente encadeada circular
 * com nó bobo {pL}.
 */
void lstSCC_imprime(tLSCC *pL);

/* Remove todas as ocorrências do ID {id} na lista simplesmente encadeada
 * circular com nó bobo {pL}, retornando a quantidade de instâncias excluídas.
 */
int lstSCC_exclui(tLSCC *pL, int id);
