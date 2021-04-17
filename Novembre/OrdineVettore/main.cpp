#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int MAXN = 30;
    int v[MAXN],i,n,cre=1,dec=1;
    do {
        printf("Inserire un numero compreso tra 0 e 30: ");
        scanf("%d",&n);
        system("CLS");
        if(n<1 || n>30) {
            printf("Il numero inserito non e\' utilizzabile!\n\n");
        }
    }while(n<1 || n>30);
    for(i=0;i<n;i++) {
        printf("Inserire il valore numero %d: ",i+1);
        scanf("%d",&v[i]);
        system("CLS");
    }
    for(i=0;i<n-1;i++) {
        if(v[i]>v[i+1]) {
            cre=0;
        }
        if(v[i]<v[i+1]) {
            dec=0;
        }
    }
    if(!cre && !dec)
        printf("I numeri inseriti non sono ordinati\n\n");
    else    {
        if(cre && dec) {
            printf("I numeri inseriti sono uguali\n\n");
        }
        else {
            if(cre){
                printf("I numeri inseriti sono in ordine crescente\n\n");
            }
            else {
                printf("I numeri inseriti sono in ordine decrescente\n\n");
            }
        }
    }
    system("PAUSE");
    return 0;
}
