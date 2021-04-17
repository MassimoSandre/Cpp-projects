#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 20

#define MAXGEN 10
#define MINGEN 1

int ricerca(int v[],int n,int x) {
    if(v[n-1] == x) {
        return true;
    }
    else {
        if(n == 1) {
            return false;
        }
        else {
            return ricerca(v,n-1,x);
        }
    }
}

int main()
{
    int v[NMAX],n,i,x;

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

    printf("\nInserire un numero da cercare: ");
    scanf("%d", &x);

    if(ricerca(v,n,x)) {
        printf("Presente");
    }
    else {
        printf("Non presente");
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
