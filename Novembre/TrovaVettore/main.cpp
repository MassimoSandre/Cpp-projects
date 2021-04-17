#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int MAXN = 30;    // Valore massimo di elementi per il vettore
    int v[MAXN],            // Dichiarazione del vettore
        i,                  // Contatore/indice
        n,                  // Numero di valori da inserire
        t,                  // Valore da cercare
        trovato=0;          // Flag | Viene posto a 1 se il valore ricercato viene trovato
    do {                    // Controllo sull'input
        printf("Inserire un numero compreso tra 0 e %d: ",MAXN);
        scanf("%d",&n);
        system("CLS");
        if(n<1 || n>MAXN) {
            printf("Il numero inserito non e\' utilizzabile!\n\n");
        }
    }while(n<1 || n>MAXN);

    for(i=0;i<n;i++) {      // Inserimento valori vettore
        printf("Inserire il valore numero %d: ",i+1);
        scanf("%d",&v[i]);
        system("CLS");
    }
    printf("Inserire il valore da cercare: ");
    scanf("%d",&t);
    system("CLS");

    for(i=0;i<n;i++) {  // Ricerca valore richiesto
        if(v[i] == t) {
            trovato = 1;
            i=n;
        }
    }
    if(trovato)        // Verifica la presenza del valore richiesto
        printf("Il numero e\' stato trovato\n\n");
    else
        printf("Il numero non e\' stato trovato\n\n");
    system("PAUSE");
    return 0;
}
