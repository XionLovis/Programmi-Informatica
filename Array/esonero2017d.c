#include <stdio.h>

/*  INPUT: un array inserito dall'utente
    PRE: l'array contiene almeno tre elementi e gli elementi sono del tipo int
    OUTPUT: una variabile che ha valori 1 o 0
    POST: la variabile vale 1 se esiste una tripla consecutiva di elementi dove
          la somma o il prodotto dei primi due da come risultato il terzo
          elemento
    Tipo di problema: verifica esistenziale */

/*  funzione che verifica se esiste almeno una tripa consecutiva nella sequenza
    dove la somma o il prodotto dei primi due elementi da come risultato il
    terzo elemento della sequenza */
int sommaProdotto(int sequenza[], int lunghezza) {
  //PRE: lunghezza è la lunghezza della sequenza
  int esiste = 0;   //valore da restituire, all'inizio non esiste nessuna tripla del genere
  int i = 0;        //variabile contatore

  /*  vai avanti finché ci sono elementi  */
  while (i < lunghezza - 2 && !esiste) {
    /* verifica se esiste una tripla che soddisfa la condizione */
    if(sequenza[i+2] == sequenza[i] + sequenza[i+1] || sequenza[i+2] == sequenza[i] * sequenza[i+1])
      esiste = 1;
    else
      i++;      //vai avanti
  }

  return esiste;
}

/*  funzione principale */
int main() {
  int lunghezza;    //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di vedere se nella sequenza di elementi, esiste almeno una tripla consecutiva\n");
  printf("di elementi dove il terzo elemento %c pari alla somma o al prodotto degli elementi precedenti\n", 138);
  printf("Quindi, quanti numeri vuoi introdurre?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  int sequenza[lunghezza];
  printf("\n");
  for(int i=0; i<lunghezza; i++) {
    printf("Dammi un numero: ");
    scanf("%d", &sequenza[i]);
  }

  /* in caso si verifica la condizione */
  if(sommaProdotto(sequenza, lunghezza))
    printf("Nella sequenza esiste almeno una tripla che soddisfa la condizione\n");
  else
    printf("Nella sequenza non esistono triple che soddisfano la condizione\n");
}
