/* TAD: Circulo (x1,y1) (x2,y2) (x3,y3)*/
/* Tipo exportado */
typedef struct cir Circulo;

/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Circulo *cir_cria(float x1, float y1, float c);

/* Função libera - Libera a memória de um circulo previamente criado */
void cir_libera(Circulo *p);

/* Função acessa - Retorna os valores das coordenadas ds pontos do círculo */
void cir_acessa(Circulo *p, float *x1, float *y1, float *c);

/* Função atribui - Atribui novos valores às coordenadas ds pontos do círculo */
void cir_atribui(Circulo *p, float x1, float y1, float c);

/* Função getTriangulo - Retorna uma string com os valores do círculo
 * formato(x,y)*/
char *cir_getCirculo(Circulo *p);

/* Função exibe -Escreve na tela o círculo */
void cir_exibe(Circulo *p);

/* Função clona -recebe um cir e retorna um novo cir com os mesmos valores do
 * cir recebido*/
Circulo *cir_clona(Circulo *p);
/* Função perimetro -recebe um cir e retorna o perimetro*/
float cir_perimetro(Circulo *p);
/* Função area -recebe um cir e retorna a area*/
float cir_area(Circulo *p);
