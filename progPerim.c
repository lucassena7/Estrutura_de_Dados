//Obter as coordenadas dos pontos
//Calcular o perímetro a partir dos pontos
//Exibir perímetro 'bonitinho'

//Mostre para cada uma das pessoas (total 3)
//Seu nome, as coordenadas e perímetro do seu triângulo

#include <stdio.h>
#include <math.h>
#include <string.h>

void obterUmPonto (char idPonto, int* x, int* y)
{
  printf ("\nDigite as coordenadas do ponto %c:\n", idPonto);
  scanf ("%d %d", x, y);
}

void obterPontos(int* xA,int* yA, int* xB, int* yB, int* xC,int* yC)
{
    obterUmPonto('A', xA, yA);
    obterUmPonto ('B', xB, yB);
    obterUmPonto ('C', xC, yC);
     
     return ;
}

float calcDist (int x1, int y1, int x2, int y2)
{
  return sqrt(pow((x1-x2),2.0) +pow((y1-y2),2.0));
}

float calcPerimetro (int xA, int yA, int xB, int yB, int xC, int yC)
{
  //Declaração de variáveis
  float perim;
  float dAB = calcDist (xA,  yA, xB, yB);
  float dAC = calcDist (xA, yA, xC, yC);
  float dBC = calcDist (xC, yC, xB, yB);
  perim = dAB + dAC + dBC;
  return perim;
}

void desenhaMoldura(void) //Para ela executar sua tarefa, nada é necessário.
{
  printf ("\n=====================================");
  printf ("\n=====================================");
  return;
}

void exibeResp (char nome[], float perim)
{
  //mostrar o perímetro calculado pelo programa
  //desenhe moldura, escreva o perímetro e desenhe a moldura dnv
  desenhaMoldura();

  printf ("\n%s - Perimetro: %.1f", nome, perim);

  desenhaMoldura();

  return;
}

int main(void) 
{
  //Declaração de variáveis
  int xA, yA, xB, yB, xC, yC;
  char nome[10];
  float perim;
  int i;

  for (i=0; i<3; i++)
    {
      printf ("\n\nNome da %d pessoa ?", i+1);
      gets (nome);
      //em strings não se usa o &

      obterPontos(&xA,&yA,&xB,&yB,&xC,&yC);

    perim=calcPerimetro(xA,yA,xB,yB,xC,yC);

    exibeResp(nome, perim);
    }
  return 0;
}
