#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Dimensione massimo dell'array di struttura
// Ovvero quantità massima di contatti registrabili
#define RMAX 100

// Struttura memorizzazione record
struct sContatti
{
    // Indice record
    int index;
	// Nome record
    char nome[15];
    int lunghezza_nome;
	// Cognome record
    char cognome[15];
    int lunghezza_cognome;
	// Numero record
    char numero[15];
    int lunghezza_numero;

    int lastid;
} sCont[RMAX],sLast;

// Struttura memorizzazione ultimo ordine
struct sOrdine {int v[RMAX];} ord;

// Prototipi funzioni
void stampaMenu(int nContatti, int ls);							// Procedura di stampa menu'

int leggiRecord();										// Funzione lettura record da file (restituisce in numero di record)

void scambioRecord(int a, int b);						// Procedura di scambio posizione tra 2 record

void stampaRecord(int nContatti);						// Procedura stampa tutti record

void cercaRecord(int nContatti);						// Procedura di ricerca record per chiave

void ordinaElenco(int nContatti);						// Procedura ordinamento (bubble-sort) record

void modificaRecord(int nContatti, bool &el, bool &ri); // Procedura modifica record

void aggiungiRecord(int &nContatti, bool &pos);			// Procedura aggiunta record

void eliminaRecord(int &nContatti, bool &el, bool &ri);	// Procedura eliminaizone record

void salvaFile(int nContatti, bool &s);					// Procedura di gestione salvataggio record a file

void noSalvare(bool sal, int nContatti);				// Procedura di terminazione | In caso le modifiche non siano salvate, chiederà se è necessario farlo

void save(int nContatti);								// Procedura di salvataggio record a file

bool isInSel(int s,int v[], int l);						// Funzione che ritorna true se il record indicato è stato selezionato

void formatta(char str[]);

void annullaAzione(int &nContatti,int ls);

void verificaEsistenza();

void resettaIndex(int nContatti);

bool esiste(int c);

int lunstr(char *str);

char toLowCase(char ch);

char toUpCase(char ch);

int strToInt(char *str);

void cpystr(char *str1, char *str2);

//int cmpstr(char *str1, char *str2);


int main()
{
    verificaEsistenza();
    int n = leggiRecord();		// nella variabile n viene salvato il numero di record
								// vengono caricati i record dal file
    bool sal = true;	        // La variabile sal sara posta a true se tutte le modifiche sono state salvate

    int sc,						// Variabile gestione scelta opzione
        ls = -1;
    char ap[10];				// Striga di lettura scelta da tastiera per evitare errori runtime
    stampaMenu(n,ls);				// Viene stampato il menù
    do {
        do {
            printf("Scegliere un opzione: ");		// Richiesta di scelta opzione
            fflush(stdin);
            gets(ap);								// Lettura inserimento da tastiera
            sc = strToInt(ap);							// Conversione valore inserito in int
            system("CLS");							// Pulizia scermo
            if(sc > 9 || sc < 1)  {					// Se l'opzione inserita non esite,
                stampaMenu(n,ls);							// Viene ristampata menù e richesta e ripetuto l'inserimento
                printf("Inserire un opzione tra 1 e 9\n\n");
            }
        } while(sc > 9 || sc < 1);

        switch(sc) {				// Controllo opzione scelta
        case 1:						// Opzione 1. stampa record
            stampaRecord(n);		// Richiamo funzione stampa record
            system("PAUSE");		// Attesa pressione tasto prima di continuare
            system("CLS");			// Pulizia scermo
            stampaMenu(n,ls);			// Viene stampato il menù
            break;
        case 2:						// Opzione 2. cerca record
            cercaRecord(n);			// Richiamo funzione ricerca record
            system("PAUSE");		// Attesa pressione tasto prima di continuare
            system("CLS");			// Pulizia scermo
            stampaMenu(n,ls);			// Viene stampato il menù
            break;
        case 3:											// Opzione 3. ordinamento record
            ordinaElenco(n);							// Richiamo funzione ordinamento record
            ls = 3;
            stampaMenu(n,ls);								// Viene stampato il menù
            printf("Elenco ordinato con successo\n\n");	// Conferma, a video, dell'esecuzione dell'ordinamento
            sal = false;								// La variabile booleana sal segnala la presenza di modifiche non salvate
            break;
        case 4:
            bool el,
                ri;
            do {
                modificaRecord(n,el,ri);
                system("CLS");
            } while (ri);
            if(el) {
                ls = 0;
                stampaMenu(n,ls);
                printf("Record modificato con successo\n\n");
                sal = false;

            }
            else {
                stampaMenu(n,ls);
                printf("Azione annullata con successo\n\n");
            }
            break;
        case 5:																// Opzione 5. aggiunta record
            bool pos;														// La variabile pos, quanto a true, segnala la riuscita dell'aggiunta record
            aggiungiRecord(n,pos);											// Richiamo finzione aggiunta record
                                                                            // Viene stampato il menù
            if (pos) {
                ls = 1;
                stampaMenu(n,ls);                                        // Se l'aggiunta è andata a buon fine,
                printf("Record aggiunto con successo\n\n");						// Viene stampata a video la conferma
                sal = false;
                											// La variabile booleana sal segnala la presenza di modifiche non salvate
            }
            else {
                stampaMenu(n,ls);
                printf("Impossibile inserire un record, file pieno\n\n");
            } 	                                                // Altrimenti viene stampata la conferma di annullamento
            break;
        case 6:													// Opzione 6. eliminazione record

            do {
            eliminaRecord(n,el,ri);									// Richiamo funzione eliminazione record
            system("CLS");											// pulizia schermo
            } while(ri);										// Se l'utente non ha finito ripeti
            										// Viene stampato il menù
            if(el) {
                ls = 2;											// Se l'eliminazione è andata a buon fine,
                stampaMenu(n,ls);
                printf("Record eliminato con successo\n\n");		// Viene stampata a video la conferma
                sal = false;
                								// La variabile booleana sal segnala la presenza di modifiche non salvate
            }
            else {
                stampaMenu(n,ls);
                printf("Azione annullata con successo\n\n");	// Altrimenti viene stampata la conferma di annullamento
            }
            break;
        case 7:													// Opzione 7. salvataggio modifiche a file
            bool ibs;											// La variabile ibs viene posta a true se il salvataggio è stato eseguito
            salvaFile(n, ibs);									// Richiamo funzione gestione salvataggio
            stampaMenu(n,ls);										// Viene stampato il menù
            if(ibs) {											// Se il salvataggio è andato a buon fine,
				printf("Modifiche salvate con successo\n\n");		// Viene stampata a video la conferma
                sal = true;											// La variabile booleana sal segnala la presenza di modifiche non salvate
            }
            else printf("Azione annullata con successo\n\n");   // Altrimenti viene stampata la conferma di annullamento
            break;
        case 8:													// Opzione 8. uscita senza salvataggio obbligatorio
            noSalvare(sal, n);									// Richiamo alla funzione di gestione terminazione (richiesta di salvataggio se sal è false)
            stampaMenu(n,ls);										// Viene stampato il menù
            break;
        case 9:
            if(ls != -1) {
                annullaAzione(n,ls);

                ls = -1;
                stampaMenu(n,ls);
                printf("Modifica annullata correttamente\n\n");

            }
            else {
                stampaMenu(n,ls);
                printf("Non ci sono modifiche da annullare\n\n");
            }
            break;
        default:												// Non è possibile che si raggiunga il fase default dello switch
            exit(1);											// Pertanto l'esecuzione di questo condice è un errore
            break;
        }

    } while(sc != 8);											// Se la scelta non è quella di terminazione, si ritorna al menù
    return 0;
}

