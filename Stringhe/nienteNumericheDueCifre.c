#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa come parametro e la modifica così che
 * elimina tutte le coppie di numeri */
void nienteNumericheDueCifre(char *stringa) {
  int i, j;   //variabili contatori

  i = 0;

  /* vai avanti finché ci sono elementi */
  while (stringa[i] != '\0') {
    /* verifica se il carattere attuale non è numerico, se è così, vai avanti */
    if(!(stringa[i] >= '0' && stringa[i] <= '9'))
      i++;
    else {
      /* se il carattere attuale e quello successivo sono numeri, cancellali */
      if(i != 0 && (stringa[i+1] >= '0' && stringa[i+1] <= '9') && !(stringa[i+2] >= '0' && stringa[i+2] <= '9')
          && !(stringa[i-1] >= '0' && stringa[i-1] <= '9')) {
        for(j = i; stringa[j] != '\0'; j++)
          stringa[j] = stringa[j+1];
      }
      else {
        if(i == 0 && (stringa[i+1] >= '0' && stringa[i+1] <= '9') && !(stringa[i+2] <= '0' && stringa[i+2] <= '9')) {
          for(j = i; stringa[j] != '\0'; j++)
            stringa[j] = stringa[j+1];
        }
        else
          i++;
      }
    }
  }
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di vedere se in una stringa che inserisci ci sono due numeri consecutivi\n");
  printf("e li cancello\n");
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione */
  nienteNumericheDueCifre(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);
}
