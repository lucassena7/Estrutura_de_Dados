// Obter as coordenadas dos pontos
// Calcular perímetro a partir dos pontos
// Exibir perímetro bonitinho
// Mostre para cada uma das pessoas (total 4)
// Seu nome, as coordenadas e perímetro de seu triângulo, classificados crescentemente pelo perímetro

//Importação de bibliotecas
#include <stdio.h>
#include <math.h>
#include <string.h>

//Definição de constantes
#define TAM 4

//Funções
float calcDist(int x1,int y1, int x2, int y2) //Função calcula distância
{
  return sqrt(pow((x1-x2),2.0) +pow((y1-y2),2.0)); //Fórmula dada em sala de aula
}

float calcPerimetro(int linha[]) //Função calcula perímetro
{
  //Declaração de variáveis
  float perim;
  float dAB=calcDist(linha[0],linha[1],linha[2],linha[3]); //calculando a distância entre A-B
  float dAC=calcDist(linha[0],linha[1],linha[4],linha[5]); //calculando a distância entre A-C
  float dBC=calcDist(linha[2],linha[3],linha[4],linha[5]); //calculando a distância entre B-C

  //atribuindo a variável 'perim' o resultado da soma das distâncias (A-B,A-C,B-C)
  perim= dAB+dAC+dBC;

  //retornando o perímetro
  return perim;  
}

void desenhaMoldura(void) //Função desenvolvida para 'exibir bonitinho'
{
  printf("\n==============================");
  printf("\n==============================");
  return;
}

void exibeResposta(char nome[], float perim, int matriz[][6])
{
	int i=0, j;
    // mostrar o perímetro calculado pelo programa
    // desenha moldura, escreve o perim, desenha a moldura
    desenhaMoldura();
    printf("\n%s - Perimetro: %.1f", nome, perim);
   	printf("\nCoordenadas: ");
   	
  	for (j=0;j<6;j++)
    {
    	printf("%d ", matriz[i][j]);
		}
	
    desenhaMoldura();
    return;
}

void ordenar (float vetor[], char vetorStr[], int tamanho)
{
	//Declaração de variáveis
	int aux , i, j,k;
  char temp[10];
	
	for (i=1; i<=tamanho-1; i++) //Iniciando o 'for' na posição '1' e indo até o penúltimo elemento
	{
		aux = vetor[i]; //'aux' recebe o valor do vetor[i]
		j = i-1; // 'j' recebe o valor de 'i' - 1
    
		while ((j >=0) && (vetor[j] > aux)) //Enquanto 'j' for >= 0 && valor percorrido por 'j' for > 'aux'
		{
			vetor[j+1] = vetor[j]; //o prox de 'j' recebe 'j'
			vetor[j] = aux; //j recebe o valor de temp

         //Experimental
         strcpy (temp, &vetorStr[i]); //Copiando a string da posição 'i' do vetor para 'temp'
     	 	 strcpy (&vetorStr[j+1], &vetorStr[j]);
     	 	 strcpy (&vetorStr[j],temp);
      
			j--; //reavaliando a posição
    }
	}
}

int main(void) 
{
  //Declaração de variáveis
  int mCoordenadas[TAM][6]; //4 pessoas - 6 coordenadas
  int temp;
  char  vNomes[TAM][10]; //4 pessoas - máx 10 caracteres
  char vNomesAux[10];
  float vPerim[TAM], auxPerim;
  int i,j,k;

//Obtendo os dados do usuário
  for(i=0;i<TAM;i++) 
  {
    printf("\nNome da %dª pessoa?",i+1);
    scanf("%s", vNomes[i]); // scanf("%s", vNomes+i)
    
    // obter as coordenadas dos pontos da pessoa i
    for (j=0;j<6;j++)
    {
      printf("Digite a coordenada %d\n",j+1);
      scanf("%d", &mCoordenadas[i][j]);
    }
    //atribuindo o valor do perímetro da pessoa 'i' no v[Perim] 
    vPerim[i]=calcPerimetro(mCoordenadas[i]);
  }

  printf("Antes da ordenacao:");
  for (i=0;i<TAM;i++)
	{
		exibeResposta(vNomes[i], vPerim[i], &mCoordenadas[i]); 
	}
  
  // organizar os vetores/matriz em ordem de perímetro
  // exibir os vetores
  for (i = 0; i < TAM; i++) //Iniciando 'i' na primeira posição
  {
    for (j = i+1; j < TAM; j++) //Iniciando 'j' na '2' posição
    {
      if (vPerim[i] > vPerim[j]) //Se o valor que está armazenado em 'i' for > que o armazenado em 'j'
      {
        auxPerim = vPerim[i];  //Armazenando o valor que está armazenado em 'i' no auxPerim
        vPerim[i] = vPerim[j]; //o valor que está armazenado em 'i' recebe o valor armazenado em 'j'
        vPerim[j] = auxPerim; //Armazenando o valor que está armazenado em 'auxPerim' em 'j'
        
        strcpy (vNomesAux, vNomes[i]);
        strcpy (vNomes[i], vNomes[j]);
        strcpy (vNomes[j], vNomesAux);
        
				for (k=0;k<6;k++)  //Percorrendo as colunas da matriz
				{
					temp =mCoordenadas[i][k]; //armazenando a a coordenada na variável 'temp'
					mCoordenadas[i][k] = mCoordenadas[j][k]; //Ordenando as coordenadas da matriz
					mCoordenadas[j][k] = temp; //Ordenando as coordenadas da matriz
				}	 
			}
    }
  }
  
  printf("\n\nDepois da ordenacao:");
  for (i=0;i<TAM;i++)
	{
		exibeResposta(vNomes[i], vPerim[i], &mCoordenadas[i]); 
	}
  return 0;
}

// Ordenei o vPerim --> {1,0,7,6} --> {0,1,6,7}Lucas
// Nomes --> {Lucas,Marcia,Paulo,Sergio} --> {Marcia,Lucas,Sergio,Paulo}
// mCoordenadas      Coordenadas
//               {L}    11  00  11  00  11 01     0
//               {M}    00  01  01  10  00 11     1
//               {S}    10  01  00  10  01 00     6
//               {P}    01  11  11  10  00 11     7  
