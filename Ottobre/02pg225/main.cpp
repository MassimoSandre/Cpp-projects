#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n,
        m = INT_MIN;
    do {
        do {
            printf("Inserire un numero positivo (terminare con 0): ");
            scanf("%d", &n);
            system("CLS");
            if(n < 0) {
                printf("Il numero inserito e\' negativo!\n\n");
            }
            else {
                if(n > m) {
                    m = n;
                }
            }
        }while(n < 0);
    }while (n != 0);
    system("CLS");
    printf("Il numero maggiore tra quelli inserito e\' %d\n\n", m);
    system("PAUSE");
    return 0;
}
