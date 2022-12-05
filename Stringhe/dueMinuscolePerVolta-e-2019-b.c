#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e la modifica così che ogni sequenza di almeno
 * due caratteri alfabetici minuscoli venga trasformata in una sequenza di
 * esattamente due caratteri alfabetici minuscoli */
void dueMinuscolePerVolta(char *stringa) {
  /* se la stringa ha meno di due elementi non devi fare nulla */
  if(strlen(stringa) > 2) {
    /* scorri la stringa, il primo carattere che puoi cancellare è il terzo */
    int i = 2;
    while(stringa[i] != '\0')
      /* cancella se il terzo carattere è anche esso un alfabetico minuscolo */
      if((stringa[i-2] >= 'a' && stringa[i-2] <= 'z') && (stringa[i-1] >= 'a' && stringa[i-1] <= 'z')
        && (stringa[i] >= 'a' && stringa[i] <= 'z'))
          for(int j=i; stringa[j] != '\0'; j++)
            stringa[j] = stringa[j+1];
      /* altrimenti vai avanti */
      else
        i++;
  }
}

/* funzione di test per dueMinuscolePerVolta */
void testDueMinuscolePerVolta() {

  /* stringa vuota */
  char stringa1[] = "";
  dueMinuscolePerVolta(stringa1);
  printf("\nTest dueMinuscolePerVolta(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa con tre caratteri alfabetici minuscoli all'inizio */
  char stringa2[] = "abc456";
  dueMinuscolePerVolta(stringa2);
  printf("Test dueMinuscolePerVolta(\"abc456\"): Atteso = \"ab456\", Calcolato = \"%s\"\n", stringa2);

  /* stringa con tre caratteri alfabetici minuscoli alla fine */
  char stringa3[] = "123def";
  dueMinuscolePerVolta(stringa3);
  printf("Test dueMinuscolePerVolta(\"123def\"): Atteso = \"123de\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con tre caratteri alfabetici minuscoli in mezzo */
  char stringa4[] = "123abc456";
  dueMinuscolePerVolta(stringa4);
  printf("Test dueMinuscolePerVolta(\"123abc456\"): Atteso = \"123ab456\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con solo caratteri alfabetici minuscoli */
  char stringa5[] = "qwerty";
  dueMinuscolePerVolta(stringa5);
  printf("Test dueMinuscolePerVolta(\"qwerty\"): Atteso = \"qw\", Calcolato = \"%s\"\n", stringa5);

  /* stringa con solo caratteri non alfabetici minuscoli */
  char stringa6[] = "123456";
  dueMinuscolePerVolta(stringa6);
  printf("Test dueMinuscolePerVolta(\"123456\"): Atteso = \"123456\", Calcolato = \"%s\"\n", stringa6);

  /* istanza normale */
  char stringa7[] = "12qwerty234()=recap";
  dueMinuscolePerVolta(stringa7);
  printf("Test dueMinuscolePerVolta(\"12qwerty234()=recap\"):Atteso = \"12qw234()=re\", Calcolato = \"%s\"\n", stringa7);
}

/* funzione principale */
int main() {
  /* INPUT */
  printf("Mi occupo di prendere una stringa e modificarla in modo tale che ci siano massimo\n");
  printf("due lettere minuscole consecutive\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovo \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione */
  dueMinuscolePerVolta(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);

  /* fai apparire il test */
  testDueMinuscolePerVolta();
}
