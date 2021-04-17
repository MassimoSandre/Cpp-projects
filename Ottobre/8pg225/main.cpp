#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dado1,
        dado2;
    srand(time(NULL));
    dado1 = (rand()%6)+1;
    dado2 = (rand()%6)+1;
    printf("Il risultato del lancio dei dadi e\' %d e %d\n\n", dado1,dado2);
    printf("Totale: %d\n\n\n", dado1+dado2);
    system("PAUSE");
    return 0;
}
