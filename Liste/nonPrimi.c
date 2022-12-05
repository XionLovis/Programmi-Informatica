#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* struttura per rappresentare una lista */
struct Nodo {
  int info;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/* funzione che determina se un numero della lista è primo o meno */
int primo(int x) {
  int i, flag;
  flag = 1;
  i = 2;

  while(i <= sqrt(x) && flag == 1) {
    if(x % i == 0)
      flag = 0;
    i++;
  }
  return flag;
}

NODO leggiLista(void) {
  NODO p, primo;
  int i, n;
  primo = NULL;

  printf("Numero di elementi: ");
  scanf("%d", &n);

  printf("Inserisci %d interi positivi: ", n);
  for ( i = 0; i < n; i++) {
    /* alloca il nodo nella memoria */
    p = malloc(sizeof(struct Nodo));
    scanf("%d", &p -> info);
    p -> next = primo;
    primo = p;
  }
  return primo;
}

void stampa(NODO p) {
  while (p != NULL) {
    /* finché ci sono elementi */
    printf("%d ", p -> info);
    p = p -> next;
  }
  printf("\n");
}

int main() {
  NODO p, q,  r;
  p = leggiLista();
  r = NULL;

  while (p != NULL) {
    if(primo(p -> info) == 0) {
      /* alloca il nodo nella memoria */
      q = malloc(sizeof(struct Nodo));
      q -> info = p -> info;
      q -> next = r;
      r = q;
    }
    p = p -> next;
  }
  stampa(r);
}
