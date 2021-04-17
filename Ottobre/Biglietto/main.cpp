#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int c,
        bg;

    char m;
    do {
        printf("Specificare il mezzo da trasportare (a/c): ");
        scanf("%c",&m);
        system("CLS");
        if(m != 'a' && m != 'c')
        {
            printf("Il mezzo inserito non puo\' essere processato\n\n");
        }
    }while(m != 'a' && m != 'c');

    printf("Inserire la cilindrata del mezzo: ");
    scanf("%d", &c);

    switch(m) {
        case 'a':
            if(c > 2000) {
                bg = 40;
            }
            else {
                if(c > 1000) {
                    bg = 30;
                }
                else {
                    bg = 20;
                }
            }
            break;
        case 'c':
            if(c > 3000) {
                bg = 100;
            }
            else {
                if(c > 2000) {
                    bg = 50;
                }
                else {
                    bg = 40;
                }
            }
            break;
        default:
            exit(1);
            break;
    }
    system("CLS");
    printf("Il prezzo del biglietto e\' di %d euro\n\n\n", bg);
    system("PAUSE");

    return 0;
}
