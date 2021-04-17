#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define NMAX 20

#define MAXGEN 100
#define MINGEN -100

int ricmax(int v[],int n) {
    if(n == 0) {
        return INT_MIN;
    }
    else {
        return (v[n-1] > ricmax(v,n-1) ? v[n-1] : ricmax(v,n-1));
    }
}
int ricmin(int v[],int n) {
    if(n == 0) {
        return INT_MAX;
    }
    else {
        return (v[n-1] < ricmin(v,n-1) ? v[n-1] : ricmin(v,n-1));
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

    printf("\n\nNumero maggiore: %d\nNumero minore: %d\n\n", ricmax(v,n),ricmin(v,n));
    system("PAUSE");
    return 0;
}
