#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n,
        fatt=1;

    do {
        printf("Inserire un numero positivo: ");
        scanf("%d", &n);
        system("CLS");
        if(n < 0) {
            printf("Il numero inserito non e\' utilizzabile\n\n");
        }
    }while(n < 0);
    if(n == 0 || n == 1) {
        printf("\n%d! = 0", n);
    }
    else {
        int i = n;
        while(i > 0) {
            fatt = fatt*i;
            i--;
        }
        printf("\n%d! = %d\n\n\n", n,fatt);
    }
    system("PAUSE");
    return 0;
}
