#include <stdio.h>
#include <string.h>

/* funzione che riceve come parametro una stringa e ne fa uno shift,
 * ovvero sposta di una posizione (verso destra) ciascun carattere
 * della stringa. L'ultimo carattere diventa il primo dopo lo shift. */
void shift(char * stringa) {
  /* salva l'ultimo carattere */
  char temp = stringa[strlen(stringa) - 1];
  /* sposta verso destra gli altri caratteri */
  for(int i=strlen(stringa)-2; i>=0; i--)
    stringa[i+1] = stringa[i];
  /* copia il primo carattere */
  stringa[0] = temp;
}

/* funzione che riceve una stringa e la modifica spostando a destra ongi      *
 * carattere, l'ultimo carattere della stringa diventa il primo dopo shift    *
 * La funzione riceve una stringa e un intero x e modifica la stringa facendo *
 * x operazioni di shift                                                      */
void shiftParametrico(char *stringa, int x) {
  /* fai x shift */
  for(int i=0; i<x; i++)
    shift(stringa);
}

/* funzione di test per shiftParametrico */
void testShiftParametrico() {

  /* stringa vuota */
  char stringa1[] = "";
  shiftParametrico(stringa1, 3);
  printf("\nTest shiftParametrico(\"\", 3): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

  /* stringa con un solo carattere */
  char stringa2[] = "a";
  shiftParametrico(stringa2, 5);
  printf("Test shiftParametrico(\"a\", 5): Atteso = \"a\", Calcolato = \"%s\" \n", stringa2);

  /* shift di 0 posizioni */
  char stringa3[] = "abcdef";
  shiftParametrico(stringa3, 0);
  printf("Test shiftParametrico(\"abcdef\", 0): Atteso = \"abcdef\", Calcolato = \"%s\" \n", stringa3);

  /* shift di 1 posizione */
  char stringa4[] = "abcdef";
  shiftParametrico(stringa4, 1);
  printf("Test shiftParametrico(\"abcdef\"): Atteso = \"fabcde\", Calcolato = \"%s\" \n", stringa4);

  /* shift di un numero di posizioni pari alla lunghezza della stringa */
  char stringa5[] = "abcdef";
  shiftParametrico(stringa5, strlen(stringa5));
  printf("Test shiftParametrico(\"abcdef\", strlen(stringa5)): Atteso = \"abcdef\", Calcolato = \"%s\" \n", stringa5);

  /* utilizzo normale di shift parametrico */
  char stringa6[] = "abcdef";
  shiftParametrico(stringa6, 2);
  printf("Test shiftParametrico(\"abcdef\", 2): Atteso = \"efabcd\", Calcolato = \"%s\" \n", stringa6);
}

/* funzione principale */
int main() {
  int numeroShift;            //il numero di posizioni da shiftare

  /* input */
  printf("Mi occupo di leggere una stringa e stampare una versione shiftata di un numero da te scelto\n");
  printf("Introduci una stringa:  ");
  char stringa[50];
  fgets(stringa, 50, stdin);
  printf("\nDi quanti posizioni vuoi shiftare?\n");
  scanf("%d", &numeroShift);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* modifica la stringa */
  shiftParametrico(stringa, numeroShift);

  /* stampa la stringa modificata */
  printf("La nuova stringa modificata di %d posizioni %c: %s\n", numeroShift, 138, stringa);

  /* fai apparire il test */
  testShiftParametrico();
}
