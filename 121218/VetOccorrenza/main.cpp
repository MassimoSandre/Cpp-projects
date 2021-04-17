#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAXV 20 // Dimensione massima del vettore

int main()
{
    int n,v[MAXV],vv[MAXV],vr[MAXV],r=0,trov,i,j;
    do {    // Mi assicuro che l'utente inserisca un numero di elementi inseribili nel vettore
        printf("Inserire il numero di valori del vettore: ");
        scanf("%d",&n);
        system("CLS");
        if(n<1||n>MAXV){
            printf("Si prega di inserire un numero positivo minore di %d\n\n",MAXV);
        }
    }while(n<1||n>MAXV);

    for(i=0;i<n;i++) { // Carico manualmente il vettore di partenza
        printf("Inserire i valori per il vettore(%d/%d): ",i+1,n);
        scanf("%d",&v[i]);
        system("CLS");
    }

    for(i=0;i<n;i++) { // Porto tutti i valori del vettore contatore a 0
        vr[i]=0;
    }

    for(i=0;i<n;i++) {  // Scorro tutti i valori del vettore
        trov=0; // Inizializzo il flag di rilevamento
        for(j=0;j<r;j++) {  // Scorro il vallore delle occorrenze
            if(v[i]==vv[j]) {   // Se il valore del vettore viene è già stato
                trov=1;         // Inserito nelle occorrenze
                vr[j]++;        // ci si limita a incrementare il contatore
            }                   // corrispondente
        }
        if(!trov) {           // Se invece il valore non si era ancora presentato
            vv[r]=v[i];       // esso viene inserito nel vettore delle occorrenze
            vr[r]++;          // e gli viene associato un contatore successivamente incrementato
            r++;              // A questo punto si estende la parte di lettura del vettore delle occorrenze
        }
    }
    for(i=0;i<r;i++) { // Output delle occorrenze
        printf("Il valore %d si ripete %d volte\n",vv[i],vr[i]);
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
