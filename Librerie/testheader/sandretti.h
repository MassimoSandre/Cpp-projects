

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef SANDRETTI_H_INCLUDED
#define SANDRETTI_H_INCLUDED


namespace sandretti {

    //Inserimento di un numero con controllo | necessita di un valore minimo ed un valore massimo
    int ins(int mn,int mx) {
        if(mx<mn) {
            printf("Errore - Il valore mn non può essere maggiore di mx\n");
            exit(1);
        }
        else {
            int n;
            do {
                printf("Inserire un numero compreso tra %d e %d: ",mn,mx);
                scanf("%d",&n);
                system("CLS");
                if(n<mn||n>mx)
                    printf("Il numero inserito non rispetta i limiti!\n\n");
            }while(n<mn||n>mx);
            return n;
        }
    }

    // Caricamento manuale di un vettore di t elementi
    void manualArray(int v[],int t) {
        int i;
        for(i=0;i<t;i++) {
            printf("Inserire il valore da inserire nella posizione %d: ",i);
            scanf("%d",&v[i]);
            system("CLS");
        }
    }

    void randArray(int v[],int t,int mn,int mx) {
        srand(time(NULL));
        int i;
        for(i=0;i<t;i++) {
            v[i] = (rand()%(mx-mn+1))+mn;
        }
    }
}

#endif
