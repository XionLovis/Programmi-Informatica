#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* struttura per rappresentare un punto */
struct Punto {
  float x;
  float y;
};

typedef struct Punto PUNTO;

/* struttura per la rappresentazione di un triangolo equilatero */
struct Triangolo {
  PUNTO vertice;
  float lato;
};

typedef struct Triangolo TRIANGOLO;

/* struttura per rappresentare una lista */
struct Nodo {
  TRIANGOLO t;
  struct Nodo *next;
};

typedef struct Nodo *NODO;

/* funzione per il calcolo del perimetro di un triangolo */
float perimetro(TRIANGOLO t) {
  return t.lato * 3;
}

/* funzione che calcola il vertice in basso a sinistra */
PUNTO bassoSinistra(TRIANGOLO t) {
  PUNTO p;
  p.x = t.vertice.x - (t.lato)/2;
  p.y = t.vertice.y - ((t.lato)/2 * sqrt(3));
  return p;
}

/* funzione che calcola il vertice in basso a destra */
PUNTO bassoDestra(TRIANGOLO t) {
  PUNTO p;
  p.x = t.vertice.x + (t.lato)/2;
  p.y = t.vertice.y - ((t.lato)/2 * sqrt(3));
  return p;
}

/* funzione che stampa un punto */
void stampaPunto(PUNTO p) {
  printf("(%.2f, %.2f)\n", p.x, p.y);
}

/* funzione che stampa un triangolo */
void stampaTriangolo(TRIANGOLO t) {
  PUNTO p1, p2;
  p1 = bassoSinistra(t);
  p2 = bassoDestra(t);

  printf("Triangolo con perimetro %.2f e vertici: ", perimetro(t));
  stampaPunto(t.vertice);
  printf(", ");
  stampaPunto(p1);
  printf(", ");
  stampaPunto(p2);
  printf("\n");
}

/* funzione che stampa la lista */
void stampa(NODO lista) {

  /* verifica se la lista è vuota */
  if(lista == NULL)
    printf("Niente da stampare, lista vuota\n\n");
  else {
    printf("Ecco la lista:\n");
    while (lista != NULL) {
      /* vai avanti finché ci sono nodi */
      stampaTriangolo(lista -> t);
      lista = lista -> next;
    }
    printf("\n");
  }
}

/* funzione che legge un triangolo */
TRIANGOLO leggiTriangolo() {
  TRIANGOLO t;    //triangolo da leggere

  /* inserisci la base */
  do {
    printf("Quanto %c lunga la base?\n", 138);
    scanf("%d", &t.lato);
    /* se non è valido */
    if(t.lato <= 0)
      printf("Non %c un valore valido, deve essere positivo\n", 138);
  } while(t.lato <= 0);

  /* leggi il vertice */
  printf("Qual %c la coordinata x del vertice in alto?\n", 138);
  scanf("%d", &t.vertice.x);
  printf("Qual %c la coordinata y del vertice in alto?\n", 138);
  scanf("%d", &t.vertice.y);
  printf("\n");

  return t;
}

/* funzione per l'inserimento di un triangolo in lista */
NODO inserimento(NODO lista) {
  NODO nuovo = malloc(sizeof(struct Nodo));   //alloca il nuovo nodo nell'heap

  /* riempi il campo dati */
  nuovo -> t = leggiTriangolo();
  printf("\n");

  /* inserimento in testa? */
  if (lista == NULL || (nuovo.t.lato < head.lato)) {
    nuovo -> next = lista;
    lista = nuovo;
  }
  else {
    /* inserimento non in testa */
    NODO previous = lista;
    NODO succ = lista -> next;
    /* cerca il posto giusto dove fare l'inserimento */
    while (succ != NULL && succ.t.lato < nuovo.t.lato) {
      previous = previous -> next;
      succ = succ -> next;
    }
    /* collega il nuovo nodo alla lista */
    previous -> next = nuovo;
    nuovo -> next = succ;
  }
  printf("Inserimento effettuato\n\n");
  return nuovo;
}

/* funzione che cancella un triangolo per valore */
