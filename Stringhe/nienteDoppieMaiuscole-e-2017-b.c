#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e la modifica eliminando tutte le ripetizioni
 * consecutive di lettere maiuscole */
void nienteDoppieMaiuscole(char *stringa) {
  int i, j;           //vaariabili contarori

  i = 0;
  /* vai avanti fino alla fine della stringa */
  while(stringa[i] != '\0') {
    /* verifica se il carattere maiuscolo attuale è uguale al successivo */
    if((stringa[i] >= 'A' && stringa[i] <= 'Z') && (stringa[i] == stringa[i+1])) {
      /* copia tutti i caratteri da i+1 una posizione indietro */
      j = i;
      while(stringa[j] != '\0') {
        stringa[j] = stringa[j+1];
        j++;
      }
    }
    else
      i++;          //passa al prossimo carattere
  }
}

/* funzione di test per nienteDoppieMaiuscole */
void testNienteDoppieMaiuscole() {

  /* stringa vuota */
  char stringa1[] = "";
  nienteDoppieMaiuscole(stringa1);
  printf("\nTest nienteDoppieMaiuscole(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa con solo caratteri maiuscoli */
  char stringa2[] = "AAAAA";
  nienteDoppieMaiuscole(stringa2);
  printf("Test nienteDoppieMaiuscole(\"AAAAA\"): Atteso = \"A\", Calcolato = \"%s\"\n", stringa2);

  /* stringa con solo caratteri minuscoli */
  char stringa3[] = "aaaa";
  nienteDoppieMaiuscole(stringa3);
  printf("Test nienteDoppieMaiuscole(\"aaaa\"): Atteso = \"aaaa\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con un solo carattere minuscolo in prima posizione */
  char stringa4[] = "aBBBBBDDT";
  nienteDoppieMaiuscole(stringa4);
  printf("Test nienteDoppieMaiuscole(\"aBBBBBDDT\"): Atteso = \"aBDT\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con un solo carattere minuscolo in ultima posizione */
  char stringa5[] = "AAABBCe";
  nienteDoppieMaiuscole(stringa5);
  printf("Test nienteDoppieMaiuscole(\"AAABBCe\"): Atteso = \"ABCe\", Calcolato = \"%s\"\n", stringa5);

  /* stringa con una sola doppia maiuscola in prima posizione */
  char stringa6[] = "AABcd";
  nienteDoppieMaiuscole(stringa6);
  printf("Test nienteDoppieMaiuscole(\"AABcd\"): Atteso = \"ABcd\", Calcolato = \"%s\"\n", stringa6);

  /* stringa con una sola doppia di maiuscole in ultima posizione */
  char stringa7[] = "abCDD";
  nienteDoppieMaiuscole(stringa7);
  printf("Test nienteDoppieMaiuscole(\"abCDD\"): Atteso = \"abCD\", Calcolato = \"%s\"\n", stringa7);

  /* stringa con una sola doppia di maiuscole in posizione centrale */
  char stringa8[] = "abCCdef";
  nienteDoppieMaiuscole(stringa8);
  printf("Test nienteDoppieMaiuscole(\"abCCdef\"): Atteso = \"abCdef\", Calcolato = \"%s\"\n", stringa8);

  /* istanza normale */
  char stringa9[] = "AAbqwerTTTTTyYYYYy";
  nienteDoppieMaiuscole(stringa9);
  printf("Test nienteDoppieMaiuscole(\"AAbqwerTTTTTyYYYYy\"): Atteso = \"AbqwerTyYy\", Calcolato = \"%s\"\n", stringa9);
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di cancellare tutte le lettere maiuscole uguali successive, lasciando solo una\n");
  char stringa[50];
  printf("Inserire una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa)-1] = '\0';

  /* invoca la funzione nienteDoppieMaiuscole */
  nienteDoppieMaiuscole(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);

  /* fai apparire il test */
  testNienteDoppieMaiuscole();
}
