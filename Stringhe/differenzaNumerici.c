#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e restituisce la massima differenza fra due *
 * caratteri numerici che appartengono alla stringa e fra i quali non ci sono  *
 * altri caratteri numerici, oppure -1 se la stringa non contiene due carattere *
 * numerici                                                                    */
int differenzaNumerici(char *stringa) {
  int i;                            //variabile contatore
  int ultimoNumero;                 //ultimo numero letto
  int numeroCorrente;               //numero corrente
  int differenzaAttuale;            //la differenza attuale
  int differenzaMassima;            //la differenza massima

  /* inizializzazioni */
  differenzaMassima = -1;
  ultimoNumero = -1;
  i = 0;                            //prima posizione da guardare

  /* vai avanti fino alla fine della stringa */
  while (stringa[i] != '\0') {
    /* il carattere attuale è numerico? altrimenti non devi fare niente */
    if(stringa[i] >= '0' && stringa[i] <= '9') {
      /* prendi il numero corrente */
      numeroCorrente = stringa[i] - '0';

      /* hai già trovato caratteri numerici? */
      if(ultimoNumero != -1) {

        /* calcola la differenza fra i due numeri */
        if(numeroCorrente > ultimoNumero)
          differenzaAttuale = numeroCorrente - ultimoNumero;
        else
          differenzaAttuale = ultimoNumero - numeroCorrente;

        /* nuovo numero? */
        if(differenzaAttuale > differenzaMassima)
          differenzaMassima = differenzaAttuale;
      }

      /* aggiorna l'ultimo numero */
      ultimoNumero = numeroCorrente;
    }

    i++;      //passa al prossimo carattere
  }
  return differenzaMassima;
}

/* funzione test per differenzaNumerici */
void testDifferenzaNumerici() {

  /* stringa vuota */
  char stringa1[] = "";
  printf("Test differenzaNumerici(\"\"): Atteso = -1, Calcolato = %d \n", differenzaNumerici(stringa1));

  /* stringa senza caratteri numerici */
  char stringa2[] = "abcd";
  printf("Test differenzaNumerici(\"abcd\"): Atteso = -1, Calcolato = %d \n", differenzaNumerici(stringa2));

  /* stringa con un solo carattere numerico */
  char stringa3[] = "abcd2";
  printf("Test differenzaNumerici(\"abcd2\"): Atteso = -1, Calcolato = %d \n", differenzaNumerici(stringa3));

  /* stringa con due caratteri numerici di cui uno è il primo */
  char stringa4[] = "1abc3d";
  printf("Test differenzaNumerici(\"1abc3d\"): Atteso = 2, Calcolato = %d \n", differenzaNumerici(stringa4));

  /* stringa con due caratteri numerici di cui uno è l'ultimo */
  char stringa5[] = "ab3cdf7";
  printf("Test differenzaNumerici(\"ab3cdf7\"): Atteso = 4, Calcolato = %d \n", differenzaNumerici(stringa5));

  /* stringa con due caratteri numerici soli */
  char stringa6[] = "34";
  printf("Test differenzaNumerici(\"34\"): Atteso = 1, Calcolato = %d \n", differenzaNumerici(stringa6));

  /* istanza normale */
  char stringa7[] = "a12b7c3da9bcd2";
  printf("Test differenzaNumerici(\"a12b7c3da9bcd2\"): Atteso = 7, Calcolato = %d \n", differenzaNumerici(stringa7));
}

/* funzione principale */
int main() {
  /* interazione con l'utente */
  printf("Mi occupo di calcolare la differenza massima tra due caratteri numerici in una stringa\n");
  printf("e sono caratteri tra i quali non compaiono altri caratteri numerici\n");
  printf("Inserisci una stringa:  ");
  char stringa[50];
  fgets(stringa, 50, stdin);

  /* rimuovi il carattere \0 */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione differenzaNumerici */
  int differenza = differenzaNumerici(stringa);

  /* output */
  if(differenza == -1)
    printf("La stringa non contiene due caratteri numerici\n");
  else
    printf("La differenza massima fra due caratteri numerici %c %d\n", 138, differenza);
}
