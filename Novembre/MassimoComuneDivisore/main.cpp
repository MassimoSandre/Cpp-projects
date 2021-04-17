#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a,
        b;
    do {
        printf("Inserire 2 numeri positivi: ");
        scanf("%d %d",&a,&b);
        system("CLS");
        if(a<=0 || b<=0) {
            printf("I numeri inseriti non sono accettabili!\n\n");
        }
    }while(a<=0 || b<=0);
    while(a!=b) {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    system("CLS");
    printf("Il Massimo Comune Divisore e\' %d\n\n",a);
    system("PAUSE");
    return 0;
}
