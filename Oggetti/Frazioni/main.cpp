#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Frazione.h"

int main()
{
    int temp;
    char sup[10];
    Frazione f1,f2;

    printf("Inserisci il numeratore della prima frazione: ");
    fflush(stdin);
    gets(sup);
    f1.setNumeratore(atoi(sup));

    do {
        printf("Inserisci in denominatore della prima frazione: ");
        fflush(stdin);
        gets(sup);
        temp = atoi(sup);
        if(temp == 0) {
            printf("\nIl valore inserito non e\' accettabile\n\n");
        }
    }while(temp == 0);
    f1.setDenominatore(temp);

    printf("Inserire il numeratore della seconda frazione: ");
    fflush(stdin);
    gets(sup);
    f2.setNumeratore(atoi(sup));

    do {
        printf("Inserisci in denominatore della seconda frazione: ");
        fflush(stdin);
        gets(sup);
        temp = atoi(sup);
        if(temp == 0) {
            printf("\nIl valore inserito non e\' accettabile\n\n");
        }
    }while(temp == 0);
    f2.setDenominatore(temp);

    system("CLS");

    printf("f1 = ");
    f1.stampaFrazione();

    printf("\nf2 = ");
    f2.stampaFrazione();

    printf("\n\nf1 + f2 = ");
    Frazione t = f1.copiaFrazione();
    t.aggiungiFrazione(f2);
    t.stampaFrazione();

    printf("\nf1 - f2 = ");
    t = f1.copiaFrazione();
    t.sottraiFrazione(f2);
    t.stampaFrazione();

    printf("\nf2 - f1 = ");
    t = f2.copiaFrazione();
    t.sottraiFrazione(f1);
    t.stampaFrazione();

    printf("\nf1 * f2 = ");
    t = f1.copiaFrazione();
    t.moltiplicaFrazione(f2);
    t.stampaFrazione();

    printf("\nf1 / f2 = ");
    t = f1.copiaFrazione();
    t.dividiFrazione(f2);
    t.stampaFrazione();

    printf("\nf2 / f1 = ");
    t = f2.copiaFrazione();
    t.dividiFrazione(f1);
    t.stampaFrazione();
    printf("\n\n");

    system("PAUSE");
    return 0;
}
