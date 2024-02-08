// Faça um programa para emitir o carnê de pagamento de uma compra parcelada sem
// entrada. A data da compra, o valor a ser parcelado e o número (n) de parcelas
// será perguntado ao usuário.

// Em cada boleto deverá constar o número do boleto (1 a n), a data do
// vencimento e o valor do boleto. O intervalo entre as parcelas é de 20 dias.

// a) Resolva o problema utilizano apenas o TAD DATA
// b) Resolva o problema utilizando o TAD BOLETO

// Importação de bibliotecas
#include "Boleto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de constantes
struct carne {
  tData *dataCompra;
  tBoleto *b;
  float valor;
  int numParc;
};
typedef struct carne tCarne;

void preencherStru(tCarne *pessoa);
void exibirDados(tCarne *pessoa);

int main() {
  tCarne pess;

  preencherStru(&pess);

  exibirDados(&pess);

  printf("\n\n");

  return 0;
}
void preencherStru(tCarne *pessoa) {
  int day, month, year, parc;
  float valor;

  printf("\nEntre com o dia:\n ");
  scanf("%d", &day);
  printf("\nEntre com o mes:\n ");
  scanf("%d", &month);
  printf("\nEntre com o ano:\n ");
  scanf("%d", &year);

  pessoa->dataCompra = dta_cria(day, month, year);

  printf("\nEntre com o valor do produto:\n ");
  scanf("%f", &pessoa->valor);

  printf("\nEntre com o nmr de parcelas:\n ");
  scanf("%d", &pessoa->numParc);

  pessoa->b = bol_cria(1, day, month, year, (valor / pessoa->numParc));
}

void exibirDados(tCarne *pessoa) {
  printf("\nData de compra: %s\n", dta_getData(pessoa->dataCompra));
  printf("\nValor do produto: %.2f", pessoa->valor);
  printf("\nNumero de parcelas: %d\n", pessoa->numParc);
  printf("\nBoleto: %s", bol_getBoleto(pessoa->b));
}
