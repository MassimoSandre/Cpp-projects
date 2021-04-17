#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAXV 20 // Dimensione massima del vettore

int main()
{
    int vn[MAXV],   // Vettore non compresso
        vp[MAXV],   // Vettore compresso
        n,          // Numero di valori nel vettore
        rip,        // Flag della rilevazione
        i,          // Contatore generico + indice del vettore non compresso
        j,          // indice del vettore compresso
        val=0;
    do { // Mi assicuro che l'utente inserisca un numero di elementi inseribili nel vettore
        printf("Inserire il numero di valori del vettore: ");
        scanf("%d",&n);
        system("CLS");
        if(n<1||n>MAXV){
            printf("Si prega di inserire un numero positivo minore di %d\n\n",MAXV);
        }
    }while(n<1||n>MAXV);

    for(i=0;i<n;i++) { // Carico manualmente il vettore non compresso
        printf("Inserire un valore (%d/%d): ",i+1,n);
        scanf("%d",&vn[i]);
        system("CLS");
    }

    for(i=0;i<n;i++) {  // Porto tutte le posizioni del vettore a 0
        vp[i]=0;        // In questo modo in fase di controllo questa cifra
    }                   // Verrà esclusa in automatico


    for(i=0;i<n;i++) {  // Scorro tutti i valori del vettore
        rip=0;

        for(j=0;j<val+1;j++) {  // Controllo che il valore non sia già presente nel vettore compresso
            if(vn[i]==vp[j])    // il valore vp[val] sarà sempre uguale a 0
                rip=1;          // quindi questa cifra verra esclusa a prescindere
        }
        if(!rip) {              // Se il valore non viene trovato
            vp[val]=vn[i];      // Viene inserito
            val++;
        }
    }
    printf("Vettore compresso:\n");
    for(i=0;i<val;i++) {    // Output del vettore compresso
        printf("%d\t",vp[i]);
    }
    printf("\n");
    system("PAUSE");
    return 0;
}
