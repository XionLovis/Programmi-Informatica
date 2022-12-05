/* programma che legge una sequenza di n numeri floating point e la rappresenta
 * con una lista L; stampare la lista. Costruire una seconda lista L' composta
 * dai soli elementi di L maggiori della media; stampare L' */

#include <stdio.h>
#include <stdlib.h>

/* struttura per rappresentare una lista */
struct Nodo {
  float numero;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/* funzione per leggere una sequenza di numeri */
NODO leggiArray() {
  NODO p;
  NODO primo;   //valore da restituire
  int i;        //variabile contatore
  int lung;     //lunghezza della sequenza

  /* legge la lunghezza della sequenza */
  do {
    /* verifica se la lunghezza è positiva */
    printf("Quanti numeri vuoi inserire?\n");
    scanf("%d", &lung);
    if(lung <= 0)
      printf("La lunghezza deve essere positiva\n");
  } while(lung <= 0);

  primo = NULL;
  /* legge la sequenza */
  for (i = 0; i < lung; i++) {
    /* alloca p nell'heap */
    printf("Dammi un numero:\n");
    p = malloc(sizeof(struct Nodo));
    p -> next = primo;
    scanf("%f", &p -> numero);
    primo = p;
  }

  return primo;
}

/* funzione per stampare una lista */
void stampa(NODO lista) {
  /* se la lista non è nulla vai avanti */
  while (lista != NULL) {
    printf("%3.2f ", lista -> numero);
    lista = lista -> next;
  }
  printf("\n");
}

/* funzione che calcola la media della sequenza*/
float media(NODO p) {
  float s = 0.0;
  float n = 0.0;
  float m;

  /* se la lista non è nulla vai avanti */
  while (p != NULL) {
    s = s + p -> numero;
    n = n + 1;
    p = p -> next;
  }

  m = s/n;

  return m;
}

/* funzione principale */
int main() {
  NODO p, q, r, s;
  float m;

  /* legge la prima lista */
  printf("Mi occupo di prendere una sequenza di numeri reali, stampare la lista\n");
  printf("e successivamente prendere i numeri della prima sequenza, metterli in un'altra\n");
  printf("lista e stampare anch'essa\n");
  p = leggiArray();

  /* stampa la prima lista */
  printf("Ecco la prima lista: \n");
  stampa(p);

  /* calcola la media della prima lista */
  m = media(p);

  r = NULL;   //inizialmente la lista è vuota
  q = p;

  while (q != NULL) {
    /* finché la prima lista non è vuota vai avanti */
    if(q -> numero > m) {
      /* se il numero attuale è più grande della media */
      s = malloc(sizeof(struct Nodo));
      s -> numero = q -> numero;
      s -> next = r;
      r = s;
    }
    q = q -> next;    //vai avanti
  }
  /* stampa la seconda lista */
  printf("Ecco la seconda lista: \n");
  stampa(r);
}
