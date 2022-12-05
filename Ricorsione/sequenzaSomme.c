#include <stdio.h>

/* funzione che verifica se all'interno di un array ricevuto come parametro
 * ogni tripla consecutiva di numeri la somma del primo elemento con il
 * secondo dà come risultato il terzo elemento */
int verificaSequenza(int sequenza[], int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  int somma = 1;    //valore da restituire, all'inizio tutte le triple soddisfano la condizione

  /* verifica se ogni sequenza soddisfa la condizione */
  if(sequenza[0] + sequenza[1] != sequenza[2])
    somma = 0;
  else
    verificaSequenza(sequenza + 1, lunghezza - 1);
  return somma;
}

/* funzione principale */
int main() {
  int lunghezza;    //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di vedere se in una sequenza di numeri che inserirai\n");
  printf("ogni tripla di numeri consecutivi sono tali che la somma del primo\n");
  printf("il secondo da come risultato il terzo\n");
  printf("Quindi, quanti numeri vuoi introdurre?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  int sequenza[lunghezza];
  for (int i = 0; i < lunghezza; i++) {
    printf("Dammi un numero: ");
    scanf("%d", &sequenza[i]);
  }

  /* verifica se si soddisfa la condizione */
  if(verificaSequenza(sequenza, lunghezza))
    printf("Tutte le triple della sequenza soddisfano la condizione\n");
  else
    printf("Almeno un tripla della sequenza non soddisfa la condizione\n");
}
