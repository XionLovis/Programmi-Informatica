#include <stdio.h>
#include <stdlib.h>

/* struttura per rappresentare una lista */
struct Nodo {
  int elemento;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/* funzione per stampare una lista */
void stampa(NODO lista) {
  /* vai avanti finché ci sono elementi */
  while (lista != NULL) {
    printf("%d ", lista -> elemento);
    lista = lista -> next;
  }
  printf("\n");
}

/* funzione che legge due array inseriti dall'utente */
NODO leggiArray() {
  NODO p;
  NODO primo = NULL;
  int i;
  int lunghezza;    //lunghezza dell'array

  /* leggi la lunghezza dell'array */
  printf("Quanti numeri vuoi introdurre?\n");
  scanf("%d", &lunghezza);

  /* leggi la sequenza */
  for (i = 0; i < lunghezza; i++) {
    p = malloc(sizeof(struct Nodo));
    printf("Inserisci un numero: ");
    scanf("%d", &p -> elemento);
    p -> next = primo;
    primo = p;
  }
  return primo;
}

/* funzione che prende i due array e li ordina con una merge sort */
NODO merge(NODO a, NODO b) {
  //PRE: lunghezza è la lunghezza di a1 e lunghezza2 è la lunghezza di b
  struct Nodo *primo = NULL;
  struct Nodo *c;      //array finale

  /* prima fase: ci sono elementi da copiare da entrambi gli array */
  while (a != NULL && b != NULL) {
    c = malloc(sizeof(struct Nodo));
    c -> next = primo;
    primo = c;

    /* copia da a */
    if (a -> elemento > b -> elemento) {
      c -> elemento = a -> elemento;
      a = a -> next;
    }
    /* copia da b */
    else {
      c -> elemento = b -> elemento;
      b = b -> next;
    }
  }

  while (a != NULL) {
    /* alloca c nell'heap */
    c = malloc(sizeof(struct Nodo));
    c -> elemento = a -> elemento;
    c -> next = primo;
    primo = c;
    a = a -> next;
  }

  while (b != NULL) {
    /* alloca c nell'heap */
    c = malloc(sizeof(struct Nodo));
    c -> elemento = b -> elemento;
    c -> next = primo;
    primo = c;
    b = b -> next;
  }
  return primo;
}

/* FUNZIONE PRINCIPALE */
int main() {
  NODO a;    //primo array che inserisce l'utente
  NODO b;    //secondo array che inserisce l'utente
  NODO c;

  /* creazione dei due array */
  printf("Mi occupo di prendere due array e ordinarli con un merge sort\n");
  printf("Inserisci il primo array:\n");
  a = leggiArray();
  printf("\nInserisci il secondo array:\n");
  b = leggiArray();

  /* prende gli array, li ordina e gli unisce con una merge sort */
  c = merge(a, b);

  /* stampa l'array ordinato */
  stampa(c);
}
