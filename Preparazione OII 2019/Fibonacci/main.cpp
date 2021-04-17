#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int fibonacci(int n) {
    if(n==0||n==1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}


int main()
{
    int n;
    printf("Sequenza di Fibonacci\n");
    do {
        printf("Inserire un numero positivo: ");
        scanf("%d",&n);printf("Sequenza di Fibonacci\n");
        system("CLS");
        if(n<=0)
            printf("Sequenza di Fibonacci\nSi prega di inserire un numero positivo!\n\n");
    }while(n<=0);
    printf("Il numero inserito corrisponde alla posizione del numero di Fibonacci: %d\n\n",fibonacci(n-1));
    system("PAUSE");
    return 0;
}
