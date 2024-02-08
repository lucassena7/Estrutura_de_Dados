// Utilizando o TAD Racional, definido abaixo,  crie o módulo principal de um
// programa (calculadora.c) que implemente uma calculadora baseada em números
// racionais. A calculadora deve permitir que o usuário realize as operações de
// soma, subtração, multiplicação e divisão de números racionais fornecido,
// exibindo os resultados das operações na tela. Obrigatoriamente todos os
// números utilizados pela calculadora devem ser representados pelo tipo
// abstrato Racional. TAD RACIONAL:  Um número racional positivo é o que pode
// ser expresso como quociente de dois inteiros positivos:    a/b.

#include "calculadora.h"
#include <stdio.h>

int main(void) {
  Racional *rTeste1, *rTeste2, *rTest;
  int resp;

  // Teste soma
  rTeste1 = rac_cria(2, 3);
  rTeste2 = rac_cria(4, 3);
  rTest = rac_add(rTeste1, rTeste2);
  rac_exibe(rTest);

  // Teste subtração
  rTeste1 = rac_cria(4, 3);
  rTeste2 = rac_cria(2, 3);
  rTest = rac_sub(rTeste1, rTeste2);
  rac_exibe(rTest);

  // Tete multiplicação
  rTeste1 = rac_cria(4, 3);
  rTeste2 = rac_cria(2, 3);
  rTest = rac_mul(rTeste1, rTeste2);
  rac_exibe(rTest);

  // Teste divisão
  rTeste1 = rac_cria(4, 3);
  rTeste2 = rac_cria(2, 3);
  rTest = rac_divide(rTeste1, rTeste2);
  rac_exibe(rTest);

  // Teste iguais
  rTeste1 = rac_cria(2, 3);
  rTeste2 = rac_cria(2, 3);
  resp = rac_iguais(rTeste1, rTeste2);

  if (resp == 0) {
    printf("\nSucesso!");
  } else {
    printf("\nFracasso!");
  }

  return 0;
}
