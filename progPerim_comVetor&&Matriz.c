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

float calcPerimetro(int linha[]) {//Função calcula perímetro

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

void exibeResposta(char nome[], float perim, int linha[])
{
	int i=0, j;
    // mostrar o perímetro calculado pelo programa
    // desenha moldura, escreve o perim, desenha a moldura
    desenhaMoldura();
    printf("\n%s - Perimetro: %.1f", nome, perim);
   	printf("\nCoordenadas: ");
   	
  	for (j=0;j<6;j++)
    {
    	printf("%d ", linha[j]);
		}
	
    desenhaMoldura();
    return;
}
void troca(float vPerim[], char vNomes[][10], int mCoordenadas[][6], int i, int k){
  int aux,j;
  char temp[10];
  float auxPerim;
  auxPerim = vPerim[i];
  vPerim[i]=vPerim[k];
  vPerim[k]=auxPerim;

  strcpy(temp, vNomes[i]);
  strcpy(vNomes[i], vNomes[k]);
  strcpy(vNomes[k],temp);

  for (j=0;j<6;j++){
      aux=mCoordenadas[i][j];
      mCoordenadas[i][j]=mCoordenadas[k][j];
      mCoordenadas[k][j] = aux;
  }
}
int buscabinaria( float  vet[], int qt, float chv, int *pos){
  int inic=0,fim=qt-1,achou=0;
  int meio;
  while (inic <=fim && !achou){
    meio=(inic+fim)/2;
    if (vet[meio]== chv){
      achou = 1;
    }
    else if (vet[meio] > chv)
      fim=meio-1;
    else
      inic=meio+1;
  }
  if (achou == 1){
    *pos=meio;
    return 1;
  }
  else{
    *pos=inic;
    return 0;
  }


  
}
void ordenar (float vPerim[], char vNomes[][10], int mCoordenadas[][6],int tamanho){
	//Declaração de variáveis
	int aux , i, j,k,ultTroca;
  char temp[10];
  float auxPerim;
	int fimDesordenado;
	for(fimDesordenado=tamanho;fimDesordenado>0;fimDesordenado=ultTroca){
     ultTroca= 0;
		 for (i=0;i<fimDesordenado-1;i++) {
       if (vPerim[i] > vPerim[i+1]){
         ultTroca=i;
         troca(vPerim,vNomes,mCoordenadas,i,i+1);
      }
       else if (vPerim[i] == vPerim[i+1])
         if (strcmp(vNomes[i], vNomes[i+1])>0){



           ultTroca=i;
           troca(vPerim,vNomes,mCoordenadas,i,i+1);
           }
      }

  }
}

int main(void) 
{
  //Declaração de variáveis
  int mCoordenadas[TAM][6]={{5,6,7,8,3,4},{4,5,7,6,8,9},{5,6,7,8,3,4},{4,5,7,6,8,9}}; //4 pessoas - 6 coordenadas
  int i;
  char  vNomes[TAM][10] = {"nana","kaka","lulu","juju"}; //4 pessoas - máx 10 caracteres
 
  float vPerim[TAM];
  

//Obtendo os dados do usuário
  /*
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
 */
  // usando os dados atribuídos
  for(i=0;i<TAM;i++){
    vPerim[i]=calcPerimetro(mCoordenadas[i]);
  }
  
  printf("\n\n\nAntes da ordenacao:");
  for (i=0;i<TAM;i++)
	{
		exibeResposta(vNomes[i], vPerim[i], mCoordenadas[i]); 
	}
  
  // organizar os vetores/matriz em ordem de perímetro
  ordenar(vPerim,vNomes,mCoordenadas,TAM);
  
  printf("\n\n\n\n\Depois da ordenacao:");
  for (i=0;i<TAM;i++)
	{
		exibeResposta(vNomes[i], vPerim[i], mCoordenadas[i]); 
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
