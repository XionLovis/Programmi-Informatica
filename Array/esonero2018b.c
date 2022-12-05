#include <stdio.h>

/*  INPUT: un array inserito dall'utente
 *  PRE: l'array ha almeno tre elementi e gli elementi sono del tipo int      *
 *  OUTPUT: una variabile che ha valori 1 o 0                                 *
 *  POST: la variabile vale 1 se ogni tripla consecutiva il prodotto di due   *
 *        numeri da come risultato 12                                         *
 *  Tipo di problema: Verifica esistenziale                                   */

 /* funzione che verifica se nell'array esiste una tripla dove il prodotto di
  * due numeri da come risultato 12 */
int triplaProdotto12(int sequenza[], int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  int esiste = 0;   //valore da restituire, all'inizio non ci sono triple
  int i = 0;        //variabile contatore

  /* vai avanti finché ci sono elementi */
  while (i <= lunghezza - 3 && !esiste) {
    /* verifica se esiste una tripla che soddisfa la condizione */
    if((sequenza[i] * sequenza[i+1] == 12) || sequenza[i] * sequenza[i+2] == 12
        || sequenza[i+1] * sequenza[i+2] == 12)
        esiste = 1;
    else
        i++;    //vai avanti
  }
  return esiste;
}

/* funzione principale */
int main() {
  int lunghezza;      //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  printf("Dammi dei numeri e vedo se in una tripla ci sono due numeri che moltiplicati fanno 12\n");
  printf("Quindi, quanti numeri vuoi inserire?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  int sequenza[lunghezza];
  printf("\n");
  for(int i=0; i<lunghezza; i++) {
    printf("Dammi un numero:  ");
    scanf("%d", &sequenza[i]);
  }

  /* in caso si verifica la condizione */
  if(triplaProdotto12(sequenza, lunghezza))
    printf("Esiste almeno una tripla che soddisfa la condizione\n");
  else
    printf("Non ci sono triple che soddisfano la condizione\n");
}
