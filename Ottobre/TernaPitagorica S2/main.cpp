#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int a,
        b,
        c,
        temp;

    /*  Input dei lati del triangolo */
    printf("Inserire i 3 lati di un triangolo\n");
    scanf("%d %d %d", &a, &b,&c);

    /*  Rilevamento ipotenusa */
    if(a > b && a > c);
    else {
        if(b > a && b > c) {
            temp = a;
            a = b;
            b = temp;
        }
        else
            if(c > a && c > b) {
                temp = a;
                a = c;
                c = temp;
            }
            else {
                printf("\nIl triangolo inserito non e\' rettangolo\n");
                system("PAUSE");
                return 0;
            }
    }

    a*=a;
    b*=b;
    c*=c;

    if(b + c == a) {
        printf("\nIl triangolo inserito e\' rettangolo\n");
    }
    else {
        printf("\nIl triangolo inserito non e\' rettangolo\n");
    }

    system("PAUSE");
    return 0;
}
