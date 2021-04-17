#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int v[7]={0,0,0,0,0,0,0},   // v[0] numero di valori | v[1:6] frequenza facce dei dadi
        i,      // Contatore | Indice
        vg,     // Valore Generato
        fr;     // Valore di cui trovare la frequenza
    do {        // Controllo input numero di lanci
        printf("Inserire un numero positivo di lanci: ");
        scanf("%d",&v[0]);
        system("CLS");
        if(v[0]<0) {
            printf("Il numero inserito non e\' utilizzabile!\n\n");
        }
    }while(v[0]<0);

    for(i=0;i<v[0];i++) {   // Generazione dei valori randomici
        vg=rand()%6+1;
        v[vg]++;
    }
    do {    // Controllo input valore di cui calcolare la frequenza
        printf("Inserire il valore di una faccia di un dado per conoscerne la frequenza: ");
        scanf("%d",&fr);
        system("CLS");
        if(fr<1 || fr>6) {
            printf("Il numero inserito non esiste su un dado\n\n");
        }
    }while(fr<1 || fr>6);

    printf("Il numero %d e\' stato generato %d volte su %d lanci totali (%.2f Percento)\n\n\n",fr,v[fr],v[0],(float)v[fr]/v[0]*100);
    system("PAUSE");
    return 0;
}
