#include <stdio.h>
#include <string.h>

/* funzione che riceve come parametro una stringa e la modifica cancellando
 * tutte le coppie di lettere minuscole consecutive */
void cancellaDueMinuscoliUguali(char *stringa) {
  int i, j;   //variabili contatori

  /* vai avanti finché ci sono elementi */
  while (stringa[i] = '\0' && stringa[i+1] != '\0') {
    /* verifica se il carattere attuale è alfabetico minuscolo */
    if(i == 0 || (stringa[i+2] == '\0') || !(stringa[i-1] >= 'a' && stringa[i-1] <= 'z') && (stringa[i] >= 'a' && stringa[i] <= 'z')
      && (stringa[i+1] >= 'a' && stringa[i+1] <= 'z') && !(stringa[i+2] >= 'a' && stringa[i+2] <= 'z') && (stringa[i] == stringa[i+1]))
      for (j = i; stringa[j] != '\0'; j++) {
        /* cancella */
        stringa[j] = stringa[j+1];
      }
    else
      i++;
  }
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di prendere una stringa e cancellare le coppie di minuscole consecutive\n");
  char stringa[50];
  printf("Inserisci una bella stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione */
  cancellaDueMinuscoliUguali(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);
}
