#include <iostream>
#include <stdio.h>
#include <stdlib.h>

unsigned long long potenza(int n, int e) {
    if(e == 0) {
        return 1;
    }
    else {
        return n * potenza(n,e-1);
    }
}

int main()
{
    int n,e;

    printf("Inserire un numero da elevare a potenza: ");
    scanf("%d",&n);

    do {
        printf("Inserire l\'esponente: ");
        scanf("%d",&e);
        system("CLS");
        if(e<0) {
            printf("Inserire un esponente positivo\n\n");
        }
    }while(e<0);

    printf("Risultato della potenza: ");
    std::cout << potenza(n,e) << std::endl << std::endl;
    system("PAUSE");
    return 0;
}
