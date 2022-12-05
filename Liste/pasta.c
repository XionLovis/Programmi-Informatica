#include <stdio.h>
#include <stdlib.h>

/* struttura per rappresentare un pacco di pasta */
struct Pasta {
  char tipo[20];
  char azienda[20];
  int tempoCottura;
  int raffInt;
};

typedef struct Pasta PASTA;

/* struttura per definire una lista di paste */
struct Nodo {
  PASTA p;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/******************************************************************************
 **************************** INSERIMENTO IN CODA *****************************
 ******************************************************************************/

/* funzione che legge i dati di un pacco di pasta */
PASTA leggiPasta() {
  PASTA pasta;    //pasta da leggere

  /* inserisci il tipo di pasta */
  printf("Che tipo di pasta %c?\n", 138);
  scanf("%s", &pasta.tipo);

  /* inserisci l'azienda */
  printf("Qual %c l'azienda che ha prodotto la pasta?\n", 138);
  scanf("%s", &pasta.azienda);

  /* inserisci i minuti di cottura */
  printf("Quanti sono i minuti di cottura?\n");
  scanf("%d", &pasta.tempoCottura);

  /* inserisci se è raffinata o intera */
  do {
    printf("La pasta %c intera (PREMI 1) o raffinata (PREMI 2)?\n", 138);
    scanf("%d", &pasta.raffInt);
    /* se il valore inserito non %c valido */
    if(pasta.raffInt != 1 && pasta.raffInt != 2)
      printf("Non %c un valore valido\n", 138);
  } while(pasta.raffInt != 1 && pasta.raffInt != 2);
  return pasta;
}

/* funzione per l'inserimento di un pacco di pasta in coda alla lista */
NODO inserimento(NODO lista) {
  /* allocazione del nuovo nodo nell'heap */
  NODO nuovo;
  nuovo = malloc(sizeof(struct Nodo));

  /* riempi il campo dati del nuovo nodo */
  nuovo -> p = leggiPasta();
  printf("\n");
  nuovo -> next = NULL;

  /* se la lista è vuota, questo è il primo nodo */
  while (lista -> next != NULL)
    lista = lista -> next;

    /* ora lista  contiene l'indirizzo dell'ultimo elemento della lista */
    lista -> next = nuovo;
  return nuovo;
}

/******************************************************************************
 ********************************** STAMPE ************************************
 ******************************************************************************/

/* funzione per stampare un pacco di pasta */
void stampaPasta(PASTA p) {
  /* stampa il tipo di pasta */
  printf("Tipo di pasta: %s\n", p.tipo);
  /* stampa il nome dell'azienda */
  printf("Azienda: %s\n", p.azienda);
  /* stampa il tempo di cottura */
  printf("Tempo di cottura: %d min\n", p.tempoCottura);
  /* stampa se è intera o raffinata */
  if(p.raffInt == 1)
    printf("La pasta %c intera\n", 138);
  else
    printf("La pasta %c raffinata\n", 138);
  printf("\n");
}

/* funzione per stampare una lista */
void stampa(NODO lista) {
  NODO nodo = lista;
  /* se la lista è vuota non devi fare nulla */
  if(nodo != NULL) {
    printf("\nEcco la lista delle paste:\n");
    while (nodo != NULL) {
      stampaPasta(nodo -> p);
      nodo = nodo -> next;
    }
    printf("\n\n");
  }
  else
    printf("Niente da stampare\n\n");
}

/******************************************************************************
 **************************** CANCELLAZIONE IN TESTA **************************
 ******************************************************************************/

/* funzione per cancellare il primo pacco di pasta della lista */
NODO cancellazione(NODO lista) {
  NODO nodoCorrente;    //nodo corrente

  /* se la lista è vuota non cancelli nulla */
  if(lista == NULL)
    nodoCorrente = NULL;
  else {
    nodoCorrente = lista -> next;   //nodo da deallocare
    free(lista);
    printf("Cancellazione effettuata\n\n");
  }
  return nodoCorrente;
}

/******************************************************************************
 ******************************* GESTIONE FILE ********************************
 ******************************************************************************/

/* funzione per l'acquisizione di una lista su file */
NODO acquisizione() {
  FILE *fp = fopen("pasta.txt", "r");   //per la lettura di un file di testo
  NODO head = NULL;       //testa della lista
  NODO current;           //nodo corrente
  NODO previous;          //nodo precedente

  PASTA pasta;            //un pacco di pasta
  int letto;              //lettura ok o meno

  /* se il file è vuoto non devi fare nulla */
  if(fp != NULL) {
    letto = fread(&pasta, sizeof(PASTA), 1, fp);
    if (letto) {    //se effettivamente lo ha letto
      /* leggi il primo nodo */
      head = malloc(sizeof(struct Nodo));
      head -> p = pasta;

      /* tieni traccia dell'ultimo nodo letto */
      previous = head;
      /* adesso leggi tutti gli altri nodi */
      do {
        /* leggi un nuovo nodo */
        letto = fread(&pasta, sizeof(PASTA), 1, fp);
        if (letto) {    // se effettivamente lo ha letto
          /* alloca il nuovo nodo nell'heap */
          current = malloc(sizeof(struct Nodo));
          current -> p = pasta;

          /* collega il nodo al precedente */
          previous -> next = current;

          /* il nuovo nodo diventa il precedente */
          previous = current;
        }
        else  //setta il campo next dell'ultimo nodo, il file è terminato
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
  FILE *fp = fopen("pasta.txt", "w");   //per la scrittura di un file di testo

  /* se la lista è vuota non devi fare nulla */
  if(fp != NULL) {
    while (lista != NULL) {   //procedi finché hai nodi
      /* ciò che scrivi è un pacco di pasta */
      fwrite(&(lista -> p), sizeof(struct Nodo), 1, fp);
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
  NODO lista = acquisizione();      //crea la lista
  int risposta = -1;                //per l'interazione con l'utente

  while (risposta != 0) {
    /* scelta dell'operazione */
    printf("Che operazione vuoi svolgere?\n");
    printf("1 -> Inserisci un pacco di pasta\n");
    printf("2 -> Cancellazione del primo pacco di pasta della lista\n");
    printf("3 -> Visualizza la lista\n");
    printf("0 -> Termina il programma\n");
    scanf("%d", &risposta);

    /* inserisci in coda */
    if(risposta == 1) {
      inserimento(lista);
    }

    /* cancella in testa */
    else if(risposta == 2) {
      lista = cancellazione(lista);
    }

    /* Visualizza lista */
    else if(risposta == 3) {
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
