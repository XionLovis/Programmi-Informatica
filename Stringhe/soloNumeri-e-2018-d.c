#include <stdio.h>
#include <string.h>

/* funzione che riceve come parametro una stringa e la modifica così che nella
 * stringa compaiono solo i numeri della stringa parametro, dove ogni due
 * numeri consecutivi sono separati da un singolo spazio. Il primo e l'ultimo
 * carattere della stringa devono essere numeri */
void soloNumeri(char *stringa) {
  int i, j;         //variabili contatori

  i = 0;

  /* vai avanti finché ci sono elementi */
  while (stringa[i] != '\0') {
    /* se il carattere attuale è un numero, vai avanti */
    if(stringa[i] >= '0' && stringa[i] <= '9')
      i++;
    else {        //non è un numero
      /* se il prossimo carattere è un numero, sostituisci con uno spazio, se
       * il carattere invece è in posizione 0, cancellalo */
      if(i != 0 && (stringa[i+1] >= '0' && stringa[i+1] <= '9')) {
        stringa[i] = ' ';
        i++;
      }
      else {
        /* cancellalo */
        for(j=i; stringa[j] != '\0'; j++)
          stringa[j] = stringa[j+1];
      }
    }
  }
}

/* funzione di test per soloNumeri */
void testSoloNumeri() {

  /* stringa vuota */
  char stringa1[] = "";
  soloNumeri(stringa1);
  printf("\nTest soloNumeri(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa con solo numeri */
  char stringa2[] = "12345";
  soloNumeri(stringa2);
  printf("Test soloNumeri(\"12345\"): Atteso = \"12345\", Calcolato = \"%s\"\n", stringa2);

  /* stringa senza numeri */
  char stringa3[] = "qwerty";
  soloNumeri(stringa3);
  printf("Test soloNumeri(\"qwerty\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con un solo numero all'inizio */
  char stringa4[] = "1abcde";
  soloNumeri(stringa4);
  printf("Test soloNumeri(\"1abcde\"): Atteso = \"1\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con un solo numero alla fine */
  char stringa5[] = "abcde6";
  soloNumeri(stringa5);
  printf("Test soloNumeri(\"abcde6\"): Atteso = \"6\", Calcolato = \"%s\"\n", stringa5);

  /* stringa con un solo carattere non numerico all'inizio */
  char stringa6[] = "a234";
  soloNumeri(stringa6);
  printf("Test soloNumeri(\"a234\"): Atteso = \"234\", Calcolato = \"%s\"\n", stringa6);

  /* stringa con un solo carattere non numerico alla fine */
  char stringa7[] = "1234e";
  soloNumeri(stringa7);
  printf("Test soloNumeri(\"1234e\"): Atteso = \"1234\", Calcolato = \"%s\"\n", stringa7);

  /* stringa con un solo carattere non numerico in mezzo */
  char stringa8[] = "123qwerty456";
  soloNumeri(stringa8);
  printf("Test soloNumeri(\"123qwerty456\"): Atteso = \"123 456\", Calcolato = \"%s\"\n", stringa8);

  /* istanza normale */
  char stringa9[] = "qq123wdwe()====43 56";
  soloNumeri(stringa9);
  printf("Test soloNumeri(\"qq123wdwe()====43 56\"): Atteso = \"123 43 56\", Calcolato = \"%s\"\n", stringa9);
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di prendere una stringa ed eliminare tutti i caratteri che non sono numeri\n");
  printf("lasciando uno spazio tra di loro\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione */
  soloNumeri(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);

  /* fai apparire il test */
  testSoloNumeri();
}
