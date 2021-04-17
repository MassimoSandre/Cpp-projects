#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n,
        i = 0;
    do {
        printf("Inserire un numero (terminare con 0): ");
        scanf("%d", &n);
        system("CLS");
        if(n != 0) {
            i++;
        }
    }while(n!=0);
    if(i == 0)
        printf("Non sono stati inseriti dei numeri\n\n\n");
    else
        printf("Sono stati inserito %d numeri\n\n\n", i);
    system("PAUSE");
    return 0;
}
