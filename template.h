#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// facilitadores de função

void limpatela() { system("cls || clear"); }
void pausa() {
  printf("Aperte para continuar... ");
  getchar();
}
int sorteio(int i) { return rand() % i; }
char escolhe_opcao() { return getchar(); }
void limpar() { fflush(stdin); }
int converterInteiro(char string[20]) {}
