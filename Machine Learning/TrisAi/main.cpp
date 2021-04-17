#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STRUCT 9999

struct sVittorie {
    char vMosse[9];
} svitt[LEN_STRUCT];

void stampatabella(char *v);
bool vittoria(char *v);
bool accettabile(char *inp, char *v);

int main()
{
    char vtris[9],inp[10];
    int mosse;
    while(true) {

        for(int i = 0; i < 9; i++) {
            vtris[i] = ' ';
        }
        mosse = 0;
        stampatabella(vtris);
        do {
            do {
                printf("Inserire la mossa: ");
                fflush(stdin);
                gets(inp);
                system("CLS");
                if(accettabile(inp,vtris)) {
                    stampatabella(vtris);
                    printf("Coordinata non valida\n\n");
                }
            } while(accettabile(inp,vtris));
        } while(mosse < 9);
        if(vittoria) {

        }
    }
    return 0;
}

void stampatabella(char *v) {
    printf("\t\t 1   2   3\n");
    printf("\n\t\t   |   |   \n");
    printf("\tA\t %c | %c | %c \n",v[0],v[1], v[2]);
    printf("\t\t___|___|___\n");
    printf("\t\t   |   |   \n");
    printf("\tB\t %c | %c | %c \n",v[3],v[4], v[5]);
    printf("\t\t___|___|___\n");
    printf("\t\t   |   |   \n");
    printf("\tC\t %c | %c | %c \n",v[6],v[7], v[8]);
    printf("\t\t   |   |   \n\n");
}

bool vittoria(char *v) {

}

bool accettabile(char *inp, char *v) {
    if(atoi(inp) > 0 && atoi(inp) < 4 && strlen(inp) == 2 && (tolower(inp[1]) == 'a' || tolower(inp[1]) ==  'b' || tolower(inp[1]) == 'c')) {
        return true;
    }
    else {
        return false;
    }
}

