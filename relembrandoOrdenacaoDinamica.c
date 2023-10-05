//Importação de bibliotecas
#include <stdio.h>
#include <string.h>

typedef struct {
	int idade;
	float salario;
} TFuncionario;

//Protótipo das funções
int menu ();
void leituraDados (TFuncionario Funcio[], int quant);
void exibirDadosPaciente (TFuncionario Funcio);
void exibirTodosPacientes (TFuncionario Funcio[], int quant);


//Main
int main(void) {
	//declaração de variáveis
	TFuncionario vFuncionario;
	int num1, op;
	
	do {
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op) {
			//Entrada de dados
			case 1: printf ("\nEntre com o valor de n: ");
			        scanf ("%d", &num1);
			        
			        leituraDados (&vFuncionario, num1);
				      break;

			//Exibir todos os pacientes
			case 2: exibirTodosPacientes (&vFuncionario, num1);
              break;
      
			//Saída
			case 3: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		system ("PAUSE");
	}
	while (op != 3);

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
	printf ("(3) Sair\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

void leituraDados (TFuncionario Funcio[], int quant) {
  //Declaração de variáveis
	int i;
  TFuncionario *vFuncio;

  vFuncio = malloc(quant*sizeof(TFuncionario)); //Armazenando memória inicialmente para 'quant' structs

  //Percorrendo o vetor
	for (i=0; i<quant; i++) {
		printf ("\nEntre com a idade do Funcionario :\n ");
		scanf("%d",&vFuncio[i].idade);

    printf ("\nEntre com o salário do Funcionario :\n ");
		scanf("%f",&vFuncio[i].salario);
  }
}

void exibirDadosPaciente (TFuncionario Funcio)
{
	printf ("\nIdade: %d\n", Funcio->idade);
	printf ("Taxa de xolesterol: %.2f\n", Funcio->salario);
}

void exibirTodosPacientes (TFuncionario Funcio[], int quant)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor que representa a agência de carros
	for (i=0;i<quant;i++)
	{
		exibirDadosPaciente (Funcio[i]);
	}
}
