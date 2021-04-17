#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int a,
        b,
        c;
    printf("Inserire i 3 lati di un triangolo:\n");
    scanf("%d %d %d", &a, &b, &c);

    if(a==b && a==c) {
        printf("Il Triangolo inserito e\' equilatero");
    }
    else if(a != b && a != c && b != c) {
        printf("Il Triangolo inserito e\' scaleno");
    }
    else {
        printf("Il Triangolo inserito e\' isoscele");
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
