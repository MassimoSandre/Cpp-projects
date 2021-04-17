#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int num;
    do {
        printf("Inserire un numero positivo maggiore di 0\n");
        scanf("%d", &num);
        system("CLS");
        if(num <= 0) printf("Il numero %d non puo\' essere utilizzato!\n",num);
    }while(num <= 0);
    int cont = 0,l,totale = 0;
    do{
        printf("Inserire un numero: ");
        cin >> l;
        totale = totale + l;
        system("CLS");
        cont++;
    }while(cont < num);
    printf("Il risultato e\': %d\n\n", totale);
    system("PAUSE");
    return 0;
}
