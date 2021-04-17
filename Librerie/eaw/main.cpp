#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXVAL 50

#define MAXGEN 100
#define MINGEN 1

int main()
{
    int v[MAXVAL],n,sc,i,j;
    char mode;
    srand(time(NULL));

    do {
        printf("Inserire il numero di valori del vettore: ");
        scanf("%d",&n);
        system("CLS");
        if(n>MAXVAL||n<0)
            printf("Il numero deve essere maggiore di 0 e minore o uguale a %d\n\n",MAXVAL);
    }while(n>MAXVAL||n<0);

    do {
        printf("Specificare se si intende caricare il vettore manualmente o automaticamente(m/a): ");
        scanf("%c",&mode);
        system("CLS");
    }while(mode!='m'&&mode!='a'&&mode!='M'&&mode!='A');


    switch(mode) {
        case 'a':
        case 'A':
            for(i=0;i<n;i++)
                v[i]=rand()%(MAXGEN-MINGEN+1)+MINGEN;
            break;
        case 'm':
        case 'M':
            for(i=0;i<n;i++){
                printf("Inserire il numero il posizione %d: ",i);
                scanf("%d",&v[i]);
                system("CLS");
            }
            break;
    }


    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(v[j]<v[i]) {
                sc=v[i];
                v[i]=v[j];
                v[j]=sc;
            }
        }
    }

    printf("Numeri ordinati:\n");
    for(i=0;i<n;i++)
        printf("%d\t",v[i]);

    return 0;
}
