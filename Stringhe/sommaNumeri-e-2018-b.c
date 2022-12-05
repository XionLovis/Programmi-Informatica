#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e la modifica così che nella stringa compaiono
 * solo i numeri della stringa, dove ogni due numeri consecutivi sono separati
 * da un '+'. Il primo e l'ultimo carattere della stringa devono essere numerici
 * ammesso che la stringa non sia vuota */
void sommaNumeri(char *stringa) {
  int i, j;         //variabili contatori

  i = 0;

  /* vai avanti finché ci sono elementi */
  while (stringa[i] != '\0') {
    /* verifica se il carattere attuale è numerico, se è così, vai avanti */
    if(stringa[i] >= '0' && stringa[i] <= '9')
      i++;
    else {          //carattere non numerico
      /* sostituisci il carattere attuale con '+', a meno che sia il carattere
       * 0, in quel caso cancellalo */
     if(i != 0 && (stringa[i+1] >= '0' && stringa[i+1] <= '9')) {
       stringa[i] = '+';
       i++;
     }
     else {
       /* cancellalo */
       for(j=i; stringa[j] !='\0'; j++)
        stringa[j] = stringa[j+1];
     }
    }
  }
}

/* funzione test per sommaNumeri */
void testSommaNumeri() {

  /* stringa vuota */
  char stringa1[] = "";
  sommaNumeri(stringa1);
  printf("\nTest sommaNumeri(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa con solo caratteri numerici */
  char stringa2[] = "12345";
  sommaNumeri(stringa2);
  printf("Test sommaNumeri(\"12345\"): Atteso = \"12345\", Calcolato = \"%s\"\n", stringa2);

  /* stringa con solo caratteri non numerici */
  char stringa3[] = "qwerty";
  sommaNumeri(stringa3);
  printf("Test sommaNumeri(\"qwerty\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con un solo carattere numerico all'inizio */
  char stringa4[] = "1abcde";
  sommaNumeri(stringa4);
  printf("Test sommaNumeri(\"1abcde\"): Atteso = \"1\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con un solo carattere numerico alla fine */
  char stringa5[] = "abcde6";
  sommaNumeri(stringa5);
  printf("Test sommaNumeri(\"abcde6\"): Atteso = \"6\", Calcolato = \"%s\"\n", stringa5);

  /* stringa con un solo carattere non numerico all'inizio */
  char stringa6[] = "a234";
  sommaNumeri(stringa6);
  printf("Test sommaNumeri(\"a234\"): Atteso = \"234\", Calcolato = \"%s\"\n", stringa6);

  /* stringa con un solo carattere non numerico alla fine */
  char stringa7[] = "1234e";
  sommaNumeri(stringa7);
  printf("Test sommaNumeri(\"1234e\"): Atteso = \"1234\", Calcolato = \"%s\"\n", stringa7);

  /* stringa con un carattere non numerico in mezzo */
  char stringa8[] = "123abcd456";
  sommaNumeri(stringa8);
  printf("Test sommaNumeri(\"123abcd456\"): Atteso = \"123+456\", Calcolato = \"%s\"\n", stringa8);

  /* istanza normale */
  char stringa9[] = "12asdaf33gr55555";
  sommaNumeri(stringa9);
  printf("Test sommaNumeri(\"12asdaf33gr55555\"): Atteso = \"12+33+55555\", Calcolato = \"%s\"\n", stringa9);
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di eliminare tutti i caratteri non numerici di una stringa e sostituirli\n");
  printf("con il simbolo '+'\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione */
  sommaNumeri(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);

  /* fai apparire il test */
  testSommaNumeri();
}
