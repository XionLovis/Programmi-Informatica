#include <stdio.h>

/* funzione che riceve come parametro un array e la sua lunghezza, e verifica
 * se all'interno ogni tripla consecutiva è tale che la somma del primo e del
 * secondo elemento è uguale alla differenza tra il terzo e il secondo elemento*/
int verificaSuccessione(int sequenza[], int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  int successione = 1;  //valore da restituire, all'inizio tutte le triple soddisfano la condizione

  /* verifica se esiste almeno una tripla che non soddisfa la condizione */
  if(!(sequenza[0] + sequenza[1] == sequenza[2] - sequenza[1]))
    successione = 0;
  else
    verificaSuccessione(sequenza+1, lunghezza-1);
  return successione;
}

/* funzione principale */
int main() {
  int lunghezza;    //lunghezza della sequenza
  int sequenza[lunghezza];  //sequenza che inserisce l'utente

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di vedere se in una sequenza di numeri che inserirai ogni\n");
  printf("tripla consecutiva di numeri la somma del primo numero e del secondo numero\n");
  printf("%c uguale alla differenza del terzo numero con il secondo numero\n", 138);
  printf("Quindi, quanti numeri vuoi inserire?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  for (int i = 0; i < lunghezza; i++) {
    printf("Dammi un numero: ");
    scanf("%d", &sequenza[i]);
  }

  /* verifica se si soddisfa la condizione */
  if(verificaSuccessione(sequenza, lunghezza))
    printf("Tutte le triple della sequenza soddisfano la condizione\n");
  else
    printf("Almeno una tripla della sequenza non soddisfa la condizione\n");
}
