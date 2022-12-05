#include <stdio.h>
#include <stdlib.h>

/* struttura per rappresentare una lista */
struct Nodo {
  int info;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/* funzione che legge i dati di una lista */
NODO leggiLista() {
  NODO p, primo;
  primo = NULL;
  int numero;

  /* legge quanti numeri ci sono nella lista */
  printf("Numero di elementi: ");
  scanf("%d", &numero);

  /* legge i numeri della lista */
  printf("Inserisci %d numeri: ", numero);
  for (int i = 0; i < numero; i++) {
    /* alloca il nodo nella memoria */
    p = malloc(sizeof(struct Nodo));
    scanf("%d", &p -> info);
    p -> next = primo;
    primo = p;
  }
  return primo;
}

void stampa(NODO lista) {
  while (lista != NULL) {
    /* vai avanti finché ci sono elementi */
    printf("%d --> ", lista -> info);
    lista = lista -> next;
  }
  printf("\n");
}

/* funzione che prende un array e inverte l'ordine degli elementi */
NODO inverti(NODO lista) {
  NODO q, q1;
  q1 = NULL;

  /* vai avanti finché ci sono elementi */
  while (lista != NULL) {
    /* alloca il nodo nella memoria */
    q = malloc(sizeof(struct Nodo));
    q -> info = lista -> info;
    q -> next = q1;
    q1 = q;
    lista = lista -> next;
  }
  return q1;
}

/* funzione principale */
int main() {
  NODO lista, q;
  lista = leggiLista();
  q = inverti(lista);
  stampa(lista);
}
