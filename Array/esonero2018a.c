#include <stdio.h>

/*  INPUT: un array inserito dall'utente
    PRE: l'array ha almeno tre elementi e gli elementi sono del tipo int
    OUTPUT: una variabile che ha valori 1 o 0
    POST: la variabile vale 1 se ogni tripla consecutiva di elementi due
          numeri della sequenza, la somma tra di loro fa 10
    Tipo di problema: Verifica universale */

/* funzione che verifica se in un array ogni tre numeri consecutivi la somma
   di due dei numeri da come risultato 10 */
int tripleSomma10(int sequenza[], int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  int somma;      //valore da restituire
  somma = 1;      //all'inizio tutti i numeri soddisfano la condizione

  int i;          //variabile contatore
  i = 0;

  /*  vai avanti finché ci sono elementi  */
  while (i <= lunghezza - 3 && somma) {
    /* verifica se almeno una tripla consecutiva non soddisfa la condizione */
    if((sequenza[i] + sequenza[i+1] != 10 ) && (sequenza[i] + sequenza[i+2] != 10) && (sequenza[i+1] + sequenza[i+2] != 10))
      somma = 0;
    else
      i++;          //altrimenti vai avanti
  }
  return somma;
}

/*  funzione principale */
int main() {
  int lunghezza;          //lunghezza della sequenza

  /*  legge la lunghezza della sequenza */
  printf("Mi occupo di vedere se ogni tre numeri consecutivi che inserisci la somma di due numeri\n");
  printf("da come risultato 10, pezzo di merda, magari muori inculato da tre neri\n");
  printf("SE NON FUNZIONA MI SCARTAVETRO LA MINCHIA, PEZZO DI MERDA\n");
  printf("Quindi, quanti numeri vuoi introdurre?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  int sequenza[lunghezza];
  printf("\n");
  for(int i = 0; i < lunghezza; i++) {
    printf("Dammi un numero: ");
    scanf("%d", &sequenza[i]);
  }

  /* in caso si verifica la condizione */
  if(tripleSomma10(sequenza, lunghezza))
    printf("\nNella tua sequenza tutti i numeri soddisfano la condizione\n");
  else
    printf("\nNella tua sequenza almeno una tripla di numeri non soddisfa la condizione\n");
}
