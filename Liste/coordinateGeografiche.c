#include <stdio.h>
#include <stdlib.h>

/* struttura per le coordinate geografiche */
struct Coordinata {
  float longitudine;
  float latitudine;
};

typedef struct Coordinata COOR;

/* lista di nodi */
struct Nodo {
  COOR c;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/******************************************************************************
 ********************************** STAMPE ************************************
 ******************************************************************************/

/* per stampare le coordinate */
void stampaCoordinata(struct Coordinata c) {
  printf("Longitudine %f%c, Latitudine %f%c\n", c.longitudine, 167, c.latitudine, 167);
}

/* per stampare una lista di coordinate */
void stampa(NODO head) {
  /* vai avanti finché ci sono coordinate */
  NODO nodo;
  nodo = head -> next;    //supero il primo nodo fittizio
  if(nodo == NULL)
    printf("Non ci sono coordinate da stampare\n\n");
  else {
    printf("Ecco tutte le coordinate:\n\n");
    int i = 1;
    while (nodo != NULL) {
      printf("Coordinata %d: ", i);
      stampaCoordinata(nodo -> c);
      i++;
      nodo = nodo -> next;
    }
    printf("\n");
  }
}

/******************************************************************************
 **************************** INSERIMENTO IN CODA *****************************
 ******************************************************************************/

/* leggi la longitudine e la latitudine di una coordinata */
COOR leggiCoordinata() {
  COOR c;       //coordinata da leggere
  printf("Introduci la longitudine della coordinata:");
  scanf("%f", &c.longitudine);
  printf("Introduci la latitudine della coordinata:");
  scanf("%f", &c.latitudine);
  return c;
}

/* inserimento di una coordinata in coda alla lista */
void inserimento(NODO head) {
  /* alloca il nodo nella memoria */
  NODO coda = malloc(sizeof(struct Nodo));
  /* riempi il campo di dati */
  coda -> c = leggiCoordinata();
  coda -> next = NULL;

  while(head -> next != NULL)   //l'ultimo nodo ha il campo next vuoto
    head = head -> next;

  /* ora head contiene l'indirizzo dell'ultimo nodo della lista */
  head -> next =coda;
  printf("Inserimento effettuato\n\n");
}

/******************************************************************************
 ************************** CANCELLAZIONE IN TESTA ****************************
 ******************************************************************************/

NODO cancellazione(NODO head) {
  NODO nodoCorrente;        //nodo corrente

  /* se la lista è vuota non cancelli nulla */
  if(head -> next == NULL) {
    printf("Non c'%c niente da cancellare\n\n", 138);
  }
  else {
    nodoCorrente = head -> next;        //nodo da deallocare
    head -> next = nodoCorrente -> next;        //indirizzo da restituire
    free(nodoCorrente);
    printf("Cancellazione effettuata\n\n");
  }
  return head;
}

/* funzione principale */
int main() {
  /* crea la lista */
  struct Nodo *lista = malloc(sizeof(struct Nodo  ));   //lista con il nodo fittizio
  lista -> next = NULL;

  int risposta = -1;      //per l'interazione con l'utente

  while (risposta != 0) {
    /* Scegli un'operazione con l'utente */
    printf("Che operazione vuoi svolgere?\n");
    printf("1 -> Inserisci una coordinata alla lista\n");
    printf("2 -> Cancella la prima coordinata della lista\n");
    printf("3 -> Visualizza la lista delle coordinate\n");
    scanf("%d%*c", &risposta);

    /* inserimento in coda*/
    if(risposta == 1) {
      inserimento(lista);
    }

    /* cancellazione in testa */
    else if(risposta == 2) {
      cancellazione(lista);
    }

    /* Visualizza la lista */
    else if(risposta == 3) {
      stampa(lista);
    }

    /* termina il programma */
    else if(risposta == 0) {
      printf("Programma finito, addio\n\n");
    }

    else
      printf("Non ha alcun significato, riprova\n\n");
  }
}