void stampaMenu(int nContatti, int ls)
{					// Funzione di stampa menù
    printf("Rubrica - %d Contatti salvati\n\n",nContatti);
    printf("\t1. Stampa tutti i record\n");
    printf("\t2. Cerca un record\n");
    printf("\t3. Riordina l\'elenco\n");
    printf("\t4. Modifica record\n");
    printf("\t5. Aggiungi record\n");
    printf("\t6. Elimina record\n");
    printf("\t7. Salva le modifiche\n");
    printf("\t8. Esci\n");

    switch(ls) {
    case -1:
        printf("\n");
        break;
    case 0:
        printf("\n\t9. Annulla l'ultima modifica: %s %s %s\n\n",sLast.nome,sLast.cognome,sLast.numero);
        break;
    case 1:
        printf("\n\t9. Annulla l'ultima aggiunta: %s %s %s\n\n",sLast.nome,sLast.cognome,sLast.numero);
        break;
    case 2:
        printf("\n\t9. Annulla l'ultima eliminazione: %s %s %s\n\n",sLast.nome,sLast.cognome,sLast.numero);
        break;
    case 3:
        printf("\n\t9. Annulla l'ultimo ordinamento\n\n");
        break;
    }
}

int leggiRecord()
{               							// Funzione lettura record da file
    FILE *pfi = fopen("contatti.txt","r");	// Apertura file
    int i = 0,j;								// Dichiarazione ed inizializzazione contatore
    while(!feof(pfi) && i < RMAX) {				// Finché il non si raggiungerà la fine del file o il limite di record inseribili

        fscanf(pfi,"%d",&sCont[i].lunghezza_nome);
        if(sCont[i].lunghezza_nome == 0) {
            break;
        }
        fflush(stdin);
        fgets(sCont[i].nome,sCont[i].lunghezza_nome+1,pfi);
        fscanf(pfi,"%d",&sCont[i].lunghezza_cognome);
        fflush(stdin);
        fgets(sCont[i].cognome,sCont[i].lunghezza_cognome+1,pfi);
        fscanf(pfi,"%d",&sCont[i].lunghezza_numero);

        fflush(stdin);

        fgets(sCont[i].numero,sCont[i].lunghezza_numero+2,pfi);

        for(j = 0; j < sCont[i].lunghezza_numero; j++) {
            sCont[i].numero[j] = sCont[i].numero[j+1];
        }
        sCont[i].numero[j] = '\0';

        sCont[i].index = i;

        i++;									// Incremento contatore
    }
    fclose(pfi);							// Chiusura file
    return i;								// Ritornato il numero di record
}

