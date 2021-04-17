#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int MAXN = 30;
    int v[MAXN],i,n,div=0;
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
        if(v[i]!=v[i+1]) {
            div=1;
            i=n-1;
        }
    }
    if(div)
        printf("I numeri inseriti sono diversi\n\n");
    else
        printf("I numeri inseriti sono uguali\n\n");
    system("PAUSE");
    return 0;
}
