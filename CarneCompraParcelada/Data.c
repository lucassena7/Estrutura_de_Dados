//--------------
// Implementa�o
//--------------

#include "Data.h"
struct data {
  int dia, mes, ano;
};
// fun�es auxiliares

int convDataDiaJuliano(int dia, int mes, int ano) {
  int A, B, C, D, E, F;
  if (mes < 3) {
    ano = ano - 1;
    mes = mes + 12;
  }
  A = (int)(ano / 100);
  B = (int)(A / 4);
  C = 2 - A + B;
  D = (int)(365.25 * (ano + 4716));
  E = (int)(30.6001 * (mes + 1));
  F = D + E + dia + 0.5 + C - 1524.5;
  return (int)(F);
}

tData *convDiaJulianoData(int juliano) {
  int A, B, C, D, E, F, G, H, I, J, K;

  A = juliano;
  if (A > 2299160) {
    B = (int)((A - 1867216.25) / 36524.25);
    C = A + 1 + B - (int)(B / 4);
  } else {
    C = A;
  }
  D = C + 1524;
  E = (int)((D - 122.1) / 365.25);
  F = (int)(E * 365.25);
  G = (int)((D - F) / 30.6001);
  H = D - F - (int)(G * 30.6001);
  if (G < 14) {
    I = G - 1;
  } else {
    I = G - 13;
  }
  if (I > 2)
    J = E - 4716;
  else
    J = E - 4715;
  if (J > 0)
    K = J;
  else
    K = abs(J + 1);
  return (dta_cria(H, I, K));
}

// funcoes EXPORTADAS do TAD Data

tData *dta_cria(int dia, int mes, int ano) {
  tData *dt = (tData *)malloc(sizeof(struct data));
  dt->dia = dia;
  dt->mes = mes;
  dt->ano = ano;
  return dt;
}

/* Fun�o libera � Libera  mem�ria de uma Data criada */
void dta_libera(tData *p) { free(p); }

/* Fun�o acessa - Retorna os valores de uma Data */
void dta_acessa(tData *p, int *dia, int *mes, int *ano) {
  *dia = p->dia;
  *mes = p->mes;
  *ano = p->ano;
  return;
}

/* Fun�o atribui - Atribui novos valores � Data */
void dta_atribui(tData *p, int dia, int mes, int ano) {
  p->dia = dia;
  p->mes = mes;
  p->dia = ano;
  return;
}

/* Fun�o Intervalo - Retorna a data ap�s X dias */
tData *dta_intervalo(tData *p, int X) {
  int juliano = convDataDiaJuliano(p->dia, p->mes, p->ano);
  juliano += X;
  return convDiaJulianoData(juliano);
}

/* Fun�o Exibe � Escreve na tela a data  no formato dd/mm/aaaa */
void dta_exibe(tData *p) { printf("%02d/%02d/%04d", p->dia, p->mes, p->ano); }
char *dta_getData(tData *p) {
  char *dt;
  dt = (char *)malloc(11);
  sprintf(dt, "%02d/%02d/%04d", p->dia, p->mes, p->ano);
  return dt;
}

char *dta_MesExtenso(tData *p) {
  char *nomemes;
  switch (p->mes) {
  case 1:
    nomemes = "janeiro";
    break;
  case 2:
    nomemes = "fevereiro";
    break;
  case 3:
    nomemes = "marco";
    break;
  case 4:
    nomemes = "abril";
    break;
  case 5:
    nomemes = "maio";
    break;
  case 6:
    nomemes = "junho";
    break;
  case 7:
    nomemes = "julho";
    break;
  case 8:
    nomemes = "agosto";
    break;
  case 9:
    nomemes = "setembro";
    break;
  case 10:
    nomemes = "outubro";
    break;
  case 11:
    nomemes = "novembro";
    break;
  case 12:
    nomemes = "dezembro";
    break;
  default:
    nomemes = "*invalido*";
  }
  return nomemes;
}

// Fim do TAD
tData *somar_dias(tData *data, int num_dias) {
  int dias_no_mes;
  while (num_dias > 0) {
    switch (data->mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      dias_no_mes = 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      dias_no_mes = 30;
      break;
    case 2:
      if ((data->ano % 4 == 0 && data->ano % 100 != 0) ||
          data->ano % 400 == 0) {
        dias_no_mes = 29;
      } else {
        dias_no_mes = 28;
      }
      break;
    default:
      dias_no_mes = 0;
      break;
    }
    if (num_dias >= dias_no_mes - data->dia + 1) {
      num_dias -= dias_no_mes - data->dia + 1;
      data->dia = 1;
      if (data->mes == 12) {
        data->mes = 1;
        data->ano++;
      } else {
        data->mes++;
      }
    } else {
      data->dia += num_dias;
      num_dias = 0;
    }
  }
  return data;
}