void scambioRecord(int a, int b)
{                           				// Funzione di scambio di 2 record
    char temp[15];								// La variabile temp servità come variabile temporanea
    int t;
    cpystr(temp,sCont[a].nome);
    cpystr(sCont[a].nome,sCont[b].nome);		// Esegui lo scambio classico dei nomi
    cpystr(sCont[b].nome, temp);
    cpystr(temp,sCont[a].cognome);
    cpystr(sCont[a].cognome,sCont[b].cognome); 	// Esegui lo scambio classico dei cognomi
    cpystr(sCont[b].cognome, temp);
    cpystr(temp,sCont[a].numero);
    cpystr(sCont[a].numero,sCont[b].numero);	// Esegui lo scambio classico dei numeri
    cpystr(sCont[b].numero, temp);
    t = sCont[a].lunghezza_nome;
    sCont[a].lunghezza_nome = sCont[b].lunghezza_nome;
    sCont[b].lunghezza_nome = t;
    t = sCont[a].lunghezza_cognome;
    sCont[a].lunghezza_cognome = sCont[b].lunghezza_cognome;
    sCont[b].lunghezza_cognome = t;
    t = sCont[a].lunghezza_numero;
    sCont[a].lunghezza_numero = sCont[b].lunghezza_numero;
    sCont[b].lunghezza_numero = t;
    t = sCont[a].index;
    sCont[a].index = sCont[b].index;
    sCont[b].index = t;
}

void stampaRecord(int nContatti)
{                               			// Funzione stampa record
    printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero"); // stampa intestazione
    // Ciclo di stampa tutti i record in ordine di salvataggio
	// Formato: INDICE NOME	COGNOME	NUMERO
	for(int i = 0; i < nContatti;i++) {
        printf("%15d.%15s%15s%15s\n",i+1,sCont[i].cognome,sCont[i].nome,sCont[i].numero);
    }
    printf("\n");

}

void cercaRecord(int nContatti)
{                               			// Funzione ricerca record
											// La funzione permette all'utente di inserire una chiave
											// e di filtrare tutti i record che contengono (anche parzialemente)
											// la chiave di ricerca
											// es: chiave -> ndr | Plausibili record filtrabili -> Andrea 	D. 			1111111111
											//													   Massimo 	Sandretti	3347045526
											// N.B. Il sistema di filtraggio non è case-sensitive

	char tbs[15];							// La stringa tbs contiene la chiave di ricerca
    printf("Inserire la chiave di ricerca: ");
    fflush(stdin);
    gets(tbs);								// Inserimento chiave
    printf("\n");
    bool it;								// La variabile it è a true se la chiave è stata trovata
    int j = 1;

    printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");

    for(int i = 0; i < nContatti; i++) {							// Inizio ciclo di scorrimento record
        it = true;														// Si da per scontato che la chiave sarà presente nella stringa
        for(int k = 0,u = 0; k < lunstr(tbs); k++) {					// Inizia un ciclo di scorrimento della chiave
				if(toLowCase(tbs[k]) != toLowCase(sCont[i].nome[k+u])) {		// Se viene trovato un valore diverso dalla chiave,
					it = false;													// La chiave non è stata trovata
				}															//
				if(lunstr(sCont[i].nome) >= u+lunstr(tbs) && !it) {			// Se non si è ancora arrivati alla fine della stringa,
						it = true;												// Si da per scontato che la chiave si trovi a partire dalla posizione u + 1 della stringa
						k = -1;													// L'indice della chiave viene riazzerato
						u++;													// Indice di posizione d'inizio della chiave viene incrementato
            }
        }
        if(it) {																			// Se la chiave non è stata trovata in una posizione della stringa
            printf("%15d.%15s%15s%15s\n",j,sCont[i].cognome,sCont[i].nome,sCont[i].numero);		// L'intero record, di cui fa parte la stringa viene stampato;
            j++;																				// Viene incrementato il contatore dei record
            continue;																			// Non è necessario procedere il controllo nelle altre stringhe dello stesso record, quindi si salta alla fine del ciclo
        }

        it = true;														// Si da per scontato che la chiave sarà presente nella stringa

        for(int k = 0, u = 0; k < lunstr(tbs); k++) {					// Inizia un ciclo di scorrimento della chiave
            if(toLowCase(tbs[k]) != toLowCase(sCont[i].cognome[k+u])) {			// Se viene trovato un valore diverso dalla chiave,
                it = false;														// La chiave non è stata trovata
            }
            if(lunstr(sCont[i].cognome) >= u+lunstr(tbs) && !it) {			// Se non si è ancora arrivati alla fine della stringa,
                it = true;														// Si da per scontato che la chiave si trovi a partire dalla posizione u + 1 della stringa
                k = -1;															// L'indice della chiave viene riazzerato
                u++;															// Indice di posizione d'inizio della chiave viene incrementato
            }
        }
        if(it) {																			// Se la chiave non è stata trovata in una posizione della stringa
            printf("%15d.%15s%15s%15s\n",j,sCont[i].cognome,sCont[i].nome,sCont[i].numero);		// L'intero record, di cui fa parte la stringa viene stampato;
            j++;																				// Viene incrementato il contatore dei record
            continue;																			// Non è necessario procedere il controllo nelle altre stringhe dello stesso record, quindi si salta alla fine del ciclo
        }

        it = true;													// Si da per scontato che la chiave sarà presente nella stringa
        for(int k = 0, u = 0; k < lunstr(tbs); k++) {				// Inizia un ciclo di scorrimento della chiave
            if(toLowCase(tbs[k]) != toLowCase(sCont[i].numero[k+u])) {		// Se viene trovato un valore diverso dalla chiave,
                it = false;													// La chiave non è stata trovata
            }
            if(lunstr(sCont[i].numero) >= u+lunstr(tbs) && !it) {		// Se non si è ancora arrivati alla fine della stringa,
                it = true;													// Si da per scontato che la chiave si trovi a partire dalla posizione u + 1 della stringa
                k = -1;														// L'indice della chiave viene riazzerato
                u++;														// Indice di posizione d'inizio della chiave viene incrementato
            }
        }
        if(it) {																			// Se la chiave non è stata trovata in una posizione della stringa
            printf("%15d.%15s%15s%15s\n",j,sCont[i].cognome,sCont[i].nome,sCont[i].numero);		// L'intero record, di cui fa parte la stringa viene stampato;
            j++;																				// Viene incrementato il contatore dei record
            continue;																			// Non è necessario procedere il controllo nelle altre stringhe dello stesso record, quindi si salta alla fine del ciclo
        }
    }
    if(j == 1) { 											// Se non vengono trovati record contenenti la chiave di ricerca,
        system("CSL");
        printf("Non e\' stato trovato nessun record\n\n");		// L'utente viene avvisato con un messaggio
    }
    else {
        printf("\n");
    }
}

