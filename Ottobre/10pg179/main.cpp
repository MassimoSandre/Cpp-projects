#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int a,
        b,
        r;

    printf("Inserire 2 numeri:\n");
    scanf("%d %d", &a,&b);
    if(a==b)
        r = a;
    else r = (a+b)/2;
    printf("Il valore medio e\': %d\n\n", r);
    system("PAUSE");
    return 0;
}
