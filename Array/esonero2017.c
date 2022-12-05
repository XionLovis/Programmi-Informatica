#include <stdio.h>

/* INPUT: una sequenza di interi inserita dall'utente
   PRE: la sequenza ha almeno tre elementi
   OUTPUT: una variabile che vale 1 o 0
   POST: la variabile vale 1 se all'interno della sequenza esiste un tripla
         consecutiva di numeri dove il numero intermedio è il risultato della
         differenza tra il numero precedente e il numero successivo e viceversa
   Tipo di problema: Verifica esistenziale*/

/* Programma che verifica se all'interno di un array inserito dall'utente
   esistono tre numeri consecutivi dove il valore intermedio è uguale alla
   differenza fra il valore dell'elemento precedente ed il valore del numero
   successivo, oppure alla differenza del numero successivo ed il numero
   precedente */

/* funzione che determina se all'interno della sequenza esiste una tripla
   consecutiva di numeri che soddisfa la condizione menzionata prima */
int differenzaAdiacenti(int sequenza[], int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  int esiste = 0;         //all'inizio non ci sono elementi del genere
  int i = 1;                  //variabile contatore

  /* guarda tutti gli elementi intermedi, finché non finisci la sequenza o trovi uno buono */
  while(i < lunghezza - 1 && !esiste) {
    /* la tripla soddisfa la condizione? */
    if((sequenza[i] == sequenza[i-1] - sequenza[i+1]) ||
      (sequenza[i] == sequenza[i+1] - sequenza[i-1]))
      esiste = 1;
    else
      i++;
  }
  return esiste;
}

/* funzione principale */
int main() {
  int lunghezza;      //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di vedere se in un sequenza che inserisci esiste\n");
  printf("una tripla consecutiva di elementi dove il numero intermedio\n");
  printf("%c il risultato del numero precedente e del numero successivo o viceversa\n", 138);
  printf("Quanti numeri vuoi introdurre?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  int sequenza[lunghezza];
  for(int i = 0; i < lunghezza; i++) {
    printf("Dammi un numero: ");
    scanf("%d", &sequenza[i]);
  }

  /* in caso la condizione sia soddisfatta */
  if(differenzaAdiacenti(sequenza, lunghezza))
    printf("Nella tua sequenza esiste almeno un tripla che soddisfa la condizione\n");
  else
    printf("Nella tua sequenza non ci sono triple che soddisfano la condizione\n");
}