void ordinaElenco(int nContatti)
{               							// Funzione di ordinamento record (bubble-sort)

    for (int i = 0; i < nContatti; i++) {
        ord.v[i] = sCont[i].index;
    }
    int k = 0;
    bool ordw = false;										// La variabile ord fungerà da spia: sarà posta a false se potrebbero essere necessari ulteriori scambi
    while(!ordw)  {
        k++; // Finché i record non saranno ordinati,
        ordw = true;												// Do per scontato che l'i-esimo ciclo sia l'ultimo necessario;
        for(int i = 0; i < nContatti-k; i++) {					// Inizia il ciclo di scorrimento dei record
            if(strcmp(sCont[i].cognome,sCont[i+1].cognome) > 0) {			// se la stringa "nome" del report i-esimo è alfabeticamente maggiore di quella di del record i+i-esimo
                scambioRecord(i,i+1);									// Effettuo lo scambio tra i due record
                ordw = false;											// Dato che è stato necessario uno scambio, la sentinella viene posta a false: non rodinato
            }
            else {													// Altrimenti
                if(strcmp(sCont[i].cognome,sCont[i+1].cognome) == 0) {		// Se la stringa "nome" del report i-esimo è uguale alla stringa "nome" del report i+1-esimo
                    if(strcmp(sCont[i].nome,sCont[i+1].nome) > 0) {	//  se la stringa "cognome" del report i-esimo è alfabeticamente maggiore di quella di del record i+i-esimo
                        scambioRecord(i,i+1);									// Effettuo lo scambio tra i due record
                        ordw = false;											// Dato che è stato necessario uno scambio, la sentinella viene posta a false: non rodinato
                    }
                    else {													// Altrimenti
                        if(strcmp(sCont[i].nome,sCont[i+1].nome) == 0) {	// Se la stringa "cognome" del report i-esimo è uguale alla stringa "cognome" del report i+1-esimo
                            if(strcmp(sCont[i].numero,sCont[i+1].numero) > 0) { 	// se la stringa "numero" del report i-esimo è alfabeticamente maggiore di quella di del record i+i-esimo
                                scambioRecord(i,i+1);									// Effettuo lo scambio tra i due record
                                ordw = false;											// Dato che è stato necessario uno scambio, la sentinella viene posta a false: non rodinato
                            }
                        }
                    }
                }
            }

        }
    }
}

