#include <stdio.h>
#include <stdlib.h>

/* struttura che rappresenta due punti del piano */
struct Estremo {
  float x;
  float y;
};

typedef struct Estremo EST;

/* struttura che rappresenta un segmento */
struct Segmento {
  EST estremo;
  float lunghezza;
};

typedef struct Segmento SEG;

/* lista dei nodi */
struct Nodo {
  SEG segmento;
  struct Nodo *next;
};

typedef struct Nodo NODO;

/******************************************************************************
 *********************************** STAMPE ***********************************
 ******************************************************************************/

/* funzione per stampare un segmento */
void stampaSegmento(SEG *segmento) {
  printf("Segmento con estremi (%.2f,%.2f) e lunghezza %.2f\n", segmento -> estremo.x, segmento -> estremo.y, segmento -> lunghezza);
}

/* funzione per stampare una lista di segmenti */
void stampa(NODO *lista) {
  /* se la lista è vuota non devi fare nulla */
  if(lista == NULL)
		printf("Lista vuota!\n\n");
	else {
		/* lista non vuota */
		printf("*****************\n");
		while(lista != NULL) {
			stampaSegmento(&lista -> segmento);
			lista = lista -> next;
		}
		printf("*****************\n\n");
	}
}

/******************************************************************************
 ****************************** CANCELLAZIONE *********************************
 ******************************************************************************/

/* funzione per cancellare il primo segmento con lunghezza 12 */
NODO *cancellazione(NODO *lista) {
  /* lista vuota? */
  if(lista == NULL)
    printf("Lista vuota, niente da cancellare\n\n");
  else {
    /* cancellazione in testa */
    if(lista -> segmento.lunghezza == 12) {
      NODO *dealloca = lista;
      lista = lista -> next;
      free(dealloca);
      printf("Cancellazione effettuata\n\n");
    }
    /* cancellazione non in testa */
    else {
      int trovato = 0;
      NODO *nodo = lista;
      /* vai a cercare un segmento pari a 12, se c'è */
      while (nodo -> next != NULL && !trovato)
        if(nodo -> next -> segmento.lunghezza == 12)
          trovato = 1;
        else
          nodo = nodo -> next;

      /* nodo trovato */
      if(trovato) {
        NODO *dealloca = nodo -> next;
        nodo -> next = nodo -> next -> next;
        free(dealloca);
        printf("Cancellazione effettuata\n\n");
      }
      /* nodo non trovato */
      else {
        printf("Non esistono segmenti di lunghezza 12\n\n");
      }
    }
  }
  return lista;
}

/******************************************************************************
 ****************************** INSERIMENTO IN CODA ***************************
 *****************************************************************************/

/* funzione èer leggere i dati di un segmento */
void leggiSegmento(SEG *segmento) {

  /* riempi il campo dati */
  printf("Inserisci la coordinata x dell'estremo sinistro del segmento: ");
  scanf("%f", &(segmento -> estremo.x));
  printf("Inserisci la coordinata y dell'estremo sinistro del segmento: ");
  scanf("%f", &(segmento -> estremo.y));
  do {
    /* inserisci la lunghezza */
    printf("Inserisci la lunghezza del segmento: ");
    scanf("%f", &(segmento -> lunghezza));
    if(segmento -> lunghezza <= 0)
      printf("La lunghezza deve essere positiva\n\n");
  } while(segmento -> lunghezza <= 0);
}

/* funzione per inserire un segmento in coda alla lista */
NODO *inserimento(NODO *lista) {
  NODO *nuovoNodo;    //nuovo ultimo nodo
  nuovoNodo = malloc(sizeof(struct Nodo));
  leggiSegmento(&nuovoNodo -> segmento);
  nuovoNodo -> next = NULL;

  if(lista == NULL)   //lista vuota
    lista = nuovoNodo;    //il nuovo diventa l'ultimo
  else {    //lista non vuota
    NODO *nodo = lista;
    while(nodo -> next != NULL)
      nodo = nodo -> next;
      nodo -> next = nuovoNodo;
  }
  printf("Inserimento effettuato\n\n");
  return nuovoNodo;
}

/* funzione principale */
int main() {
  int risposta = -1;    //per l'interazione con l'utente
  NODO *lista = NULL;   //crea la lista

  while (risposta != 0) {
    /* scelta dell'operazione */
    printf("Che operazione vuoi scegliere?\n");
    printf("1 -> Inserisci un segmento\n");
    printf("2 -> Cancella il primo segmento che abbia lunghezza pari a 12\n");
    printf("3 -> Visualizza la lista di segmenti\n");
    printf("0 -> Termina il programma\n");
    scanf("%d", &risposta);

    /* inserimento di un segmento */
    if(risposta == 1) {
      lista = inserimento(lista);
    }

    /* cancellazione di un segmento */
    else if(risposta == 2) {
      cancellazione(lista);
    }

    /* visualizza lista */
    else if(risposta == 3) {
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
