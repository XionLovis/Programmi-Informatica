#include <stdio.h>
#include <string.h>

/* funzione che riceve come parametro una stringa e la modifica in modo tale
 * che rimangano solo le 'X', dove ogni due sequenze di 'X' sono separate da
 * da un singolo spazio ' ' */
void xInRilievo(char *stringa) {
  int i, j;     //variabili contatori

  i = 0;

  /* vai avanti fino alla fine della stringa */
  while (stringa[i] != '\0') {
    /* verifica se il contenuto attuale nonè 'X' */
    if(stringa[i] == 'X')
      i++;
    else {    //non è 'X'
      /* se il prossimo carattere è 'X', sostituisci con uno spazio, altrimenti
       * cancellalo */
      if(i != 0 && (stringa[i+1] == 'X')) {
        stringa[i] = ' ';
        i++;
      }
      else {
        for(j = i; stringa[j] != '\0'; j++) {
          stringa[j] = stringa[j+1];
        }
      }
    }
  }
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di modificare una stringa eliminando tutti i caratteri\n");
  printf("che non sono 'X'\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione */
  xInRilievo(stringa);

  /* output */
  printf("\nEcco la stringa modificata: %s\n", stringa);
}
