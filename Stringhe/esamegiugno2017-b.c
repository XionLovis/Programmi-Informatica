#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e la modifica trasformando ogni carattere
 * non alfabetico e lo trasforma in un asterisco */
void asteriscoNonAlfabetico(char *stringa) {
  /* verifica ogni carattere della stringa */
  for(int i=0; i<strlen(stringa); i++) {
    /* verifica se il carattere non è alfabetico */
    if(!((stringa[i] >= 'a' && stringa[i] <= 'z') || (stringa[i] >= 'A' && stringa[i] <= 'Z')))
      /* trasforma in asterisco */
      stringa[i] = '*';
  }
}

/* funzione test per asteriscoNonAlfabetico */
void testAsteriscoNonAlfabetico() {

  /* stringa vuota */
  char stringa1[] = "";
  asteriscoNonAlfabetico(stringa1);
  printf("\nTest asteriscoNonAlfabetico(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa con solo caratteri alfabetici */
  char stringa2[] = "asdfghjkl";
  asteriscoNonAlfabetico(stringa2);
  printf("Test asteriscoNonAlfabetico(\"asdfghjkl\"): Atteso = \"asdfghjkl\", Calcolato = \"%s\"\n", stringa2);

  /* stringa senza caratteri alfabetici */
  char stringa3[] = "12.,?ì^!!";
  asteriscoNonAlfabetico(stringa3);
  printf("Test asteriscoNonAlfabetico(\"12.,?ì^!!): Atteso = \"*********\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con un solo carattere non alfabetico in prima posizione */
  char stringa4[] = "5qwerty";
  asteriscoNonAlfabetico(stringa4);
  printf("Test asteriscoNonAlfabetico(\"5qwerty\"): Atteso = \"*qwerty\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con un solo carattere non alfabetico in ultima posizione */
  char stringa5[] = "qwerty8";
  asteriscoNonAlfabetico(stringa5);
  printf("Test asteriscoNonAlfabetico(\"qwerty8\"): Atteso = \"qwerty*\", Calcolato = \"%s\"\n", stringa5);

  /* stringa con un solo carattere alfabetico in prima posizione */
  char stringa6[] = "a1234";
  asteriscoNonAlfabetico(stringa6);
  printf("Test asteriscoNonAlfabetico(\"a1234\"): Atteso = \"a****\", Calcolato = \"%s\"\n", stringa6);

  /* stringa con un solo carattere alfabetico in ultima posizione */
  char stringa7[] = "abced6";
  asteriscoNonAlfabetico(stringa7);
  printf("Test asteriscoNonAlfabetico(\"abced6\"): Atteso = \"abced*\", Calcolato = \"%s\"\n", stringa7);

  /* stringa con un solo carattere non alfabetico in posizione centrale */
  char stringa8[] = "qwer7yu";
  asteriscoNonAlfabetico(stringa8);
  printf("Test asteriscoNonAlfabetico(\"qwer7yu\"): Atteso = \"qwer*yu\", Calcolato = \"%s\"\n", stringa8);

  /* stringa con caratteri alfabetici e non alfabetici */
  char stringa9[] = "qwer23.)gerHEDRDGr)(=^)";
  asteriscoNonAlfabetico(stringa9);
  printf("Test asteriscoNonAlfabetico(\"qwer23.)gerHEDRDGr)(=^)\"): Atteso = \"qwer****gerHEDRDGr****\"\n");
  printf("Calcolato = \"%s\"\n", stringa9);
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di convertire tutti i caratteri non alfabetici di una stringa in asterischi\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca asteriscoNonAlfabetico */
  asteriscoNonAlfabetico(stringa);

  /* output */
  printf("\nEcco la stringa convertita: %s\n", stringa);

  /* fai apparire il test */
  testAsteriscoNonAlfabetico();
}
