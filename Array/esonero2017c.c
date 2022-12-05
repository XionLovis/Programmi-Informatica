#include <stdio.h>

/* INPUT: un array inserito dall'utente
   PRE: l'array ha almeno tre elementi e gli elementi sono del tipo int
   OUTPUT: una variabile che ha come valori 1 o 0
   POST: la variabile vale 1 se ogni tripla consecutiva di elementi sono tali
         che uno dei tre elementi è pari alla somma degli altri due
   Tipo di problema: Verifica universale */

/* funzione che controlla se all'interno dell'array ogni tripla consecutiva di
   numeri uno dei tre è pari alla somma degli altri due */
int sommaTriple(int sequenza[], int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  int tripla = 1;   //variabile da restituire, all'inizio tutti i numeri soddisfano la condizione
  int i = 0;        //variabile contatore

  while (i < lunghezza - 2 && tripla) {
    /* verifica se esiste una tripla che non soddisfa la condizione */
    if((sequenza[i] != sequenza[i+1] + sequenza[i+2])
      && (sequenza[i+1] != sequenza[i] + sequenza[i+2])
      && (sequenza[i+2] != sequenza[i] + sequenza[i+1]))
      tripla = 0;
    else
      i++;      //vai avanti altrimenti
  }

  return tripla;
}

/* funzione principale */
int main() {
  int lunghezza;    //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di verificare se dentro una sequenza di elementi che introduci\n");
  printf("ogni tripla consecutiva di elementi, uno dei tre elementi %c uguale alla\n", 138);
  printf("alla somma degli altri due\n");
  printf("Quindi, quanti numeri vuoi introdurre?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  int sequenza[lunghezza];
  for(int i=0; i<lunghezza; i++) {
    printf("Dammi un numero: ");
    scanf("%d", &sequenza[i]);
  }

  if(sommaTriple(sequenza, lunghezza))
    printf("Nella sequenza inserita tutti gli elementi soddisfano la condizione\n");
  else
    printf("Non tutti gli elementi della sequenza soddisfano la condizione\n");
}
