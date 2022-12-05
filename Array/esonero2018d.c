#include <stdio.h>

/*  INPUT: un array di elementi inserito dall'utente                          *
 *  PRE: l'array ha almeno tre elementi e gli elementi sono del tipo int      *
 *  OUTPUT: una variabile che ha valori 1 o 0                                 *
 *  POST: la variabile vale 1 se esiste una tripla consecutiva di elementi dove
 *        la somma di due interi fa 6                                         *
 *  Tipo di problema: verifica esistenziale                                   */

/* funzione che verifica se all'interno dell'array esiste una tripla consecutiva *
 * di elementi dove la somma di due interi fa 6                                  */
 int triplaSomma6(int seq[], int lung) {
   //PRE: lung è la lunghezza della sequenza
   int esiste = 0;    //valore da restituire, all'inizio non ci sono triple del genere
   int i = 0;         //variabile contatore

   /* verifica tutti gli elementi dell'array */
   while (i <= lung - 3 && !esiste) {
     /* se esiste una tripla che soddisfa la condizione */
     if((seq[i] + seq[i+1] == 6) || (seq[i] + seq[i+2] == 6) || (seq[i+1] + seq[i+2] == 6))
      esiste = 1;
    else
      i++;            //altrimenti vai avanti
   }
   return esiste;
 }

 /* funzione principale */
 int main() {
   int lung;          //lunghezza della sequenza

   /* legge la lunghezza della sequenza */
   printf("Mi occupo di vedere se in una tripla consecutiva di numeri di una sequenza\n");
   printf("che inserisci ci sono due numeri che sommati fanno 6\n");
   scanf("%d", &lung);

   /* legge la sequenza */
   int seq[lung];
   printf("\n");
   for(int i=0; i<lung; i++) {
     printf("Dammi un numero:  ");
     scanf("%d", &seq[i]);
   }

   /* se si verifica la condizione */
   if(triplaSomma6(seq, lung))
    printf("Nella sequenza esiste almeno una tripla che soddisfa la condizione\n");
   else
    printf("Non ci sono triple che soddisfano la condizione nella sequenza\n");
 }
