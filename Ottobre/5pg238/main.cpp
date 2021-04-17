#include <iostream>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    int NUM;
    do {
        printf("Inserire un numero compreso tra 10 e 20: ");
        scanf("%d", &NUM);
        system("CLS");
        if(NUM >= 20 || NUM <= 10) {
            printf("Si prega di inserire un valore processabile\n\n");
        }
    }while(NUM >= 20 || NUM <= 10);

    int cont;
    for(cont = NUM; cont > 0;cont--) {
        printf("%d\n", cont);
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
