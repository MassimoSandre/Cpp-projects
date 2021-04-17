#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int m;

    printf("Inserire un numero maggiore di 0 e minore di 10: ");
    scanf("%d", &m);
    printf("\n\n");
    printf("Il numero inserito e\' ");
    switch(m) {
        case 1:
            printf("UNO");
            break;
        case 2:
            printf("DUE");
            break;
        case 3:
            printf("TRE");
            break;
        case 4:
            printf("QUATTRO");
            break;
        case 5:
            printf("CINQUE");
            break;
        case 6:
            printf("SEI");
            break;
        case 7:
            printf("SETTE");
            break;
        case 8:
            printf("OTTO");
            break;
        case 9:
            printf("NOVE");
            break;
        default:
            printf("inutilizzabile");
            break;

    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
