#include <stdio.h>
#include <stdlib.h>

/* struttura per rappresentare un libro */
struct Libro {
  char nomLibro[20];
  char nomAutore[20];
  int pagine;
  int edizione;
};

typedef struct Libro LIBRO;

/* struttura per rappresentare una lista */
struct Nodo {
  LIBRO l;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/******************************************************************************
 ************************** INSERIMENTO IN CODA *******************************
 ******************************************************************************/

/* funzione che legge i dati di un libro */
LIBRO leggiLibro() {
  LIBRO l;    //libro da leggere

  /* inserisci il nome del libro */
  printf("Inserisci il nome del libro: ");
  scanf("%s", &l.nomLibro);

  /* inserisci il nome dell'autore */
  printf("Inserisci il nome dell'autore: ");
  scanf("%s", &l.nomAutore);

  /* numero di pagine */
  printf("Inserisci il numero di pagine: ");
  scanf("%d", &l.pagine);

  do {
    /* determina se il libro è prima edizione o una ristampa */
    printf("Inserisci se %c una prima edizione (PREMI 1) o una ristampa (PREMI 2): ");
    scanf("%d", &l.edizione);
  } while(l.edizione != 1 && l.edizione != 2);
  return l;
}

/* funzione che inserisce un libro in coda alla lista */
NODO inserimento(NODO lista) {
  NODO nuovo;     //nuovo nodo della lista
  nuovo = malloc(sizeof(struct Nodo));    //alloca il nodo nell'heap

  /* riempi i campi del nuovo nodo */
  nuovo -> l = leggiLibro();
  printf("\n");
  nuovo -> next = NULL;

  /* se la lista è vuota questo è il primo elemento */
  if(lista == NULL)
    lista = nuovo;
  else {
    NODO current = lista;
    while (current -> next != NULL)
      current = current -> next;
      current -> next = nuovo;
  }
  printf("Inserimento effettuato\n\n");
  return nuovo;
}

/******************************************************************************
 *********************************** STAMPE ***********************************
 ******************************************************************************/

/* funzione per stampare un libro */
void stampaLibro(LIBRO l) {
  /* nome del libro */
  printf("Nome del libro: %s\n", l.nomLibro);
  /* nome dell'autore */
  printf("Nome dell'autore: %s\n", l.nomAutore);
  /* numero di pagine */
  printf("Numero di pagine: %d\n", l.pagine);
  /* prima edizione o ristampa */
  if(l.edizione == 1)
    printf("Prima edizione\n");
  else
    printf("Ristampa\n");
  printf("\n");
}

/* funzione per stampare una lista di libri */
void stampa(NODO lista) {
  /* se la lista è vuota non devi fare nulla */
  if(lista != NULL) {
    printf("Ecco la lista dei libri:\n");
    while (lista != NULL) {
      stampaLibro(lista -> l);
      lista = lista -> next;
    }
    printf("\n\n");
  }
  else
    printf("Non ci sono libri nella lista\n\n");
}

/******************************************************************************
 ******************************* CANCELLAZIONE IN TESTA ***********************
 ******************************************************************************/

/* funzione che cancella il primo libro di una lista */
NODO cancellazione(NODO lista) {
  NODO nodoCorrente;    //nodo corrente

  /* se la lista è vuota non cancelli nulla */
  if(lista == NULL)
    nodoCorrente = NULL;
  else {
    nodoCorrente = lista -> next;     //nodo da deallocare
    free(lista);
    printf("Cancellazione effettuata\n\n");
  }
  return nodoCorrente;
}

/******************************************************************************
 ********************************** GESTIONE FILE *****************************
 ******************************************************************************/

/* funzione per l'acquisizione di una lista su file */
NODO acquisizione() {
  FILE *fp = fopen("libri.txt", "r");     //per la lettura di un file di testo
  NODO head = NULL;       //testa della lista
  NODO current;           //nodo corrente
  NODO previous;          //nodo precedente

  LIBRO libro;            //un libro
  int letto;              //lettura ok o meno

  /* se non hai aperto il file non devi fare niente */
  if(fp != NULL) {
    /* leggi il primo nodo della lista */
    letto = fread(&libro, sizeof(LIBRO), 1, fp);
    if (letto) {    //almeno un libro è presente nel file
      /* memorizza nell'heap il primo nodo della lista */
      head = malloc(sizeof(struct Nodo));
      head -> l = libro;

      /* tieni traccia dell'ultimo nodo letto, per collegarlo al successivo */
      previous = head;
      /* adesso leggi tutti gli altri nodi */
      do {
        /* leggi un nuovo nodo */
        letto = fread(&libro, sizeof(LIBRO), 1, fp);
        if (letto) {    //se effettivamente lo ha letto
          /* memorizza nell'heap un nuovo nodo */
          current = malloc(sizeof(struct Nodo));
          current -> l = libro;

          /* collega il nodo al precedente */
          previous -> next = current;

          /* il nuovo nodo diventa il precedente */
          previous = current;
        }
        else    //il file è terminato, setta il campo next dell'ultimo nodo
          previous -> next = NULL;
      } while(letto);
        printf("Lista recuperata da file\n\n");
    }
    else
      printf("Lista vuota, niente da recuperare\n\n");
      fclose(fp);
  }
  else
    printf("Apertura non riuscita\n\n");
  return head;
}

/* funzione per il salvataggio di una lista su file */
void salvataggio(NODO lista) {
  FILE *fp = fopen("libri.txt", "w");   //per la scrittura di un file di testo

  if(fp != NULL) {
    while (lista != NULL) {   //procedi finché hai nodi
      /* ciò che scrivi è un libro */
      fwrite(&(lista -> l), sizeof(struct Nodo), 1, fp);
      lista = lista -> next;    //vai avanti
    }
    fclose(fp);
    printf("Salvataggio eseguito\n\n");
  }
  else
    printf("Salvataggio non eseguito\n\n");
}

/* funzione principale */
int main() {
  NODO lista = acquisizione();    //crea la lista
  int risposta = -1;              //per l'interazione con l'utente

  while (risposta != 0) {
    /* scelta dell'operazione */
    printf("Quale operazione vuoi svolgere?\n");
    printf("1 -> Inserisci un libro nella lista\n");
    printf("2 -> Cancella il primo libro della lista\n");
    printf("3 -> Visualizza la lista di libri\n");
    printf("0 -> Termina programma\n");
    scanf("%d", &risposta);

    /* inserisci libro */
    if(risposta == 1) {
      lista = inserimento(lista);
    }

    /* cancella libro */
    else if(risposta == 2) {
      lista = cancellazione(lista);
    }

    /* Visualizza lista */
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
  salvataggio(lista);
}
