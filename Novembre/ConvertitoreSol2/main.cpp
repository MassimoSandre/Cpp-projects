#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BASE 16
#define NUMBIT 2

using namespace std;

int main()
{
    int l =pow(BASE,NUMBIT);
    int num, peso;
    printf("Inserire un numero compreso tra 0 e %d: ",l-1);
    scanf("%d",&num);
    if((num > 0) && (num < l-1)) {
        printf("Il numero %d corrisponde a: ",num);
        peso = pow(BASE,(NUMBIT-1));
        while(peso >0) {
            printf("%d", num/peso);
            num =num%peso;
            peso = peso/2;
        }
        printf("\n\n");
    }
    else
        printf("Il numero inserito e\' inutilizzabile\n\n");
    system("PAUSE");
    return 0;
}
