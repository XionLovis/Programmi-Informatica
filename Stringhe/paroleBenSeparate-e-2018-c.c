#include <stdio.h>
#include <string.h>

/* funzione che riceve una stringa e la modifica così che nella stringa compaiono
 * solo le parole minuscole della stringa, dove ogni due parole consecutive
 * sono separate dal simbolo '-'. Il primo e l'ultimo carattere della stringa
 * devono essere alfabetici minuscoli */
void paroleBenSeparate(char *stringa) {
  int i, j;           //variabili contatori

  i = 0;

  /* vai avanti finché ci sono elementi */
  while(stringa[i] != '\0') {
    /* verifica se il carattere attuale è alfabetico minuscolo, se è così, vai avanti */
    if(stringa[i] >= 'a' && stringa[i] <= 'z')
      i++;
    else {  //carattere non alfabetico minuscolo
      /* sostituisci il carattere attuale con '-', se il prossimo è alfabetico
       * minuscolo, se il carattere è in posizione 0 cancellalo */
      if(i != 0 && (stringa[i+1] >= 'a' && stringa[i+1] <= 'z')) {
        stringa[i] = '-';
        i++;
      }
      else {
        /* cancellalo */
        for(j=i; stringa[j] != '\0'; j++)
          stringa[j] = stringa[j+1];
      }
    }
  }
}

/* funzione di test per paroleBenSeparate */
void testParoleBenSeparate() {

  /* stringa vuota */
  char stringa1[] = "";
  paroleBenSeparate(stringa1);
  printf("\nTest paroleBenSeparate(\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

  /* stringa con solo caratteri non alfabetici */
  char stringa2[] = "12345";
  paroleBenSeparate(stringa2);
  printf("Test paroleBenSeparate(\"12345\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa2);

  /* stringa con solo parole minuscole */
  char stringa3[] = "qwerty";
  paroleBenSeparate(stringa3);
  printf("Test paroleBenSeparate(\"qwerty\"): Atteso = \"qwerty\", Calcolato = \"%s\"\n", stringa3);

  /* stringa con un solo carattere alfabetico minuscolo in prima posizione */
  char stringa4[] = "a234";
  paroleBenSeparate(stringa4);
  printf("Test paroleBenSeparate(\"a234\"): Atteso = \"a\", Calcolato = \"%s\"\n", stringa4);

  /* stringa con un solo carattere alfabetico minuscolo alla fine */
  char stringa5[] = "1234e";
  paroleBenSeparate(stringa5);
  printf("Test paroleBenSeparate(\"1234e\"): Atteso = \"e\", Calcolato = \"%s\"\n", stringa5);

  /* stringa con un solo carattere non alfabetico minuscolo all'inizio */
  char stringa6[] = "1abcde";
  paroleBenSeparate(stringa6);
  printf("Test paroleBenSeparate(\"1abcde\"): Atteso = \"abcde\", Calcolato = \"%s\"\n", stringa6);

  /* stringa con un solo carattere non alfabetico minuscolo alla fine */
  char stringa7[] = "abcde6";
  paroleBenSeparate(stringa7);
  printf("Test paroleBenSeparate(\"abcde6\"): Atteso = \"abcde\", Calcolato = \"%s\"\n", stringa7);

  /* stringa con un carattere non alfabetico minuscolo in mezzo */
  char stringa8[] = "abcd345efg";
  paroleBenSeparate(stringa8);
  printf("Test paroleBenSeparate(\"abcd345efg\"): Atteso = \"abcd-efg\", Calcolato = \"%s\"\n", stringa8);

  /* istanza normale */
  char stringa9[] = "12aaas35))()qwerty 45";
  paroleBenSeparate(stringa9);
  printf("Test paroleBenSeparate(\"12aaas35))()qwerty 45\"): Atteso = \"aaas-qwerty\", Calcolato = \"%s\"\n", stringa9);
}

/* funzione principale */
int main() {
  /* input */
  printf("Mi occupo di prendere una stringa ed eliminare tutti i caratteri non alfabetici minuscoli\n");
  printf("e li sostituisco con il simbolo '-'\n");
  char stringa[50];
  printf("Inserisci una stringa:  ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* invoca la funzione */
  paroleBenSeparate(stringa);

  /* output */
  printf("Ecco la stringa modificata: %s\n", stringa);

  /* fai apparire il test */
  testParoleBenSeparate();
}
