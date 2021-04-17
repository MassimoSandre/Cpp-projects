#include <iostream>
#include <stdio.h>
#include <stdlib.h>



int main()
{
    int v[5],i,somma=0;
    for(i=0;i<5;i++) {
        printf("Inserire il valore numero %d: ",i+1);
        scanf("%d",&v[i]);
        system("CLS");
    }
    for(i=0;i<5;i++) {
        somma+=v[i];
    }
    printf("La somma dei numeri inseriti e\': %d\n\n\n",somma);
    system("PAUSE");
}
