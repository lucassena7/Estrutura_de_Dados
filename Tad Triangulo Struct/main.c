// Atividade 1: Faça um programa que obtenha o nome de 4 pessoas e as
// coordenadas dos pontos do triângulo de cada uma delas. Exiba o nome, as
// coordenadas e o perímetro de cada uma, classificados crescentemente pelo
// valor do perímetro

// Atividade 3: Altere o programa da atividade 1 para struct  e com o TAD ponto
// para as coordenadas ( vetor de pontos)

// Importação de bibliotecas
#include "tipoPonto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de constantes
#define TAM 4

// Declaração do struct
struct pessoa {
  char nome[15];
  Ponto *A, *B, *C;
  float perim;
};
typedef struct pessoa tPessoa;

// Protótipo das funções
void preencherStru(tPessoa pessoa[]);
void exibirDadosPessoa(tPessoa pessoa[]);
void ordenarStru(tPessoa pessoa[]);

int main(void) {
  tPessoa pess[TAM];

  preencherStru(pess);

  printf("\nStruct antes da ordenacao: ");
  exibirDadosPessoa(pess);

  ordenarStru(pess);

  printf("\nStruct depois da ordenacao:\n ");
  exibirDadosPessoa(pess);

  return 0;
}

void preencherStru(tPessoa pessoa[]) {
  int i;
  float x1, x2, x3, y1, y2, y3;

  for (i = 0; i < TAM; i++) {
    printf("\nEntre com o nome da Pessoa %d:\n ", i + 1);
    scanf("%s", pessoa[i].nome);

    // obter as coordenadas dos pontos
    printf("Digite a coordenada x1\n");
    scanf("%f", &x1);

    printf("Digite a coordenada y1\n");
    scanf("%f", &y1);

    printf("Digite a coordenada x2\n");
    scanf("%f", &x2);

    printf("Digite a coordenada y1\n");
    scanf("%f", &y2);

    printf("Digite a coordenada x3\n");
    scanf("%f", &x3);

    printf("Digite a coordenada y3\n");
    scanf("%f", &y3);

    pessoa[i].A = pto_cria(x1, y1);
    pessoa[i].B = pto_cria(x2, y2);
    pessoa[i].C = pto_cria(x3, y3);

    pessoa[i].perim = pto_distancia(pessoa[i].A, pessoa[i].B) +
                      pto_distancia(pessoa[i].A, pessoa[i].C) +
                      pto_distancia(pessoa[i].B, pessoa[i].C);
  }
}
void exibirDadosPessoa(tPessoa pessoa[]) {
  // declaração de variáveis
  int i;

  for (i = 0; i < TAM; i++) {
    printf("\nNome: %s", pessoa[i].nome);

    printf("\nA: %s", pto_getPonto(pessoa[i].A));
    printf("\nB: %s", pto_getPonto(pessoa[i].B));
    printf("\nC: %s", pto_getPonto(pessoa[i].C));

    printf("\nPerimetro: %.2f\n", pessoa[i].perim);
  }
}

void ordenarStru(tPessoa *pessoa) {
  // Declaração de variáveis
  int i, j;
  tPessoa aux;

  for (i = 0; i < TAM - 1; i++) {
    for (j = i + 1; j < TAM; j++) {
      if (pessoa[i].perim > pessoa[j].perim) {
        aux = pessoa[j];
        pessoa[j] = pessoa[i];
        pessoa[i] = aux;
      }
    }
  }
}
