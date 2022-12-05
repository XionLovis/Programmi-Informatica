#include <stdio.h>

/* funzione che riceve come parametro un array e ritorna 1 se all'interno della
 * sequenza ci sta un numero che è il cubo del numero precedente o del numero
 * successivo */
int cubiPrecSucc(int sequenza[], int lunghezza) {
  int esiste = 0;   //valore da restituire, all'inizio non ci sono numeri del genere

  /* verifica se esiste un numero del genere */
  if((sequenza[0] * sequenza[0] * sequenza[0] == sequenza[1])
    || (sequenza[1] * sequenza[1] * sequenza[1] == sequenza[0])
    || (sequenza[1] * sequenza[1] * sequenza[1] == sequenza[2])
    || (sequenza[2] * sequenza[2] * sequenza[2] == sequenza[1]))
    esiste = 1;
  else
    cubiPrecSucc(sequenza + 1, lunghezza - 1);
  return esiste;
}

/* funzione principale */
int main() {
  int lunghezza;    //lunghezza della sequenza
  int sequenza[lunghezza];  //sequenza

  /* legge la lunghezza della sequenza */
  printf("Mi occupo di vedere se in una sequenza di numeri che inserisci esiste\n");
  printf("un numero che sia il cubo del numero precedente o del numero successivo\n");
  printf("Quindi, quanti numeri vuoi inserire?\n");
  scanf("%d", &lunghezza);

  /* legge la sequenza */
  for (int i = 0; i < lunghezza; i++) {
    printf("Dammi un numero: ");
    scanf("%d", &sequenza[i]);
  }

  /* verifica se si soddisfa la condizione */
  if(cubiPrecSucc(sequenza, lunghezza))
    printf("Almeno un numero che sia il cubo del numero precedente o del numero successivo\n");
  else
    printf("Non esistono numeri che siano il cubo del numero precedente o del numero successivo\n");
}