void modificaRecord(int nContatti, bool &el, bool &ri)
{
    el = false;
    ri = false;
    char conf;

    int v[RMAX];
    int c = 0;
    for(int i = 0; i < RMAX; i++)
        v[i] = -1;

    char tbs[15];
    printf("Inserire la chiave di ricerca: ");
    fflush(stdin);
    gets(tbs);
    printf("\n");
    bool it;
    int j = 1,sel;

    printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");

    for(int i = 0; i < nContatti; i++) {
        it = true;
        for(int k = 0,u = 0; k < lunstr(tbs); k++) {
            if(toLowCase(tbs[k]) != toLowCase(sCont[i].nome[k+u])) {
                it = false;
            }
            if(lunstr(sCont[i].nome) >= u+lunstr(tbs) && !it) {
                it = true;
                k = -1;
                u++;
            }
        }
        if(it) {
            printf("%15d.%15s%15s%15s\n",j,sCont[i].cognome,sCont[i].nome,sCont[i].numero);

            v[c++] = i;

            j++;
            continue;
        }

        it = true;

        for(int k = 0, u = 0; k < lunstr(tbs); k++) {
            if(toLowCase(tbs[k]) != toLowCase(sCont[i].cognome[k+u])) {
                it = false;
            }
            if(lunstr(sCont[i].cognome) >= u+lunstr(tbs) && !it) {
                it = true;
                k = -1;
                u++;
            }
        }
        if(it) {
            printf("%15d.%15s%15s%15s\n",j,sCont[i].cognome,sCont[i].nome,sCont[i].numero);

            v[c++] = i;

            j++;
            continue;
        }

        it = true;
        for(int k = 0, u = 0; k < lunstr(tbs); k++) {
            if(toLowCase(tbs[k]) != toLowCase(sCont[i].numero[k+u])) {
                it = false;
            }
            if(lunstr(sCont[i].numero) >= u+lunstr(tbs) && !it) {
                it = true;
                k = -1;
                u++;
            }
        }
        if(it) {
            printf("%15d.%15s%15s%15s\n",j,sCont[i].cognome,sCont[i].nome,sCont[i].numero);

            v[c++] = i;

            j++;
            continue;
        }
    }
    if(j == 1) {
        system("CLS");

        do {
            printf("Non e\' stato trovato nessun record, ritentare? [S/N]: ");
            scanf("%c", &conf);
            system("CLS");
        } while(toLowCase(conf) != 's' && toLowCase(conf) != 'n');
        if(toLowCase(conf) == 's') {
            el = true;
            ri = true;
        }
    }
    else {
        if(j == 2) {
            do {
                printf("\nConfermare di voler modificare questo record? [S/N]: ");
                scanf("%c", &conf);
                system("CLS");
                if(toLowCase(conf) != 's' && toLowCase(conf) != 'n')  {
                    printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");
                    printf("%15d.%15s%15s%15s\n",j,sCont[v[0]].cognome,sCont[v[0]].nome,sCont[v[0]].numero);
                }
            } while(toLowCase(conf) != 's' && toLowCase(conf) != 'n');
            if(toLowCase(conf) == 's') {
                el = true;

                cpystr(sLast.nome,sCont[v[0]].nome);
                cpystr(sLast.cognome,sCont[v[0]].cognome);
                cpystr(sLast.numero,sCont[v[0]].numero);
                sLast.lastid = v[0];

                system("CLS");
                fflush(stdin);
                printf("Inserire il nuovo nome [%s]: ",sCont[v[0]].nome);
                gets(tbs);
                if(lunstr(tbs) > 0) {
                    cpystr(sCont[v[0]].nome,tbs);
                    sCont[v[0]].lunghezza_nome = lunstr(tbs);
                    formatta(sCont[v[0]].nome);
                }
                printf("Inserire il nuovo cognome [%s]: ",sCont[v[0]].cognome);
                gets(tbs);
                if(lunstr(tbs) > 0) {
                    cpystr(sCont[v[0]].cognome,tbs);
                    sCont[v[0]].lunghezza_cognome = lunstr(tbs);
                    formatta(sCont[v[0]].cognome);
                }
                printf("Inserire il nuovo numero [%s]: ", sCont[v[0]].numero);
                gets(tbs);
                if(lunstr(tbs) > 0) {
                    cpystr(sCont[v[0]].numero,tbs);
                    sCont[v[0]].lunghezza_numero = lunstr(tbs);
                }
            }
        }
        else {
            system("CLS");
            printf("Record trovati:\n");
            do {
                printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");
                for(int g = 0; g < c; g++) {
                    printf("%15d.%15s%15s%15s\n\n",v[g]+1,sCont[v[g]].cognome,sCont[v[g]].nome,sCont[v[g]].numero);
                }
                printf("Selezionare il record da eliminare: ");
                scanf("%s", &tbs);
                sel = strToInt(tbs);
                sel--;
                system("CLS");
                if(!isInSel(sel, v,c)) {
                    printf("Il record selezionato non e\' tra quelli selezionati\n\n");
                }
            } while(!isInSel(sel, v,c));

            printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");
            printf("%15d.%15s%15s%15s\n\n",sel+1,sCont[sel].cognome,sCont[sel].nome,sCont[sel].numero);

            do {
                printf("Confermare di voler modificare questo record? [S/N]: ");
                scanf("%c", &conf);
                system("CLS");
                if(toLowCase(conf) != 's' && toLowCase(conf) != 'n')  {
                    printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");
                    printf("%15d.%15s%15s%15s\n\n",sel+1,sCont[sel].cognome,sCont[sel].nome,sCont[sel].numero);
                }
            } while(toLowCase(conf) != 's' && toLowCase(conf) != 'n');
            if(toLowCase(conf) == 's') {
                el = true;

                cpystr(sLast.nome,sCont[sel].nome);
                cpystr(sLast.cognome,sCont[sel].cognome);
                cpystr(sLast.numero,sCont[sel].numero);
                sLast.lastid = sel;

                system("CLS");
                fflush(stdin);
                printf("Inserire il nuovo nome [%s]: ",sCont[sel].nome);
                gets(tbs);
                if(lunstr(tbs) > 0) {
                    cpystr(sCont[sel].nome,tbs);
                    sCont[sel].lunghezza_nome = lunstr(tbs);
                    formatta(sCont[0].nome);
                }

                printf("Inserire il nuovo cognome [%s]: ",sCont[sel].cognome);
                gets(tbs);
                if(lunstr(tbs) > 0) {
                    cpystr(sCont[sel].cognome,tbs);
                    sCont[sel].lunghezza_cognome = lunstr(tbs);
                    formatta(sCont[0].cognome);
                }

                printf("Inserire il nuovo numero [%s]: ", sCont[sel].numero);
                gets(tbs);
                if(lunstr(tbs) > 0) {
                    cpystr(sCont[sel].numero,tbs);
                    sCont[sel].lunghezza_numero = lunstr(tbs);
                }
            }
        }
    }
}

