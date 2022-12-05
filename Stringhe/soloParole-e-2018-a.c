#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e la modifica in modo che appaiono solo le
 * parole, ovvero solo le sequenze massimali di caratteri alfabetici maiuscoli
 * o minuscoli non accentati della stringa, dove ogni due parole consecutive
 * sono separate da un singolo spazio. Il primo e l'ultimo carattere della
 * stringa devono essere alfabetici */
void soloParole(char *stringa) {
  int i, j;         //variabili contatori

  i = 0;

  /* vai avanti fino alla fine della stringa */
  while (stringa[i] != '\0') {
    /* verifica se il carattere attuale è alfabetico, se è così vai avanti */
    if((stringa[i] >= 'a' && stringa[i] <= 'z') || (stringa[i] >= 'A' && stringa[i] <= 'Z'))
      i++;
    else {        //carattere non alfabetico
      /* sostituisci il carattere attuale con uno spazio solo se il prossimo
       * è alfabetico e quello corrente non ha indice 0, altrimenti cancellalo */
       if(i != 0 && ((stringa[i+1] >= 'a' && stringa[i+1] <= 'z') || (stringa[i+1] >= 'A' && stringa[i+1] <= 'Z'))) {
        /* sostituisci il carattere con uno spazio e poi vai avanti */
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

/* funzione test per soloParole */
void testSoloParole() {

  /* stringa vuota */
  char stringa1[] = "";
  soloParole(stringa1);
  printf("\nTest soloParole(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa con solo caratteri alfabetici */
  char stringa2[] = "qwerty";
  soloParole(stringa2);
  printf("Test soloParole(\"qwerty\"): Atteso = \"qwerty\", Calcolato = \"%s\"\n", stringa2);

  /* stringa senza caratteri numerici */
  char stringa3[] = "0è,  .34";
  soloParole(stringa3);
  printf("Test soloParole(\"0è,  .34\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con solo un carattere alfabetico all'inizio */
  char stringa4[] = "a234()0";
  soloParole(stringa4);
  printf("Test soloParole(\"a234()0\"): Atteso = \"a\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con solo un carattere alfabetico alla fine */
  char stringa5[] = "1234==a";
  soloParole(stringa5);
  printf("Test soloParole(\"1234==a\"): Atteso = \"a\", Calcolato = \"%s\"\n", stringa5);

  /* stringa con un solo carattere non alfabetico all'inizio */
  char stringa6[] = "6abcde";
  soloParole(stringa6);
  printf("Test soloParole(\"6abcde\"): Atteso = \"abcde\", Calcolato = \"%s\"\n", stringa6);

  /* stringa con un solo carattere alfabetico alla fine */
  char stringa7[] = "abcde6";
  soloParole(stringa7);
  printf("Test soloParole(\"abcde6\"): Atteso = \"abcde\", Calcolato = \"%s\"\n", stringa7);

  /* stringa con una sola parola centrale */
  char stringa8[] = "123abcd 45";
  soloParole(stringa8);
  printf("Test soloParole(\"123abcd 45\"): Atteso = \"abcd\", Calcolato = \"%s\"\n", stringa8);

  /* stringa con tante parole */
  char stringa9[] = "abc 5def ?? ghi";
  soloParole(stringa9);
  printf("Test soloParole(\"abc 5def ?? ghi\"): Atteso = \"abcd def ghi\", Calcolato = \"%s\"\n", stringa9);
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di eliminare tutti i caratteri non alfabetici di una stringa\n");
  printf("lasciando solo le parole della stringa\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1];

  /* invoca la funzione */
  soloParole(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);

  /* fai apparire il test */
  testSoloParole();
}
