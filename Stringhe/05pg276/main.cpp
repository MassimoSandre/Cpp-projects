#include <iostream>
#include <string.h>
#include <stdlib.h>

#define MAX 15

int main()
{

    char str[MAX],in[5],decine[MAX];
    int inp;
    bool uno=false,deci=false;

    do {
        printf("Inserire un valore in cifre: ");
        scanf("%d",&inp);
        system("CLS");
        if(inp>100||inp<0) {
            printf("Inserire un valore compreso tra 0 e 100\n\n");
        }
    }while(inp>100||inp<0);

    itoa(inp,in,10);

    switch(strlen(in)) {
    case 1:
    case 2:
        switch(in[strlen(in)-1]) {
        case '0':
            if(strlen(in)==1) strcpy(str,"zero");
            break;
        case '1':
            strcpy(str,"uno");
            uno=true;
            break;
        case '2':
            strcpy(str,"due");
            break;
        case '3':
            strcpy(str,"tre");
            break;
        case '4':
            strcpy(str,"quattro");
            break;
        case '5':
            strcpy(str,"cinque");
            break;
        case '6':
            strcpy(str,"sei");
            break;
        case '7':
            strcpy(str,"sette");
            break;
        case '8':
            strcpy(str,"otto");
            break;
        case '9':
            strcpy(str,"nove");
            break;
        }

        if(strlen(in)>1) {
            switch(in[0]) {
            case '1':
                switch(in[1]) {
                case '1':
                    strcpy(decine,"undici");
                    break;
                case '2':
                    strcpy(decine,"dodici");

                    break;
                case '3':
                    strcpy(decine,"tredici");
                    break;
                case '4':
                    strcpy(decine,"quattoridici");
                    break;
                case '5':
                    strcpy(decine,"quindici");
                    break;
                case '6':
                    strcpy(decine,"sedici");
                    break;
                case '7':
                    strcpy(decine,"diciassette");
                    break;
                case '8':
                    strcpy(decine,"diciotto");
                    break;
                case '9':
                    strcpy(decine,"diciannove");
                    break;
                }
                deci=true;
                break;
            case '2':
                strcpy(decine,"venti");
                break;
            case '3':
                strcpy(decine,"trenta");
                break;
            case '4':
                strcpy(decine,"quaranta");
                break;
            case '5':
                strcpy(decine,"cinquanta");
                break;
            case '6':
                strcpy(decine,"sesanta");
                break;
            case '7':
                strcpy(decine,"settanta");
                break;
            case '8':
                strcpy(decine,"ottanta");
                break;
            case '9':
                strcpy(decine,"novanta");
                break;
            }
            if(uno&&!deci) {
                decine[strlen(decine)-1]='\0';
            }
            if(!deci) {
                strcat(decine,str);
            }
        }
        else {
            strcpy(decine,str);
        }

    break;
    case 3:
        strcpy(decine,"cento");
        break;
    }

    decine[0]=toupper(decine[0]);
    printf("Il numero inserito e\' %s\n\n",decine);
    system("PAUSE");

    return 0;
}
