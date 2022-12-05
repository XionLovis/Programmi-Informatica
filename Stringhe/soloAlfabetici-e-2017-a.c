#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e la modifica eliminando tutti i caratteri
 * non alfabetici */
void soloAlfabetici(char * stringa) {
  int i;          //variabile contatore
  int j;          //variabile contatore

  i = 0;

  /* vai avanti fino alla fine della stringa */
  while (stringa[i] != '\0') {
    /* verifica se il carattere attuale non è alfabetico */
    if(!((stringa[i] >= 'a' && stringa[i] <= 'z') || (stringa[i] >= 'A' && stringa[i] <= 'Z'))) {
      /* copia tutti i caratteri da i+1 una posizione indietro */
      j = i;
      while (stringa[j] != '\0') {
        stringa[j] = stringa[j+1];
        j++;
      }
    }
    else
      i++;        //vai al prossimo carattere
  }
}

/* funzione test per soloAlfabetici */
void testSoloAlfabetici() {

  /* stringa vuota */
  char stringa1[] = "";
  soloAlfabetici(stringa1);
  printf("\nTest soloAlfabetici(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa con solo caratteri alfabetici */
  char stringa2[] = "qwerty";
  soloAlfabetici(stringa2);
  printf("Test soloAlfabetici(\"qwerty\"): Atteso = \"qwerty\", Calcolato = \"%s\"\n", stringa2);

  /* stringa con solo caratteri non alfabetici */
  char stringa3[] = "12345";
  soloAlfabetici(stringa3);
  printf("Test soloAlfabetici(\"12345\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con un solo carattere alfabetico in prima posizione */
  char stringa4[] = "a2345";
  soloAlfabetici(stringa4);
  printf("Test soloAlfabetici(\"a2345\"): Atteso = \"a\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con un solo carattere alfabetico in ultima posizione */
  char stringa5[] = "1234e";
  soloAlfabetici(stringa5);
  printf("Test soloAlfabetici(\"1234e\"): Atteso = \"e\", Calcolato = \"%s\"\n", stringa5);

  /* stringa con un solo carattere non alfabetico in prima posizione */
  char stringa6[] = "5qwerty";
  soloAlfabetici(stringa6);
  printf("Test soloAlfabetici(\"5qwerty\"): Atteso = \"qwerty\", Calcolato = \"%s\"\n", stringa6);

  /* stringa con un solo carattere non alfabetico in ultima posizione */
  char stringa7[] = "qwerty7";
  soloAlfabetici(stringa7);
  printf("Test soloAlfabetici(\"qwerty7\"): Atteso = \"qwerty\", Calcolato = \"%s\"\n", stringa7);

  /* stringa con un solo carattere non alfabetico in mezzo */
  char stringa8[] = "qwer7yu";
  soloAlfabetici(stringa8);
  printf("Test soloAlfabetici(\"qwer7yu\"): Atteso = \"qweryu\", Calcolato = \"%s\"\n", stringa8);

  /* istanza normale */
  char stringa9[] = "12asd464-;;e()7wi";
  soloAlfabetici(stringa9);
  printf("Test soloAlfabetici(\"12asd464-;;e()7wi\"): Atteso = \"asdewi\", Calcolato = \"%s\"\n", stringa9);
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di eliminare tutti i caratteri non alfabetici di una stringa\n");
  char stringa[50];
  printf("Inserisci una stringa:  ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione soloAlfabetici */
  soloAlfabetici(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);

  /* fai apparire il test */
  testSoloAlfabetici();
}
