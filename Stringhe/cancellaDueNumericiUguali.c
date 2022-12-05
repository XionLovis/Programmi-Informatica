#include <stdio.h>
#include <string.h>

/* funzione che riceve come parametro una stringa e la modifica in modo tale
 * se all'interno della stringa ci sono due numeri consecutivi uguali li
 * cancella */
void cancellaDueNumericiUguali(char *stringa) {
  int i, j;     //vaariabili contarori

  i = 0;

  while (stringa[i] != '\0') {
    /* verifica se il carattere attuale è numerico e uguale al successivo */
    if((stringa[i] >= '1' && stringa[i] <= '9') && (stringa[i] == stringa[i+1])) {
      /* copia tutti i caratteri da i+1 una posizione indietro */
      j = i;
      while(stringa[j] != '\0') {
        stringa[j] = stringa[j + 1];
        j++;
      }
    }
    else
      i++;    //vai avanti
  }
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di eliminare tutti i numeri che sono ripetuti due volte consecutive\n");
  printf("di una stringa che inserirai\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* invoca la funzione */
  cancellaDueNumericiUguali(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);
}
