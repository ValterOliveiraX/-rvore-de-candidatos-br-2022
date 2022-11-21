#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodo *ptrNodo;
struct nodo {
  elemento info;
  ptrNodo esq, dir;
};

typedef ptrNodo tree;

void define(tree *t) { *t = NULL; }

void criaRaiz(tree *t, elemento item) {
  tree no;
  no = (ptrNodo)malloc(sizeof(struct nodo));
  no->esq = NULL;
  no->dir = NULL;
  strcpy(no->info, item);
  *t = no;
}

int vazia(tree t) { return (t == NULL); }

ptrNodo localiza(tree t, elemento item) {
  ptrNodo locesq, locdir;
  locesq = NULL;
  locdir = NULL;
  if (strcmp(t->info, item) != 0) {
    if (t->esq != NULL)
      locesq = localiza(t->esq, item);
    if (locesq == NULL) {
      if (t->dir != NULL)
        locdir = localiza(t->dir, item);
      if (locdir == NULL)
        return NULL;
      else
        return locdir;

    } else
      return locesq;
  } else
    return t;
}

int adicionarDir(tree t, elemento item_pai, elemento item) {
  tree pai, no;
  pai = localiza(t, item_pai);
  if (pai != NULL)
    if (pai->dir != NULL)

      return 0;
    else {

      no = (ptrNodo)malloc(sizeof(struct nodo));

      no->esq = NULL;
      no->dir = NULL;
      strcpy(no->info, item);
      pai->dir = no;

      return 1;
    }
}

int adicionarEsq(tree t, elemento item_pai, elemento item) {
  tree pai, no;
  pai = localiza(t, item_pai);
  if (pai != NULL)
    if (pai->esq != NULL)
      return 0;
    else {

      no = (ptrNodo)malloc(sizeof(struct nodo));

      no->esq = NULL;
      no->dir = NULL;
      strcpy(no->info, item);
      pai->esq = no;

      return 1;
    }
}

int grau(tree t) { // quantidade de nodos à direita
   if (t==NULL)
      return 0;
   else
      if (t->dir == NULL)
         return 1;
      else
         return (1 + grau(t->dir));
}
/**

void imprime_grau_nivel(tree t, int n) { // inicialmente o n=1
   printf(grau(t->esq));
   printf(n); //nivel
   if (t->esq != NULL)
      imprime_grau_nivel(t->esq, n+1);
   if (t->dir != NULL)
      imprime_grau_nivel(t->dir, n);
}

void nivelOrd(tree t, int n) { 
   if (t != NULL) { 
      nivelOrd(t->esq, n+1); // percorre subarvore esq 
      printf("%s - %d\n", t->info, n);       
      // se quiser grauNodo printf("%s\n - %d", t->info, n, grauNodo(t));       
      nivelOrd(t->dir, n); // percorre subarvore dir // 
   } 
}









*/