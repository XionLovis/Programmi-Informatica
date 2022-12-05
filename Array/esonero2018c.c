#include <stdio.h>

/*  INPUT: un array di elementi inserito dall'utente                        *
 *  PRE: l'array ha almeno tre elementi e gli elementi sono del tipo int    *
 *  OUTPUT: una variabile che ha valori 1 o 0                               *
 *  POST: la variabile vale 1 se in ogni tripla consecutiva di numeri, il   *
 *        prodotto di due numeri fa -12                                     *
 *  Tipo di problema: Verifica universale                                   */

 /* funzione che verifica se non ci sono triple consecutive nell'array dove
  * il prodotto di due numeri fa -12  */
int tripleProdottoMeno12(int sequenza[], int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  int tripla;       //valore da restituire
  tripla = 1;       //all'inizio tutti i numeri soddisfano la condizione

  int i;            //variabile contatore
  i = 0;

  /* vai avanti finché ci sono elementi */
  while (i <= lunghezza -3 && tripla) {
    /* verifica se esiste una tripla che non soddisfa la condizione */
    if((sequenza[i] * sequenza[i+1] != -12) && (sequenza[i] * sequenza[i+2] != -12) && (sequenza[i+1] * sequenza[i+2] != -12))
      tripla = 0;
    else
      i++;          //altrimenti vai avanti
  }
  return tripla;
}

/* funzione principale */
int main() {
  int lunghezza;    //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di vedere se ogni tripla consecutiva di numeri, il prodotto\n");
  printf("di due numeri da come risultato -12\n");
  printf("Quindi, quanti numeri vuoi inserire?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  int sequenza[lunghezza];
  printf("\n");
  for(int i=0; i<lunghezza; i++) {
    printf("Dammi un numero:  ");
    scanf("%d", &sequenza[i]);
  }

  /* se la condizione si verifica */
  if(tripleProdottoMeno12(sequenza, lunghezza))
    printf("Nella tua sequenza tutti i numeri soddisfano la condizione\n");
  else
    printf("Nella sequenza almeno una tripla non soddisfa la condizione\n");
}