void aggiungiRecord(int &nContatti, bool &pos)
{                               			// Funzione aggiunta record
    pos = true;

    char conf;

    if(nContatti == RMAX) {										// Se è stato raggiunto il massimo di record
        pos = false;												// il programma vieta l'inserimento di un nuovo record
    }
    else {
        printf("Inserire il nome: ");
        gets(sCont[nContatti].nome);
        sCont[nContatti].lunghezza_nome = lunstr(sCont[nContatti].nome);
        formatta(sCont[nContatti].nome);

        do {
            printf("Inserire il cognome: ");
            gets(sCont[nContatti].cognome);
            sCont[nContatti].lunghezza_cognome = lunstr(sCont[nContatti].cognome);
            if(!sCont[nContatti].lunghezza_cognome) {
                system("CLS");
                printf("Impossibile lasciare vuoto questo campo\n\n");
            }
        } while(!sCont[nContatti].lunghezza_cognome);
        formatta(sCont[nContatti].cognome);



        printf("Inserire il numero: ");
        gets(sCont[nContatti].numero);
        sCont[nContatti].lunghezza_numero = lunstr(sCont[nContatti].numero);

        cpystr(sLast.nome,sCont[nContatti].nome);
        cpystr(sLast.cognome,sCont[nContatti].cognome);
        cpystr(sLast.numero,sCont[nContatti].numero);
        sLast.lastid = nContatti;
        sCont[nContatti].index = nContatti;



        if(esiste(nContatti)) {
            system("CLS");
            do {
                printf("Questo contatto e\' gia\' stato registrato, mantenerlo comunque? [S/N]: ");
                scanf("%c", &conf);
                system("CLS");
                if(toLowCase(conf) != 's' && toLowCase(conf) != 'n')  {
                    printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");
                    printf("%15d.%15s%15s%15s\n\n",nContatti+1,sCont[nContatti].cognome,sCont[nContatti].nome,sCont[nContatti].numero);
                }
            } while(toLowCase(conf) != 's' && toLowCase(conf) != 'n');
            if(toLowCase(conf) == 'n') {
                pos = false;
            }
            else {
                nContatti++;
            }
        }
        else {
            nContatti++;
        }
    }
    system("CLS");
}

