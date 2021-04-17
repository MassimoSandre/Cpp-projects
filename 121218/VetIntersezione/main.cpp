#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAXV 30 // Dimensione massima del vettore

int main()
{
    int n,          // Numero di valori nei vettori
        v1[MAXV],   // Primo vettore
        v2[MAXV],   // Secondo vettore
        ve[MAXV],   // Valore intersezione di v1 e v2
        val=0,      // Contatore degli elementi di intersezione;
        rip=0,      // flag della rilevazione dell'intersezione (se posto a 1 non viene inserito il valore)
        i,          // Contatore generico + indice primo del vettore
        j,          // indice del secondo vettore
        k;          // Indice ausiliario
     do {   // Mi assicuro che l'utente inserisca un numero di elementi inseribili nei vettori
        printf("Inserire il numero di valori dei vettori: ");
        scanf("%d",&n);
        system("CLS");
        if(n<1||n>MAXV){
            printf("Si prega di inserire un numero positivo minore di %d\n\n",MAXV);
        }
    }while(n<1||n>MAXV);

    for(i=0;i<n;i++) {  // Caricamento manuale del primo vettore
        printf("Inserire i valori per il primo vettore(%d/%d): ",i+1,n);
        scanf("%d",&v1[i]);
        system("CLS");
    }
    for(i=0;i<n;i++) {  // Caricamento manuale del secondo vettore
        printf("Inserire i valori per il secondo vettore(%d/%d): ",i+1,n);
        scanf("%d",&v2[i]);
        system("CLS");
    }

    for(i=0;i<n;i++) {  // Scorro tutti i valori del primo vettore
        rip=0;
        for(j=0;j<n;j++) {  // Scorro tutti i valori del secondo vettore
            if(v1[i]==v2[j]) {          // Se viene rilevata un intersezione
                for(k=0;k<val;k++) {    // si verifica che questa non sia
                    if(ve[k]==v2[j])    // ancora stata inserita nel vettore
                        rip=1;

                }
                if(!rip) {          // Se non si trova la stessa intersezione
                    ve[val]=v1[i];  // quella rilevata viene inserita nel vettore delle intersezioni
                    val++;
                }
            }
        }
    }

    printf("Intersezione dei vettori:\n");
    for(i=0;i<val;i++) {    // Output del vettore delle intersezioni
        printf("%d\t",ve[i]);
    }
    printf("\n");
    system("PAUSE");

    return 0;
}
