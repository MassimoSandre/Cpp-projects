#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n==0 || n ==1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    int e;

    do {
        printf("Inserire un numero positivo: ");
        scanf("%d",&e);
        system("CLS");
    }while(e<0);

    printf("Risultato di fibonacci corrispondente: %d\n\n",fibonacci(e));
    system("PAUSE");
    return 0;
}
