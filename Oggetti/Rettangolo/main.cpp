#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Rettangolo.h"

int main()
{
    Rettangolo ret;
    float n,t;
    printf("Inserire l'altezza del rettangolo: ");
    scanf("%f",&n);
    ret.setAltezza(n);
    printf("Inserire la lunghezza del rettangolo: ");
    scanf("%f",&n);
    ret.setLarghezza(n);
    system("CLS");
    printf("Dati rettangolo:\n\t");
    ret.stampa();
    printf("\n\n");
    printf("Altezza: %f\n",ret.getAltezza());
    printf("Larghezza: %f\n",ret.getLarghezza());
    printf("Area: %f\n",ret.getArea());
    printf("Perimetro: %f\n\n",ret.getPerimetro());

    printf("Inserire una nuova altezza per il rettangolo: ");
    scanf("%f",&n);
    printf("Inserire una nuova larghezza per il rettangolo: ");
    scanf("%f",&t);
    ret.modifica(n,t);
    system("CLS");
    printf("Dati nuovo rettangolo:\n\t");
    ret.stampa();
    printf("\n\n");
    printf("Altezza: %f\n",ret.getAltezza());
    printf("Larghezza: %f\n",ret.getLarghezza());
    printf("Area: %f\n",ret.getArea());
    printf("Perimetro: %f\n\n",ret.getPerimetro());
    return 0;
}
