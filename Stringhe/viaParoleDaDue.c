#include <stdio.h>
#include <string.h>

/* funzione che riceve come parametro un stringa e la modifica in modo tale che
 * si cancellino due caratteri alfabetici consecutivi */
void viaParoleDaDue(char *stringa) {
  int i, j;     //variabili contatori

  i = 1;

  /* vai avanti fino alla fine della stringa */
  while (stringa[i] != '\0') {
    /* verifica se il carattere attuale è alfabetico */
    if ((stringa[i-1] >= 'A' && stringa[i-1] <= 'Z') || (stringa[i-1] >= 'a' && stringa[i-1] <= 'z')
       && (stringa[i] >= 'A' && stringa[i] <= 'Z') || (stringa[i] >= 'a' && stringa[i] <= 'z')) {
      /* copia tutti i caratteri da i+1 una posizione indietro */
      j = i;
      while (stringa[j] != '\0') {
        stringa[j] = stringa[j+1];
        j++;
      }
    }
    else
      i++;    //passa al prossimo
  }
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di prendere una stringa ed eliminare i caratteri alfabetici\n");
  printf("consecutivi in coppia\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione */
  viaParoleDaDue(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);
}
