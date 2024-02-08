// Atividade 1: Faça um programa que obtenha o nome de 4 pessoas e as
// coordenadas dos pontos do triângulo de cada uma delas. Exiba o nome, as
// coordenadas e o perímetro de cada uma, classificados crescentemente pelo
// valor do perímetro

// Atividade 5: Altere o programa da atividade 1 para usar o TAD Triangulo

// Importação de bibliotecas
#include "tipoTriangulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de constantes
#define TAM 4

struct pessoa {
  char nome[15];
  Triangulo *T;
  float perim;
};
typedef struct pessoa tPessoa;

void preencherStru(tPessoa pessoa[]);
void exibirDadosPessoa(tPessoa pessoa[]);
void ordenarStru(tPessoa pessoa[]);

int main() {
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

    pessoa[i].T = tri_cria(x1, y1, x2, y2, x3, y3);

    pessoa[i].perim = tri_perimetro(pessoa[i].T);
  }
}

void exibirDadosPessoa(tPessoa pessoa[]) {
  // declaração de variáveis
  int i;

  for (i = 0; i < TAM; i++) {
    printf("\nNome: %s", pessoa[i].nome);

    printf("\nA: %s", tri_getTriangulo(pessoa[i].T));

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
