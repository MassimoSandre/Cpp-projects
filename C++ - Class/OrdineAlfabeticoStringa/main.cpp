#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXS 20
#define MAXN 20

int main()
{
    char str[MAXS][MAXN],sup[MAXN];
    bool trov=false;
    int n,i,j;
    printf("Inserire il numero di compagni: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Inserire il nome del compagno %d: ",i+1);
        fflush(stdin);
        gets(str[i]);
    }

    printf("Inserire il nome di un compagno da ricercare: ");
    fflush(stdin);
    gets(sup);

    for(i=0;i<n;i++) {
        if(strstr(str[i],sup)&&strlen(str[i])==strlen(sup)) trov=true;
    }

    if(trov) printf("Il compagno e\' presente\n\n");
    else printf("Il compagno non e\' presente\n\n");
    system("PAUSE");
    return 0;
}
