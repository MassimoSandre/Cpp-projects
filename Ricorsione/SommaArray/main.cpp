#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 20

#define MAXGEN 10
#define MINGEN 1

int som(int v[],int n) {
    if(n == 0) {
        return 0;
    }
    else {
        return v[n-1] + som(v,n-1);
    }
}

int main()
{
    int v[NMAX],n,i;

    do {
        printf("Inserire un numero compreso tra 1 e %d: ",NMAX);
        scanf("%d",&n);
        system("CLS");
        if(n<1 || n>NMAX)
            printf("Il numero inserito non e\' processabile\n\n");
    } while(n<1 || n>NMAX);

    srand(time(NULL));
    for(i = 0; i < n; i++) {
        v[i] = rand()%(MAXGEN-MINGEN+1)+MINGEN;
    }

    for(i = 0; i < n; i++) {
        printf("%4d",v[i]);
    }

    printf("\n\nLa somma degli elementi del vettore e\': %d\n\n", som(v,n));
    system("PAUSE");
    return 0;
}
