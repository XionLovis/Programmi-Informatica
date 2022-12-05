/* programma che prende una lista di interi in ordine crescente e completa la
 * lista con i numeri mancanti */
#include <stdio.h>
#include <stdlib.h>

/* struttura per rappresentare una lista */
struct Nodo {
  int numero;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/* funzione per stampare una lista */
void stampa(NODO lista) {
  /* vai avanti finché ci sono elementi */
  while (lista != NULL) {
    printf("%d; ", lista -> numero);
    lista = lista -> next;
  }
  printf("\n");
}

/* funzione che legge una sequenza di numeri interi */
NODO leggiLista() {
  NODO p;
  NODO primo;   //nodo da restituire
  int i;        //variabile contatore
  int lunghezza;  //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  do {
    printf("Inserisci la lunghezza della lista:\n");
    scanf("%d", &lunghezza);
    /* in caso la lunghezza è negativa o nulla */
    if(lunghezza <= 0)
      printf("La lunghezza deve essere positiva\n");
  } while(lunghezza <= 0);

  primo = NULL;
  printf("Inserisci %d numeri in ordine crescente\n", lunghezza);
  /* legge la sequenza */
  for (i = 0; i < lunghezza; i++) {
    printf("Dammi un numero: \n");
    /* alloca p nell'heap */
    p = malloc(sizeof(struct Nodo));
    scanf("%d", &p -> numero);
    p -> next = primo;
    primo = p;
  }

  return primo;
}

/* funzione che completa una lista con i numeri mancanti in essa */
void completa(NODO p) {
  NODO q;

  while (p -> next != NULL) {
    /* se il l'elemento attuale è più grande dell'elemento prossimo */
    if (p -> numero > p -> next -> numero + 1) {
      /* alloca q nell'heap */
      q = malloc(sizeof(struct Nodo));
      q -> numero = p -> next -> numero + 1;
      q -> next = p -> next;
      p -> next = q;
    }
    else
      p = p -> next;
  }
}

/* funzione principale */
int main() {
  NODO p;

  printf("Mi occupo di prendere una lista e completarla con i numeri che le mancano\n");
  p = leggiLista();

  /* completa la lista */
  completa(p);

  /* stampa la lista */
  printf("Ecco la lista completa: \n");
  stampa(p);
}
