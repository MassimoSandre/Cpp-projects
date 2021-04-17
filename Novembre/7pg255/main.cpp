#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAX 50

int main()
{
    int v[MAX],d[MAX/2],di=0,n,i,j,k,tb=0;
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

    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(v[i] == v[j]) {
                for(k=0;k<di;k++) {
                    if(v[i]==d[k]) {
                        tb=1;
                    }
                }
                if(!tb) {
                    d[di]=v[i];
                    di++;

                }
                tb=0;
            }
        }
    }
    if(di>0) {
        printf("I valori ripetuti piu\' volte sono:\n\n");
        for(i=0;i<di;i++) {
            printf("%d  ",d[i]);
        }
    }
    else
        printf("I valori sono tutti diversi");
    printf("\n\n");
    system("PAUSE");
    return 0;
}
