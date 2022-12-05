#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* struttura per rappresentare un film */
struct Film {
  char nomeFilm[20];
  char nomeRegista[20];
  int anno;
  int magg18;
};

typedef struct Film FILM;

/* struttura per rappresentare una lista */
struct Nodo {
  FILM film;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/******************************************************************************
 ************************** INSERIMENTO IN TESTA ******************************
 ******************************************************************************/

/* funzione che legge i dati di un film */
FILM leggiFilm() {
  FILM film;

  /* inserisci il nome del film */
  printf("Nome del film: ");
  scanf("%s", &film.nomeFilm);
  /* inserisci il nome del regista */
  printf("Nome del regista: ");
  scanf("%s", &film.nomeRegista);
  /* inserisci l'anno di uscita */
  printf("Anno di uscita: ");
  scanf("%d", &film.anno);
  /* determina se è vietato a minore di 18 */
  do {
    printf("E' vietato a minori di 18 anni? (SI = 1, NO = 0)\n");
    scanf("%d", &film.magg18);
    if(film.magg18 != 1 && film.magg18 != 0)
      printf("Non %c un valore valido\n", 138);
  } while(film.magg18 != 1 && film.magg18 != 0);
  printf("\n");
  return film;
}

/* funzione che inserisce un film in testa alla lista */
NODO inserimento(NODO lista) {
  NODO nuovo = malloc(sizeof(struct Nodo));   //alloca il nodo nell'heap

  /* riempie il campo dati del nuovo nodo */
  nuovo -> film = leggiFilm();
  printf("\n");

  /* collega il nodo alla testa */
  nuovo -> next = lista;
  printf("Inserimento effettuato\n\n");

  /* aggiorna la testa della lista */
  return nuovo;
}

/******************************************************************************
 ********************************* STAMPE *************************************
 ******************************************************************************/

/* funzione per stampare un film */
void stampaFilm(FILM film) {
  /* stampa il nome del film */
  printf("Film: %s\n", film.nomeFilm);
  /* stampa il nome del regista */
  printf("Regista: %s\n", film.nomeRegista);
  /* stampa l'anno di uscita */
  printf("Anno: %d\n", film.anno);
  /* è vietato a minori di 18? */
  if(film.magg18 == 1)
    printf("Vietato ai menori di 18 anni\n");
  else
    printf("Non vietato ai menori di 18 anni\n");
  printf("\n");
}

/* funzione per stampare una lista */
void stampa(NODO lista) {
  /* se la lista è vuota, non devi fare nulla */
  if(lista == NULL)
    printf("Non ci sono film nella lista\n\n");
  else {
    printf("Ecco la lista di film:\n");
    while (lista != NULL) {
      stampaFilm(lista -> film);
      lista = lista -> next;
    }
    printf("\n");
  }
}

/******************************************************************************
 ************************** CANCELLAZIONE IN CODA *****************************
 ******************************************************************************/

/* funzione per cancellare l'ultimo elemento della lista */
NODO cancellazione(NODO lista) {

  /* se la lista è vuota, non devi fare nulla */
  if(lista -> next == NULL)
    printf("Niente da cancellare\n\n");
  else {
    /* arriva in fondo alla lista */
    while (lista -> next != NULL) {
      lista = lista -> next;
    }
    /* ora lista ha l'indirizzo dell'ultimo elemento della lista */
    free(lista -> next);
    lista -> next = NULL;
    /* stampa il messaggio e termina */
    printf("Film cancellato\n\n");
  }
  return lista;
}

/******************************************************************************
 ****************************** GESTIONE FILE *********************************
 ******************************************************************************/

/* funzione per l'acquisizione di una lista su file */
NODO acquisizione() {
  FILE *fp = fopen("film.txt", "r");    //per la lettra di un file di testo
  NODO head = NULL;       //testa della lista
  NODO current;           //nodo corrente
  NODO previous;          //nodo precedente

  FILM film;              //un film
  int letto;              //lettura ok o meno

  /* se la lista è vuota non devi fare nulla */
  if(fp != NULL) {
    /* leggi il primo nodo della lista */
    letto = fread(&film, sizeof(FILM), 1, fp);
    if(letto) {   //se effettivamente lo ha letto
      /* memorizza nell'heap il primo nodo della lista */
      head = malloc(sizeof(struct Nodo));
      head -> film = film;

      /* tieni traccia del nodo precedente */
      previous = head;
      /* ora leggi tutti gli altri nodi */
      do {
        /* leggi un nuovo nodo */
        letto = fread(&film, sizeof(FILM), 1, fp);
        if (letto) {    //se effettivamente lo ha letto
          /* memorizza nell'heap il nuovo nodo */
          current = malloc(sizeof(struct Nodo));
          current -> film = film;

          /* collega il nodo al precedente */
          previous -> next = current;

          /* il nuovo nodo diventa il precedente */
          previous = current;
        }
        else    //setta il campo next dell'ultimo nodo, il file è terminato
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

/* funzione per salvataggio di una lista su file */
void salvataggio(NODO lista) {
  FILE *fp = fopen("film.txt", "w");    //per la scrittura di un file di testo

  /* se la lista è vuota non devi fare nulla */
  if (fp != NULL) {
    while (lista != NULL) {   //procedi finché hai nodi
      /* ciò che scrivi è un film */
      fwrite(&(lista -> film), sizeof(struct Nodo), 1, fp);
      lista = lista -> next;
    }
    fclose(fp);
    printf("Salvataggio eseguito\n\n");
  }
  else
    printf("Salvataggio non eseguito\n\n");
}

/* funzione principale */
int main() {
  NODO lista = acquisizione();      //crea la lista
  int risposta = -1;                //per l'interazione con l'utente

  while (risposta != 0) {
    /* scelta dell'operazione */
    printf("Che operazione vuoi svolgere?\n");
    printf("1 -> Inserisci un film\n");
    printf("2 -> Cancella l'ultimo film della lista\n");
    printf("3 -> Visualizza la lista di film\n");
    printf("0 -> Termina il programma\n");
    scanf("%d", &risposta);

    /* inserisci in testa */
    if (risposta == 1) {
      lista = inserimento(lista);
    }

    /* cancella in coda */
    else if (risposta == 2) {
      lista = cancellazione(lista);
    }

    /* Visualizza lista */
    else if (risposta == 3) {
      stampa(lista);
    }

    /* termina programma */
    else if (risposta == 0) {
      printf("Programma terminato, addio\n\n");
    }

    /* numero sbagliato */
    else if (risposta != 0) {
      printf("Non ha alcun significato, riprova\n\n");
    }
  }
  salvataggio(lista);
}
