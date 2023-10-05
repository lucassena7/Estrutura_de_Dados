//Importação de bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nome [30];
	float xolesterol, broteinas, toroteinas;
	char situacao[50];
} TPaciente;

//Protótipo das funções
int menu ();
int leituraDados (TPaciente* vPaciente, int quant);
void exibirDadosPaciente (TPaciente vPaciente);
void exibirTodosPacientes (TPaciente vPaciente[], int quant);
void ordenarAlfa (TPaciente vPaciente[], int tamanho);
void preencherDados(TPaciente* vPaciente);
void preencherSituacao (TPaciente* vPaciente);

//Main
int main(void) {
	//declaração de variáveis
	TPaciente vPaciente;
	int num1, num2, op, resp;
	
	do {
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op) {
			//Entrada de dados
			case 1: printf ("\nEntre com o valor de n: ");
			        scanf ("%d", &num1);
			        
			        resp = leituraDados (&vPaciente, num1);
              if (resp == 0) {
                printf ("Ocorreu erro !.\n");               
              }
              else {
                printf ("Sucesso !.\n"); 
              }
				      break;

			//Exibir todos os pacientes
			case 2: exibirTodosPacientes (&vPaciente, num1);
              break;

			//Ordenar Alfabéticamente
			case 3: ordenarAlfa (&vPaciente, num1); 
					    break;

      //Pesquisar por nome
			case 4: 
      
			//Saída
			case 5: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		system ("PAUSE");
	}
	while (op != 4);

  return 0;
}

//Implementação das demais funções
int menu () {
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Entrada de dados\n");
	printf ("(2) Exibir todos os pacientes\n");
	printf ("(3) Ordenar o struct Alfabeticamente\n");
  printf ("(4) Procurar Nome\n");
	printf ("(5) Sair\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int leituraDados (TPaciente* vPaciente, int quant) {
	//Declaração de variáveis
	int i;
	TPaciente *aux;

  aux = (TPaciente*) malloc(quant*sizeof(TPaciente));

  //verificando se a memória foi alocada
	if (aux == NULL) {
		return 0;
	} 
  else {
	//Percorrendo o vetor
	for (i=0; i<quant; i++) {
    preencherDados(&vPaciente[i]);
    
		preencherSituacao (&vPaciente[i]);
		}
    return 1;
	}
}

 void preencherDados(TPaciente* vPaciente) {
    fflush (stdin);
		printf ("\nEntre com o nome do Paciente:\n ");
		scanf("%s",vPaciente->nome);
	  
		printf ("Entre com a taxa de 'xolesterol' do paciente %s (0~100):\n", vPaciente->nome);
		scanf ("%f", &vPaciente->xolesterol);
	  
		printf ("Entre com a taxa de 'broteinas' do paciente %s (-10~10):\n", vPaciente->nome);
		scanf ("%f", &vPaciente->broteinas);

    printf ("Entre com a taxa de 'toroteinas' do paciente %s (5000~10000):\n", vPaciente->nome);
		scanf ("%f", &vPaciente->toroteinas);
 }

void preencherSituacao (TPaciente* vPaciente) {
  if ((vPaciente->xolesterol >= 30) && (vPaciente->xolesterol<= 50) && (vPaciente->broteinas>= -3) && (vPaciente->broteinas<= 7) && (vPaciente->toroteinas>= 6500) && (vPaciente->toroteinas<= 8000)) {
    //Preenchendo o campo 'situacao' do struct
	  strcpy (vPaciente->situacao, "Normal");
  }
  else if(vPaciente->xolesterol < 30) {
    strcpy (vPaciente->situacao, "Hipoxolesterol");
  }
  else if(vPaciente->xolesterol > 50) {
    strcpy (vPaciente->situacao, "Hiperxolesterol");
  }
  else if(vPaciente->broteinas < -3) {
    if (strcmp(vPaciente->situacao,"") == 0) { //Se a situação estiver 'vazia'
		  		strcpy (vPaciente->situacao, "Hipobroteina");
    }
    else { //Se a situação estiver 'vazia'
      strcat(vPaciente->situacao, "Hipobroteina");
    }
  }
  else if(vPaciente->broteinas > 7) {
    if (strcmp(vPaciente->situacao,"") == 0) { //Se a situação estiver 'vazia'
      strcpy (vPaciente->situacao, "Hiperbroteina");
		}
		else { //Se a situação estiver 'vazia'
      strcat(vPaciente->situacao, "Hiperbroteina");
		}
	}
	else if(vPaciente->toroteinas < 6500) {
    if (strcmp(vPaciente->situacao,"") == 0) { //Se a situação estiver 'vazia'
      strcpy (vPaciente->situacao, "Hipotoroteinas"); 
		}
		else { //Se a situação não estiver vazia 
      strcat(vPaciente->situacao, "Hipotoroteinas");
		}
	}
	else if(vPaciente->toroteinas > 8000) {
    if (strcmp(vPaciente->situacao,"") == 0) { //Se a situação estiver 'vazia'
      strcpy (vPaciente->situacao, "Hipertoroteinas"); 
		}
		else {//Se a situação não estiver vazia 
      strcat(vPaciente->situacao, "Hipertoroteinas");
		}
	}
}

void exibirDadosPaciente (TPaciente vPaciente)
{
	printf ("\nNome: %s\n", vPaciente.nome);
	printf ("Taxa de xolesterol: %.2f\n", vPaciente.xolesterol);
	printf ("Taxa de broteinas: %.2f\n", vPaciente.broteinas);
	printf ("Taxa de toroteinas: %.2f\n", vPaciente.toroteinas);
	printf ("Situacao: %s\n", vPaciente.situacao);
	
}

void exibirTodosPacientes (TPaciente vPaciente[], int quant)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor que representa a agência de carros
	for (i=0;i<quant;i++)
	{
		exibirDadosPaciente (vPaciente[i]);
	}
}

void ordenarAlfa (TPaciente vPaciente[], int tamanho) {
  //Declaração de variáveis
  TPaciente vPacAux;
  int i, j;

  for (i=1; i<=tamanho-1; i++) //Iniciando o 'for' na posição '1' e indo até o penúltimo elemento
	{
		vPacAux = vPaciente[i]; //'vPacAux' recebe o vPaciente[i]
		j = i-1; // 'j' recebe o valor de 'i' - 1
		while ((j >=0) && (strcmp(vPaciente[j].nome,vPacAux.nome)>0)) //Enquanto 'j' for >= 0 && valor nome do struct percorrido por 'j' for > o nome do struct 'aux'
		{
			vPaciente[j+1] = vPaciente[j]; //o prox de 'j' recebe 'j'
			vPaciente[j] = vPacAux; //j recebe o valor de vPacAux
			j--; //reavaliando a posição
		}
	}
}

void verificarPaciente (TPaciente vPaciente[], int tamanho, char nome[]) {
  //Declaração de variáveis
  int i, resp;
  
  for (i=0; i<tamanho; i++)
    {
      if (strcmp(vPaciente[i].nome, nome) == 0)
      {
        exibirDadosPaciente (vPaciente[i]);
      }
      else {
        printf ("Deseja incluir novo paciente ? (1-SIM // 2-NAO)");
        scanf ("%d", &resp);
      }
      if (resp == 1) {
        //leituraDados (TPaciente vPaciente[], int quant)
      }
      else {
        printf ("Exit");
      }
    }
}
