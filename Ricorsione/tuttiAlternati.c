#include <stdio.h>
#include <stdlib.h>

/* una funzione ricorsiva che verifica se, in un array di numeri interi, i
 * numeri positivi e negativi si alternano. Ad esempio, la funzione deve
 * restituire il valore 1 se tutti i numeri si alternano, altrimenti restituisce
 * 0 */
int tuttiAlternati(int *sequenza, int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  int alternati = 1;    //valore da restituire, all'inizio tutti si alternano

  /* verifica che tutti si alternano */
  if((sequenza[0] > 0 && sequenza[1] > 0) || (sequenza[0] < 0 && sequenza[1] < 0))
    alternati = 0;
  else
    tuttiAlternati(sequenza + 1, lunghezza - 1);
  return alternati;
}

/* funzione per salvare i numeri dell'array in un file di testo */
void scriviNumeri(int *sequenza, int lunghezza) {
  FILE *fp = fopen("interi.txt", "w");    //per la scrittura di un file di testo
  if(fp != NULL) {
    for (int i = 0; i < lunghezza; i++) {
      /* ciò che scrivi è un numero */
      fwrite(&sequenza, i, 1, fp);
      i++;
    }
    fclose(fp);
    printf("Salvataggio eseguito\n\n");
  }
  else
    printf("Salvataggio non eseguito\n\n");
}

/* funzione che conta quanti numeri ci sono all'interno dell'array */
int quantiNumeri() {
  FILE *fp = fopen("interi.txt", "r");    //per la lettura di un file di testo
  int numeri;        //valora da restituire
  int letto;    //lettura ok o meno

  int lunghezza;    //lunghezza dell'array
  int sequenza[lunghezza];     //array

  if(fp == NULL) {
    printf("Non ci sono numeri\n\n");
  }
  else {
    letto = fread(&sequenza, lunghezza, 1, fp);
    if(letto) {
      numeri++;
      sequenza = sequenza + 1;
      lunghezza = lunghezza - 1;

      /* adesso leggi tutti gli altri nodi */
      do {
        /* leggi un nuovo numero */
        letto = fread(&sequenza, lunghezza, 1, fp);
        if(letto) {
          numeri++;
          sequenza = sequenza + 1;
          lunghezza = lunghezza - 1;
        }
      } while(letto);
        printf("Numeri recuperati da file\n\n");
    }
  }
  fclose(fp);
  return numeri;
}

/* funzione che legge una sequenza di interi da un file .txt e li memorizza
 * su un array che è ricevuto come parametro */
void leggiNumeri(int *sequenza, int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  FILE *fp = fopen("interi.txt", "r");
  int letto;    //lettura ok o meno
  int current;
  int previous;

  int seq;      //un array
  int lungh;    //la sua lunghezza

  /* se il file è vuoto non devi fare nulla */
  if(fp == NULL)
    printf("Non ci sono numeri nel file\n\n");
  else {
    /* leggi il primo numero della lista */
    letto = fread(&seq, lungh, 1, fp);
    if(letto) {   //almeno un numero presente nella lista
      sequenza = seq;

      previous = sequenza;

      /* adesso leggi tutti gli altri numeri */
      do {
        /* leggi un nuovo numero */
        letto = fread(&seq, lungh, 1, fp);
        if(letto) {   //se effettivamente lo ha letto
          current = sequenza
        }
      } while(letto);
        printf("Lista recuperata da file\n\n");
    }
    else
      printf("Lista vuota, niente da recuperare\n\n");
      fclose(fp);
  }
  return seq;
}

/* funzione principale */
int main() {
  int lunghezza;    //lunghezza dell'array;
  int risposta = -1;  //per l'interazione con l'utente

  /* acquisizione dati e lettura dell'array da input */
  printf("Vuoi introdurre una nuova sequenza (SI = 1), oppure recuperarla da file(SI = 2)\n");
  scanf("%d", &risposta);

  /* introduzione sequenza da input */
  if(risposta == 1) {
    /* legge la lunghezza della sequenza */
    printf("Quanti numeri vuoi inserire?\n");
    scanf("%d", &lunghezza);

    /* legge la sequenza */
    int sequenza[lunghezza];
    for (int i = 0; i < lunghezza; i++) {
      /* inserisci i numeri della sequenza */
      printf("Dammi un numero:");
      scanf("%d", &sequenza[i]);
    }

    /* invoca la funzione e stampa il risultato */
    if(tuttiAlternati(sequenza, lunghezza))
      printf("Tutti numeri della sequenza sono di segno alterno\n");
    else
      printf("Non tutti i numeri della sequenza sono di segno alterno\n");

    /* salva la sequenza su file */
    scriviNumeri(sequenza, lunghezza);
  }
  /* recupero la sequenza da file */
  else {
    /* determina la lunghezza della sequenza */
    lunghezza = quantiNumeri();

    /* crea l'array e leggine i valori degli elementi da file */
    int sequenza[lunghezza];
    leggiNumeri(sequenza, lunghezza);
    printf("Ecco la sequenza recuperata\n");
    for (int i = 0; i < lunghezza; i++) {
      printf("%d ", sequenza[i]);
    }
    printf("\n");

    /* invoca la funzione ricorsiva e stampa il risultato */
    if(tuttiAlternati(sequenza, lunghezza))
      printf("Tutti i numeri della sequenza sono di segno alterno\n");
    else
      printf("Non tutti i numeri della sequenza sono di segno alterno\n");

    /* salva la sequenza su file */
    scriviNumeri(sequenza, lunghezza);
  }
}
