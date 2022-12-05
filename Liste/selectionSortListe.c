#include <stdio.h>
#include <stdlib.h>

/* struttura per rappresentare una lista */
struct Nodo {
  int numero;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/* funzione per stampare una lista di numeri */
void stampa(NODO lista) {
  /* se la lista non è vuota */
  while (lista != NULL) {
    printf("%d ", lista -> numero);
    lista = lista -> next;
  }
  printf("\n");
}

/* funzione che legge i dati di un array */
NODO leggiArray() {
  NODO p;
  NODO primo = NULL;
  int i;    //variabile contatore
  int lunghezza;    //lunghezza dell'array

  /* legge la lunghezza della sequenza */
  printf("Quanti numeri vuoi inserire?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  for (i = 0; i < lunghezza; i++) {
    p = malloc(sizeof(struct Nodo));
    printf("Inserisci un numero: ");
    scanf("%d", &p -> numero);
    p -> next = primo;
    primo = p;
  }
  return primo;
}

/* funzione che cambia la posizione di due numeri */
void exchange(int *a, int *b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

/* funzione che prende l'array e lo ordina con il selection sort */
void selectionSort(NODO a) {
  NODO p;
  /* verifica se la lista non è nulla */
  while (a != NULL) {
    p = a -> next;
    while (p != NULL) {
      if(a -> numero > p -> numero)
        exchange(&p -> numero, &a -> numero);
      p = p -> next;
    }
    a = a -> next;
  }
}

/* funzione principale */
int main() {
  NODO p;
  printf("Mi occupo di prendere un array e ordinarlo con l'algoritmo selection sort\n");
  p = leggiArray();

  /* ordina l'array */
  selectionSort(p);

  /* stampa l'array */
  printf("Array ordinato:\n");
  stampa(p);
}
