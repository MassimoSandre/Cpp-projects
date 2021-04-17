#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAX 50

int main()
{
    int v[MAX],v1[MAX],v2[MAX],n,i,j=0,k=0,x;
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
    printf("Inserisci un valore di divisione dell\'array: ");
    scanf("%d",&x);

    for(i=0;i<n;i++) {
        if(v[i]>x) {
            v1[j]=v[i];
            j++;
        }
        else {
            v2[k]=v[i];
            k++;
        }
    }

    system("CLS");

    printf("Primo vettore:\n");
    for(i=0; i<j;i++) {
        printf("%d  ",v1[i]);
    }
    printf("\n\nSecondo vettore:\n");
    for(i=0; i<k;i++) {
        printf("%d  ",v2[i]);
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
