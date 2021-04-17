#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int n,pos=0,neg=0,somma=0;
    do{
        printf("Inserire un numero positivo o negativo (terminare con 0): ");
        scanf("%d",&n);
        system("CLS");
        if(n<0)
            neg++;

        if(n>0) {
            pos++;
            somma+=n;
        }
    }while(n!=0);
    printf("La media dei numeri positivi inseriti e\' %d \nsono stati inseriti %d numeri negativi\n\n",somma/pos,neg);
    system("PAUSE");
    system("PAUSE");
    return 0;
}
