#include <stdio.h>
#include <string.h>

#define DIMENSIONE 30  //costante per la lunghezza delle stringhe e dell'array

/************************************************/
/********** DEFINIZIONE STRUTTURE ***************/
/************************************************/

 /* struttura per rappresentare una data */
typedef struct Data {
	int giorno;
	int mese;
	int anno;
} DATA;

/* struttura per rappresentare un indirizzo */
typedef struct Indirizzo {
	char via[DIMENSIONE];
	int numero;
	char citta[DIMENSIONE];
} INDIRIZZO;

/* struttura per rappresentare una persona */
typedef struct Persona {
	char nome[DIMENSIONE];
	char cognome[DIMENSIONE];
	DATA dataDiNascita;
	INDIRIZZO indirizzo;
} PERSONA;

/************************************************/
/********** FUNZIONI DI SUPPORTO ****************/
/************************************************/

/* OUTPUT data di nascita */
void stampaData(DATA* data){
    printf("DATA DI NASCITA: %d/%d/%d\n", data->giorno, data->mese, data->anno);
}

/* OUTPUT indirizzo */
void stampaIndirizzo(INDIRIZZO* indirizzo){
    printf("INDIRIZZO: Via %s %d, %s\n", indirizzo->via, indirizzo->numero,indirizzo->citta);
}

/* OUTPUT persona */
void stampaPersona(PERSONA* persona){
    printf("\nNOME: %s\n", persona->nome);
    printf("COGNOME: %s\n", persona->cognome);
    stampaData(&(persona->dataDiNascita));
    stampaIndirizzo(&(persona->indirizzo));
}

/* INPUT data */
void immettiData(DATA* data) {
	/* leggi giorno, mese e anno */
	printf("Inserisci il giorno: ");
	scanf("%d", &(data->giorno));
	printf("Inserisci il mese: ");
	scanf("%d", &(data->mese));
	printf("Inserisci l'anno: ");
	scanf("%d%*c", &(data->anno));
}

/* INPUT indirizzo */
void immettiIndirizzo(INDIRIZZO* indirizzo) {
	/* leggi giorno, mese e anno */
	printf("Inserisci la via: ");
	fgets(indirizzo->via,DIMENSIONE,stdin);
	(indirizzo->via)[strlen(indirizzo->via)-1]='\0';
	printf("Inserisci il numero civico: ");
	scanf("%d%*c", &(indirizzo->numero));
	printf("Inserisci la citt%c: ", 133);				// inserisci valore
	fgets(indirizzo->citta,DIMENSIONE,stdin);
	(indirizzo->citta)[strlen(indirizzo->citta)-1]='\0';
}

/* ricerca una persona con un certo nome e cognome e restituisce un puntatore
 * alla persona nell'anagrafe, oppure NULL se la persona non esiste*/
PERSONA* cerca(PERSONA* anagrafe, int dimensione, char* nome, char* cognome) {
	PERSONA* persona = NULL;		// valore da restituire
	int i=0;
	while(i<dimensione && persona==NULL) {
		if(strcmp(nome,(anagrafe+i)->nome)==0 && strcmp(cognome,(anagrafe+i)->cognome)==0)
			persona = anagrafe + i;
		else
			i++;
	}
	return persona;
}

/* funzione che sposta una persona una posizione indietro nell'anagrafe */
void sposta(PERSONA* anagrafe, PERSONA* persona) {
	strcpy((persona-1)->nome, persona->nome);
	strcpy((persona-1)->cognome, persona->cognome);
	persona->dataDiNascita = (persona-1)->dataDiNascita;
	persona->indirizzo = (persona-1)->indirizzo;
}

/************************************************/
/************* FUNZIONI DEL MENU ****************/
/************************************************/

/* INPUT persona */
void immettiPersona(PERSONA* persona) {

	/* ottieni i dati della persona */
	printf("Introduci il nome della persona: ");
	fgets(persona->nome, DIMENSIONE, stdin);
	(persona->nome)[strlen(persona->nome)-1]='\0';

	printf("Introduci il cognome della persona: ");
	fgets(persona->cognome, DIMENSIONE, stdin);
	(persona->cognome)[strlen(persona->cognome)-1]='\0';

	printf("Introduci la data di nascita della persona...\n");
    immettiData(&(persona->dataDiNascita));

	printf("Introduci l'indirizzo della persona...\n");
    immettiIndirizzo(&(persona->indirizzo));
}

/* funzione per ricercare una persona; la funzione chiede nome e cognome della persona
 * e restituisce un puntatore alla persona oppure NULL se la persona non esiste */
PERSONA* ricercaPersona(PERSONA* anagrafe, int dimensione) {
	/* nome e cognome della persona da ricercare */
	char nome[DIMENSIONE];
	char cognome[DIMENSIONE];

	printf("Introduci il nome della persona: ");
	fgets(nome, DIMENSIONE, stdin);
	(nome)[strlen(nome)-1]='\0';

	printf("Introduci il cognome della persona: ");
	fgets(cognome, DIMENSIONE, stdin);
	(cognome)[strlen(cognome)-1]='\0';

	return cerca(anagrafe,dimensione,nome,cognome);
}

