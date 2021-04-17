#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXN 30

int main()
{
    srand(time(NULL));
    int v[MAXN],
        n,  // Numero di valori da generare
        i,  // Contatore e Indice 1
        j,  // Contatore e Indice 2
        tr=0;   // Flag verifica ripetizioni
    do{         // Controllo sull'input
        printf("Inserire il numero di valori da generare (da 1 a %d): ",MAXN);
        scanf("%d",&n);
        system("CLS");
        if(n<1 || n>MAXN)
            printf("Il numero inserito non e\' utilizzabile\n\n");
    }while(n<1 || n>MAXN);

    for(i=0;i<n;i++){   // Generazione di n valori randomici (n > 0 && n <= 30)
        v[i]=rand()%100+1;
    }

    for(i=0;i<n;i++) {  // Doppio ciclo for per identificazione di valori uguali
        for(j=i+1;j<n;j++) {
            if(v[i] == v[j]) {
                tr = 1;
                i=n;
                j=n;
            }
        }
    }

    if(tr)
        printf("Tra i numeri generati ci sono delle ripetizioni\n\n");
    else
        printf("Tra i numeri generati non ci sono delle ripetizioni\n\n");
    system("PAUSE");
    return 0;
}
