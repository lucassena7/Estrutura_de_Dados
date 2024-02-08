#include "Data.h"
typedef struct bol tBoleto;

/* Funções exportadas */
tBoleto *bol_cria(int numBol, int dia, int mes, int ano, float valor);

void bol_libera(tBoleto *b);

void bol_acessa(tBoleto *b, int *numBol, int *dia, int *mes, int *ano,
                float *valor);

void bol_atribui(tBoleto *b, int numBol, int dia, int mes, int ano,
                 float valor);

char *bol_getBoleto(tBoleto *b);

void bol_exibe(tBoleto *b);
