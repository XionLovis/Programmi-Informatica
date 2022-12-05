#include <stdio.h>

/* funzione che riceve come parametro un array e la sua lunghezza e verifica
 * che ogni tripla consecutiva di elementi due elementi su tre sono positivi */
int esattamenteDueSuTre(int sequenza[], int lunghezza) {
  int valido = 1;   //valore da restituire, all'inizio tutte le triple soddisfano la condizione

  /* verifica se c'è almeno una tripla consecutiva che non soddisfa la condizione */
  if((sequenza[0] > 0 && sequenza[1] > 0 && sequenza[2] > 0) || (sequenza[0] < 0 && sequenza[1] < 0 && sequenza[2] < 0)
    || (sequenza[0] < 0 && sequenza[1] > 0 && sequenza[2] < 0) || (sequenza[0] < 0 && sequenza[1] < 0 && sequenza[2] > 0)
    || (sequenza[0] > 0 && sequenza[1] < 0 && sequenza[2] < 0))
    valido = 0;
  else {
    esattamenteDueSuTre(sequenza + 1, lunghezza - 1);
  }
  return valido;
}

/* funzione principale */
int main() {
  int lunghezza;    //lunghezza dell'array

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di vedere se in una sequenza di elementi che inserirai, ogni tripla\n");
  printf("di numeri consecutivi due numeri sono positivi e l'altro %c negativo\n", 138);
  printf("Quindi, quanti numeri vuoi inserire?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  int sequenza[lunghezza];
  for (int i = 0; i < lunghezza; i++) {
    /* inserire i numeri dell'array */
    printf("Dammi un numero: ");
    scanf("%d", &sequenza[i]);
  }

  /* verifica se si soddisfa la condizione */
  if (esattamenteDueSuTre(sequenza, lunghezza)) {
    printf("Tutte le triple della sequenza soddisfano la condizione\n");
  }
  else {
    printf("Non tutte triple della sequenza soddisfano la condizione\n");
  }
}
