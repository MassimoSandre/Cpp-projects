#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n,
        i = 0,
        m = 0;

    do {
        printf("Inserire un numero (terminare con 0): ");
        scanf("%d", &n);
        system("CLS");
        if(n != 0) {
            i++;
            m = m + n;
        }
    }while(n!=0);

    if(i == 0)
        printf("Non sono stati inseriti numeri\n\n");
    else
        printf("La media dei numeri inseriti e\' %d\n\n", m/i);

    system("PAUSE");
    return 0;
}
