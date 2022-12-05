#include <stdio.h>

/* funzione che riceve come parametro un array e verifica se al suo interno
 * esiste un elemento che è il quadrato dell'elemento precedente o successivo */
int quadratoPrecSucc(int sequenza[], int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  int esiste = 0;   //valore da restituire, all'inizio non ci sono numeri del genere

  /* verifica se si soddisfa la condizione */
  if((sequenza[0] * sequenza[0] == sequenza[1]) || (sequenza[2] * sequenza[2] == sequenza[1])
    || (sequenza[1] * sequenza[1] == sequenza[0]) || (sequenza[1] * sequenza[1] == sequenza[2]))
    esiste = 1;
  else
    quadratoPrecSucc(sequenza + 1, lunghezza - 1);
  return esiste;
}

/* funzione principale */
int main() {
  int lunghezza;    //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di vedere se all'interno di una sequenza di numeri esiste un\n");
  printf("numero che %c il quadrato del numero precedente o del numero successivo\n", 138);
  printf("Quindi, quanti numeri vuoi inserire?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  int sequenza[lunghezza];
  for(int i = 0; i < lunghezza; i++) {
    printf("Dammi un numero: ");
    scanf("%d", &sequenza[i]);
  }

  /* verifica se esiste un numero del genere */
  if(quadratoPrecSucc(sequenza, lunghezza))
    printf("Almeno un numero della sequenza %c il quadrato del successivo o del precedente\n", 138);
  else
    printf("Non esistono numeri che siano il quadrato del successivo o del precedente\n");
}
