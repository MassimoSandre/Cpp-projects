#include <iostream>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    int NUM;
    do {
        printf("Inserire un numero compreso tra 1 e 20: ");
        scanf("%d", &NUM);
        system("CLS");
        if(NUM >= 20 || NUM <= 1) {
            printf("Si prega di inserire un valore processabile\n\n");
        }
    }while(NUM >= 20 || NUM <= 1);

    int y,x;
    if(NUM > 10) {
        for(y = 0; y < NUM; y++) {
        if(y >= 10)
            printf("%d  ", y);
        else
            printf("%d   ", y);
        for(x = 1; x < NUM; x++) {

            if(y == 0) {
                if(x >= 10) {
                    if(x >=100)
                        printf("%d ",x);
                    else
                        printf("%d  ",x);
                }
                else
                    printf("%d   ",x);
            }
            else {
                if(x*y >=10) {
                    if(x*y >= 100)
                        printf("%d ",y*x);
                    else
                        printf("%d  ",y*x);


                }
                else
                     printf("%d   ",x*y);
            }
        }
        printf("\n\n\n");
    }
    }
    else {
       for(y = 0; y < NUM; y++) {
        printf("%d\t", y);
        for(x = 1; x < NUM; x++) {
            if(y == 0) {
                printf("%d\t",x);
            }
            else
                printf("%d\t",y*x);
        }
        printf("\n\n\n");
    }
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
