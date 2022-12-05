#include <stdio.h>
#include <string.h>

/* funzione che riceve come parametro una stringa e la modifica eliminando
 * tutti i caratteri che non sono numerici */
void eliminaNonNumerici(char *stringa) {
  //PRE: stringa non vuota

  int i;                    //variabile contatore
  int j;                    //variabile contatore

  i = 0;
  /* vai avanti fino alla fine della stringa */
  while (stringa[i] != '\0') {
    /* il carattere attuale non è numerico? */
    if(!(stringa[i] >= '0' && stringa[i] <= '9')) {
      /* copia tutti i caratteri da i+1 una posizione indietro */
      j = i;
      while (stringa[j] != '\0') {
        stringa[j] = stringa[j+1];
        j++;
      }
    }
    else
      i++;                   //vai al prossimo carattere
  }
}

/* funzione test per eliminaNonNumerici */
void testEliminaNonNumerici() {

  /* stringa senza caratteri numerici */
  char stringa1[] = "abcde";
  eliminaNonNumerici(stringa1);
  printf("\nTest eliminaNonNumerici(\"abcde\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa con solo caratteri numerici */
  char stringa2[] = "12345";
  eliminaNonNumerici(stringa2);
  printf("Test eliminaNonNumerici(\"12345\"): Atteso = \"12345\", Calcolato = \"%s\"\n", stringa2);

  /* striga con solo un carattere non numerico in prima posizione */
  char stringa3[] = "a2345";
  eliminaNonNumerici(stringa3);
  printf("Test eliminaNonNumerici(\"a2345\"): Atteso = \"a2345\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con solo un carattere non numerico in ultima posizione */
  char stringa4[] = "1234b";
  eliminaNonNumerici(stringa4);
  printf("Test eliminaNonNumerici(\"1234b\"): Atteso = \"1234b\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con un solo carattere numerico in prima posizione */
  char stringa5[] = "1bcdef";
  eliminaNonNumerici(stringa5);
  printf("Test eliminaNonNumerici(\"1bcdef\"): Atteso = \"1bcdef\", Calcolato = \"%s\"\n", stringa5);

  /* stringa con un solo carattere numerico in ultima posizione */
  char stringa6[] = "abcde6";
  eliminaNonNumerici(stringa6);
  printf("Test eliminaNonNumerici(\"abcde6\"): Atteso = \"6\", Calcolato = \"%s\"\n", stringa6);

  /* stringa vuota */
  char stringa7[] = "";
  eliminaNonNumerici(stringa7);
  printf("Test eliminaNonNumerici(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa7);

  /* stringa con diversi caratteri non numerici e con caratteri numerici */
  char stringa8[] = "asg3455dfghfk7fjh8";
  eliminaNonNumerici(stringa8);
  printf("Test eliminaNonNumerici(\"asg3455dfghfk7fjh8\"): Atteso = \"345578\", Calcolato = \"%s\"\n", stringa8);
}

/* funzione principale */
int main() {
  printf("Mi occupo di cancellare tutti i caratteri non numerici di una stringa\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca eliminaNonNumerici */
  eliminaNonNumerici(stringa);

  /* output */
  printf("Ecco la stringa senza caratteri non numerici: %s \n", stringa);

  /* mostra il test */
  testEliminaNonNumerici();
}
