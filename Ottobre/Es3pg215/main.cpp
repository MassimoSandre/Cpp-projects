#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int num,i = 2;
    do{
        printf("Inserire un numero positivo maggiore di 0\n");
        scanf("%d",&num);
        if(num <= 0) printf("Inserire un numero maggiore di 0!\n");
        system("cls");
    }while(num <= 0);

    while(i<num) {
        if(i % 2 == 0) {
            printf("%d ",i);
        }
        i++;

    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
