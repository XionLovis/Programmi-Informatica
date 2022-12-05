#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30  //dimensione per tutti gli array e stringhe

/* struttura per rappresentare una data di nascita */
typedef struct Data {
  int giorno;
  int mese;
  int anno;
} DATA;

/* struttura per rappresentare una persona */
typedef struct Persona {
  char nome[DIM];
  char cognome[DIM];
  DATA dataDiNascita;
} PERSONA;

typedef struct Nodo {
  PERSONA p;
  struct Nodo *next;
} *NODO;

/******************************************************************************
 ************************************* STAMPE *********************************
 ******************************************************************************/

/* funzione per stampare una persona */
void stampaPersona(PERSONA p) {
  printf("Nome: %s\n", p.nome);
  printf("Cognome: %s\n", p.cognome);
  printf("Data di nascita: %d/%d/%d\n", p.dataDiNascita.giorno, p.dataDiNascita.mese, p.dataDiNascita.anno);
}

/* funzione per stampare una lista */
void stampa(NODO lista) {
  /* vai avanti finché ci sono elementi */
  if(lista == NULL)
    printf("Non ci sono persone nella lista\n\n");
  else {
    printf("Ecco la lista delle persone:\n");
    while (lista != NULL) {
      stampaPersona(lista -> p);
      lista = lista -> next;
    }
    printf("\n");
  }
}

/******************************************************************************
 ***************************** INSERIMENTO IN CODA ****************************
 ******************************************************************************/

/* funzione per leggere i dati di una persona */
PERSONA leggiPersona() {
  PERSONA p, *pipol;    //persona da leggere

  pipol = &p;

  /* Inserisci il nome della persona */
  printf("Introduci il nome della persona: ");
  scanf("%s", &p.nome);
  //fgets(p.nome, DIM, stdin);
  //(p.nome)[strlen(p.nome) - 1] = '\0';

  /* Inserisci il cognome della persona */
  printf("\nIntroduci il cognome della persona: ");
  scanf("%s", &p.cognome);
  //fgets(p.cognome, DIM, stdin);
  //(p.cognome)[strlen(p.cognome) - 1] = '\0';

  /* inserimento della data di nascita */
  printf("Inserisci la data di nascita\n");
  printf("Inserisci il giorno:");
  scanf("%d", &p.dataDiNascita.giorno);
  printf("Inserisci il mese:");
  scanf("%d", &p.dataDiNascita.mese);
  printf("Inserisci l'anno:");
  scanf("%d", &p.dataDiNascita.anno);

  return p;
}

NODO inserimento(NODO head) {
  NODO nuovoNodo;     //il nuovo nodo della lista
  nuovoNodo = malloc(sizeof(struct Nodo));

  /* riempi i campi del nuovo nodo */
  nuovoNodo -> p = leggiPersona();
  printf("\n");
  nuovoNodo -> next = head;

  /* collega il nodo alla testa */
  nuovoNodo -> next = head;
  printf("Inserimento effettuato\n\n");
  return nuovoNodo;
}

/******************************************************************************
 ************************** CANCELLAZIONE IN TESTA ****************************
 ******************************************************************************/

/* funzione per cancellare la prima persona della lista */
NODO cancellazione(NODO lista) {
  NODO nuovoNodo;
  /* se la lista è vuota, non devi fare nulla */
  if(lista == NULL)
    printf("Non ci sono persone nella lista\n\n");
  else {
    nuovoNodo = lista -> next;
    free(lista);
    printf("\nCancellazione effettuata\n\n");
  }
  return nuovoNodo;
}

/******************************************************************************
 ****************************** GESTIONE FILE *********************************
 ******************************************************************************/

/* funzione per l'acquisizione di una lista su file */
NODO acquisizione() {
  FILE *fp = fopen("persone.txt", "r");   //per la lettura di un file di testo
  NODO head = NULL;     //testa della lista
  NODO previous;        //nodo precedente
  NODO current;         //nodo corrente

  PERSONA persona;    //una persona
  int letto;    //lettura ok o meno

  /* se non hai aperto il file non devi fare nulla */
  if(fp != NULL) {
    /* leggi il primo nodo della lista */
    letto = fread(&persona, sizeof(PERSONA), 1, fp);
    if(letto) {   //almeno un cerchio è presente nel file
      /* memorizza nell'heap il primo nodo della lista */
      head = malloc(sizeof(struct Nodo));
      head -> p = persona;

      /* tieni traccia dell'ultimo nodo letto, per collegarlo al successivo */
      previous = head;
      /* adesso leggi tutti gli alri nodi */
      do {
        /* leggi un nuovo nodo */
        letto = fread(&persona, sizeof(PERSONA), 1, fp);
        if(letto) {   //se effettivamente lo ha letto
          /* memorizza nell'heap un nuovo nodo */
          current = malloc(sizeof(struct Nodo));
          current -> p = persona;

          /* collega il primo al precedente */
          previous -> next = current;

          /* il nuovo nodo diventa il precedente */
          previous = current;
        }
        else    //il file è terminato, setta il campo next del prossimo nodo
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

/* funzione per il salvataggio di una lista su un file */
void salvataggio(NODO lista) {
  FILE *fp = fopen("persone.txt", "w");   //per la scrittura di un file di testo
  if(fp != NULL) {
    while (lista != NULL) {   //procedi finché ci sono elementi
      /* ciò che scrivi è una persona */
      fwrite(&(lista -> p), sizeof(PERSONA), 1, fp);
      lista = lista -> next;    //vai avanti al prossimo nodo
    }
    fclose(fp);
    printf("Salvataggio eseguito\n\n");
  }
  else
    printf("Salvataggio non eseguito\n\n");
}

/* funzione principale */
int main() {
  /* crea la lista */
  NODO lista = acquisizione();
  int risposta = -1;      //per l'interazione con l'utente

  while (risposta != 0) {
    /* scelta dell'operazione */
    printf("Che operazione vuoi svolgere?\n");
    printf("1 -> Inserisci una persona nella lista\n");
    printf("2 -> Cancella la prima persona della lista\n");
    printf("3 -> Visualizza tutte le persone della lista\n");
    printf("0 -> Termina il programma\n");
    scanf("%d", &risposta);

    /* inserimento in coda */
    if(risposta == 1) {
      lista = inserimento(lista);
    }

    /* cancellazione in coda */
    else if(risposta == 2) {
      lista = cancellazione(lista);
    }

    /* Visualizza la lista */
    else if(risposta == 3) {
      stampa(lista);
    }

    /* termina il programma */
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