/* funzione per cancellare una persona e restituisce un puntatore alla persona
 * oppure NULL se la persona non esiste */
PERSONA* cancellaPersona(PERSONA* anagrafe, int dimensione) {
	PERSONA* persona;		// la persona da cancellare

	/* prima cerca la persona */
	persona = ricercaPersona(anagrafe,dimensione);

	/* se esiste cancellala */
	if(persona!= NULL) {
		int i = 0; 		// contatore

		/* anagrafe + dimensione - 1 � l'indirizzo dell'ultimo elemento dell'anagrafe;
		 * devi spostare indietro tutti gli elementi da quello che ha indirizzo persona+1 */

		while(persona+i+1<=anagrafe+dimensione -1) {
			/* sposta la posizione un posto indietro */
			sposta(anagrafe,persona+i+1);
			i++;
		}

	}

	return persona;
}

/* funzione per visualizzare l'anagrafe */
void visualizzaAnagrafe(PERSONA* anagrafe, int numero) {
	printf("\n**********\n");
	printf("ANAGRAFE\n");
	printf("**********\n");
	/* visualizza tutte le persone dell'anagrafe */
	for(int i=0; i<numero; i++){
		stampaPersona(anagrafe+i);
	}
}

/************************************************/
/*************** GESTIONE FILE ******************/
/************************************************/

/* ACQUISIZIONE DATI DAL FILE ANAGRAFE.DAT, restituisce il numero
 * di persone presenti nell'anagrafe */
int acquisiciFile(PERSONA* anagrafe){

	int numero = 0;			// valore da restituire
    FILE *fpin;
    fpin = fopen("anagrafe.dat","rb");
    if(fpin!=NULL) {
		numero=fread(anagrafe, sizeof(PERSONA),DIMENSIONE, fpin);
		printf("nell'anagrafe sono presenti %d persone\n",numero);
		fclose(fpin);
	}
	else
		printf("L'anagrafe non esiste (ancora).");
	return numero;
}

/* COPIA DATI SUL FILE anagrafe.dat */
 void salvaAnagrafe(PERSONA* anagrafe, int numero){
     FILE *fpout;
     fpout = fopen("anagrafe.dat","wb"); //APRO IL FILE PER LA SCRITTURA
     if(fpout!=NULL) {
		 fwrite(anagrafe,sizeof(PERSONA),numero,fpout);
		 fclose(fpout);
	 }
	 else
		 printf("File non salvato!\n");
 }

/************************************************/
/*********** PROGRAMMA PRINCIPALE ***************/
/************************************************/

 /* funzione principale di interazione con l'utente */
int main() {

	int numero=-1;	 		// per la scelta dell'utente

	/* elenco di persone */
	PERSONA anagrafe[DIMENSIONE];
	/* acquisizione dei dati da file */
	int numeroPersone = acquisiciFile(anagrafe);

    visualizzaAnagrafe(anagrafe,numeroPersone);
	/* ciclo di interazione con l'utente */
	while(numero!=0) {
		printf("\nCiao utente! Puoi svolgere le seguenti operazioni:\n");
		printf("Introduci 1 -> Immetti una persona\n");
		printf("Introduci 2 -> Cancella una persona\n");
		printf("Introduci 3 -> Ricerca una persona\n");
		printf("Introduci 4 -> Visualizza l'anagrafe\n");
		printf("Introduci 0 -> Termina il programma\n");
		scanf("%d%*c", &numero);

		/* immetti una persona */
		if(numero==1)
			/* ci sono ancora posti nell'anagrafe? */
			if(numeroPersone<DIMENSIONE) {
				immettiPersona(anagrafe+numeroPersone);
				numeroPersone++;
				printf("Inserimento effettuato\n");
			}
			else
				printf("Mi dispiace, abbiamo raggiunto la capienza massima\n");

		/* cancella una persona */
		else  if(numero==2)
			/* se la cancellazione � andata a buon fine decrementa il numero di persone */
			if(cancellaPersona(anagrafe, numeroPersone)) {
				numeroPersone--;
				printf("Cancellazione effettuata\n");
			}
			else
				printf("Mi dispiace, la persona non %c presente nell'anagrafe\n", 138);

		/* ricerca una persona per visualizzarne i dati */
		else  if(numero==3) {
			PERSONA* persona = ricercaPersona(anagrafe, numeroPersone);
			if(persona!=NULL) {
				printf("\nEcco la persona cercata");
				stampaPersona(persona);
			}
			else
				printf("Mi dispiace, la persona non %c presente nell'anagrafe\n", 138);
		}

		/* visualizza tutta l'anagrafe */
		else  if(numero==4)
			visualizzaAnagrafe(anagrafe, numeroPersone);

		/* numero sbagliato? */
		else  if(numero!=0)
			printf("Questo numero non vuol dire niente. Riproviamo!\n");
		/* fine programma */
		else {
			printf("Salvo tutto! Adios!\n");
			salvaAnagrafe(anagrafe,numeroPersone);
		}
	}
}
