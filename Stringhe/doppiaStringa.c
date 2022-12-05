#include <stdio.h>
#include <string.h>


 /* funzione che verifica se la stringa consiste di due sottostringhe uguali */
 int doppiaStringa(char *stringa) {
   int doppia = 1;                      //valore da restituire
   int lunghezza = strlen(stringa);     //lunghezza della stringa
   int i = 0;                           //variabile contatore

   /* se la lunghezza è dispari allora no */
   if(lunghezza % 2 != 0)
    doppia = 0;
  else {
    /* vai avanti finché non hai visto la prima metà */
    while(doppia && i < lunghezza/2)
      /* confronta la posizione i con la posizione n/2 + i */
      if(stringa[i] != stringa[lunghezza/2 + i])
        doppia = 0;
      else
        i++;
  }
  return doppia;
 }

/* funzione di test per doppiaStringa */
void testDoppiaStringa() {

  /* stringa vuota */
  char stringa1[] = "";
  printf("\nTest doppiaStringa(\"\"): Atteso = 1, Calcolato = %d \n", doppiaStringa(stringa1));

  /* stringa con un solo carattere */
  char stringa2[] = "a";
  printf("Test doppiaStringa(\"\a\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(stringa2));

  /* stringa con due caratteri uguali */
  char stringa3[] = "aa";
  printf("Test doppiaStringa(\"aa\"): Atteso = 1, Calcolato = %d \n", doppiaStringa(stringa3));

  /* stringa con due caratteri diversi */
  char stringa4[] = "ab";
  printf("Test doppiaStringa(\"ab\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(stringa4));

  /* stringa in cui l'unico problema è sul primo carattere */
  char stringa5[] = "obcdabcd";
  printf("Test doppiaStringa(\"obcdabcd\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(stringa5));

  /* stringa in cui l'unico problema è sull'ultimo carattere */
  char stringa6[] = "abcdabcp";
  printf("Test doppiaStringa(\"abcdabcp\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(stringa6));

  /* stringa in cui il problema è su un carattere centrale */
  char stringa7[] = "abedabcd";
  printf("Test doppiaStringa(\"abedabcd\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(stringa7));

  /* istanza positiva normale */
  char stringa8[] = "abcdabcd";
  printf("Test doppiaStringa(\"abcdabcd\"): Atteso = 1, Calcolato = %d \n", doppiaStringa(stringa8));

  /* istanza negativa normale */
  char stringa9[] = "aafq343234v";
  printf("Test doppiaStringa(\"aafq343234v\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(stringa9));
}

/* funzione principale */
int main() {
  printf("Mi occupo di vedere se la stringa che inserisci %c composta da due sottostringhe uguali\n", 138);
  char stringa[50];
  printf("Inserisci una stringa: ");
  fgets(stringa, 50, stdin);

  /* rimuovi \n */
  stringa[strlen(stringa) - 1] = '\0';

  /* verifica la proprietà */
  if(doppiaStringa(stringa))
    printf("\nLa stringa %c composta da due sottostringhe uguali\n", 138);
  else
    printf("\nLa stringa non %c composta da due sottostringhe uguali\n", 138);

  /* fai apparire il test */
  testDoppiaStringa();
}
