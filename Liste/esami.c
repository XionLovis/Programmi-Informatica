#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struttura per rappresentare un esame */
struct Esame {
  char nomEsame[30];
  char nomProf[30];
  int CFU;
  int obbligatorio;
};

typedef struct Esame EXAM;

/* struttura per rappresentare una lista di nodi */
struct Nodo {
  EXAM e;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/******************************************************************************
 ***************************** INSERIMENTO IN TESTA ***************************
 ******************************************************************************/

/* funzione che legge i dati di un esame */
EXAM leggiEsame() {
  EXAM e;   //esame da leggere

  /* inserisci la materia dell'esame */
  printf("Nome dell'esame: ");
  fgets(e.nomEsame, 30, stdin);
  e.nomEsame[strlen(e.nomEsame) - 1] = '\0';    //rimuovi \n

  /* inserisci il nome del professore */
  printf("\nNome del professore: ");
  fgets(e.nomProf, 30, stdin);
  e.nomProf[strlen(e.nomProf) - 1] = '\0';    //rimuovi \n

  /* inserisci i cfu dell'esame */
  printf("CFU dell'esame: ");
  scanf("%d", &e.CFU);

  /* l'esame è obbligatorio? */
  do {
    printf("Obbligatorio (PREMI 1) o a scelta (PREMI 2)?\n");
    scanf("%d", &e.obbligatorio);
  } while(e.obbligatorio != 1 && e.obbligatorio != 2);
  return e;
}

/* funzione per inserire un esame in testa alla lista */
NODO inserimento(NODO lista) {
  /* alloca il nodo nell'heap */
  NODO testa = malloc(sizeof(struct Nodo));
  /* riempi il campo dati del nuovo nodo */
  testa -> e = leggiEsame();

  /* collega il nodo alla testa */
  testa -> next = lista;
  printf("Inserimento effettuato\n\n");

  /* aggiorna la testa della lista dentro main */
  return testa;
}

/******************************************************************************
 ************************************ STAMPE **********************************
 ******************************************************************************/

/* funzione per stampare un esame */
void stampaEsame(EXAM e) {
  printf("Materia esame: %s\n", e.nomEsame);
  printf("Nome professore: %s\n", e.nomProf);
  printf("CFU esame: %d\n", e.CFU);
  if(e.obbligatorio == 1)
    printf("Obbligatorio\n");
  else
    printf("A scelta\n");
  printf("\n");
}

/* funzione per stampare una lista di esami */
void stampa(NODO lista) {
  /* se la lista è vuota non devi fare nulla */
  if(lista == NULL)
    printf("Non ci sono esami da stampare\n\n");
  else {
    printf("Ecco la lista degli esami:\n");
    while (lista != NULL) {
      /* vai avanti finché ci sono nodi */
      stampaEsame(lista -> e);
      lista = lista -> next;
    }
    printf("\n");
  }
}

/******************************************************************************
 *************************** CANCELLAZIONE IN CODA ****************************
 ******************************************************************************/

/* funzione che cancella l'ultimo esame della lista */
void cancellazione(NODO lista) {

  /* c'è un intervallo da cancellare? */
  if(lista -> next == NULL)
    printf("Niente da cancellare\n\n");
  else {
    /* arriva in fondo alla lista */
    while (lista -> next != NULL) {
      lista = lista -> next;
    }
    /* dealloca l'ultimo nodo ed il penultimo diventa ultimo */
    free(lista -> next);
    lista -> next = NULL;
    /* stampa messaggio e termina */
    printf("Esame cancellato\n\n");
  }
}

/******************************************************************************
 ******************************* GESTIONE FILE ********************************
 ******************************************************************************/

/* funzione per l'acquisizione di una lista su file */
NODO acquisizione() {
  FILE *fp = fopen("esami.txt", "r");   //per la lettura di un file di testo
  NODO head = NULL;     //testa della lista
  NODO current;         //nodo corrente
  NODO previous;        //nodo precedente

  EXAM esame;           //un esame
  int letto;            //lettura ok o meno

  /* se non hai aperto il file non devi fare nulla */
  if(fp != NULL) {
    /* leggi il primo nodo della lista */
    letto = fread(&esame, sizeof(EXAM), 1, fp);
    if(letto) {   //almeno un cerchio è presente nella lista
      /* memorizza nell'heap il primo nodo della lista */
      head = malloc(sizeof(struct Nodo));
      head -> e = esame;

      /* tieni traccia dell'ultimo nodo letto, per collegarlo al successivo */
      previous = head;
      /* adesso leggi tutti gli altri nodi */
      do {
        /* leggi un nuovo nodo */
        letto = fread(&esame, sizeof(EXAM), 1, fp);
        if(letto) {   //se effettivamente lo ha letto
          /* memorizza nell'heap un nuovo nodo */
          current = malloc(sizeof(struct Nodo));
          current -> e = esame;

          /* collega il nodo al precedente */
          previous -> next = current;

          /* il nuovo nodo diventa il precedente */
          previous = current;
        }
        else    //il file è terminato, setta il campo next dell'ultimo nodo
          previous -> next = NULL;
      } while(letto);
        printf("Lista recuperata\n\n");
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
  FILE *fp = fopen("esami.txt", "w");   //per la scrittura di un file di testo

  /* se la lista è vuota non devi fare nulla */
  if(fp != NULL) {
    while (lista != NULL) {   //procedi fino a che hai nodi
      /* ciò che scrivi è un esame */
      fwrite(&(lista -> e), sizeof(struct Nodo), 1, fp);
      lista = lista -> next;    //vai al prossimo nodo
    }
    fclose(fp);
    printf("Salvataggio eseguito\n\n");
  }
  else
    printf("Salvataggio non eseguito\n\n");
}

/* funzione principale */
int main() {
  NODO lista = acquisizione();   //per l'interazione

  int risposta = -1;    //per l'interazione con l'utente

  while (risposta != 0) {
    /* scelta dell'operazione */
    printf("Quale operazione vuoi svolgere?\n");
    printf("1 -> Inserisci un esame\n");
    printf("2 -> Cancella l'ultimo esame della lista\n");
    printf("3 -> Visualizza la lista\n");
    printf("0 -> Termina il programma\n");
    scanf("%d", &risposta);

    /* inserimento in testa */
    if(risposta == 1) {
      lista = inserimento(lista);
    }

    /* cancellazione in coda */
    else if(risposta == 2) {
      cancellazione(lista);
    }

    /* Visualizza lista */
    else if(risposta == 3) {
      stampa(lista);
    }

    /* termina il programma */
    else if(risposta == 0) {
      printf("Programma finito, addio\n\n");
    }

    /* numero sbagliato */
    else if (risposta != 0) {
      printf("Non ha alcun significato, riprova\n\n");
    }
  }
  salvataggio(lista);
}
