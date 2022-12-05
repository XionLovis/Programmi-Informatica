#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e la modifica così che ogni sequenza di
 * almeno due caratteri consecutivi uguali venga trasformata in una sequenza
 * di esattamente due caratteri consecutivi uguali */
void alPiuDueConsecutivi(char *stringa) {
  /* se ci sono massimo due caratteri non devi fare niente */
  if(strlen(stringa) > 2) {
    /* scorri tutta la stringa, il primo carattere che potresti cancellare è il terzo */
    int i = 2;
    while (stringa[i] != '\0')
      /* cancella se il carattere è uguale ai due precedenti */
      if((stringa[i] == stringa[i-2]) && (stringa[i] == stringa[i-1]))
        for(int j=i; stringa[j] != '\0'; j++)
          stringa[j] = stringa[j+1];
      /* altrimenti vai avanti */
      else
        i++;
  }
}

/* funzione di test per alPiuDueConsecutivi */
void testAlPiuDueConsecutivi() {

  /* stringa vuota */
  char stringa1[] = "";
  alPiuDueConsecutivi(stringa1);
  printf("\nTest alPiuDueConsecutivi(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa con tre caratteri uguali all'inizio */
  char stringa2[] = "aaabcd";
  alPiuDueConsecutivi(stringa2);
  printf("Test alPiuDueConsecutivi(\"aaabcd\"): Atteso = \"aabcd\", Calcolato = \"%s\"\n", stringa2);

  /* stringa con tre caratteri uguali alla fine */
  char stringa3[] = "abcddd";
  alPiuDueConsecutivi(stringa3);
  printf("Test alPiuDueConsecutivi(\"abcddd\"): Atteso = \"abcdd\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con tre caratteri uguali al centro */
  char stringa4[] = "abcccd";
  alPiuDueConsecutivi(stringa4);
  printf("Test alPiuDueConsecutivi(\"abcccd\"): Atteso = \"abcccd\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con solo caratteri uguali */
  char stringa5[] = "aaaaaa";
  alPiuDueConsecutivi(stringa5);
  printf("Test alPiuDueConsecutivi(\"aaaaaa\"): Atteso = \"aa\", Calcolato= \"%s\" \n", stringa5);

  /* stringa con tutti caratteri diversi */
  char stringa6[] = "qwerty";
  alPiuDueConsecutivi(stringa6);
  printf("Test alPiuDueConsecutivi(\"qwerty\"): Atteso = \"qwerty\", Calcolato = \"%s\"\n", stringa6);

  /* istanza normale */
  char stringa7[] = "1aaa12aaaaa12aaa1";
  alPiuDueConsecutivi(stringa7);
  printf("Test alPiuDueConsecutivi(\"1aaa12aaaaa12aaa1\"): Atteso = \"1aa12aa12aa1\", Calcolato = \"%s\"\n", stringa7);
}

/* funzione principale */
int main() {
  /* INPUT */
  printf("Mi occupo di prendere una stringa e modificarla in modo tale che ogni sequenza\n");
  printf("consecutiva di caratteri uguali con pi%c di due caratteri uguali consecutivi\n", 151);
  printf("sia sostiuita con massimo due caratteri uguali\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovo \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione */
  alPiuDueConsecutivi(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);

  /* fai apparire il test */
  testAlPiuDueConsecutivi();
}
