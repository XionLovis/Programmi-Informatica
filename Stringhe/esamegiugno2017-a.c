#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e la modifica trasformando tutte le lettere
 * minuscole dell'alfabeto inglese nelle corrispondenti maiuscole */
void rendiMaiuscole(char *stringa) {
  /* scandisci ogni carattere della stringa */
  for(int i=0; i<strlen(stringa); i++) {
    /* se il carattere attuale è alfabetico minuscolo, trasformalo */
    if(stringa[i] >= 'a' && stringa[i] <= 'z')
      stringa[i] = stringa[i] + 'A' - 'a';
  }
}

/* funzione test per rendiMaiuscole */
void testRendiMaiuscole() {

  /* stringa vuota */
  char stringa1[] = "";
  rendiMaiuscole(stringa1);
  printf("\nTest rendiMaiuscole(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa senza minuscole */
  char stringa2[] = "ABCDEF";
  rendiMaiuscole(stringa2);
  printf("Test rendiMaiuscole(\"ABCDEF\"): Atteso = \"ABCDEF\", Calcolato = \"%s\"\n", stringa2);

  /* stringa con solo caratteri minuscoli */
  char stringa3[] = "abcdef";
  rendiMaiuscole(stringa3);
  printf("Test rendiMaiuscole(\"abcdef\"): Atteso = \"ABCDEF\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con una sola minuscola in prima posizione */
  char stringa4[] = "aBCDEF";
  rendiMaiuscole(stringa4);
  printf("Test rendiMaiuscole(\"aBCDEF\"): Atteso = \"ABCDEF\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con solo una minuscola in ultima posizione */
  char stringa5[] = "ABCDEf";
  rendiMaiuscole(stringa5);
  printf("Test rendiMaiuscole(\"ABCDEf\"): Atteso = \"ABCDEF\", Calcolato = \"%s\"\n", stringa5);

  /* stringa con un solo carattere maiuscolo in prima posizione */
  char stringa6[] = "Asdfgt";
  rendiMaiuscole(stringa6);
  printf("Test rendiMaiuscole(\"Asdfgt\"): Atteso = \"ASDFGT\", Calcolato = \"%s\"\n", stringa6);

  /* stringa con solo un carattere maiuscolo in ultima posizione */
  char stringa7[] = "aerfgP";
  rendiMaiuscole(stringa7);
  printf("Test rendiMaiuscole(\"aerfgP\"): Atteso = \"AERFGP\", Calcolato = \"%s\"\n", stringa7);

  /* stringa con la sola minuscola in posizione centrale */
  char stringa8[] = "ABcDEF";
  rendiMaiuscole(stringa8);
  printf("Test rendiMaiuscole(\"ABcDEF\"): Atteso = \"ABCDEF\", Calcolato = \"%s\"\n", stringa8);

  /* stringa con caratteri di ogni tipo */
  char stringa9[] = "aasfEYD43bJd))h";
  rendiMaiuscole(stringa9);
  printf("Test rendiMaiuscole(\"aasfEYD43bJ))d\"): Atteso = \"AASFEYD43BJ))D\", Calcolato = \"%s\"\n", stringa9);
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo prendere le lettere minuscole di una stringa e trasformale in miuscole\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione */
  rendiMaiuscole(stringa);

  /* output */
  printf("\nEcco la nuova stringa: %s\n", stringa);

  /* fai apparire il test */
  testRendiMaiuscole();
}
