#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* un punto del piano */
struct Punto {
  float x;
  float y;
};

typedef struct Punto PUNTO;

struct Cerchio {
  PUNTO centro;
  float raggio;
};

typedef struct Cerchio CERCHIO;

struct Nodo {
  CERCHIO c;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/******************************************************************************
 ******************************* STAMPE ***************************************
 ******************************************************************************/

/* per stampare un cerchio */
void stampaCerchio(struct Cerchio c) {
  printf("Il cerchio ha centro (%.2f, %.2f)", c.centro.x, c.centro.y);
  printf("e raggio %.2f\n", c.raggio);
}

/* per stampare una lista di cerchi */
void stampa(struct Nodo *lista) {
  /* vai avanti fino a che ci sono cerchi */
  if(lista == NULL)
    printf("Non ci sono cerchi da stampare\n\n");
  else {
    printf("Ecco la lista dei cerchi\n\n");
    while (lista != NULL) {
      stampaCerchio(lista -> c);
      lista = lista -> next;
    }
    printf("\n");
  }
}

/******************************************************************************
 **************************** INSERIMENTO IN TESTA ****************************
 ******************************************************************************/

/* leggi i campi di un cerchio */
CERCHIO leggiCerchio() {
  CERCHIO c;      //cerchio da leggere
  printf("Introduci la coordinata x del centro: ");
  scanf("%f", &c.centro.x);
  printf("Introduci la coordinata y del centro: ");
  scanf("%f", &c.centro.y);
  do {
    printf("Introduci il raggio: ");
    scanf("%f", &c.raggio);
    if(c.raggio <= 0)
      printf("Il raggio deve essere positivo\n");
  }
  while(c.raggio <= 0);
  return c;
}

/* inserimento di un cerchio in testa */
NODO inserimento(NODO head) {
  /* alloca il nodo nella memoria */
  NODO testa = malloc(sizeof(struct Nodo));
  /* riempi il campo di dati */
  testa -> c = leggiCerchio();

  /* collega il nodo alla testa */
  testa -> next = head;
  printf("Inserimento effettuato\n\n");

  /* aggiorna la testa della lista dentro main */
  return testa;
}

/******************************************************************************
 ****************************** CANCELLAZIONE *********************************
 ******************************************************************************/

NODO cancellazione(NODO head) {
  int risposta = 0;        //per l'interazione con l'utente
  NODO nodoCorrente;       //nodo corrente
  NODO nodoPrec;           //nodo precedente

  /* se la lista è vuota non cancelli nulla */
  if(head != NULL) {
    printf("Ecco il primo cerchio della lista:\n");
    stampaCerchio(head -> c);
    printf("E' questo il cerchio che vuoi cancellare? (SI = 1, NO = 0)\n");
    scanf("%d", &risposta);

    /* cancellazione del primo nodo della lista */
    if(risposta) {
      nodoCorrente = head;    //nodo da deallocare
      head = head -> next;    //indirizzo da restituire
      free(nodoCorrente);
    }
    /* cancellazione di un nodo nella lista che non è il primo */
    else {
      nodoCorrente = head -> next;    //parti dal secondo nodo
      nodoPrec = head;                //indirizzo da restituire
      while (nodoCorrente != NULL && risposta != 1) {
        printf("Ecco un nuovo cerchio della lista:\n");
        stampaCerchio(nodoCorrente -> c);
        printf("E' questo il cerchio che vuoi cancellare? (SI = 1, NO = 0)\n");
        scanf("%d", &risposta);
        if(risposta) {                //cancella il nodo
          nodoPrec -> next = nodoCorrente -> next;  //collegamento del precedente al successivo
          free(nodoCorrente);
        }
        else {                        //proponi all'utente il prossimo nodo
          nodoCorrente = nodoCorrente -> next;
          nodoPrec = nodoPrec -> next;
        }
      }
    }
  }
  /* messaggio di uscita per l'utente */
  if(risposta == 1)
    printf("Nodo cancellato\n\n");
  else
    printf("Non si %c cancellato niente\n\n", 138);
  return head;
}

/******************************************************************************
 ************************* VERIFICA DI CONTENIMENTO ***************************
 ******************************************************************************/

/* distanza fra due punti */
float distanza(PUNTO p1, PUNTO p2) {
  return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

/* restituisce 1 se il primo cerchio è contenuto nel secondo */
int contenuto(CERCHIO c1, CERCHIO c2) {
  /* il primo è contenuto nel secondo se e solo se: la distanza fra i centri
   * più il raggio del centro c1 è minore o uguale al raggio del cerchio c2 */
  return distanza(c1.centro, c2.centro) + c1.raggio <= c2.raggio;
}

/* per la verifica di contenimento fra i cerchi */
void verificaContenimento(NODO head) {
  if(head == NULL || head -> next == NULL)
    printf("Non ci sono abbastanza cerchi da verificare\n\n");
  else // si può fare la verifica
    if(contenuto(head -> c, head -> next -> c))
      printf("Il primo cerchio %c contenuto nel secondo\n\n", 138);
    else
      printf("Il primo cerchio non %c contenuto nel secondo\n\n", 138);
}

/******************************************************************************
 ****************************** GESTIONE FILE *********************************
 ******************************************************************************/

 /* funzione per l'acquisizione di una lista su file */
 struct Nodo* acquisizione() {
   FILE *fp = fopen("cerchi.dat", "rb");      //per la lettura di un file binario
   NODO head = NULL;    //testa della lista
   NODO current;        //nodo corrente
   NODO previous;       //nodo precedente

   CERCHIO cerchio;     //un cerchio
   int letto;           //lettura ok o meno

   /* se non hai aperto il file non devi fare niente */
   if(fp != NULL) {
     /* leggi il primo nodo della lista */
     letto = fread(&cerchio, sizeof(CERCHIO), 1, fp);
     if(letto) {        //almeno un cerchio è presente nel file
       /* memorizza nell'heap il primo nodo della lista */
       head = malloc(sizeof(struct Nodo));
       head -> c = cerchio;

       /* tieni traccia dell'ultimo nodo letto, per collegarlo al successivo nella lista */
       previous = head;
       /* adesso leggi tutti gli altri nodi */
       do {
         /* leggi un nuovo nodo */
         letto = fread(&cerchio, sizeof(CERCHIO), 1, fp);
         if(letto){   //se effettivamente lo ha letto
           /* memorizza nell'heap un nuovo nodo */
           current = malloc(sizeof(struct Nodo));
           current -> c = cerchio;

           /* collega il nodo al precedente */
           previous -> next = current;

           /* il nuovo nodo diventa il precedente */
           previous = current;
         }
         else   //il file è terminato, setta il campo next dell'ultimo nodo
          previous -> next = NULL;
       }
       while(letto);
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
  FILE *fp = fopen("cerchi.dat", "wb");   //per la scrittura su un file binario
  if(fp != NULL) {
    while (lista != NULL) {               //procedi fino a che hai nodi
      /* ciò che scrivi hai un cerchio */
      fwrite(&(lista -> c), sizeof(CERCHIO), 1, fp);
      lista = lista -> next;              //vai al prossimo nodo
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
  struct Nodo *lista = acquisizione();

  int risposta = -1;                      //per l'interazione con l'utente

  while (risposta != 0) {
    /* richiedi l'operazione con l'utente */
    printf("Che operazione vuoi svolgere?\n");
    printf("1 -> Inserisci un cerchio nella lista\n");
    printf("2 -> Elimina un cerchio dalla lista\n");
    printf("3 -> Visualizza la lista\n");
    printf("4 -> Verifica se il primo cerchio della lista %c contenuto nel secondo\n", 138);
    printf("0 -> Termina il programma\n");
    scanf("%d", &risposta);

    /* inserimento in testa alla lista */
    if(risposta == 1) {
      lista = inserimento(lista);
    }

    /* cancellazione di un cerchio */
    else if(risposta == 2) {
      lista = cancellazione(lista);
    }

    /* Visualizza la lista */
    else if(risposta == 3) {
      stampa(lista);
    }

    /* verifica se il primo cerchio è contenuto nel secondo */
    else if(risposta == 4) {
      verificaContenimento(lista);
    }

    /* termina il programma */
    else if(risposta == 0) {
      printf("Addio, programma finito\n\n");
    }

    else
      printf("Non ha alcun significato, riprova\n\n");
  }
  salvataggio(lista);
}
