#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,
        rn,
        dis = 0,
        par = 0;
    srand(time(NULL));
    printf("Inserire un numero: ");
    scanf("%d", &n);
    for (int i = 0; i < n;i++) {
        rn = rand()%101;
        printf("%d\n",rn);
        if(rn % 2 == 0)
            par++;
        else
            dis++;
    }
    printf("Numeri pari generati: %d\n",par);
    printf("Numeri dispari generati: %d\n",dis);
    return 0;
}
