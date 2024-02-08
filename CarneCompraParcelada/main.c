// Faça um programa para emitir o carnê de pagamento de uma compra parcelada sem
// entrada. A data da compra, o valor a ser parcelado e o número (n) de parcelas
// será perguntado ao usuário.

// Em cada boleto deverá constar o número do boleto (1 a n), a data do
// vencimento e o valor do boleto. O intervalo entre as parcelas é de 20 dias.

// a) Resolva o problema utilizano apenas o TAD DATA

// Importação de bibliotecas
#include "Data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de constantes
struct carne {
  tData *D;
  float valorParc;
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

  for (int i = 0; i < pess.numParc; i++) {
    printf("Boleto %d\n", i + 1);
    printf("Valor: R$ %.2f\n", pess.valorParc);
    pess.D = somar_dias(pess.D, 20);
    printf("Vencimento: %s\n", dta_getData(pess.D));
  }
  return 0;
}

void preencherStru(tCarne *pessoa) {
  int day, month, year;
  float valor;

  printf("\nEntre com o dia:\n ");
  scanf("%d", &day);
  printf("\nEntre com o mes:\n ");
  scanf("%d", &month);
  printf("\nEntre com o ano:\n ");
  scanf("%d", &year);

  pessoa->D = dta_cria(day, month, year);

  printf("\nEntre com o valor do produto:\n ");
  scanf("%f", &valor);

  printf("\nEntre com o nmr de parcelas:\n ");
  scanf("%d", &pessoa->numParc);

  pessoa->valorParc = valor / pessoa->numParc;
}

void exibirDados(tCarne *pessoa) {
  printf("\nData de compra: %s", dta_getData(pessoa->D));

  printf("\nNumero de parcelas: %d", pessoa->numParc);

  printf("\nValor de cada parcela: %.2f\n", pessoa->valorParc);
}
