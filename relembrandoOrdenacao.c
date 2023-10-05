#include <stdio.h>
#include <limits.h>

#define TAM 15

void preencherAleatorio (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	srand (time(NULL));
	
	//variando todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		//gerando um novo número aleatório e armazenando-o no vetor
		vetor[i] = 1 + rand()%50;
	}
}

//Implementação das demais funções
void ordenar (int vetor[], int tamanho)
{
	//Declaração de variáveis
	int aux, i, j;
	
	for (i=1; i<=tamanho-1; i++) //Iniciando o 'for' na posição '1' e indo até o penúltimo elemento
	{
		aux = vetor[i]; //'aux' recebe o valor do vetor[i]
		j = i-1; // 'j' recebe o valor de 'i' - 1
		while ((j >=0) && (vetor[j] > aux)) //Enquanto 'j' for >= 0 && valor percorrido por 'j' for > 'aux'
		{
			vetor[j+1] = vetor[j]; //o prox de 'j' recebe 'j'
			vetor[j] = aux; //j recebe o valor de aux
			j--; //reavaliando a posição
		}
	}
}

void exibir (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nVetor: ");
	
	//variando todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		//exibindo os valores do vetor
		printf ("%d ", vetor[i]);
	}
	
	printf ("\n");
}

int main(void) 
{
  //Declaração de variáveis
  int v[TAM];
  
  preencherAleatorio (v, TAM);

  exibir (v, TAM);
  printf ("\n");

  ordenar(v, TAM);
  
  printf ("\n");
  exibir (v, TAM);
  
  return 0;
}
