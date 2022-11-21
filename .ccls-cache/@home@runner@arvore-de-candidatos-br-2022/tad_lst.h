#include <stdio.h>
#include <stdlib.h>

typedef struct nodo *ptr_nodo;
struct nodo {
  elemento elem;
  ptr_nodo prox;
};

typedef struct {
  ptr_nodo lista;
  int tamanho;
} lista_encadeada;

typedef lista_encadeada tipo_lista;
/* Implementações */

int tamanho(lista_encadeada le) { return le.tamanho; }

int obter_elemento(lista_encadeada le, int i, elemento *e) {
  int j;
  ptr_nodo pnodo;
  if ((i <= le.tamanho) && (i > 0)) {
    pnodo = le.lista;
    for (j = 2; j <= i; j++)
      pnodo = pnodo->prox;
    *e = pnodo->elem;
    return 1;
  } else {
    *e = VL_NULO;
    return 0;
  }
}

void inicializa_lista(lista_encadeada *le) {
  le->tamanho = 0;
  le->lista = NULL;
}

int incluir_elemento(lista_encadeada *le, int i, elemento e) {
  int j;
  ptr_nodo pnodo_incluido, pnodo_anterior;
  if ((i <= le->tamanho + 1) && (i > 0)) {
    pnodo_incluido = (ptr_nodo)malloc(sizeof(struct nodo));
    if (pnodo_incluido == NULL)
      return 0; /* FALTA MEMÓRIA */
    else {
      pnodo_incluido->elem = e;
      if (i == 1) {
        pnodo_incluido->prox = le->lista;
        le->lista = pnodo_incluido;
      } else {
        pnodo_anterior = le->lista;
        for (j = 2; j < i; j++)
          pnodo_anterior = pnodo_anterior->prox;
        pnodo_incluido->prox = pnodo_anterior->prox;
        pnodo_anterior->prox = pnodo_incluido;
      }
      le->tamanho = le->tamanho + 1;
      return 1;
    }
  } else
    return 0; /* POSIÇÃO INVÁLIDA */
}

int alterar_elemento(lista_encadeada *le, int i, elemento e) {
  int j;
  ptr_nodo pnodo;
  if ((i <= le->tamanho) && (i > 0)) {
    pnodo = le->lista;
    for (j = 2; j <= i; j++)
      pnodo = pnodo->prox;
    pnodo->elem = e;
    return 1;
  } else
    return 0; /* POSIÇÃO INVÁLIDA */
}

int excluir_elemento(lista_encadeada *le, int i) {
  int j;
  ptr_nodo pnodo_excluido, pnodo_anterior;
  if ((i <= le->tamanho) && (i > 0)) {
    if (i == 1) {
      pnodo_excluido = le->lista;
      le->lista = pnodo_excluido->prox;
    } else {
      pnodo_anterior = le->lista;
      for (j = 2; j < i; j++)
        pnodo_anterior = pnodo_anterior->prox;
      pnodo_excluido = pnodo_anterior->prox;
      pnodo_anterior->prox = pnodo_excluido->prox;
    }
    free(pnodo_excluido);
    le->tamanho = le->tamanho - 1;
    return 1;
  } else
    return 0; /* POSIÇÃO INVÁLIDA */
}

int inverte_lista(tipo_lista *le){  
}


int tamanho_quantidade_nodos(lista_encadeada l){
	int cont = 0;
	while(l.lista != NULL){
	   cont++;
	   l.lista = l.lista->prox;
	}
	return cont;
}