#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    do{
        printf("Inserire un numero tra 1 e 7: ");
        scanf("%d", &n);
        system("CLS");
        if(n > 7 || n < 1) {
            printf("Il numero inserito non puo' essere utilizzato\n\n");
        }
    }while(n > 7 || n < 1);
    printf("Il numero inserito corrisponde a ");
    switch(n)
    {
        case 1:
            printf("LUNEDI\'");
            break;
        case 2:
            printf("MARTEDI\'");
            break;
        case 3:
            printf("MERCOLEDI\'");
            break;
        case 4:
            printf("GIOVEDI\'");
            break;
        case 5:
            printf("VENERDI\'");
            break;
        case 6:
            printf("SABATO");
            break;
        case 7:
            printf("DOMENICA");

            break;
        default:
            system("CLS");
            exit(1);
            break;
    }
    printf("\n\n");
    system("PAUSE");

    return 0;
}
