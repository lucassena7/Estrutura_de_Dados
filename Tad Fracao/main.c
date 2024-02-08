// Projete e desenvolva um novo Tipo Abstrato de Dados (TAD) que é uma fração. O nome do TAD deve ser Fracao.  Uma fração é definida por 3 (três) componentes: o numerador (como um número natural), o denominador (como um número natural maior do que zero) e o sinal (1 se positivo e -1 se negativo).
//  Implemente as funções deste TAD de modo que seja possível:
// Criar e retornar um ponteiro para uma nova fração, recebendo para isto um número natural como numerador, um número natural maior do que zero como denominador e 1 ou -1 dependendo do sinal da fração.
// Exibir na tela uma fração no seguinte formato : -2/3, +1/2, +3/1
// Uma função que receba 2 frações e retorne 1 se a primeira é maior que a segunda, -1 se a primeira é menor e 0 se são iguais. 
// Uma função para liberar uma fração.
// Acessar o numerador e denominador ( funções separadas) ( get)
// Modificar o numerador e denominador ( funções separadas)(set)
// Modificar uma fração ( numerador e denominador simultaneamente) 
// Acessar uma fração ( numerador e denominador simultaneamente) 

// Observe que você deve então escrever os arquivos fracao.c e fracao.h.

#include <stdio.h>
#include "fracao.h"
int main(void) {
  Fracao *f1, *f2, *f3;

  f1 = fra_cria(2, 3, -1);

  fra_exibe(f1);
  
  f2 = fra_cria(1, 2, 1);

  fra_exibe(f2);

  f3 = fra_cria(3, 1, 1);

  fra_exibe(f3);
  
  return 0;
}
