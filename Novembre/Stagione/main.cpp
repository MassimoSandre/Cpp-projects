#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int m,g;
    do {
        printf("Inserire un mese (numero): ");
        scanf("%d",&m);
        system("CLS");
        if(m>12 || m<1)
            printf("Il numero inserito non rappresenta un mese!\n\n");
    }while(m>12 || m<1);
    printf("In questo periodo dell\'anno e\' ");
    switch(m) {
        case 1:
        case 2:
            printf("Inverno");
            break;
        case 3:
            system("CLS");
            do{
                printf("Specificare il giorno: ");
                scanf("%d",&g);
                system("CLS");
                if(g<1 || g>31) {
                    printf("Il numero inserito non puo\' appartenere a questo mese!\n\n");
                }
            }while(g<1 || g>31);
            printf("In questo periodo dell\'anno e\' ");
            if(g<21)
                printf("Inverno");
            else
                printf("Primavera");
            break;
        case 4:
        case 5:
            printf("Primavera");
            break;
        case 6:
            system("CLS");
            do{
                printf("Specificare il giorno: ");
                scanf("%d",&g);
                system("CLS");
                if(g<1 || g>31) {
                    printf("Il numero inserito non puo\' appartenere a questo mese!\n\n");
                }
            }while(g<1 || g>31);
            printf("In questo periodo dell\'anno e\' ");
            if(g<21)
                printf("Primavera");
            else
                printf("Estate");
            break;
        case 7:
        case 8:
            printf("Estate");
            break;
        case 9:
            system("CLS");
            do{
                printf("Specificare il giorno: ");
                scanf("%d",&g);
                system("CLS");
                if(g<1 || g>30) {
                    printf("Il numero inserito non puo\' appartenere a questo mese!\n\n");
                }
            }while(g<1 || g>30);
            printf("In questo periodo dell\'anno e\' ");
            if(g<23)
                printf("Estate");
            else
                printf("Autunno");
            break;
        case 10:
        case 11:
            printf("Autunno");
            break;
        case 12:
            system("CLS");
            do{
                printf("Specificare il giorno: ");
                scanf("%d",&g);
                system("CLS");
                if(g<1 || g>31) {
                    printf("Il numero inserito non puo\' appartenere a questo mese!\n\n");
                }
            }while(g<1 || g>31);
            printf("In questo periodo dell\'anno e\' ");
            if(g<21)
                printf("Autunno");
            else
                printf("Inverno");
            break;
        default:
            system("CLS");
            printf("Errore di elaborazione");
            break;
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
