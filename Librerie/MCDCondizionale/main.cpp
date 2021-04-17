#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a,b;
    printf("Inserire un numero: ");
    scanf("%d",&a);
    system("CLS");
    printf("Inserire un numero: ");
    scanf("%d",&b);
    system("CLS");

    while(a!=b)
        a > b ? a-=b : b-=a;

    printf("MCD: %d\n\n",a);
    system("PAUSE");
    return 0;
}
