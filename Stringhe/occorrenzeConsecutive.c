#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e stampa un messaggio che indica qual è
 * il carattere ha il maggior numero di occorrenze consecutive nella stringa
 * e quante sono tali occorrenze */
void numeroOccorrenze(char *stringa) {
  //PRE: stringa non vuota

  int i;                    //variabile contatore
  int carattereAttuale;     //carattere attuale
  int occorrenzeAttuali;    //occorrenze attuali
  int carattereMassimo;     //carattere con più occorrenze
  int occorrenzeMassime;    //numero di occorrenze più grande

  /* inizializzazioni */
  i = 1;                    //prima posizione da guardare
  carattereAttuale = stringa[0];
  occorrenzeAttuali = 1;
  carattereMassimo = stringa[0];
  occorrenzeMassime = 1;

  /* vai avanti fino alla fine della stringa */
  while(stringa[i] != '\0') {
    /* stai continuando una sequenza? */
    if(stringa[i] == carattereAttuale) {

      /* aumenta le occorrenze attuali e anche i dati sul massimo */
      occorrenzeAttuali++;
      if(occorrenzeAttuali > occorrenzeMassime) {
        carattereMassimo = carattereAttuale;
        occorrenzeMassime = occorrenzeAttuali;
      }
    }
    else {
      /* nuovo carattere */
      carattereAttuale = stringa[i];
      occorrenzeAttuali = 1;
    }
    i++;                    //passa al prossimo carattere
  }

  /* output */
  printf("Il carattere con il maggior numero di occorrenze %c '%c' che ha %d occorrenze consecutive\n", 138, carattereMassimo, occorrenzeMassime);
}

/* funzione test per numeroOccorrenze */
void testNumeroOccorrenze() {

  /* stringa con solo ripetizioni dello stesso carattere */
  char stringa1[] = "aaaaa";
  printf("\nTest numeroOccorrenze(\"aaaaa\"): Atteso = \"Il carattere con il maggior numero di\n");
  printf("occorrenze %c 'a' che ha 5 occorrenze consecutive\",\n", 138);
  printf("Calcolato = \" ");
  numeroOccorrenze(stringa1);
  printf("\"\n\n");

  /* stringa in cui la ripetizione massima è iniziale */
  char stringa2[] = "aaabcdde";
  printf("Test numeroOccorrenze(\"aaabcdde\"): Atteso = \"Il carattere con il maggior numero di\n");
  printf("occorrenze %c 'a' che ha 3 ripetizioni consecutive\", \n", 138);
  printf("Calcolato = \" ");
  numeroOccorrenze(stringa2);
  printf("\"\n\n");

  /* stringa in cui la ripetizione massima è finale */
  char stringa3[] = "aabcddeee";
  printf("Test numeroOccorrenze(\"aabcddeee\"): Atteso = \"Il carattere con il maggior numero di\n");
  printf("occorrenze %c 'e' che ha 3 ripetizioni consecutive\", \n", 138);
  printf("Calcolato = \" ");
  numeroOccorrenze(stringa3);
  printf("\"\n\n");

  /* stringa in cui la ripetizione massima è 1 */
  char stringa4[] = "abcdef";
  printf("Test numeroOccorrenze(\"abcdef\"): Atteso = \"Il carattere con il maggior numero di\n");
  printf("occorrenze %c 'a' che ha 1 ripetizioni consecutive\", \n", 138);
  printf("Calcolato = \" ");
  numeroOccorrenze(stringa4);
  printf("\"\n\n");

  /* stringa con diverse ripetizioni lunghe */
  char stringa5[] = "abbbbbccdddeeeef";
  printf("Test numeroOccorrenze(\"abbbbbccdddeeeef\"): Atteso = \"Il carattere con il maggior numero di\n");
  printf("occorrenze %c 'b' che ha 5 ripetizioni consecutive\", \n", 138);
  printf("Calcolato = \" ");
  numeroOccorrenze(stringa5);
  printf("\"\n\n");
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di dirti qual %c il carattere che ha il maggior numero di occorrenze\n", 138);
  printf("in una stringa e quante volte si ripete consecutivamente\n");
  printf("Inserisci una stringa: ");
  char stringa[50];
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione numeroOccorrenze */
  numeroOccorrenze(stringa);
  printf("\n\n");

  /* fai apparire il test */
  testNumeroOccorrenze();
}
