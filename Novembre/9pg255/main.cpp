#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAXVEC 40

int main()
{
    int v1[MAXVEC/2],v2[MAXVEC/2],vt[MAXVEC],i,n1,n2,j=0,k=0;
    do {
        printf("Inserire in numero di valori del primo vettore (massimo %d): ",MAXVEC/2);
        scanf("%d",&n1);
        system("CLS");
        if(n1<1 || n1>MAXVEC/2)
            printf("Il numero inserito non e\' inutilizzabile\n\n");
    }while(n1<1 || n1>MAXVEC/2);

    for(i=0;i<n1;i++) {
        if(i==0) {
            printf("1/%d | Inserire i valori nel vettore (In ordine crescente): ",n1);
            scanf("%d",&v1[i]);
            system("CLS");
        }
        else {
            do {
                printf("%d/%d | Inserire i valori nel vettore (In ordine crescente): ",i+1,n1);
                scanf("%d",&v1[i]);
                system("CLS");
                if(v1[i]<v1[i-1]) {
                    printf("I numeri devono essere in ordine crescente! (Valore precedente: %d)\n\n",v1[i-1]);
                }
            }while(v1[i]<v1[i-1]);
        }
    }

    do {
        printf("Inserire in numero di valori del secondo vettore (massimo %d): ",MAXVEC/2);
        scanf("%d",&n2);
        system("CLS");
        if(n2<1 || n2>MAXVEC/2)
            printf("Il numero inserito non e\' inutilizzabile\n\n");
    }while(n2<1 || n2>MAXVEC/2);

    for(i=0;i<n2;i++) {
        if(i==0) {
            printf("1/%d | Inserire i valori nel vettore (In ordine crescente): ",n2);
            scanf("%d",&v2[i]);
            system("CLS");
        }
        else {
            do {
                printf("%d/%d | Inserire i valori nel vettore (In ordine crescente): ",i+1,n2);
                scanf("%d",&v2[i]);
                system("CLS");
                if(v2[i]<v2[i-1]) {
                    printf("I numeri devono essere in ordine crescente! (Valore precedente: %d)\n\n",v2[i-1]);
                }
            }while(v2[i]<v2[i-1]);
        }
    }
    i=0;
    while(j<n1 && k<n2) {
        if(v1[j] < v2[k]){
            vt[i]=v1[j];
            j++;
        }
        else{
            vt[i]=v2[k];
            k++;
        }
        i++;
    }

    if(j<n1 && k==n2) {
        for(;i<n2+n1;i++) {
            vt[i]=v1[i-n2];
        }
    }
    else {
        if(j==n1 && k<n2) {
            for(;i<n2+n1;i++) {
                vt[i]=v2[i-n1];
            }
        }
        else{
            printf("\n\nERRORE DI ELABORAZIONE\n\n");
        }
    }
    for(i=0;i<n1+n2;i++){
        printf("%d  ",vt[i]);
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
