#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAX 50

int main()
{
    int v[MAX],n,i
    ,tobesh;
    do {
        printf("Inserire il numero di elementi del vettore (massimo %d): ",MAX);
        scanf("%d",&n);
        system("CLS");
        if(n<1 || n>MAX)
            printf("Il numero inserito non rispetta i limiti imposti\n\n");
    }while(n<1 || n>MAX);

    for(i=0;i<n;i++) {
        printf("Inserire il valore numero %d di %d: ",i+1,n);
        scanf("%d",&v[i]);
        system("CLS");
    }

    printf("Inserire un valore da cercare nel vettore: ");
    scanf("%d",&tobesh);
    system("CLS");

    for(i=0;i<n;i++) {
        if(v[i] == tobesh) {
            printf("Il numero cercato e\' stato trovato nella posizione %d (Inserimento n.%d)\n",i,i+1);
        }
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
