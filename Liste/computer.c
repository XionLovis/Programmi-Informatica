#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struttura per rappresentare un computer */
struct Computer {
  char modello[30];
  int codice;
  int ip[12];
};

typedef struct Computer COMP;

/* lista dei nodi */
struct Nodo {
  COMP c;
  struct Nodo *next;
};

typedef struct Nodo NODO;

/******************************************************************************
 ********************************** STAMPE ************************************
 ******************************************************************************/

/* funzione per stampare un computer */
void stampaComputer(COMP *c) {
  printf("Modello: %s, codice identificativo: %d, IP: ", c->modello, c->codice);
  for (int i = 0; i < 12; i++) {
    /* inserire un punto ogni tre numeri */
    printf("%d", c -> ip[i]);
    if(i == 2 || i == 5 || i == 7)
      printf(".");
  }
  printf("\n\n");
}

/* funzione per stampare una lista di computer */
void stampa(NODO *lista) {
  /* se la lista è vuota non devi fare nulla */
  if(lista == NULL) {
    printf("Nessun computer nella lista\n\n");
  }
  else {
    printf("Ecco la lista dei computer:\n");
    while (lista != NULL) {
      /* stampa tutti i computer */
      stampaComputer(&(lista -> c));
      lista = lista -> next;
    }
    printf("\n\n");
  }
}

/******************************************************************************
 *********************************** RICERCA **********************************
 ******************************************************************************/

/* funzione che indica se esiste un computer nella lista */
int esisteComputer(NODO *lista, int cod) {
  int esiste = 0;			// risultato
	while(lista!=NULL && !esiste)
		/* computer corrente e' quello buono? */
		if(lista->c.codice == cod)
			esiste = 1;
		else
			lista=lista->next;
	return esiste;
}

/******************************************************************************
 ************************** CANCELLAZIONE IN TESTA ****************************
 ******************************************************************************/

void cancellazione(NODO **puntaHead) {
  /* lista vuota? */
  if(*puntaHead == NULL)
    printf("Non ci sono computer nella lista\n\n");
  /* lista non vuota */
  else {
    NODO *dealloca = *puntaHead;
    *puntaHead = (*puntaHead) -> next;
    free(dealloca);
    printf("Cancellazione effettuata\n\n");
  }
}

/******************************************************************************
 ************************** INSERIMENTO IN CODA *******************************
 ******************************************************************************/

/* funzione per leggere i dati di un computer */
void leggiComputer(NODO *head, COMP *c) {

  /* riempi il campo dati */
  printf("Dammi il modello: ");
	scanf("%s", c -> modello);
	c->modello[strlen(c->modello)-1] = '\0';

  /* leggi l'IP */
  for(int i = 0; i<12; i++) {
    printf("\nInserisci la cifra numero %d dell'IP del computer: ", i+1);
    scanf("%d", &(c->ip[i]));
    if(c->ip[i] < 0 || c->ip[i] > 9) {
      printf("Deve essere una singola cifra\n");
      i--;
    }
  }

  /* trova il codice */
  int trovato = 0;
  int cod = 1;      //codice da assegnare
  /* ripetutamente controlla se il codice attuale e' gia'
	 * assegnato, se sì passa al prossimo codice, altrimenti fermati */
  while (!trovato)
    /* verifica se cod sta nella lista */
    if(esisteComputer(head, cod))
      cod++;
    else
      trovato = 1;
  c -> codice = cod;
}

/* funzione per inserire una persona in coda alla lista */
NODO *inserimento(NODO *lista) {
  NODO *nuovoNodo;   //nuovo ultimo nodo
  nuovoNodo = malloc(sizeof(struct Nodo));
  leggiComputer(lista, &(nuovoNodo -> c));
  nuovoNodo -> next = NULL;

  if(lista == NULL)   //lista vuota
    lista = nuovoNodo;    //il nuovo diventa l'ultimo
  else {    //lista non vuota
    NODO *current = lista;
    while (current -> next != NULL)
      current = current -> next;
      current -> next = nuovoNodo;
  }
  printf("Inserimento effettuato\n\n");
  return nuovoNodo;
}

/* funzione principale */
int main() {
  int risposta = -1;      //per l'interazione con l'utente
  NODO *lista = NULL;    //crea la lista

  while (risposta != 0) {
    /* scelta dell'operazione */
    printf("Che operazione vuoi svolgere?\n");
    printf("1 -> Inserisci un computer nella lista\n");
    printf("2 -> Cancella il primo computer della lista\n");
    printf("3 -> Ricerca un computer nella lista\n");
    printf("4 -> Visualizza la lista dei computer\n");
    printf("0 -> Termina il programma\n");
    scanf("%d", &risposta);

    /* inserimento di un computer */
    if(risposta == 1) {
      lista = inserimento(lista);
    }

    /* cancellazione di un computer */
    else if(risposta == 2) {
      cancellazione(&lista);
    }

    /* ricerca di un computer */
    else if(risposta == 3) {
      int cod;    //codice identificativo
      printf("Inserisci il codice identificativo del computer che vuoi cercare\n");
      scanf("%d", &cod);
      if(esisteComputer(lista, cod))
        printf("Esiste un computer con quel codice identificativo nella lista\n\n");
      else
        printf("Non esiste un computer con quel codice identificativo nella lista\n\n");
    }

    /* visualizza la lista */
    else if(risposta == 4) {
      stampa(lista);
    }

    /* termina programma */
    else if(risposta == 0) {
      printf("Programma finito, addio\n\n");
    }

    /* numero sbagliato */
    else if(risposta != 0) {
      printf("Non ha alcun significato, riprova\n\n");
    }
  }
}
