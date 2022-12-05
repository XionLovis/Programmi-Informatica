#include <stdio.h>

/* INPUT: una sequenza di elementi inserita dall'utente
   PRE: la sequenza ha almeno due elementi e sono del tipo int
   OUTPUT: una variabile che ha valore 1 o 0 a seconda se soddisfa una condizione
   POST: la variabile vale 1 se ogni coppia consecutiva di elementi della sequenza
         uno divide l'altro
   Tipo di problema: Verifica universale */

/* funzione che verifica se all'interno della sequenza ogni coppia di numeri
   almeno uno dei numeri divide l'altro */
int adiacentiDivisibili(int sequenza[], int lunghezza) {
  int coppia;       //valore da restituire
  coppia = 1;       //all'inizio tutti i numeri soddisfano la condizione

  int i;            //variabile contatore
  i = 0;

  while (i < lunghezza - 1 && coppia) {
    /* verifica se tutti i numeri soddisfano la condizione */
    if((sequenza[i]%sequenza[i+1] != 0) && (sequenza[i+1])%sequenza[i] != 0)
      coppia = 0;
    else
      i++;      //vai avanti
  }

  return coppia;
}

/* funzione principale */
int main() {
  int lunghezza;      //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di verificare se ogni coppia consecutiva di numeri della\n");
  printf("sequenza che inserisci, uno dei due divide l'altro\n");
  printf("Quindi, quanti numeri vuoi mettere?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  printf("\n");
  int sequenza[lunghezza];
  for(int i=0; i<lunghezza; i++) {
    printf("Dammi un numero: ");
    scanf("%d", &sequenza[i]);
  }

  /* se la condizione viene verificata */
  if(adiacentiDivisibili(sequenza, lunghezza))
    printf("I numeri nella sequenza soddisfano la condizione\n");
  /* altrimenti */
  else
    printf("I numeri nella sequenza non soddisfano la condizione\n");
}