void eliminaRecord(int &nContatti, bool &el, bool &ri)
{                                       	// Funzione eliminazione record
    el = false;
    ri = false;
    char conf;

    int v[RMAX];
    int c = 0;
    for(int i = 0; i < RMAX; i++)
        v[i] = -1;

    char tbs[15];
    printf("Inserire la chiave di ricerca: ");
    fflush(stdin);
    gets(tbs);
    printf("\n");
    bool it;
    int j = 1,sel;

    printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");
    for(int i = 0; i < nContatti; i++) {
        it = true;
        for(int k = 0,u = 0; k < lunstr(tbs); k++) {
            if(toLowCase(tbs[k]) != toLowCase(sCont[i].nome[k+u])) {
                it = false;
            }
            if(lunstr(sCont[i].nome) >= u+lunstr(tbs) && !it) {
                it = true;
                k = -1;
                u++;
            }
        }
        if(it) {
            printf("%15d.%15s%15s%15s\n",j,sCont[i].cognome,sCont[i].nome,sCont[i].numero);

            v[c++] = i;

            j++;
            continue;
        }

        it = true;

        for(int k = 0, u = 0; k < lunstr(tbs); k++) {
            if(toLowCase(tbs[k]) != toLowCase(sCont[i].cognome[k+u])) {
                it = false;
            }
            if(lunstr(sCont[i].cognome) >= u+lunstr(tbs) && !it) {
                it = true;
                k = -1;
                u++;
            }
        }
        if(it) {
            printf("%15d.%15s%15s%15s\n",j,sCont[i].cognome,sCont[i].nome,sCont[i].numero);

            v[c++] = i;

            j++;
            continue;
        }

        it = true;
        for(int k = 0, u = 0; k < lunstr(tbs); k++) {
            if(toLowCase(tbs[k]) != toLowCase(sCont[i].numero[k+u])) {
                it = false;
            }
            if(lunstr(sCont[i].numero) >= u+lunstr(tbs) && !it) {
                it = true;
                k = -1;
                u++;
            }
        }
        if(it) {
            printf("%15d.%15s%15s%15s\n",j,sCont[i].cognome,sCont[i].nome,sCont[i].numero);

            v[c++] = i;

            j++;
            continue;
        }
    }
    if(j == 1) {
        system("CLS");
        do {
            printf("Non e\' stato trovato nessun record, ritentare? [S/N]: ");
            scanf("%c", &conf);
            system("CLS");
        } while(toLowCase(conf) != 's' && toLowCase(conf) != 'n');
        if(toLowCase(conf) == 's') {
            el = true;
            ri = true;
        }
    }
    else {
        if(j == 2) {
            do {
                printf("Confermare l\'eliminazione di questo record? [S/N]: ");
                scanf("%c", &conf);
                system("CLS");
                if(toLowCase(conf) != 's' && toLowCase(conf) != 'n')  {
                    printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");
                    printf("%15d.%15s%15s%15s\n\n",j,sCont[v[0]].cognome,sCont[v[0]].nome,sCont[v[0]].numero);
                }
            } while(toLowCase(conf) != 's' && toLowCase(conf) != 'n');
            if(toLowCase(conf) == 's') {
                el = true;

                cpystr(sLast.nome,sCont[v[0]].nome);
                cpystr(sLast.cognome,sCont[v[0]].cognome);
                cpystr(sLast.numero,sCont[v[0]].numero);
                sLast.lastid = v[0];

                for(int i = v[0]; i < nContatti-1; i++) {
                    cpystr(sCont[i].nome,sCont[i+1].nome);
                    cpystr(sCont[i].cognome,sCont[i+1].cognome);
                    cpystr(sCont[i].numero,sCont[i+1].numero);
                    sCont[i].lunghezza_nome = sCont[i+1].lunghezza_nome;
                    sCont[i].lunghezza_cognome = sCont[i+1].lunghezza_cognome;
                    sCont[i].lunghezza_numero = sCont[i+1].lunghezza_numero;
                }

                nContatti--;
                resettaIndex(nContatti);
            }
        }
        else {
            char sup[10];
            system("CLS");
            printf("Record trovati:\n");
            do {
                printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");
                for(int g = 0; g < c; g++) {
                    printf("%15d.%15s%15s%15s\n\n",v[g]+1,sCont[v[g]].cognome,sCont[v[g]].nome,sCont[v[g]].numero);
                }
                printf("Selezionare il record da eliminare: ");
                scanf("%s", sup);
                sel = strToInt(sup);
                sel--;
                system("CLS");
                if(!isInSel(sel, v,c)) {
                    printf("Il record selezionato non e\' tra quelli selezionati\n\n");
                }
            } while(!isInSel(sel, v,c));

            printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");
            printf("%15d.%15s%15s%15s\n\n",sel+1,sCont[sel].cognome,sCont[sel].nome,sCont[sel].numero);

            do {
                printf("Confermare l\'eliminazione di questo record? [S/N]: ");
                scanf("%c", &conf);
                system("CLS");
                if(toLowCase(conf) != 's' && toLowCase(conf) != 'n')  {
                    printf("%15s%15s%15s%15s\n\n","Indice","Cognome","Nome","Numero");
                    printf("%15d.%15s%15s%15s\n\n",sel+1,sCont[sel].cognome,sCont[sel].nome,sCont[sel].numero);
                }
            } while(toLowCase(conf) != 's' && toLowCase(conf) != 'n');
            if(toLowCase(conf) == 's') {
                el = true;

                cpystr(sLast.nome,sCont[sel].nome);
                cpystr(sLast.cognome,sCont[sel].cognome);
                cpystr(sLast.numero,sCont[sel].numero);
                sLast.lastid = sel;

                for(int i = sel; i < nContatti-1; i++) {
                    cpystr(sCont[i].nome,sCont[i+1].nome);
                    cpystr(sCont[i].cognome,sCont[i+1].cognome);
                    cpystr(sCont[i].numero,sCont[i+1].numero);
                    sCont[i].lunghezza_nome = sCont[i+1].lunghezza_nome;
                    sCont[i].lunghezza_cognome = sCont[i+1].lunghezza_cognome;
                    sCont[i].lunghezza_numero = sCont[i+1].lunghezza_numero;
                }

                nContatti--;
                resettaIndex(nContatti);
            }
        }
    }
}

void salvaFile(int nContatti, bool &s)
{
    char conf;
    do {
        printf("Vuoi davvero salvare le modifiche? [S/N]: ");
        scanf("%c", &conf);
        system("CLS");
    } while(toLowCase(conf) != 's' && toLowCase(conf) != 'n');
    if(toLowCase(conf) == 's') {
        s = true;
        save(nContatti);
    }
    else {
        s = false;
    }
}

void noSalvare(bool sal, int nContatti)
{
    char conf;
    if(!sal) {
        do {
            printf("Vuoi salvare le modifiche prima di uscire? [S/N]: ");
            scanf("%c", &conf);
            system("CLS");
        } while(toLowCase(conf) != 's' && toLowCase(conf) != 'n');
        if(toLowCase(conf) == 's') {
            save(nContatti);
        }
    }
}

