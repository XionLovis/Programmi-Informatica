#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e restituisce il massimo numero contenuto  *
 * nella stringa, dove un numero corrisponde a una sequenza massimale di      *
 * caratteri numerici consecutivi nella stringa. La funzione restituisce -1   *
 * se la stringa non contiene nessun carattere numerico                       */
int numeroMassimo(char *stringa) {
  int i;                  //variabile contatore
  int numeroAttuale;      //il numero attuale
  int numeroMax;          //il numero massimo

  /* inizializzazioni */
  numeroAttuale = -1;
  numeroMax = -1;
  i = 0;                  //prima posizione da guardare
  /* vai avanti fino alla fine della stringa */
  while (stringa[i] != '\0') {
    /* il carattere attuale è numerico? */
    if(stringa[i] >= '0' && stringa[i] <= '9') {
      /* primo carattere numerico? */
      if(numeroAttuale == -1)
        numeroAttuale = stringa[i] - '0';
      else
        /* se non è il primo devi guardare quello successivo */
        numeroAttuale = numeroAttuale * 10 + (stringa[i] - '0');

      /* controlla se hai un nuovo massimo */
      if(numeroAttuale > numeroMax)
        numeroMax = numeroAttuale;
    }

    /* non stiamo guardando un carattere numerico */
    else
      numeroAttuale = -1;
      i++;                //vai avanti al prossimo carattere
  }

  return numeroMax;
}

/* funzione test per numeroMassimo */
void testNumeroMassimo() {

  /* stringa vuota */
  char stringa1[] = "";
  printf("\nTest numeroMassimo(\"\"): Atteso = -1, Calcolato = %d \n", numeroMassimo(stringa1));

  /* stringa senza caratteri numerici */
  char stringa2[] = "abcd";
  printf("Test numeroMassimo(\"abcd\"): Atteso = -1, Calcolato = %d \n", numeroMassimo(stringa2));

  /* stringa con un solo carattere numerico nella prima posizione */
  char stringa3[] = "1abcd";
  printf("Test numeroMassimo(\"1abcd\"): Atteso = 1, Calcolato = %d \n", numeroMassimo(stringa3));

  /* stringa con un solo carattere numerico nella prima posizione */
  char stringa4[] = "abcd4";
  printf("Test numeroMassimo(\"abcd4\"): Atteso = 4, Calcolato = %d \n", numeroMassimo(stringa4));

  /* stringa con solo caratteri numerici */
  char stringa5[] = "12345";
  printf("Test numeroMassimo(\"12345\"): Atteso = 12345, Calcolato = %d \n", numeroMassimo(stringa5));

  /* stringa con una sequenza di caratteri numerici */
  char stringa6[] = "ab1234cd";
  printf("Test numeroMassimo(\"ab1234cd\"): Atteso = 1234, Calcolato = %d \n", numeroMassimo(stringa6));

  /* stringa con più di una sequenza di caratteri numerici */
  char stringa7[] = "ab123cd567fytjht897066";
  printf("Test numeroMassimo(\"ab123cd567fytjht897066\"): Atteso = 897066, Calcolato = %d \n", numeroMassimo(stringa7));
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di calcolare il massimo numero contenuto in una stringa che inserisci\n");
  printf("Inserisci una stringa: ");
  char stringa[50];
  fgets(stringa, 50, stdin);

  /* rimuovi '\0' */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione numeroMassimo */
  int numero = numeroMassimo(stringa);

  /* output */
  if(numero == -1)
    printf("\nNon ci sono caratteri numerici all'interno della stringa\n");
  else
    printf("\nIl numero massimo contenuto nella stringa %c: %d\n", 138, numero);

  /* fai apparire il test */
  testNumeroMassimo();
}
