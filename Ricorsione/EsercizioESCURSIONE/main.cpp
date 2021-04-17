#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 10



int main()
{

    int v[NMAX],i,j,temp;

    /// GENERO UN VETTORE DI NMAX ELEMENTI
    srand(time(NULL));
    for(i = 0; i < NMAX; i++) {
        v[i] = rand()%10+1;
    }
    /// STAMPO IN VETTORE
    for(i = 0; i < NMAX; i++) {
        printf("%3d",v[i]);
    }
    printf("\n\n");

    /// SELECT-SORT
    /*int posmin;
    for(i = 0; i < NMAX-1; i++) {
        posmin = i;
        for(j = i+1; j < NMAX; j++) {
            if(v[j] < v[posmin]) {
                posmin = j;
            }
        }
        if(posmin != i) {
            temp = v[i];
            v[i] = v[posmin];
            v[posmin] = temp;
        }

    }*/

    /// INSERT-SORT
    /*for(i = 1; i < NMAX; i++) {
        int ele = v[i];
        j=i-1;
        while(j>=0 && ele<v[j]) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = ele;
    }*/


    /// BUBBLE-SORT OTTIMIZZATO
    bool ord = true;
    int n = NMAX-1;
    while(ord && n>0) {
        ord = false;
        for(i = 0; i<n;i++) {
            if(v[i] > v[i+1]) {
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                ord = true;
            }
        }
        n--;
    }



    /// STAMPO IN VETTORE
    for(i = 0; i < NMAX; i++) {
        printf("%3d",v[i]);
    }
    printf("\n\n");

     /// RICERCA BINARIA
    int sin = 0, des = NMAX - 1, med, x;
    bool tr = false;
    printf("Inserire l\'elemento da cercare: ");
    scanf("%d",&x);
    do {
        med = (sin+des)/2;
        if(v[med] == x) {
            tr = true;
        }
        else {
            if(v[med] > x) {
                des = med-1;
            }
            else {
                sin = med+1;
            }
        }

    }while(!tr && sin <= des);

    if(tr)
        printf("PRES");
    else {
        printf("NPRES");
    }
    return 0;
}
