#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Representação do TAD: TData
//-----------
// Interface
//-----------

typedef struct data tData;

/* Funções exportadas */
/* Função cria - Aloca e retorna uma data dia/mês/ano */
tData *dta_cria(int dia, int mes, int ano);

/* Função libera � Libera  mem�ria de uma Data criada */
void dta_libera(tData *p);

/* Fun�o acessa - Retorna os valores de uma Data */
void dta_acessa(tData *p, int *dia, int *mes, int *ano);

/* Fun�o atribui - Atribui novos valores � Data */
void dta_atribui(tData *p, int dia, int mes, int ano);

/* Fun�o Intervalo - Retorna a data ap�s X dias */
tData *dta_intervalo(tData *p1, int X);

/* Fun�o Exibe � Escreve na tela a data  no formato dd/mm/aaaa */
void dta_exibe(tData *p1);

/* Fun�o getData - Retorna uma string com os valores da data no formato
 * dd/mm/aaaa*/
char *dta_getData(tData *p);

tData *somar_dias(tData *data, int num_dias);