void save(int nContatti)
{
    FILE *pfo = fopen("contatti.txt","w");
    for(int i = 0; i < nContatti; i++) {
        fprintf(pfo,"%d%s %d%s %d %s\n",sCont[i].lunghezza_nome,sCont[i].nome,sCont[i].lunghezza_cognome,sCont[i].cognome, sCont[i].lunghezza_numero,sCont[i].numero);
    }
    fclose(pfo);
}

bool isInSel(int s,int v[], int l)
{
    for(int i = 0; i < l; i++) {
        if(v[i]==s) {
            return true;
        }
    }
    return false;
}

void formatta(char str[])
{
    int i = 0;
    while (i < lunstr(str)) {
        str[i] = toUpCase(str[i]);
        i++;
        while(str[i] != ' ' && str[i]) {
            str[i] = toLowCase(str[i]);
            i++;
        }
        i++;
    }
}

void annullaAzione(int &nContatti,int ls)
{
    switch (ls) {
    case 0:
        // modifica
        cpystr(sCont[sLast.lastid].nome, sLast.nome);
        cpystr(sCont[sLast.lastid].cognome, sLast.cognome);
        cpystr(sCont[sLast.lastid].numero, sLast.numero);
        break;
    case 1:
        // aggiungi
        for(int i = sLast.lastid; i < nContatti-1; i++) {
            ///
            cpystr(sCont[i].nome,sCont[i+1].nome);
            cpystr(sCont[i].cognome,sCont[i+1].cognome);
            cpystr(sCont[i].numero,sCont[i+1].numero);
            sCont[i].lunghezza_nome = sCont[i+1].lunghezza_nome;
            sCont[i].lunghezza_cognome = sCont[i+1].lunghezza_cognome;
            sCont[i].lunghezza_numero = sCont[i+1].lunghezza_numero;
        }
        nContatti--;
        break;
    case 2:
        // elimina
        if(nContatti == RMAX) {
            system("CLS");                                            // Se è stato raggiunto il massimo di record
            printf("Impossibile re-inserire il report, file pieno");												// il programma vieta l'inserimento di un nuovo record
        }
        else {
            system("CLS");
            int i;
            for(i = nContatti; i > sLast.lastid;i--) {
                cpystr(sCont[i].nome,sCont[i-1].nome);
                cpystr(sCont[i].cognome,sCont[i-1].cognome);
                cpystr(sCont[i].numero,sCont[i-1].numero);
            }
            cpystr(sCont[i].nome,sLast.nome);
            cpystr(sCont[i].cognome,sLast.cognome);
            cpystr(sCont[i].numero,sLast.numero);
            nContatti++;
        }
        break;
    case 3:
        int j,i;
        for(i = 0; i < nContatti-1; i++) {
            if(ord.v[i] != sCont[i].index) {
                j = i+1;
                while(sCont[j].index != ord.v[i]) j++;
                scambioRecord(i,j);
            }
        }
        break;
    }
}

void verificaEsistenza()
{
    FILE *pf = fopen("contatti.txt","r");
    if(pf == NULL) {
        fclose(pf);
        pf = fopen("contatti.txt","w");
    }
    fclose(pf);
}

void resettaIndex(int nContatti)
{
    for(int i = 0; i < nContatti; i++) {
        sCont[i].index = i;
    }
}

bool esiste(int c) {
    bool e = false;
    for(int i = 0; i < c; i++) {
        if(strcmp(sCont[c].nome,sCont[i].nome) == 0 && strcmp(sCont[c].cognome,sCont[i].cognome) == 0 && strcmp(sCont[c].numero,sCont[i].numero) == 0) {
            e = true;
        }
    }
    return e;
}

int lunstr(char *str) {
    int l = 0;
    while(str[l]) l++;
    return l;
}

char toLowCase(char ch) {
    if(ch >= 65 && ch <= 90)
        ch+=32;
    return ch;
}

char toUpCase(char ch) {
    if(ch >= 97 && ch <= 122)
        ch-=32;
    return ch;
}

int strToInt(char *str) {
    int i = 0,r = 0;
    while(str[i]) {
        r *= 10;
        r += str[i]-48;
        i++;
    }
    return r;
}

void cpystr(char *str1, char *str2) {
    int i;
    for(i = 0; i < lunstr(str2)+1;i++) {
        str1[i] = str2[i];
    }
}

/*int cmpstr(char *str1, char *str2) {
    int i,r;
    bool t = false;
    while(str1[i] && str2[i] & !t) {
        if(str1[i] > str2[i]) {
            r = 1;
            t = true;
        }
        else {
            if(str1[i] < str2[i]) {
                r = -1;
                t = true;
            }
            else {
                r = 0;
            }
        }
        i++;
    }

    if(r == 0) {
        if(lunstr(str1) == lunstr(str2)) {
            return r;
        }
        else {
            if(lunstr(str1) > lunstr(str2)) {
                return 1;
            }
            else {
                return -1;
            }
        }
    }
    else {
        return r;
    }
}*/
