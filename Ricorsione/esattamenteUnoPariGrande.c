#include <stdio.h>

/* funzione che verifica, all'interno di un array di interi ricevuto
 * come parametro, se ogni tripla di interi adiacenti nell'array contiene
 * almeno due interi maggiori o uguali a 10, di cui esattamente uno pari */
int esattamenteUnoPariGrande(int sequenza[], int lunghezza) {
  int tutti;    //valore da restituire

  /* caso base */
  if(lunghezza <= 2)
    tutti = 1;
  /* passo ricorsivo */
  else {
    tutti = ((sequenza[0] >= 10 && sequenza[1] >= 10 && (sequenza[0] + sequenza[1] %2 != 0)) ||
             (sequenza[0] >= 10 && sequenza[2] >= 10 && (sequenza[0] + sequenza[2] %2 != 0)) ||
             (sequenza[1] >= 10 && sequenza[2] >= 10 && (sequenza[1] + sequenza[2] %2 != 0)) &&
             (esattamenteUnoPariGrande(sequenza+1, lunghezza-1)));
  }
  return tutti;
}

/* funzione principale */
int main() {
  int lunghezza;      //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di vedere se in una sequenza di numeri, ogni tripla consecutiva\n");
  printf("di numeri almeno due interi sono maggiori o uguali a 10, di cui esattamente\n");
  printf("uno %c pari\n", 138);
  printf("Quanti numeri vuoi introdurre?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  int sequenza[lunghezza];
  for(int i=0; i<lunghezza; i++) {
    printf("Dammi un numero:");
    scanf("%d", &sequenza[i]);
  }

  /* se si verifica la condizione */
  if(esattamenteUnoPariGrande(sequenza, lunghezza))
    printf("Tutte le triple della sequenza soddisfano la condizione\n");
  else
    printf("Almeno una tripa consecutiva della sequenza non soddisfa la condizione\n");
}
