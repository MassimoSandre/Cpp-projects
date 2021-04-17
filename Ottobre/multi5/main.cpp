#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int i = 11;
    while (i < 100) {
        if(i%5 == 0) {
            printf("%d ", i);
        }
        i++;
    }
    printf("\n");
    system("PAUSE");
    return 0;
}
