#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int m;

    printf("Inserire un numero compreso tra 1 e 12: ");
    scanf("%d", &m);
    printf("\n\n");

    switch(m) {
        case 1:
            printf("Il mese inserito e\' gennaio");
            break;

        case 2:
            printf("Il mese inserito e\' febbraio");
            break;

        case 3:
            printf("Il mese inserito e\' marzo");
            break;

        case 4:
            printf("Il mese inserito e\' aprile");
            break;

        case 5:
            printf("Il mese inserito e\' maggio");
            break;

        case 6:
            printf("Il mese inserito e\' giugno");
            break;

        case 7:
            printf("Il mese inserito e\' luglio");
            break;

        case 8:
            printf("Il mese inserito e\' agosto");
            break;

        case 9:
            printf("Il mese inserito e\' settembre");
            break;

        case 10:
            printf("Il mese inserito e\' ottobre");
            break;

        case 11:
            printf("Il mese inserito e\' novembre");
            break;

        case 12:
            printf("Il mese inserito e\' dicembre");
            break;

        default:
            printf("\n\nIl numeri inserito non e\' un mese\n\n");
            break;
    }

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
