#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VAL 10

#define MAXGEN 10
#define MINGEN 1

int main()
{
    int a[VAL],b[VAL],n,ps=0,i;
    srand(time(NULL));
    do {
        printf("Inserire il numero di valori per vettore (da 1 a %d): ",VAL);
        scanf("%d",&n);
        system("CLS");
        if(n>VAL||n<1) {
            printf("Si prega di inserire un numero da 1 a %d\n\n",VAL);
        }
    }while(n>VAL||n<1);

    for(i=0;i<n;i++) {
        a[i]=rand()%(MAXGEN-MINGEN+1)+MINGEN;
        b[i]=rand()%(MAXGEN-MINGEN+1)+MINGEN;
    }
    printf("Vettore a:");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\nVettore b:");
    for(i=0;i<n;i++)
        printf("%d\t",b[i]);

    for(i=0;i<n;i++) {
        ps+=a[i]*b[i];
    }
    printf("\n\n Prodotto scalare: %d\n\n",ps);
    system("PAUSE");
    return 0;
}
