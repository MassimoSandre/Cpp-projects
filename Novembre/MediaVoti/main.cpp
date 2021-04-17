#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAXN 30

int main()
{
    int v[MAXN],
        n,      // Numero di studenti
        i,      // Contatore | Indice
        s=0;    // Somma dei voti
    float m;    // Media dei voti
    do{         // Controllo sull'input
        printf("Inserire il numero di studenti (da 1 a %d): ",MAXN);
        scanf("%d",&n);
        system("CLS");
        if(n<1 || n>MAXN)
            printf("Il numero inserito non e\' utilizzabile\n\n");
    }while(n<1 || n>MAXN);

    for(i=0;i<n;i++) {  // Inserimento dei voti degli studenti
        do{
            printf("Inserire i voti da 1 a 10\nInserire il voto preso dallo studente numero %d: ",i+1);
            scanf("%d",&v[i]);
            system("CLS");
            if(v[i]<1 || v[i]>10)
                printf("Il numero inserito non e\' utilizzabile\n\n");
        }while(v[i]<1 || v[i]>10);

    }

    for(i=0;i<n;i++) {  // Somma dei voti
        s+=v[i];
    }

    m=(float)s/n;       // Calcolo media
    printf("La media dei voti della classe e\' %.1f\n\n",m);

    system("PAUSE");
    return 0;
}
