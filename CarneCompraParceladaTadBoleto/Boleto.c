#include "Boleto.h"

struct bol {
  int num;
  tData *date;
  float valor;
};
/* Funções exportadas */
tBoleto *bol_cria(int numBol, int dia, int mes, int ano, float valor) {
  tBoleto *b = (tBoleto *)malloc(sizeof(tBoleto));
  b->num = numBol;
  b->date = dta_cria(dia, mes, ano);
  b->date = somar_dias(b->date, 20);
  b->valor = valor;
  return b;
}

void bol_libera(tBoleto *b) {
  dta_libera(b->date);
  free(b);
}

void bol_acessa(tBoleto *b, int *numBol, int *dia, int *mes, int *ano,
                float *valor) {
  (*numBol) = b->num;
  dta_acessa(b->date, dia, mes, ano);
  (*valor) = b->valor;
}

void bol_atribui(tBoleto *b, int numBol, int dia, int mes, int ano,
                 float valor) {
  b->num = numBol;
  dta_atribui(b->date, dia, mes, ano);
  b->valor = valor;
}

char *bol_getBoleto(tBoleto *b) {
  char *pt;
  int tam = sizeof(*b) + 50;
  pt = (char *)malloc(tam);
  sprintf(pt, "Num_Boleto: %d  Data_Prox_Vencimento: %s  Valor_Parcela: %.2f",
          b->num, dta_getData(b->date), b->valor);
  return pt;
}

void bol_exibe(tBoleto *b) {
  printf("Num_Boleto: %d", b->num);
  printf("Data_Prox_Vencimento: %s", dta_getData(b->date));
  printf("Valor da parcela: %.2f", b->valor);
}
