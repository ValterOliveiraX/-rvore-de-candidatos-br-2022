#include "template.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura de entrada da base de dados;

typedef struct {
  char DT_GERACAO[20];
  char HH_GERACAO[20];
  char ANO_ELEICAO[20];
  char CD_TIPO_ELEICAO[20];
  char NM_TIPO_ELEICAO[20];
  char CD_PLEITO[20];
  char DT_PLEITO[20];
  char NR_TURNO[20];
  char CD_ELEICAO[20];
  char DS_ELEICAO[20];
  char SG_UF[20];
  char CD_MUNICIPIO[20];
  char NM_MUNICIPIO[20];
  char NR_ZONA[20];
  char NR_SECAO[20];
  char NR_LOCAL_VOTACAO[20];
  char CD_CARGO_PERGUNTA[20];
  char DS_CARGO_PERGUNTA[20];
  char NR_PARTIDO[20];
  char SG_PARTIDO[20];
  char NM_PARTIDO[50];
  char DT_BU_RECEBIDO[20];
  char QT_APTOS[20];
  char QT_COMPARECIMENTO[20];
  char QT_ABSTENCOES[20];
  char CD_TIPO_URNA[20];
  char DS_TIPO_URNA[20];
  char CD_TIPO_VOTAVEL[20];
  char DS_TIPO_VOTAVEL[20];
  char NR_VOTAVEL[20];
  char NM_VOTAVEL[20];
  char QT_VOTOS[20];
  char NR_URNA_EFETIVADA[20];
  char CD_CARGA_1_URNA_EFETIVADA[20];
  char CD_CARGA_2_URNA_EFETIVADA[20];
  char CD_FLASHCARD_URNA_EFETIVADA[20];
  char DT_CARGA_URNA_EFETIVADA[20];
  char DS_CARGO_PERGUNTA_SECAO[20];
  char DS_AGREGADAS[20];
  char DT_ABERTURA[20];
  char DT_ENCERRAMENTO[20];
  char QT_ELEITORES_BIOMETRIA_NH[20];
  char DT_EMISSAO_BU[20];
  char NR_JUNTA_APURADORA[20];
  char NR_TURMA_APURADORA[20];
} Dados;
typedef Dados elemento;
const elemento VL_NULO = {"", "", "", "", "", "", "", "", "", "", "", "",
                          "", "", "", "", "", "", "", "", "", "", "", "",
                          "", "", "", "", "", "", "", "", "", "", "", "",
                          "", "", "", "", "", "", "", "", ""};
//#include "tad_lst.h"
// tipo_lista lista;

/*PROTÓTIPOS DAS VARIÁVEIS*/
void imprimir(elemento e);
void abrir_dados();
void montaTela();

//++++++ MAIN +++++++++
int main() {
  int op;
  elemento elem;

  do {

    montaTela();
    scanf("%d", &op);
    abrir_dados();
    switch (op) {

    case 1:
      limpatela();
      abrir_dados();
      break;

    case 2:
      limpatela();
      break;

    case 3:
      limpatela();
      break;

    case 4:
      exit(1);
      break;
    }

  } while (1);

  return 0;
}

//-------------FUNCOES -----------

// carregar dados;
void abrir_dados() {
  char S[20];
  elemento e;
  char *ptr;
  FILE *arq;
  int i = 0;
  int fgetc(FILE * arq);
  arq = fopen("dadosMA.csv", "r");
  e = VL_NULO;
  int contador;
  while (EOF != fscanf(arq, "%[^\n]\n", S)) {
    ptr = strtok(S, "\";");
    strcpy(e.DT_GERACAO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.HH_GERACAO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.ANO_ELEICAO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.CD_TIPO_ELEICAO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NM_TIPO_ELEICAO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.CD_PLEITO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DT_PLEITO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NR_TURNO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.CD_ELEICAO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DS_ELEICAO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.SG_UF, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.CD_MUNICIPIO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NM_MUNICIPIO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NR_ZONA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NR_SECAO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NR_LOCAL_VOTACAO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.CD_CARGO_PERGUNTA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DS_CARGO_PERGUNTA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NR_PARTIDO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.SG_PARTIDO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NM_PARTIDO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DT_BU_RECEBIDO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.QT_APTOS, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.QT_COMPARECIMENTO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.QT_ABSTENCOES, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.CD_TIPO_URNA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DS_TIPO_URNA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.CD_TIPO_VOTAVEL, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DS_TIPO_VOTAVEL, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NR_VOTAVEL, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NM_VOTAVEL, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.QT_VOTOS, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NR_URNA_EFETIVADA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.CD_CARGA_1_URNA_EFETIVADA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.CD_CARGA_2_URNA_EFETIVADA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.CD_FLASHCARD_URNA_EFETIVADA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DT_CARGA_URNA_EFETIVADA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DS_CARGO_PERGUNTA_SECAO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DS_AGREGADAS, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DT_ABERTURA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DT_ENCERRAMENTO, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.QT_ELEITORES_BIOMETRIA_NH, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.DT_EMISSAO_BU, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NR_JUNTA_APURADORA, ptr);
    ptr = strtok(NULL, "\";");
    strcpy(e.NR_TURMA_APURADORA, ptr);
    contador = contador + e.QT_VOTOS;
    i++;

    // incluir_elemento(&lista, i, e);
    // IMPRIMIR temp -----------------------------------||||||
    imprimir(e);
    pausa();
  }
  /*INFO*/
  // e.NM_VOTAVEL - nome do candidato
  // e.NR_VOTAVEL - número do candidato
  // QT_VOTOS  - quantidade de votos por sesão
  printf("quantidade total de votos: %d", contador);

  fclose(arq);
}
// imprimir;
void imprimir(elemento e) {
  printf("\n----- Exibindo dados --------\n");
  printf("NR_ZONA: %s\n", e.NR_ZONA);
  printf("NR_SECAO: %s\n", e.NR_SECAO);
  printf("QT_APTOS: %s\n", e.QT_APTOS);
  printf("QT_COMPARECIMENTO: %s\n", e.QT_COMPARECIMENTO);
  printf("QT_ABSTENCOES: %s\n", e.QT_ABSTENCOES);
  printf("NR_VOTAVEL: %s\n", e.NR_VOTAVEL);
  printf("NM_VOTAVEL: %s\n", e.NM_VOTAVEL);
  printf("QT_VOTOS: %s\n", e.QT_VOTOS);
  printf("\n-----------------------------\n");
}

void montaTela() {
  printf("\n- Análise de dados Candidatos -\n");
  printf("1\t Carregar dados;\n");
  printf("2\t Listar zona eleitoral;\n");
  printf("3\t Informar quant.votos determinada zona eleitoral;\n");
  printf("4\t Informar em qual Zona Eleitoral\n\t onde um determinado candidato obteve a\n\t "
         "maior porcentagem de votos.\n");
  printf("\nopção escolhida ->  ");
}




int converter(char valor[10]){
  atoi(valor);
}
